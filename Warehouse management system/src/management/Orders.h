#ifndef ORDERS_H
#define ORDERS_H

#include "../utilites/Container.h"
#include "../utilites/Timer.h"

#include <map>
#include <vector>

using OrderData = std::map<int, int>;

class Orders : public Elements
{
public:
	virtual ~Orders() { }
	LocTime orderDate() const;
	OrderData orderData() const;
	std::vector< std::vector<std::string >> getLineInf(int _count = 0) const;
protected:
	Orders(const OrderData&);
private:
	LocTime time_;
	OrderData data_;
};

class StoreOrders : public Orders
{
	static int Count;
public:
	StoreOrders(const OrderData&, int _storeId);
	~StoreOrders() { }
	int storeId() const;
private:
	int storeId_;
};

class WarehouseOrders : public Orders
{
	static int Count;
public:
	WarehouseOrders(const OrderData&);
	~WarehouseOrders() { }
};

using OrdersPtr = std::shared_ptr<Orders>;
using StoreOrdersPtr = std::shared_ptr<StoreOrders>;
using WarehouseOrdersPtr = std::shared_ptr<WarehouseOrders>;

class StoreOrdersRepos : public Container
{
public:
	static const std::string NewOrder;

	static StoreOrdersRepos& Instance();
	std::vector< std::vector<std::string> > getInfLine(int _count = 0) const;

	void registerElement(ElementsPtr, bool _raise = false) override;

private:
	StoreOrdersRepos() { registerEvent(NewOrder); }
	~StoreOrdersRepos() { }



	StoreOrdersRepos(const StoreOrdersRepos&) = delete;
	StoreOrdersRepos(StoreOrdersRepos&&) = delete;
	StoreOrdersRepos operator=(const StoreOrdersRepos&) = delete;
	StoreOrdersRepos operator=(StoreOrdersRepos&&) = delete;
};

#endif // !ORDERS_H
