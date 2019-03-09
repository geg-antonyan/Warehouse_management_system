#include "Product.h"

#include "../utilites/Exception.h"
#include "../utilites/Timer.h"
#include "../utilites/UserInterface.h"

#include "Box.h"

using std::vector;
using std::make_shared;
using std::shared_ptr;
using std::make_unique;
using std::string;
using std::to_string;
using std::dynamic_pointer_cast;


RegPrdData::RegPrdData(const std::string& _data)
{
	
	string::size_type k = _data.find(' ');
	if (k == string::npos)
		throw Exception("Некорректные данные для добовлении продукта в Каталог");
	if (!isUnsignedDigit(_data.substr(0, k).c_str()))
		throw Exception("Некорректный срок годности");
	lifeTime_ = atoi(_data.substr(0, k).c_str());
	if (k + 1 == string::npos)
		throw Exception("Некорректные данные для добовлении продукта в Каталог");
	describe_ = _data.substr(k + 1, _data.length() - k + 1);
}

RegPrdData::~RegPrdData()
{
}

std::string RegPrdData::describe() const
{
	return describe_;
}

int RegPrdData::lifeTime() const
{
	return lifeTime_;
}

bool RegPrdData::isUnsignedDigit(const string& str) const
{
	string digits("0123456789"); // isdigit дает сбой при кирилице
	for (size_t i = 0u; i < str.length(); i++)
	{
		string::size_type k = digits.find(str[i]);
		if (k == string::npos)
			return false;
	}
	return true;
}



struct Product::ProductImpl
{
	string describe_;
	int dateOfManufacture_;
	int lifeTime_;
};

int Product::Count = 0;

Product::Product(const string _describe, int _lifeTime)
{
	id_ = ++Count;
	pimpl_ = make_unique<ProductImpl>();
	if (_lifeTime <= 0) throw Exception("Некорректный срок годности");
	pimpl_->lifeTime_ = _lifeTime;
	pimpl_->dateOfManufacture_ = Timer::Instance().day();
	pimpl_->describe_ = _describe;
}

Product::Product(const Product& _product)
{
	id_ = _product.id_;
	pimpl_ = make_unique<Product::ProductImpl>(*(_product.pimpl_));
	pimpl_->dateOfManufacture_ = LocTime().day();
}

Product::~Product()
{
}



string Product::describe() const
{
	return pimpl_->describe_;
}

int Product::lifeTime() const
{
	return pimpl_->lifeTime_;
}

int Product::shelfTime() const
{
	return pimpl_->lifeTime_ - (Timer::Instance().day() - pimpl_->dateOfManufacture_);
}

ProductPtr Product::clone() const
{
	return make_shared<Product>(*this);
}

ProductPtr createProduct(string _describe, int _lifeTime)
{
	return make_shared<Product>(_describe, _lifeTime);
}



ProductCatalog& ProductCatalog::Instance()
{
	static ProductCatalog instance;
	return instance;
}

ProductPtr ProductCatalog::makeProduct(int _id) const
{
	Repos::const_iterator it = hasKey(_id);
	return dynamic_pointer_cast<Product>(it->second)->clone();
}



vector< vector<string> > ProductCatalog::getInfLine(int _count) const
{
	vector< vector<string> > res;
	if (_count <= 0 || _count > repos_.size()) _count = repos_.size();
	res.resize(_count + 1);
	size_t i = 0;
	res[i] = { "ID", "Описание", "Срок год." };
	for (Repos::const_reverse_iterator it = repos_.rbegin(); i < _count; it++)
	{
		ProductPtr prd = dynamic_pointer_cast<Product>(it->second);
		res[++i] = { to_string(prd->id()), prd->describe(), to_string(prd->shelfTime()) };
	}
	return res;
}

vector<string> ProductCatalog::getInfFreePrd() const
{
	vector<string> res;
	for (const auto& ptr : repos_)
		if (!BoxCatalog::Instance().find(ptr.first))
			res.push_back(to_string(ptr.first) + ' ' + dynamic_pointer_cast<Product>(ptr.second)->describe());
	return res;
}

void makeProductCatalog(UserInterface* ui)
{
	try
	{
		ProductCatalog::Instance().registerElement(make_shared<Product>("спрайт 0.5л", 15));
		ProductCatalog::Instance().registerElement(make_shared<Product>("Кока кола 0.5л", 14));
		ProductCatalog::Instance().registerElement(make_shared<Product>("Пепси 0.5л", 13));
		ProductCatalog::Instance().registerElement(make_shared<Product>("Рис 0.5кг",6));
		ProductCatalog::Instance().registerElement(make_shared<Product>("Сахар", 30));
		ProductCatalog::Instance().registerElement(make_shared<Product>("Чипсы 100г", 20));
		ProductCatalog::Instance().registerElement(make_shared<Product>("Молоко 1л", 4));
		ProductCatalog::Instance().registerElement(make_shared<Product>("Сметана 250г", 6));
		ProductCatalog::Instance().registerElement(make_shared<Product>("Творог 150г", 5));
		ProductCatalog::Instance().registerElement(make_shared<Product>("Коньяк Арарат 0.5 л", 50));
		ProductCatalog::Instance().registerElement(make_shared<Product>("Пиво 0.5л", 20));
		ProductCatalog::Instance().registerElement(make_shared<Product>("Жидкое мило", 50));
	}
	catch (Exception& ex)
	{
		ui->errorMessage(ex.what());
	}
}

