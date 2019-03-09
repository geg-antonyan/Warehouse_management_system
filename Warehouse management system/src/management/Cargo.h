#ifndef CARGO_H
#define CARGO_H

#include "Orders.h"
#include "../utilites/Container.h"
#include "../warehouse/Warehouse.h"

#include <mutex>

enum CargoState { NOTCONFIRMED, CONFIRMED };

class Cargo : public Elements
{
public:
	Cargo(OrdersPtr, CargoState _status = NOTCONFIRMED);
	virtual ~Cargo();
	LocTime dateExec() const;
	LocTime orderDate() const;
	OrdersPtr order() const;
	CargoState state() const;
	void setState(CargoState);
	
	virtual void exec() = 0;
	virtual void cancel() = 0;
	virtual double summary() = 0;
	virtual std::string execMessage() = 0;
	virtual View getInfLine(int _count = 0) const = 0;

protected:
	LocTime dateExec_;
	CargoState state_;
	OrdersPtr order_;
};

using CargoPtr = std::shared_ptr<Cargo>;

class CargoStores : public Cargo
{
	static int Count;
public:
	CargoStores(StoreOrdersPtr, CargoState _status = NOTCONFIRMED);
	~CargoStores() { }
	void exec() override;
	void cancel() override;
	double summary() override;
	std::vector< std::vector<BoxPtr> > boxes();
	
	View getInfLine(int _count = 0) const override;
	std::string execMessage() override;
private:
	std::vector< std::vector<BoxPtr> > boxes_;
};

using CargoStoresPtr = std::shared_ptr<CargoStores>;

class CargoWarehouse : public Cargo
{
	static int Count;
public:
	CargoWarehouse(WarehouseOrdersPtr, CargoState _status = NOTCONFIRMED);
	~CargoWarehouse();
	void exec() override;
	void cancel() override;
	double summary() override;
	View getInfLine(int _count = 0) const override;
	std::string execMessage() override;
};



using CargoWarehousePtr = std::shared_ptr<CargoWarehouse>;


class CargoRepos : public Container
{
public:
	virtual ~CargoRepos();
	static const std::string CargoSended;
	void confirm(int _id, bool _raise = false);
	double summary() const;
	void removeNotConfirmCargos(bool _raise = false);
	void sendCargos();
protected:
	CargoRepos();
private:
	std::mutex mtxProc_;
};





class CargoStoresRepos : public CargoRepos
{
public:
	static CargoStoresRepos& Instance();
	View getInfLine(int _count = 0) const;
private:
	
	CargoStoresRepos();
	~CargoStoresRepos();

	CargoStoresRepos(const CargoStoresRepos&) = delete;
	CargoStoresRepos(CargoStoresRepos&&) = delete;
	CargoStoresRepos& operator=(const CargoStoresRepos&) = delete;
	CargoStoresRepos& operator=(CargoStoresRepos&&) = delete;
};


class CargoWarehouseRepos : public CargoRepos
{
public:
	static CargoWarehouseRepos& Instance();
	View getInfLine(int _count = 0) const;
private:

	CargoWarehouseRepos();
	~CargoWarehouseRepos();

	CargoWarehouseRepos(const CargoWarehouseRepos&) = delete;
	CargoWarehouseRepos(CargoWarehouseRepos&&) = delete;
	CargoWarehouseRepos& operator=(const CargoWarehouseRepos&) = delete;
	CargoWarehouseRepos& operator=(CargoWarehouseRepos&&) = delete;
};



#endif // !CARGO_H

