#include "Command.h"

#include "../utilites/Exception.h"
#include "../utilites/UserInterface.h"
#include "../utilites/Timer.h"

#include "../warehouse/Warehouse.h"
#include "../customers/Stores.h"

#include "../management/Process.h"
#include "../management/Discounts.h"
#include "../management/Cargo.h"

#include "CommandRepository.h"

using std::string;
using std::to_string;
using std::unique_ptr;
using std::shared_ptr;
using std::make_shared;
using std::make_unique;
using std::move;
using std::dynamic_pointer_cast;
using std::map;
using std::vector;



Command::Command(EventDataPtr _eventData) :
	cmdData_(_eventData)
{
}


Command::~Command()
{
}

void Command::execute()
{
	check();
	executeImpl();
}



const char * Command::helpMassage() const
{
	return helpMassageImpl();
}

Command * Command::clone(EventDataPtr _eventData) const
{
	return cloneImpl(_eventData);
}

const string RegisterProduct::NAME = "registerProduct";


RegisterProduct::RegisterProduct(EventDataPtr _cmdData) :
	Command(_cmdData)
{
}


RegisterProduct::~RegisterProduct()
{
}

void RegisterProduct::executeImpl()
{
	shared_ptr<RegPrdData> data = dynamic_pointer_cast<RegPrdData>(cmdData_);
	ProductCatalog::Instance().registerElement(make_shared<Product>(data->describe(), data->lifeTime()), true);
}


const char * RegisterProduct::helpMassageImpl() const
{
	return "Добавляет новый продукт в Католог";
}

Command * RegisterProduct::cloneImpl(EventDataPtr _cmdData) const
{
	return new RegisterProduct(_cmdData);
}

void RegisterProduct::check() const
{
	if (!dynamic_pointer_cast<RegPrdData>(cmdData_))
		Exception("Не удалось преобразовать EventData в RegPrdData");
}


const string RemoveProduct::NAME = "removeProduct";

RemoveProduct::RemoveProduct(EventDataPtr _cmdData) :
	Command(_cmdData)
{
}

RemoveProduct::~RemoveProduct()
{
}

void RemoveProduct::executeImpl()
{
	IdDataPtr data = dynamic_pointer_cast<IdData>(cmdData_);
	ProductCatalog::Instance().removeElement(data->id(), true);
}

const char* RemoveProduct::helpMassageImpl() const
{
	return "Удаляет продукты из каталога";
}

Command* RemoveProduct::cloneImpl(EventDataPtr _cmdData) const
{
	return new RemoveProduct(_cmdData);
}

void RemoveProduct::check() const
{
	if (ProductCatalog::Instance().empty())
		throw Exception("Каталог продуктов пустой");
	IdDataPtr data = dynamic_pointer_cast<IdData>(cmdData_);
	if (!data)
		Exception("Не удалось преобразовать EventData в IdData");
	if (BoxCatalog::Instance().find(data->id()))
	{
		BoxPtr box = dynamic_pointer_cast<Box>(BoxCatalog::Instance().find(data->id()));
		throw Exception("Оптовоая упаковка \"" + box->describe() + "\" использует продукт \""
			+ box->prdDescribe() + "\". для удалении продукта сначала надо удалять оптовую упаковку!!!");
	}
	if (!ProductCatalog::Instance().find(data->id()))
		throw Exception("Продукт (id=" + to_string(data->id()) + ") не найден");
}




const string RegisterBox::NAME = "registerBox";

RegisterBox::RegisterBox(EventDataPtr _cmdData) :
	Command(_cmdData)
{
}

RegisterBox::~RegisterBox()
{
}

void RegisterBox::executeImpl()
{
	shared_ptr<RegBoxData> data = dynamic_pointer_cast<RegBoxData>(cmdData_);
	BoxCatalog::Instance().registerElement(make_shared<Box>(data->prdId(), data->unit(), data->size(), data->unitPrice()), true);
}


Command* RegisterBox::cloneImpl(EventDataPtr _cmdData) const
{
	return new RegisterBox(_cmdData);
}

const char* RegisterBox::helpMassageImpl() const
{
	return  "Добавляет новую оптовую упаковку в каталог";
}

void RegisterBox::check() const
{
	if (!dynamic_pointer_cast<RegBoxData>(cmdData_))
		Exception("Не удалось преобразовать EventData в RegBoxData");
}

const string RemoveBox::NAME = "removeBox";

RemoveBox::RemoveBox(EventDataPtr _eventData) :
	Command(_eventData)
{
}

RemoveBox::~RemoveBox()
{
}

void RemoveBox::executeImpl()
{
	shared_ptr<IdData> data = dynamic_pointer_cast<IdData>(cmdData_);
	BoxCatalog::Instance().removeElement(data->id(), true);
}


Command* RemoveBox::cloneImpl(EventDataPtr _eventData) const
{
	return new RemoveBox(_eventData);
}

const char * RemoveBox::helpMassageImpl() const
{
	return "Удаляет оптовую упаковку из Каталога упаковок";
}

void RemoveBox::check() const
{
	if (BoxCatalog::Instance().empty())
		throw Exception("Каталог продуктов пустой");
	shared_ptr<IdData> data = dynamic_pointer_cast<IdData>(cmdData_);
	if (!data)
		Exception("Не удалось преобразовать EventData в IdData");
	if (Warehouse::Instance().find(data->id()))
	{
		RacksPtr rack = dynamic_pointer_cast<Racks>(Warehouse::Instance().find(data->id()));
		throw Exception("Полка № " + to_string(rack->id()) + 
			" использует данную упаковку. для удалении упаковки сначала надо удалять Полку!!!");
	}
	if (!BoxCatalog::Instance().find(data->id()))
		throw Exception("Продукт (id=" + to_string(data->id()) + ") не найден");
}


const string RegisterStore::NAME = "registerStore";

RegisterStore::RegisterStore(EventDataPtr _cmdData) :
	Command(_cmdData)
{
}

RegisterStore::~RegisterStore()
{
}

void RegisterStore::executeImpl()
{
	shared_ptr<RegStoreData> data = dynamic_pointer_cast<RegStoreData>(cmdData_);
	StoresRepos::Instance().registerElement(createStores(data->type(), data->name()), true);
}


Command* RegisterStore::cloneImpl(EventDataPtr _cmdData) const
{
	return new RegisterStore(_cmdData);
}

const char* RegisterStore::helpMassageImpl() const
{
	return "Добавляет новый магазин";
}

void RegisterStore::check() const
{
	if(!dynamic_pointer_cast<RegStoreData>(cmdData_))
		Exception("Не удалось преобразовать EventData в RegStoreData");
}

const string RemoveStore::NAME = "removeStore";

RemoveStore::RemoveStore(EventDataPtr _eventData) :
	Command(_eventData)
{
}

RemoveStore::~RemoveStore()
{
}

void RemoveStore::executeImpl()
{
	shared_ptr<IdData> data = dynamic_pointer_cast<IdData>(cmdData_);
	StoresRepos::Instance().removeElement(data->id(), true);
}


Command * RemoveStore::cloneImpl(EventDataPtr _eventData) const
{
	return new RemoveStore(_eventData);
}

const char * RemoveStore::helpMassageImpl() const
{
	return "Удаляет магазины из каталога магазинов";
}

void RemoveStore::check() const
{
	if (StoresRepos::Instance().empty())
		throw Exception("Каталог магазинов пуст");
	IdDataPtr data = dynamic_pointer_cast<IdData>(cmdData_);
	if (!data)
		Exception("Не удалось преобразовать EventData в IdData");
	if (!StoresRepos::Instance().find(data->id()))
		throw Exception("Магазин (id=" + to_string(data->id()) + ") не найден");
}


const string RegisterRack::NAME = "registerRack";

RegisterRack::RegisterRack(EventDataPtr _cmdData) :
	Command(_cmdData)
{
}

RegisterRack::~RegisterRack()
{
}

void RegisterRack::executeImpl()
{
	shared_ptr<RegRackData> data = dynamic_pointer_cast<RegRackData>(cmdData_);
	Warehouse::Instance().registerElement(make_shared<Racks>(data->id(), data->size(), data->minSize(), data->maxSize()), true);
}


Command* RegisterRack::cloneImpl(EventDataPtr _cmdData) const
{
	return new RegisterRack(_cmdData);
}

const char* RegisterRack::helpMassageImpl() const
{
	return "добавляет новую полку в складе";
}

void RegisterRack::check() const
{
	if(!dynamic_pointer_cast<RegRackData>(cmdData_))
		Exception("Не удалось преобразовать EventData в RegRackData");
}

const string RemoveRack::NAME = "removeRack";

RemoveRack::RemoveRack(EventDataPtr _cmdData) :
	Command(_cmdData)
{
}

RemoveRack::~RemoveRack()
{
}

void RemoveRack::executeImpl()
{
	shared_ptr<IdData> data = dynamic_pointer_cast<IdData>(cmdData_);
	Warehouse::Instance().removeElement(data->id(), true);
}



Command * RemoveRack::cloneImpl(EventDataPtr _cmdData) const
{
	return new RemoveRack(_cmdData);
}

const char * RemoveRack::helpMassageImpl() const
{
	return "Удаляет пустую полку из склада";
}

void RemoveRack::check() const
{
	if (Warehouse::Instance().empty())
		throw Exception("Каталог магазинов пуст");
	shared_ptr<IdData> data = dynamic_pointer_cast<IdData>(cmdData_);
	if (!data)
		Exception("Не удалось преобразовать EventData в IdData");
	if (!Warehouse::Instance().find(data->id()))
		throw Exception("Полка (id=" + to_string(data->id()) + ") не найден");
}



const string StartProcess::NAME = "StartProcess";

StartProcess::StartProcess(EventDataPtr _cmdData) :
	Command(_cmdData)
{
}

StartProcess::~StartProcess()
{
}

void StartProcess::executeImpl()
{
	Timer::Instance().start();
	std::thread th([&]() { Process::Instance().start(); });
	th.detach();
}

Command * StartProcess::cloneImpl(EventDataPtr _cmdData) const
{
	return new StartProcess(_cmdData);
}

const char * StartProcess::helpMassageImpl() const
{
	return "Начинает процесс моделировании";
}

void StartProcess::check() const
{
	if (Process::Instance().started())
		throw Exception("Процесс уже запущен");
}


const string StopProcess::NAME = "stopProcess";

StopProcess::StopProcess(EventDataPtr _cmdData) :
	Command(_cmdData)
{
}

StopProcess::~StopProcess()
{
}

void StopProcess::executeImpl()
{
	Process::Instance().deactivate();
	Process::Instance().stop();
}

Command * StopProcess::cloneImpl(EventDataPtr _cmdData) const
{
	return new StopProcess(_cmdData);
}

const char* StopProcess::helpMassageImpl() const
{
	return "Остноавливает процесс";
}

void StopProcess::check() const
{
}



const string ActivateProcess::NAME = "ActivateProcess";

ActivateProcess::ActivateProcess(EventDataPtr _cmdData) :
	Command(_cmdData)
{
}

ActivateProcess::~ActivateProcess()
{
}

void ActivateProcess::executeImpl()
{
	Process::Instance().activate();
}

Command* ActivateProcess::cloneImpl(EventDataPtr _cmdData) const
{
	return new ActivateProcess(_cmdData);
}

const char * ActivateProcess::helpMassageImpl() const
{
	return "Активирует процесс";
}

void ActivateProcess::check() const
{
	if (!Process::Instance().started())
		throw Exception("Невозможно активировать остоновленный процесс");
}

const string DeactivateProcess::NAME = "DeactivateProcess";

DeactivateProcess::DeactivateProcess(EventDataPtr _cmdData) :
	Command(_cmdData)
{
}

DeactivateProcess::~DeactivateProcess()
{
}

void DeactivateProcess::executeImpl()
{
	Process::Instance().deactivate();
}

Command* DeactivateProcess::cloneImpl(EventDataPtr _cmdData) const
{
	return new DeactivateProcess(_cmdData);
}

const char * DeactivateProcess::helpMassageImpl() const
{
	return "Деактивирует процесс моделировании";
}

void DeactivateProcess::check() const
{
	if (!Process::Instance().state())
		throw Exception("Процесс уже деактивирован");
}

const string ExecDiscount::NAME = "discountExec";

ExecDiscount::ExecDiscount(EventDataPtr _cmdData) :
	Command(_cmdData)
{
}

ExecDiscount::~ExecDiscount()
{
}

void ExecDiscount::executeImpl()
{
	IdDataPtr data = dynamic_pointer_cast<IdData>(cmdData_);
	DiscountPtr dsnt = dynamic_pointer_cast<Discount>(DiscountsRepos::Instance().removeElement(data->id(), true));
	Warehouse::Instance().setDiscount(dsnt, true);
}

Command* ExecDiscount::cloneImpl(EventDataPtr _cmdData) const
{
	return new ExecDiscount(_cmdData);
}

const char* ExecDiscount::helpMassageImpl() const
{
	return "Установливает скиду";
}

void ExecDiscount::check() const
{
	IdDataPtr data = dynamic_pointer_cast<IdData>(cmdData_);
	if (!DiscountsRepos::Instance().find(data->id()))
		throw Exception("Невозможно исполнить придложение скидки № " + to_string(data->id()) + " , так как придложение не найдено");
}

const string RemoveDiscount::NAME = "discountRemove";

RemoveDiscount::RemoveDiscount(EventDataPtr _cmdData) :
	Command(_cmdData)
{
}

RemoveDiscount::~RemoveDiscount()
{
}

void RemoveDiscount::executeImpl()
{
	IdDataPtr data = dynamic_pointer_cast<IdData>(cmdData_);
	dynamic_pointer_cast<Discount>(DiscountsRepos::Instance().removeElement(data->id(), true));
}

Command * RemoveDiscount::cloneImpl(EventDataPtr _cmdData) const
{
	return new RemoveDiscount(_cmdData);
}

const char * RemoveDiscount::helpMassageImpl() const
{
	return "Удаляет предложении о скидке";
}

void RemoveDiscount::check() const
{
	IdDataPtr data = dynamic_pointer_cast<IdData>(cmdData_);
	if (!DiscountsRepos::Instance().find(data->id()))
		throw Exception("Невозможно удалять предложение скидки № " + to_string(data->id()) + " так как придложение не найдено");
}


const string ChangeDiscount::NAME = "changeDiscount";

ChangeDiscount::ChangeDiscount(EventDataPtr _cmdData) :
	Command(_cmdData)
{
}

ChangeDiscount::~ChangeDiscount()
{
}

void ChangeDiscount::executeImpl()
{
	shared_ptr<DiscountChangeData> data = dynamic_pointer_cast<DiscountChangeData>(cmdData_);
	DiscountsRepos::Instance().changeDiscount(data->id(), data->precent(), true);
}

Command * ChangeDiscount::cloneImpl(EventDataPtr _cmdData) const
{
	return new ChangeDiscount(_cmdData);
}

const char * ChangeDiscount::helpMassageImpl() const
{
	return "изменяет процент скидки";
}

void ChangeDiscount::check() const
{
	shared_ptr<DiscountChangeData> data = dynamic_pointer_cast<DiscountChangeData>(cmdData_);
	if (!data)
		throw Exception("Не получилось переобразовать EventData в DiscountChangeData");
	if (!DiscountsRepos::Instance().find(data->id()))
		throw Exception("Предложение скидки № " + to_string(data->id()) + " не найдено");
}


const string ConfirmCargoStore::NAME = "confirmCargoStore";

ConfirmCargoStore::ConfirmCargoStore(EventDataPtr _cmdData) :
	Command(_cmdData)
{
}

ConfirmCargoStore::~ConfirmCargoStore()
{
}

void ConfirmCargoStore::executeImpl()
{
	shared_ptr<IdData> data = dynamic_pointer_cast<IdData>(cmdData_);
	CargoStoresRepos::Instance().confirm(data->id(), true);
}

Command * ConfirmCargoStore::cloneImpl(EventDataPtr _cmdData) const
{
	return new ConfirmCargoStore(_cmdData);
}

const char * ConfirmCargoStore::helpMassageImpl() const
{
	return "Утверждает перевозки в магазины";
}

void ConfirmCargoStore::check() const
{
}


const string RemoveCargoStore::NAME = "removeCargoStore";


RemoveCargoStore::RemoveCargoStore(EventDataPtr _cmdData) :
	Command(_cmdData)
{
}

RemoveCargoStore::~RemoveCargoStore()
{
}

void RemoveCargoStore::executeImpl()
{
	shared_ptr<IdData> data = dynamic_pointer_cast<IdData>(cmdData_);
	CargoStoresPtr cargo = dynamic_pointer_cast<CargoStores>(CargoStoresRepos::Instance().removeElement(data->id(), true));
	cargo->cancel();
}

Command * RemoveCargoStore::cloneImpl(EventDataPtr _cmdData) const
{
	return new RemoveCargoStore(_cmdData);
}

const char * RemoveCargoStore::helpMassageImpl() const
{
	return "Удаляет перевозку в Магазин";
}

void RemoveCargoStore::check() const
{
	shared_ptr<IdData> data = dynamic_pointer_cast<IdData>(cmdData_);
	CargoStoresPtr cargo = dynamic_pointer_cast<CargoStores>(CargoStoresRepos::Instance().find(data->id()));
	if (!cargo)
		throw Exception("Груз № " + to_string(data->id()) + " не найден");
	if (cargo->state() == CONFIRMED)
		throw Exception("Груз № " + to_string(data->id()) + " подвержден. Нельзя удалять подвержденную перевозку");

}


const string ConfirmCargoWarehouse::NAME = "confirmCargoWarehouse";

ConfirmCargoWarehouse::ConfirmCargoWarehouse(EventDataPtr _cmdData) :
	Command(_cmdData)
{
}

ConfirmCargoWarehouse::~ConfirmCargoWarehouse()
{
}

void ConfirmCargoWarehouse::executeImpl()
{
	shared_ptr<IdData> data = dynamic_pointer_cast<IdData>(cmdData_);
	CargoWarehouseRepos::Instance().confirm(data->id(), true);
}

Command* ConfirmCargoWarehouse::cloneImpl(EventDataPtr _cmdData) const
{
	return new ConfirmCargoWarehouse(_cmdData);
}

const char * ConfirmCargoWarehouse::helpMassageImpl() const
{
	return "Подверждает поставку на склад";
}

void ConfirmCargoWarehouse::check() const
{
}

const string RemoveCargoWarehouse::NAME = "removeCargoWarehouse";

RemoveCargoWarehouse::RemoveCargoWarehouse(EventDataPtr _cmdData) :
	Command(_cmdData)
{
}

RemoveCargoWarehouse::~RemoveCargoWarehouse()
{
}

void RemoveCargoWarehouse::executeImpl()
{
	shared_ptr<IdData> data = dynamic_pointer_cast<IdData>(cmdData_);
	CargoWarehousePtr cargo = dynamic_pointer_cast<CargoWarehouse>(CargoWarehouseRepos::Instance().removeElement(data->id(), true));
	cargo->cancel();
}

Command * RemoveCargoWarehouse::cloneImpl(EventDataPtr _cmdData) const
{
	return new RemoveCargoWarehouse(_cmdData);
}

const char * RemoveCargoWarehouse::helpMassageImpl() const
{
	return "Удаляет заказ на доставку";
}

void RemoveCargoWarehouse::check() const
{
	shared_ptr<IdData> data = dynamic_pointer_cast<IdData>(cmdData_);
	CargoWarehousePtr cargo = dynamic_pointer_cast<CargoWarehouse>(CargoWarehouseRepos::Instance().find(data->id()));
	if (!cargo)
		throw Exception("Доставка на склад № " + to_string(data->id()) + " не найден");
	if (cargo->state() == CONFIRMED)
		throw Exception("Доставка на склад № " + to_string(data->id()) + " подвержден. Нельзя удалять подвержденную доставкуу");
}

const string StopGenOrders::NAME = "stopGenOrders";

StopGenOrders::StopGenOrders(EventDataPtr _cmdData) :
	Command(_cmdData)
{
}

StopGenOrders::~StopGenOrders()
{
}

void StopGenOrders::executeImpl()
{
	Process::Instance().setGenOrders(false);
}

Command * StopGenOrders::cloneImpl(EventDataPtr _cmdData) const
{
	return new StopGenOrders(_cmdData);
}

const char * StopGenOrders::helpMassageImpl() const
{
	return "Остановливает прцесс генерации заказов";
}

void StopGenOrders::check() const
{
	if (!Process::Instance().stateOrders())
		throw Exception("Генрация заказов уже остановлен");
}



void commandReigister(UserInterface* _ui)
{
	try
	{
		CommandRepository::Instance().registerCommand(RegisterProduct::NAME, make_unique<RegisterProduct>(nullptr));
		CommandRepository::Instance().registerCommand(RemoveProduct::NAME, make_unique<RemoveProduct>(nullptr));

		CommandRepository::Instance().registerCommand(RegisterBox::NAME, make_unique<RegisterBox>(nullptr));
		CommandRepository::Instance().registerCommand(RemoveBox::NAME, make_unique<RemoveBox>(nullptr));

		CommandRepository::Instance().registerCommand(RegisterStore::NAME, make_unique<RegisterStore>(nullptr));
		CommandRepository::Instance().registerCommand(RemoveStore::NAME, make_unique<RemoveStore>(nullptr));

		CommandRepository::Instance().registerCommand(RegisterRack::NAME, make_unique<RegisterRack>(nullptr));
		CommandRepository::Instance().registerCommand(RemoveRack::NAME, make_unique<RemoveRack>(nullptr));

		CommandRepository::Instance().registerCommand(StartProcess::NAME, make_unique<StartProcess>(nullptr));
		CommandRepository::Instance().registerCommand(StopProcess::NAME, make_unique<StopProcess>(nullptr));
		CommandRepository::Instance().registerCommand(ActivateProcess::NAME, make_unique<ActivateProcess>(nullptr));
		CommandRepository::Instance().registerCommand(DeactivateProcess::NAME, make_unique<DeactivateProcess>(nullptr));
		CommandRepository::Instance().registerCommand(StopGenOrders::NAME, make_unique<StopGenOrders>(nullptr));

		CommandRepository::Instance().registerCommand(ExecDiscount::NAME, make_unique<ExecDiscount>(nullptr));
		CommandRepository::Instance().registerCommand(RemoveDiscount::NAME, make_unique<RemoveDiscount>(nullptr));
		CommandRepository::Instance().registerCommand(ChangeDiscount::NAME, make_unique<ChangeDiscount>(nullptr));

		CommandRepository::Instance().registerCommand(ConfirmCargoStore::NAME, make_unique<ConfirmCargoStore>(nullptr));
		CommandRepository::Instance().registerCommand(RemoveCargoStore::NAME, make_unique<RemoveCargoStore>(nullptr));

		CommandRepository::Instance().registerCommand(ConfirmCargoWarehouse::NAME, make_unique<ConfirmCargoWarehouse>(nullptr));
		CommandRepository::Instance().registerCommand(RemoveCargoWarehouse::NAME, make_unique<RemoveCargoWarehouse>(nullptr));

		
	}
	catch (Exception& ex)
	{
		_ui->errorMessage(ex.what());
	}
}

