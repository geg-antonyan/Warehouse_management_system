#ifndef STORES_H
#define STORES_H

#include "../warehouse/Warehouse.h"
#include "../management/Cargo.h"
#include <map>
#include <string>
#include <mutex>


enum StoresType { Small, Tent };

static std::map<StoresType, std::string> StoreType_Type =
{
	std::make_pair(Small, "Маленький_магазин"),
	std::make_pair(Tent, "Палатка")
};

static  std::map<std::string, StoresType> StoreType_Str =
{
	std::make_pair("Маленький_магазин", Small),
	std::make_pair("Палатка", Tent)
};

class RegStoreData : public EventData
{
public:
	RegStoreData(const std::string&);
	~RegStoreData();

	std::string name() const;
	std::string type() const;
private:
	std::string name_;
	std::string type_;
};

class Stores : public Elements, protected Observed
{
	static int Count;
	struct StoresImpl;
public:
	using Observed::addObserver;
	using Observed::removeObserver;

	Stores(const std::string& _name);
	virtual ~Stores();
	
	std::string name() const;
	StoresType type() const;

	void addBox(BoxPtr);
	void addBoxes(const std::vector<BoxPtr>&);
	std::map<std::string, int> inf() const;
	virtual void generateOrder() const = 0;
protected:
	void generateOrderImpl(int _orderSize, int _maxCount) const;
	std::unique_ptr<StoresImpl> pimpl_;
};

using StoresPtr = std::shared_ptr<Stores>;

class SmallShops : public Stores
{
public:
	SmallShops(const std::string& _name);
	~SmallShops() { }
	void generateOrder() const override;
};

class TentShops : public Stores
{
public:
	TentShops(const std::string& _name);
	~TentShops() { }
	void generateOrder() const override;
};



class StoresRepos : public Container
{
public:
	static StoresRepos& Instance();
	void generateOrders();
	std::vector< std::vector<std::string> > getInfLine(int _count = 0) const;
	View infProductsSold() const;
private:
	std::mutex mtxProc_;

	StoresRepos() { }
	~StoresRepos() { }

	StoresRepos(const StoresRepos&) = delete;
	StoresRepos(StoresRepos&&) = delete;
	StoresRepos& operator=(const StoresRepos&) = delete;
	StoresRepos& operator=(StoresRepos&&) = delete;
};

StoresPtr createStores(StoresType, const std::string&);
StoresPtr createStores(const std::string&, const std::string&);

class UserInterface;
void registerStores(UserInterface* _ui);

#endif // !STORES_H