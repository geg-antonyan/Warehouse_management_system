#include "Stores.h"

#include "../management/Orders.h"
#include "../management/Process.h"

#include "../utilites/Exception.h"
#include "../utilites/UserInterface.h"
#include <map>
#include <ctime>

using std::string;
using std::to_string;
using std::map;
using std::make_unique;
using std::make_shared;
using std::multimap;
using std::make_pair;
using std::shared_ptr;
using std::vector;
using std::dynamic_pointer_cast;
using std::unique_lock;
using std::mutex;



RegStoreData::RegStoreData(const std::string& _data)
{
	string str = _data;
	string::size_type k = str.find(' ');
	if (k == string::npos)
		throw Exception("Некорректный данные для создании магазина");
	string type = str.substr(0, k);
	auto it = StoreType_Str.find(type);
	if (it == StoreType_Str.end())
		throw Exception("Некорректный тип для создании магазина");
	type_ = type;
	k++;
	if (k == string::npos)
		throw Exception("Некорректный данные для создании магазина");
	name_ = str.substr(k, str.length() - k);
}

RegStoreData::~RegStoreData()
{
}

std::string RegStoreData::name() const
{
	return name_;
}

std::string RegStoreData::type() const
{
	return type_;
}



int Stores::Count = 0;

struct Stores::StoresImpl
{
	string name_;
	StoresType type_;
	map<string, int> repos_;
};



Stores::Stores(const string& _name)
{
	pimpl_ = make_unique<StoresImpl>();
	pimpl_->name_ = _name;
	id_ = ++Count;
}

Stores::~Stores()
{
	
}

std::string Stores::name() const
{
	return pimpl_->name_;
}

StoresType Stores::type() const
{
	return pimpl_->type_;
}

void Stores::addBox(BoxPtr _box)
{
	pimpl_->repos_[_box->describe()]++;
		
}

void Stores::addBoxes(const vector<BoxPtr>& boxes)
{
	for (const auto& ptr : boxes)
		pimpl_->repos_[ptr->describe()]++;
		
}

std::map<std::string, int> Stores::inf() const
{
	return pimpl_->repos_;
}

void Stores::generateOrderImpl(int _orderSize, int _maxCount) const
{
	srand(time(NULL));
	OrderData res;
	if (_orderSize <= 0) _orderSize = 1;
	map<int, double> inf = Warehouse::Instance().InfForStores();
	if (inf.empty()) return;

	multimap<double, int> keyDiscount;
	for (const auto& ptr : inf)
		keyDiscount.insert(make_pair(ptr.second, ptr.first));
	for (int i = 0; i < _orderSize; i++)
	{
		int probDsnt = rand() % 10;
		if (probDsnt != 4 && probDsnt != 6)
		{
			int count = rand() % _maxCount;
			if (!count) count++;
			multimap<double, int>::reverse_iterator it = keyDiscount.rbegin();
			res.insert(make_pair(it->second, count));
			keyDiscount.erase(std::next(it).base());
		}
		else
		{
			int count = rand() % _maxCount;
			if (!count) count++;
			multimap<double, int>::iterator it = keyDiscount.begin();
			res.insert(make_pair(it->second, count));
			keyDiscount.erase(it);
		}
	}
	if (!res.empty())
		StoreOrdersRepos::Instance().registerElement(make_shared<StoreOrders>(res, id_), true);
}

SmallShops::SmallShops(const string& _name) :
	Stores(_name)
{
	pimpl_->type_ = Small;
}

void SmallShops::generateOrder() const
{
	if (!Warehouse::Instance().fullSize())
		return;
	srand(time(NULL));
	generateOrderImpl(rand() % Warehouse::Instance().fullSize(), 100);
}

TentShops::TentShops(const string& _name) :
	Stores(_name)
{
	pimpl_->type_ = Tent;
}

void TentShops::generateOrder() const
{
	if (!Warehouse::Instance().fullSize())
		return;
	srand(time(NULL));
	generateOrderImpl(rand() % Warehouse::Instance().fullSize(), 60);
}

StoresRepos& StoresRepos::Instance()
{
	static StoresRepos instance;
	return instance;
}



void StoresRepos::generateOrders()
{
	Timer::Instance().delay(2);
	for (const auto& ptr : repos_)
	{
		unique_lock<mutex> uLock(mtxProc_);
		Process::Instance().wait(uLock);
    	dynamic_pointer_cast<Stores>(ptr.second)->generateOrder();
		srand(time(NULL));
		Timer::Instance().delay(2);
	}
}


vector< vector<string> > StoresRepos::getInfLine(int _count) const
{
	vector< vector<string> > res;
	if (_count <= 0 || _count > repos_.size()) _count = repos_.size();
	res.resize(_count + 1);
	size_t i = 0;
	res[i] = { "ID", "Описание", "Тип" };
	for (Repos::const_reverse_iterator it = repos_.rbegin(); i < _count; it++)
	{
		StoresPtr store = dynamic_pointer_cast<Stores>(it->second);
		res[++i] = { to_string(store->id()), store->name(), StoreType_Type[store->type()] };
	}
	return res;
}

View StoresRepos::infProductsSold() const
{
	unique_lock<mutex> uLock(mtx);
	map<string, int> mapInf;
	View res;
	for (const auto& Iptr : repos_)
	{
		map<string, int> tmp = dynamic_pointer_cast<Stores>(Iptr.second)->inf();
		for (const auto& Jptr : tmp)
			mapInf[Jptr.first] += Jptr.second;
	}
	res.resize(mapInf.size() + 1);
	size_t i = 0;
	res[i++] = { "Упаковка", "Кол." };
	for (const auto& Iptr : mapInf)
			res[i++] = { Iptr.first, to_string(Iptr.second) };
	return res;
}




StoresPtr createStores(StoresType _type, const std::string& _name)
{
	switch (_type)
	{
	case Small:
		return make_shared<SmallShops>(_name);
	case Tent:
		return make_shared<TentShops>(_name);
	default:
		return nullptr;
	}
}

StoresPtr createStores(const std::string& _type, const std::string& _name)
{
	if (_type == "Маленький_магазин")
		return make_shared<SmallShops>(_name);
	if (_type == "Палатка")
		return make_shared<TentShops>(_name);
	return nullptr;
}

void registerStores(UserInterface * _ui)
{
	try
	{
		StoresRepos::Instance().registerElement(make_shared<TentShops>("У перекрестка"));
		StoresRepos::Instance().registerElement(make_shared<TentShops>("Продуктовый мир"));
		StoresRepos::Instance().registerElement(make_shared<SmallShops>("Авангард"));
		StoresRepos::Instance().registerElement(make_shared<SmallShops>("Карин"));
	}
	catch (Exception& ex)
	{
		ex.what();
	}
}

