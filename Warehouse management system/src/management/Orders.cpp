#include "Orders.h"

#include "../utilites/Timer.h"
#include "Process.h"
#include "../customers/Stores.h"
#include "../warehouse/Warehouse.h"

using std::make_unique;
using std::map;
using std::vector;
using std::string;
using std::to_string;
using std::dynamic_pointer_cast;


Orders::Orders(const OrderData& _data)
{
	time_ = LocTime();
	data_ = _data;
}

LocTime Orders::orderDate() const
{
	return time_;
}

OrderData Orders::orderData() const
{
	return data_;
}

vector< vector<string> > Orders::getLineInf(int _count) const
{
	vector< vector<string> > res;
	if (_count <= 0 || _count > data_.size()) _count = data_.size();
	res.resize(_count + 1);
	size_t i = 0;
	res[i] = { "Продукт", "Ед. изм", "Кол." };
	for (const auto& ptr : data_)
	{
		BoxPtr box = dynamic_pointer_cast<Box>(BoxCatalog::Instance().find(ptr.first));
		if (box)
			res[++i] = { box->prdDescribe(), Unit_KeyUnit.find(box->unit())->second, to_string(ptr.second) };
		else
			res[++i] = { "Неихвестный продукт", "---", to_string(ptr.second) };
		
	}
	return res;
}

int StoreOrders::Count = 0;

StoreOrders::StoreOrders(const OrderData& _data, int _storeId) :
	Orders(_data),
	storeId_(_storeId)
{
	id_ = ++Count;
}

int StoreOrders::storeId() const
{
	return storeId_;
}

int WarehouseOrders::Count = 0;

WarehouseOrders::WarehouseOrders(const OrderData& _data) :
	Orders(_data)
{
	id_ = ++Count;
}


const string StoreOrdersRepos::NewOrder = "NewOrder";

StoreOrdersRepos& StoreOrdersRepos::Instance()
{
	static StoreOrdersRepos instance;
	return instance;
}



vector< vector<string> > StoreOrdersRepos::getInfLine(int _count) const
{
	mtx.lock();
	vector< vector<string> > res;
	if (_count <= 0 || _count > repos_.size()) _count = repos_.size();
	res.resize(_count + 1);
	size_t i = 0;
	res[i] = { "ID", "ID магазина", "Магазин", "Время заказа" };
	for (Repos::const_reverse_iterator it = repos_.rbegin(); i < _count; it++)
	{
		StoreOrdersPtr order = dynamic_pointer_cast<StoreOrders>(it->second);
		StoresPtr store = dynamic_pointer_cast<Stores>(StoresRepos::Instance().find(order->storeId()));
		string nameStore = (store) ? store->name() : "Неизвестен";
		res[++i] =
		{ 
			to_string(order->id()), to_string(order->storeId()),
			nameStore, order->orderDate().show() 
		};
	}
	mtx.unlock();
	return res;
}

void StoreOrdersRepos::registerElement(ElementsPtr _elem, bool _raise)
{
	Container::registerElement(_elem, _raise);
	raiseEvent(NewOrder, nullptr);
}



