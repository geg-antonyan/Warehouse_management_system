#include "Cargo.h"

#include "../utilites/Exception.h"
#include "../utilites/Timer.h"
#include "../utilites/freeFunc.h"
#include "../management/Process.h"

#include "../customers/Stores.h"

#include "../warehouse/Warehouse.h"
#include "../warehouse/ExpiredProducts.h"

#include <map>

using std::dynamic_pointer_cast;
using std::string;
using std::to_string;
using std::vector;
using std::multimap;
using std::make_pair;
using std::unique_lock;
using std::lock_guard;
using std::mutex;
using std::make_shared;

Cargo::Cargo(OrdersPtr _order, CargoState _status) :
	order_(_order),
	state_(_status)
{

}

Cargo::~Cargo()
{
}

LocTime Cargo::dateExec() const
{
	return dateExec_;
}

LocTime Cargo::orderDate() const
{
	return order_->orderDate();
}

OrdersPtr Cargo::order() const
{
	return order_;
}

CargoState Cargo::state() const
{
	return state_;
}

void Cargo::setState(CargoState _state)
{
	state_ = _state;
}



int CargoStores::Count = 0;

CargoStores::CargoStores(StoreOrdersPtr _order, CargoState _status) :
	Cargo(_order, _status)
{
	if (!Warehouse::Instance().fullSize())
		throw Exception("Обработка заказа № " + to_string(_order->id()) + " невозможен так как в складе нету продуктов");
	id_ = _order->id();
	dateExec_ = LocTime() + LocTime(1, 3);
	vector<BoxPtr> tempBoxes = Warehouse::Instance().handleStoreOrder(_order, true);
	if (tempBoxes.empty())
		throw Exception("Обработка заказа № " + to_string(_order->id()) + " невозможен так как ни один из заказываемых продуктов на складе обнаружено не было");
	int size = dynamic_pointer_cast<Box>(BoxCatalog::Instance().topBack())->id();
	boxes_.resize(size + 1);
	for (const auto& ptr : tempBoxes)
		boxes_[ptr->id()].push_back(ptr);
}

void CargoStores::exec()
{
	StoreOrdersPtr order = dynamic_pointer_cast<StoreOrders>(order_);
	StoresPtr store = dynamic_pointer_cast<Stores>(StoresRepos::Instance().find(order->storeId()));
	for (size_t i = 0; i < boxes_.size(); i++)
		store->addBoxes(boxes_[i]);
	Warehouse::Instance().setSaleSumm(summary(), true);

}

void CargoStores::cancel()
{
	
	vector<BoxPtr> boxes;
	for (size_t i = 0; i < boxes_.size(); i++)
		for (size_t j = 0; j < boxes_[i].size(); j++)
				boxes.push_back(boxes_[i][j]);
		
	if (!boxes.empty())
	{
		for (size_t i = 0; i < boxes.size() - 1; i++)
			Warehouse::Instance().addBox(boxes[i], Warehouse::RetCargo, false);
		Warehouse::Instance().addBox(boxes[boxes.size() - 1], Warehouse::RetCargo, true);
	}
}

double CargoStores::summary()
{
	double res = 0.0;
	for (size_t i = 0; i < boxes_.size(); i++)
		for (size_t j = 0; j < boxes_[i].size(); j++)
			res += boxes_[i][j]->price();
	return res;
}

View CargoStores::getInfLine(int _count) const
{
	vector< vector<string> > res;
	int size = 0;
	for (size_t i = 0; i < boxes_.size(); i++)
		if (!boxes_[i].empty())
			size++;
	if (_count <= 0 || _count > size) _count = size;
	res.resize(_count + 1);
	size_t i = 0;
	res[i++] = { "Упаковка", "кол" };
	for (size_t j = 0; j < boxes_.size(); j++)
	{
		if (boxes_[j].empty()) continue;

		BoxPtr box = dynamic_pointer_cast<Box>(BoxCatalog::Instance().find(j));
		string describe = box ? box->describe() : "Неизвестен";
		
		res[i++] = { describe, to_string(boxes_[j].size()) };
	}
	return res;

}

vector<vector<BoxPtr>> CargoStores::boxes()
{
	return  boxes_;
}

std::string CargoStores::execMessage()
{
	StoreOrdersPtr order = dynamic_pointer_cast<StoreOrders>(order_);
	StoresPtr store = dynamic_pointer_cast<Stores>(StoresRepos::Instance().find(order->storeId()));
	string storeName = store ? store->name() : "Неизвестный магазин"; // для безопасности
	string message = "Груз № " + to_string(id_) + " отправлен в магазин \"" + storeName + "\".";
	return message;
}

int CargoWarehouse::Count = 0;

CargoWarehouse::CargoWarehouse(WarehouseOrdersPtr _order, CargoState _status) :
	Cargo(_order, _status)
{
	id_ = ++Count;
	srand(time(NULL));
	int dd = rand() % 6;
	if (!dd) dd++; // от 1 до 5(вкл.)Ы
	int hh = rand() % 23;
	dateExec_ = LocTime(LocTime().day() + dd, hh);
}

CargoWarehouse::~CargoWarehouse()
{
}

void CargoWarehouse::exec()
{
	vector<BoxPtr> boxes;
	for (const auto& ptr : order_->orderData())
		for (int i = 0; i < ptr.second; i++)
			boxes.push_back(BoxCatalog::Instance().makeBox(ptr.first));
	Warehouse::Instance().receiveDelivery(boxes, true);
}

void CargoWarehouse::cancel()
{
	vector<int> racksId;
	for (const auto& ptr : order_->orderData())
		racksId.push_back(ptr.first);
	if (racksId.empty()) return;
	for (size_t i = 0; i < racksId.size() - 1; i++)
		Warehouse::Instance().setRackState(racksId[i], NoWaitingOrder, false);
	Warehouse::Instance().setRackState(racksId[racksId.size() - 1], NoWaitingOrder, true);
}

double CargoWarehouse::summary()
{
	double res = 0.0;
	for(const auto& ptr : order_->orderData())
		for (int i = 0; i < ptr.second; i++)
			res += dynamic_pointer_cast<Box>(BoxCatalog::Instance().find(ptr.first))->price();
	return res;
}

View CargoWarehouse::getInfLine(int _count) const
{
	View res;
	res.resize(order_->orderData().size() + 1);
	size_t i = 0;
	res[i++] = { "Упаклвка", "Кол." };
	for (const auto& ptr : order_->orderData())
		res[i++] = { 
		dynamic_pointer_cast<Box>(BoxCatalog::Instance().find(ptr.first))->describe(),
		to_string(ptr.second) };
	return res;
}

std::string CargoWarehouse::execMessage()
{
	return "Заказ на поставку № " + to_string(id_) + " доставлен.";
}

CargoRepos::~CargoRepos()
{
}

const string CargoRepos::CargoSended = "CargoSended";

CargoRepos::CargoRepos()
{
	registerEvent(CargoSended);
}

void CargoRepos::sendCargos()
{
	if (empty()) return;
	multimap<int, int> cargoTodey;
	unique_lock<mutex> uLock(mtx);
	for (const auto& ptr : repos_)
	{
		CargoPtr cargo = dynamic_pointer_cast<Cargo>(ptr.second);
		if (cargo->dateExec().day() == LocTime().day() && cargo->state() == CONFIRMED)
			cargoTodey.insert(make_pair(cargo->dateExec().hour(), cargo->id()));
	}
	uLock.unlock();

	for (const auto& ptr : cargoTodey)
	{
		Timer::Instance().delay(ptr.first - LocTime().hour());
		unique_lock<mutex> uLock(mtxProc_);
		Process::Instance().wait(uLock);

		CargoPtr cargo = dynamic_pointer_cast<Cargo>(find(ptr.second));
		if (cargo)
		{
			cargo->exec();
			string message = cargo->execMessage() + " Время исполнения " +  LocTime().show(); // для проверки корректности время отправки
			raiseEvent(CargoSended, make_shared<StrData>(message));
			removeElement(cargo->id(), true);
		}
	}
}


void CargoRepos::confirm(int _id, bool _raise)
{
	unique_lock<mutex> uLock(mtx);
	CargoPtr cargo = dynamic_pointer_cast<Cargo>(find(_id));
	if (!cargo)
		throw Exception("Груз № " + to_string(_id) + " не найден");
	cargo->setState(CONFIRMED);
	uLock.unlock();
	if (_raise)
		raiseEvent(ContainerUpdate, nullptr);
}

double CargoRepos::summary() const
{
	unique_lock<mutex> uLock(mtx);
	double res = 0.0;
	for (const auto& ptr : repos_)
	{
		CargoPtr cargo = dynamic_pointer_cast<Cargo>(ptr.second);
		res += cargo->summary();
	}
	uLock.unlock();
	return res;
}

void CargoRepos::removeNotConfirmCargos(bool _raise)
{
	unique_lock<mutex> uLock(mtx);
	if (empty()) return;
	vector<int> oldCargos;
	for (const auto& ptr : repos_)
	{
		CargoPtr cargo = dynamic_pointer_cast<Cargo>(ptr.second);
		
		if (cargo->dateExec().day() <= LocTime().day() && cargo->state() == NOTCONFIRMED)
		{
			oldCargos.push_back(cargo->id());
			cargo->cancel();
		}
	}
	uLock.unlock();
	for (size_t i = 0; i < oldCargos.size(); i++)
		removeElement(oldCargos[i], false);
	if (_raise)
		raiseEvent(ContainerUpdate, nullptr);
}


vector< vector<string> > CargoStoresRepos::getInfLine(int _count) const
{
	lock_guard<mutex> lock(mtx);
	vector< vector<string> > res;
	if (_count <= 0 || _count > repos_.size()) _count = repos_.size();
	res.resize(_count + 1);
	size_t i = 0;
	res[i] = { "ID", "ID заказа", "Время отправки", "Сумма", "Статус" };
	for (Repos::const_reverse_iterator it = repos_.rbegin(); i < _count; it++)
	{
		CargoStoresPtr cargo = dynamic_pointer_cast<CargoStores>(it->second);
		StoreOrdersPtr order = dynamic_pointer_cast<StoreOrders>(cargo->order()); // хотя cargo-id() == order->id()
		res[++i] =
		{
			to_string(cargo->id()), to_string(order->id()),
			cargo->dateExec().show(), treatMoney(to_string(cargo->summary())),
			cargo->state() == CONFIRMED ? "Утвержден" : "Не утвержден"
		};
	}
	return res;
}


CargoStoresRepos::CargoStoresRepos()
{
}


CargoStoresRepos::~CargoStoresRepos()
{
}


CargoStoresRepos& CargoStoresRepos::Instance()
{
	static CargoStoresRepos instance;
	return instance;
}

CargoWarehouseRepos & CargoWarehouseRepos::Instance()
{
	static CargoWarehouseRepos instance;
	return instance;
}

View CargoWarehouseRepos::getInfLine(int _count) const
{
	lock_guard<mutex> lock(mtx);
	View res;
	if (_count <= 0 || _count > repos_.size()) _count = repos_.size();
	res.resize(_count + 1);
	size_t i = 0;
	res[i] = { "ID", "Время заказа", "Время отправки", "Сумма", "Статус" };
	for (Repos::const_reverse_iterator it = repos_.rbegin(); i < _count; it++)
	{
		CargoWarehousePtr cargo = dynamic_pointer_cast<CargoWarehouse>(it->second);
		res[++i] =
		{
			to_string(cargo->id()), cargo->order()->orderDate().show(),
			cargo->dateExec().show(), treatMoney(to_string(cargo->summary())),
			cargo->state() == CONFIRMED ? "Утвержден" : "Не утвержден"
		};
	}
	return res;
}

CargoWarehouseRepos::CargoWarehouseRepos()
{
}

CargoWarehouseRepos::~CargoWarehouseRepos()
{
}
