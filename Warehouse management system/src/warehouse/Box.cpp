#include "Box.h"

#include "../utilites/Exception.h"
#include "../utilites/UserInterface.h"
#include "../utilites/freeFunc.h"
#include "Warehouse.h"

using std::vector;
using std::string;
using std::to_string;
using std::shared_ptr;
using std::make_shared;
using std::unique_ptr;
using std::make_unique;
using std::dynamic_pointer_cast;



RegBoxData::RegBoxData(const string& _data)
{
	string dataArr[4];
	string str = _data;
	if (str[str.length() - 1] != ' ')
		str += ' ';
	size_t i = 0u;
	string::size_type j = 0u, k = str.find(' ', j);
	while (k != string::npos && j < str.length())
	{
		if (i > 3)
			throw Exception("Некорректные данные для добавлении оптовой упаковки");
		dataArr[i++] = str.substr(j, k - j);
		j = k + 1;
		k = str.find(' ', j);
	}
	if (i != 4)
		throw Exception("Некорректные данные для добавлении оптовой упаковки");

	prdId_ = atoi(dataArr[0].c_str());
	std::unordered_map<string, Unit>::const_iterator it = Unit_KeyStr.find(dataArr[1]);
	if (it == Unit_KeyStr.end())
		throw Exception("Некорректная единица измерения");
	unit_ = it->second;
	size_ = atoi(dataArr[2].c_str());
	if (size_ <= 0)
		throw Exception("Количество упаковок должно быть больше нулья");
	unitPrice_ = atof(dataArr[3].c_str());
	if (unitPrice_ < 0)
		throw Exception("Цена не может быть отрицательным");
}

RegBoxData::~RegBoxData()
{
}

int RegBoxData::prdId() const
{
	return prdId_;
}

Unit RegBoxData::unit() const
{
	return unit_;
}

int RegBoxData::size() const
{
	return size_;
}

double RegBoxData::unitPrice() const
{
	return unitPrice_;
}


struct Box::PkgeImpl
{
	Unit unit_;
	int number_;
	double unitPrice_;
	double discount_;
	ProductPtr product_;
	int size_;
};



int Box::Count = 0;


Box::Box(int _prdId, Unit _unit, int _size, double _unitPrice) 
{
	pimpl_ = make_unique<PkgeImpl>();
	id_ = _prdId;
	pimpl_->product_ = ProductCatalog::Instance().makeProduct(id_);
	pimpl_->number_ = 0;
	pimpl_->unitPrice_ = _unitPrice;
	pimpl_->discount_ = 0.0;
	pimpl_->size_ = _size;
	pimpl_->unit_ = _unit;
}

Box::Box(const Box& _box)
{
	pimpl_ = make_unique<PkgeImpl>();
	id_ = _box.id_;
	pimpl_->product_ = ProductCatalog::Instance().makeProduct(id_);
	pimpl_->number_ = ++Count;
	pimpl_->unitPrice_ = _box.pimpl_->unitPrice_;
	pimpl_->discount_ = _box.pimpl_->discount_;
	pimpl_->size_ = _box.pimpl_->size_;
	pimpl_->unit_ = _box.pimpl_->unit_;
}

Box::~Box()
{
}

int Box::number() const
{
	return pimpl_->number_;
}


string Box::prdDescribe() const
{
	return pimpl_->product_->describe();
}

double Box::unitPrice() const
{
	return pimpl_->unitPrice_;
}

double Box::price() const
{
	return (pimpl_->unitPrice_ * pimpl_->size_)
		-
		((pimpl_->unitPrice_ * pimpl_->size_ / 100.0) * pimpl_->discount_);
}

double Box::discount() const
{
	return pimpl_->discount_;
}

int Box::shelfTime() const
{
	return pimpl_->product_->shelfTime();
}

string Box::describe() const
{
	return  pimpl_->product_->describe() + ",  "
		+ to_string(pimpl_->size_) + ' ' + 
		Unit_KeyUnit.find(pimpl_->unit_)->second;
}

int Box::size() const
{
	return pimpl_->size_;
}

Unit Box::unit() const
{
	return pimpl_->unit_;
}

void Box::setDiscount(double _precent)
{
	pimpl_->discount_ = _precent;
}

BoxPtr Box::clone() const
{
	return make_shared<Box>(*this);
}




BoxCatalog& BoxCatalog::Instance()
{
	static BoxCatalog instance;
	return instance;
}


BoxPtr BoxCatalog::makeBox(int _id) const
{
	Repos::const_iterator it = hasKey(_id);
	return dynamic_pointer_cast<Box>(it->second)->clone();
}


vector< vector<string> > BoxCatalog::getInfLine(int _count) const
{
	vector< vector<string> > res;
	if (_count <= 0 || _count > repos_.size()) _count = repos_.size();
	res.resize(_count + 1);
	size_t i = 0;
	res[i] = { "ID", "Описание", "Кол.", "Ед. изм.", "Цена", "Сумма" };
	for (Repos::const_reverse_iterator it = repos_.rbegin(); i < _count; it++)
	{
		BoxPtr box = dynamic_pointer_cast<Box>(it->second);
		res[++i] =
		{
			to_string(box->id()), box->prdDescribe(), to_string(box->size()),
			Unit_KeyUnit.find(box->unit())->second, treatMoney((to_string(box->unitPrice()))),
			treatMoney(to_string(box->price()))
		};
	}
	return res;
}

std::vector<std::string> BoxCatalog::getInfFreeBox() const
{
	vector<string> res;
	for (const auto& ptr : repos_)
		if (!Warehouse::Instance().find(ptr.first))
			res.push_back(to_string(ptr.first) + ' ' + dynamic_pointer_cast<Box>(ptr.second)->describe());
	return res;
}


void makeBoxesCatalog(UserInterface* _ui)
{
	try
	{
		BoxCatalog::Instance().registerElement(make_shared<Box>(1, pcs, 24, 55.50));
		BoxCatalog::Instance().registerElement(make_shared<Box>(2, pcs, 24, 55.50));
		BoxCatalog::Instance().registerElement(make_shared<Box>(3, pcs, 24, 55.50));
		BoxCatalog::Instance().registerElement(make_shared<Box>(4, pcs, 20, 45));
		BoxCatalog::Instance().registerElement(make_shared<Box>(5, kg, 50, 33.50));
		BoxCatalog::Instance().registerElement(make_shared<Box>(6, pcs, 20, 66.50));
		BoxCatalog::Instance().registerElement(make_shared<Box>(7, pcs, 15, 33.20));
		BoxCatalog::Instance().registerElement(make_shared<Box>(8, pcs, 16, 70));
		BoxCatalog::Instance().registerElement(make_shared<Box>(9, pcs, 10, 50));
		BoxCatalog::Instance().registerElement(make_shared<Box>(10, pcs, 5, 150));
		BoxCatalog::Instance().registerElement(make_shared<Box>(11, pcs, 24, 55.20));
		BoxCatalog::Instance().registerElement(make_shared<Box>(12, liter, 25, 30));
	}
	catch (Exception& ex)
	{
		_ui->errorMessage(ex.what());
	}
}

