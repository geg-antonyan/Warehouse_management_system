#include "AppObservers.h"

#include "../utilites/UserInterface.h"
#include "../utilites/Exception.h"

#include "../management/Orders.h"
#include "../management/Cargo.h"
#include "../management/Process.h"

#include "../customers/Stores.h"

#include "../warehouse/ExpiredProducts.h"

#include "CommandDispatcher.h"

using std::dynamic_pointer_cast;
using std::shared_ptr;
using std::make_shared;

CommandIssuedOB::CommandIssuedOB(CommandDispatcher& _cd) :
	Observer("CommandIssused"),
	cd_(_cd)
{
}

void CommandIssuedOB::notify(shared_ptr<EventData> _eventData)
{
	shared_ptr<CommandData> data = dynamic_pointer_cast<CommandData>(_eventData);
	cd_.commandEntered(data->eventData());
}

PrdCatalogUpdatedOB::PrdCatalogUpdatedOB(UserInterface* _ui) :
	Observer("ProductCatalogUpdate"), 
	ui_(_ui)
{
}

void PrdCatalogUpdatedOB::notify(shared_ptr<EventData>)
{
	ui_->PrdCatalogUpdate();
}

BoxCatalogUpdatedOB::BoxCatalogUpdatedOB(UserInterface* _ui) :
	Observer("BoxCatalogUpdate"),
	ui_(_ui)
{
}

void BoxCatalogUpdatedOB::notify(shared_ptr<EventData>)
{
	ui_->BoxCatalogUpdate();
}

StoresReposUpdatedOB::StoresReposUpdatedOB(UserInterface * _ui) :
	Observer("StoresReposUpdate"),
	ui_(_ui)
{
}

void StoresReposUpdatedOB::notify(shared_ptr<EventData>)
{
	ui_->StoresReposUpdate();
}

WarehouseUpdatedOB::WarehouseUpdatedOB(UserInterface* _ui) :
	Observer("WarehouseUpdate"),
	ui_(_ui)
{
}

void WarehouseUpdatedOB::notify(shared_ptr<EventData>)
{
	ui_->WarehouseUpdate();
}

TickOB::TickOB(UserInterface* _ui) :
	Observer("Tick"),
	ui_(_ui)
{
}

void TickOB::notify(shared_ptr<EventData>)
{
	ui_->tick();
}

ProcessStartOB::ProcessStartOB(UserInterface* _ui) :
	Observer("ProcessStart"),
	ui_(_ui)
{

}

void ProcessStartOB::notify(shared_ptr<EventData>)
{
	ui_->processStart();
}

StoreOrdRepUpdateOB::StoreOrdRepUpdateOB(UserInterface * _ui) :
	Observer("StoreOrdersReposUpdate"),
	ui_(_ui)
{
}

void StoreOrdRepUpdateOB::notify(shared_ptr<EventData>)
{
	ui_->StoreOrdersReposUpdate();
}

NewStoreOrdGenerOB::NewStoreOrdGenerOB(UserInterface* _ui) :
	Observer("NewStoreOrderGenerate"),
	ui_(_ui)
{
}

void NewStoreOrdGenerOB::notify(shared_ptr<EventData>)
{
	int id = 0;
	try
	{
		StoreOrdersPtr order = dynamic_pointer_cast<StoreOrders>(StoreOrdersRepos::Instance().topBack());
		id = order->id();
		CargoStoresRepos::Instance().registerElement(make_shared<CargoStores>(order), true);
	}
	catch (Exception& ex)
	{
		//StoreOrdersRepos::Instance().removeElement(id, true);
		ui_->postMessage(ex.what());
	}

}

CargoStoreRepUpdateOB::CargoStoreRepUpdateOB(UserInterface* _ui) :
	Observer("CargoStoresReposUpdateObserver"),
	ui_(_ui)
{
}

void CargoStoreRepUpdateOB::notify(shared_ptr<EventData>)
{
	ui_->CargoStoreReposUpdate();
}


CargoWarehouseRepUpdateOB::CargoWarehouseRepUpdateOB(UserInterface * _ui) :
	Observer("CargoRepUpdate"),
	ui_(_ui)
{
}

void CargoWarehouseRepUpdateOB::notify(shared_ptr<EventData>)
{
	ui_->CargoWarehouseReposUpdate();
}


CargoSendedOB::CargoSendedOB(UserInterface * _ui) :
	Observer("cargoSendedObserver"),
	ui_(_ui)
{
}

void CargoSendedOB::notify(shared_ptr<EventData> _eventData)
{
	StrDataPtr data = dynamic_pointer_cast<StrData>(_eventData);
	ui_->postMessage(data->str());
}


ExpiredPrdUpdateOB::ExpiredPrdUpdateOB(UserInterface * _ui) :
	Observer("ExpiredPrdUpdate"),
	ui_(_ui)
{
}

void ExpiredPrdUpdateOB::notify(shared_ptr<EventData>)
{
	ui_->ExpieredPrdUpdate();
}

ProcessErrorOB::ProcessErrorOB(UserInterface * _ui) :
	Observer("ProcessError"), 
	ui_(_ui)
{
}

void ProcessErrorOB::notify(std::shared_ptr<EventData> _event)
{
	StrDataPtr data = dynamic_pointer_cast<StrData>(_event);
	ui_->errorMessage(data->str());
}

DiscountsReposUpdateOB::DiscountsReposUpdateOB(UserInterface * _ui) :
	Observer("DiscountsReposUpdate"),
	ui_(_ui)
{
}

void DiscountsReposUpdateOB::notify(shared_ptr<EventData>)
{
	ui_->DiscountsReposUpdate();
}

void registerUiObservers(UserInterface* _ui)
{
	ProductCatalog::Instance().addObserver(Container::ContainerUpdate, std::make_unique<PrdCatalogUpdatedOB>(_ui));
	BoxCatalog::Instance().addObserver(Container::ContainerUpdate, std::make_unique<BoxCatalogUpdatedOB>(_ui));
	StoresRepos::Instance().addObserver(Container::ContainerUpdate, std::make_unique<StoresReposUpdatedOB>(_ui));
	Warehouse::Instance().addObserver(Container::ContainerUpdate, std::make_unique<WarehouseUpdatedOB>(_ui));
	StoreOrdersRepos::Instance().addObserver(Container::ContainerUpdate, std::make_unique<StoreOrdRepUpdateOB>(_ui));
	StoreOrdersRepos::Instance().addObserver(StoreOrdersRepos::NewOrder, std::make_unique<NewStoreOrdGenerOB>(_ui));
	CargoStoresRepos::Instance().addObserver(Container::ContainerUpdate, std::make_unique<CargoStoreRepUpdateOB>(_ui));
	CargoStoresRepos::Instance().addObserver(CargoRepos::CargoSended, std::make_unique<CargoSendedOB>(_ui));
	CargoWarehouseRepos::Instance().addObserver(Container::ContainerUpdate, std::make_unique<CargoWarehouseRepUpdateOB>(_ui));
	CargoWarehouseRepos::Instance().addObserver(CargoRepos::CargoSended, std::make_unique<CargoSendedOB>(_ui));
	ExpiredProducts::Instance().addObserver(ExpiredProducts::ExpiredPrdUpdate, std::make_unique<ExpiredPrdUpdateOB>(_ui));
	DiscountsRepos::Instance().addObserver(Container::ContainerUpdate, std::make_unique<DiscountsReposUpdateOB>(_ui));
	Process::Instance().addObserver(Process::Tick, std::make_unique<TickOB>(_ui));
	Process::Instance().addObserver(Process::Start, std::make_unique<ProcessStartOB>(_ui));
	Process::Instance().addObserver(Process::Error, std::make_unique<ProcessErrorOB>(_ui));
}
