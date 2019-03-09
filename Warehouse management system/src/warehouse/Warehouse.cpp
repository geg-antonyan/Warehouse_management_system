#include "Warehouse.h"

#include "ExpiredProducts.h"

#include "../utilites/Exception.h"
#include "../utilites/freeFunc.h"
#include "../utilites/UserInterface.h"

#include "../management/Discounts.h"
#include "../management/Cargo.h"

#include <set>

using std::dynamic_pointer_cast;
using std::unique_lock;
using std::mutex;
using std::to_string;
using std::string;
using std::vector;
using std::map;
using std::make_shared;
using std::make_pair;
using std::set;

RegRackData::RegRackData(const std::string& _data)
{
	string str = _data;
	if (str.length() > 1 && str[str.length() - 1] != ' ')
		str += ' ';
	vector<int> vec;
	int i = 0;
	string::size_type k = str.find(' '), j = 0;
	while (k != string::npos)
	{
		vec.push_back(atoi(str.substr(j, k).c_str()));
		j = k + 1;
		k = str.find(' ', j);
	}
	if (vec.size() != 4)
		throw Exception("Некорректная информация для добавлении полки в склад");
	if (vec[1] > vec[3] || vec[1] <= 0 || vec[2] >= vec[3])
		throw Exception("Некорректная информация для добавлении полки в склад");
	id_ = vec[0]; size_ = vec[1]; minSize_ = vec[2]; maxSize_ = vec[3];
	state_ =  NoWaitingOrder;
}

RegRackData::~RegRackData()
{
}

int RegRackData::id() const
{
	return id_;
}

int RegRackData::size() const
{
	return size_;
}

int RegRackData::minSize() const
{
	return minSize_;
}

int RegRackData::maxSize() const
{
	return maxSize_;
}



RackState RegRackData::state() const
{
	return state_;
}


Racks::Racks(int _id, int _size, int _minSize, int _maxSize) :
	minSize_(_minSize),
	maxSize_(_maxSize),
	state_(NoWaitingOrder)
{
	id_ = _id;
	if (_size > _maxSize || _minSize >= _maxSize || _size == 0)
		throw Exception("Некорректный данные для регистрации полки на Складе");
	while (_size--)
		boxes_.push_back(dynamic_pointer_cast<Box>(BoxCatalog::Instance().makeBox(id_)));
	describe_ = boxes_[0]->describe();
}

int Racks::size() const
{
	return boxes_.size();
}

int Racks::minSize() const
{
	return minSize_;
}

int Racks::maxSize() const
{
	return maxSize_;
}

std::deque<BoxPtr> Racks::boxes() const
{
	return boxes_;
}

double Racks::summary() const
{
	double res = 0.0;
	for (auto& ptr : boxes_)
		res += ptr->price();
	return res;
}

RackState Racks::state() const
{
	return state_;
}

View Racks::getInfLine(int _count)
{
	View res;
	if (_count <= 0 || _count > boxes_.size()) _count = boxes_.size();
	res.resize(_count + 1);
	size_t i = 0;
	res[i] = { "№", "Продукт", "Кол", "Ед. изм.", "Цена", "Скидка %", "Сумма" , "Срок год." };
	for (i = 1; i < _count + 1; i++)
	{
		auto& box = boxes_[i - 1];
		res[i] =
		{
			to_string(box->number()), box->prdDescribe(), to_string(box->size()),
			Unit_KeyUnit.find(box->unit())->second, treatMoney(to_string(box->unitPrice())),
			treatMoney(to_string(box->discount())), treatMoney(to_string(box->price())),
			to_string(box->shelfTime())
		};
	}
	return res;
}


Warehouse& Warehouse::Instance()
{
	static Warehouse instance;
	return instance;
}

void Warehouse::registerElement(ElementsPtr _elem, bool _raise)
{
	RacksPtr rack = dynamic_pointer_cast<Racks>(_elem);
	initCapital_ += rack->summary();
	Container::registerElement(rack, _raise);
}

void Warehouse::addBox(BoxPtr _box, Operation _oper, bool _raise)
{
	unique_lock<mutex> uLock(mtx);
	Repos::const_iterator it = hasKey(_box->id());
	RacksPtr rack = dynamic_pointer_cast<Racks>(it->second);
	if (rack->size() >= rack->maxSize_)
		throw Exception("Полка № " + to_string(rack->id()) + " полная");
	rack->boxes_.push_back(_box);
	if (_oper == Delivery)
		deliverySum_ += _box->price();
	uLock.unlock();
	if (_raise)
		raiseEvent(ContainerUpdate, nullptr);
}

vector<BoxPtr> Warehouse::handleStoreOrder(const StoreOrdersPtr _order, bool _raise)
{
	vector<BoxPtr> res;
	mtx.lock();
	for (const auto& ptr : _order->orderData())
	{
		RacksPtr rack = dynamic_pointer_cast<Racks>(find(ptr.first));
		if (!rack || !rack->size()) continue;
		BoxPtr box = rack->boxes_.front();
		int	resCount = ptr.second / box->size();
		int ostatok = ptr.second % box->size();
		if (ostatok > box->size() / 2)
			resCount++;
		if (!resCount) resCount++; // дл¤ безопаснсти
		if (resCount > rack->size()) resCount = rack->size();
		for (int i = 0; i < resCount; i++)
		{
			res.push_back(rack->boxes_.front());
			rack->boxes_.pop_front();
		}
	}
	mtx.unlock();
	if (!res.empty())
	{
		if (_raise)
			raiseEvent(ContainerUpdate, nullptr);
	}
	return res;
}

void Warehouse::receiveDelivery(const vector<BoxPtr>& _boxes,  bool _raise)
{
	set<int> rackId;
	for (const auto& ptr : _boxes)
	{
		rackId.insert(ptr->id());
		addBox(ptr, Delivery, false);
	}
	unique_lock<mutex> uLock(mtx);
	for (const auto& ptr : rackId)
	{
		RacksPtr rack = dynamic_pointer_cast<Racks>(hasKey(ptr)->second);
		rack->state_ = NoWaitingOrder;
	}
	uLock.unlock();
	if (_raise)
		raiseEvent(ContainerUpdate, nullptr);
}

void Warehouse::setRackState(int _id, RackState _state, bool _raise)
{
	unique_lock<mutex> uLock(mtx);
	RacksPtr rack = dynamic_pointer_cast<Racks>(find(_id));
	if (!rack) return;
	rack->state_ = _state;
	uLock.unlock();
	if (_raise)
		raiseEvent(ContainerUpdate, nullptr);
}


void Warehouse::setDiscount(const DiscountPtr& _dsnt, bool _raise)
{
	unique_lock<mutex> uLock(mtx);
	double summary = 0.0;
	RacksPtr rack = dynamic_pointer_cast<Racks>(find(_dsnt->boxId()));
	if (!rack) return;
	vector<int> nums = _dsnt->numbers();
	auto& boxes = rack->boxes_;
	double precent = _dsnt->precent();
	for (size_t i = 0; i < boxes.size() && !nums.empty(); i++)
		for (size_t j = 0; j < nums.size(); j++)
			if (boxes[i]->number() == nums[j])
			{
				double tmp = boxes[i]->price();
				boxes[i]->setDiscount(precent);
				tmp -= boxes[i]->price();
				summary += tmp;
				nums.erase(nums.begin() + j);
				break;
			}
	discountSum_ += summary;
	uLock.unlock();
	DiscountsRepos::Instance().addSumm(summary, true);
	if (_raise)
		raiseEvent(ContainerUpdate, nullptr);
}

void Warehouse::generateDiscount(int _shelfTime, double _precent)
{
	if (!fullSize()) return;
	unique_lock<mutex> uLock(mtx);
	for (const auto& iPtr : repos_)
	{
		vector<int> numbers;
		RacksPtr rack = dynamic_pointer_cast<Racks>(iPtr.second);
		for (const auto& jPtr : rack->boxes_)
			if (jPtr->shelfTime() <= _shelfTime && jPtr->discount() < _precent)
				numbers.push_back(jPtr->number());
		if (!numbers.empty())
			DiscountsRepos::Instance().registerElement(make_shared<Discount>(rack->id_, numbers, _precent), true);
	}
}

void Warehouse::controlDecrease(bool _raise)
{
	unique_lock<mutex> uLock(mtx);
	OrderData orderData;
	for (auto& ptr : repos_)
	{
		RacksPtr rack = dynamic_pointer_cast<Racks>(ptr.second);
		if (rack->size() <= rack->minSize_ && rack->state_ == NoWaitingOrder)
		{
			orderData.insert(make_pair(rack->id_, rack->maxSize_ - rack->size()));
			rack->state_ = WaitingOrder;
		}
	}
	uLock.unlock();
	if (_raise)
		raiseEvent(ContainerUpdate, nullptr);
	if (orderData.empty()) return;
	WarehouseOrdersPtr order = make_shared<WarehouseOrders>(orderData);
	CargoWarehouseRepos::Instance().registerElement(make_shared<CargoWarehouse>(order), true);
}

void Warehouse::controlOverdue(bool _raise)
{
	unique_lock<mutex> uLock(mtx);
	vector<BoxPtr> boxes;
	for (auto& ptr : repos_)
	{
		RacksPtr rack = dynamic_pointer_cast<Racks>(ptr.second);
		for (size_t i = 0; i < rack->boxes_.size(); i++)
			if (rack->boxes_[i]->shelfTime() <= 0)
			{
				overdueSum_ += rack->boxes_[i]->price();
				boxes.push_back(rack->boxes_[i]);
				rack->boxes_.erase(rack->boxes_.begin() + i);
				i--;
			}
	}
	uLock.unlock();
	if (boxes.size())
	{
		if (_raise)
			raiseEvent(ContainerUpdate, nullptr);
		ExpiredProducts::Instance().addExpiredBoxes(boxes, true);
	}
}

void Warehouse::setSaleSumm(double _summ, bool _raise)
{
	unique_lock<mutex> uLock(mtx);
	salesSum_ += _summ;
	uLock.unlock();
	if (_raise)
		raiseEvent(ContainerUpdate, nullptr);
}





View Warehouse::getInfLine(int _count) const
{
	mtx.lock();
	View res;
	if (_count <= 0 || _count > repos_.size()) _count = repos_.size();
	res.resize(_count + 1);
	size_t i = 0;
	res[i] = { "ID", "Упаковка", "Кол.", "Макс. кол.", "Мин. кол.", "Ожидает дост." };
	for (Repos::const_reverse_iterator it = repos_.rbegin(); i < _count; it++)
	{
		RacksPtr rack = dynamic_pointer_cast<Racks>(it->second);
		res[++i] =
		{
					   to_string(rack->id_), rack->describe_, to_string(rack->size()),
					   to_string(rack->maxSize_), to_string(rack->minSize_),
					   (rack->state_ == WaitingOrder) ? "Да" : "Нет"
		};
	}
	mtx.unlock();
	return res;
}

View Warehouse::getRackInfLine(int _id, int _count) const
{
	mtx.lock();
	RacksPtr rack = dynamic_pointer_cast<Racks>(find(_id));
	if (!rack)
		throw Exception("Полка № " + to_string(rack->id()) + " не найдена");
	
	View res = rack->getInfLine(_count);
	mtx.unlock();
	return res;
}

map<int, double> Warehouse::InfForStores() const
{
	mtx.lock();
	map<int, double> res;
	for (const auto &iptr : repos_)
	{
		RacksPtr rack = dynamic_pointer_cast<Racks>(iptr.second);
		if (!rack) continue;
		if (!rack->size()) continue;
		double max = 0.0;
		for (const auto& jptr : rack->boxes_)
			if (jptr->discount() > max)
				max = jptr->discount();
		res.insert(make_pair(iptr.first, max));
	}
	mtx.unlock();
	return res;
}

double Warehouse::salesSum() const
{
	return salesSum_;
}

double Warehouse::summary() const
{
	return initCapital_ + deliverySum_;
}

double Warehouse::remaindSum() const
{
	return initCapital_ + deliverySum_ - overdueSum_ - salesSum_ - discountSum_;
}

double Warehouse::deliverySum() const
{
	return deliverySum_;
}

double Warehouse::damagesSum() const
{
	return discountSum_ + overdueSum_;
}

double Warehouse::initCapital() const
{
	return initCapital_;
}

int Warehouse::fullSize() const
{
	if (empty()) return 0;
	int res = 0;
	mtx.lock();
	for (const auto& ptr : repos_)
		if (dynamic_pointer_cast<Racks>(ptr.second)->size())
			res++;
	mtx.unlock();
	return res;
}

Warehouse::Warehouse() :
	initCapital_(0.0),
	deliverySum_(0.0),
	overdueSum_(0.0),
	salesSum_(0.0),
	discountSum_(0.0)
{

}

Warehouse::~Warehouse()
{
}


void makeWarehouse(UserInterface* _ui)
{
	try
	{
		Warehouse::Instance().registerElement(make_shared<Racks>(1, 50, 10, 100));
		Warehouse::Instance().registerElement(make_shared<Racks>(2, 55, 10, 130));
		Warehouse::Instance().registerElement(make_shared<Racks>(3, 35, 10, 125));

		Warehouse::Instance().registerElement(make_shared<Racks>(4, 75, 15, 135));
		Warehouse::Instance().registerElement(make_shared<Racks>(5, 25, 12, 300));
		Warehouse::Instance().registerElement(make_shared<Racks>(6, 32, 11, 250));

		Warehouse::Instance().registerElement(make_shared<Racks>(7, 34, 7, 150));
		Warehouse::Instance().registerElement(make_shared<Racks>(8, 27, 9, 221));
		Warehouse::Instance().registerElement(make_shared<Racks>(9, 68, 11, 198));

		Warehouse::Instance().registerElement(make_shared<Racks>(10, 66, 12, 167));
		Warehouse::Instance().registerElement(make_shared<Racks>(11, 33, 15, 225));
		Warehouse::Instance().registerElement(make_shared<Racks>(12, 35, 20, 300));
	
	}
	catch (Exception& ex)
	{
		_ui->errorMessage(ex.what());
	}
}

