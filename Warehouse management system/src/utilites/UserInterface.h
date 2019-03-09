
#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "../utilites/Observed.h"

#include <string>

class CommandData : public EventData
{
public:
	CommandData(const std::string& _eventData) { command_ = _eventData; }
	const std::string eventData() const { return command_; }
private:
	std::string command_;
};


class UserInterface : protected Observed
{
public:
	using Observed::addObserver;
	using Observed::removeObserver;
	static const std::string CommandEntered;
	UserInterface() { registerEvent(CommandEntered);}
	virtual ~UserInterface() { }
	
	virtual void errorMessage(const std::string& m) = 0;
	virtual void postMessage(const std::string& m) = 0;

	virtual void PrdCatalogUpdate() = 0;
	virtual void BoxCatalogUpdate() = 0;
	virtual void StoresReposUpdate() = 0;
	virtual void WarehouseUpdate() = 0;

	virtual void StoreOrdersReposUpdate() = 0;
	virtual void CargoStoreReposUpdate() = 0;
	virtual void ExpieredPrdUpdate() = 0;
	virtual void DiscountsReposUpdate() = 0;
	virtual void CargoWarehouseReposUpdate() = 0;

	virtual void tick() = 0;
	virtual void processStart() = 0;
};


#endif // !USER_INTERFACE_H