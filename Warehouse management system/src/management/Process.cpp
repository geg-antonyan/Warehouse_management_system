#include "Process.h"

#include <functional>

#include "../customers/Stores.h"

#include "../warehouse/Warehouse.h"

#include "../utilites/Exception.h"
#include "../utilites/UserInterface.h"
#include "../utilites/Timer.h"

#include "Cargo.h"

using std::thread;
using std::mutex;
using std::unique_lock;
using std::string;
using std::make_shared;

const string Process::Tick = "Tick";
const string Process::Error = "Error";
const string Process::Start = "Run";

Process::Process() :
	state_(true),
	start_(false),
	stop_(false),
	genOrders_(true)
{
	registerEvent(Tick);
	registerEvent(Error);
	registerEvent(Start);
}

Process::~Process()
{

}

Process& Process::Instance()
{
	static Process instance;
	return instance;
}

void Process::activate()
{
	Timer::Instance().activate();
	state_ = true;
	condVariable.notify_all();
}

void Process::deactivate()
{
	Timer::Instance().pause();
	state_ = false;
}

void Process::setGenOrders(bool _state)
{
	genOrders_ = _state;
}

bool Process::started()
{
	return start_;
}

bool Process::state()
{
	return state_;
}

bool Process::stateOrders()
{
	return genOrders_;
}

void Process::wait(std::unique_lock<std::mutex>& _ulook)
{
	condVariable.wait(_ulook, std::bind(&Process::state, this));
}

void Process::controlProcFlow()
{
	thread th([&]()
		{
			try
			{
				CargoStoresRepos::Instance().removeNotConfirmCargos(true);
				CargoWarehouseRepos::Instance().removeNotConfirmCargos(true);
				DiscountsRepos::Instance().clear(true);
				Warehouse::Instance().controlOverdue(true);
				Warehouse::Instance().controlDecrease(true);
				Warehouse::Instance().generateDiscount(3, 20.0);
				if (genOrders_)
					StoresRepos::Instance().generateOrders();
			}
			catch (Exception& ex)
			{
				raiseEvent(Error, make_shared<StrData>(ex.what()));
			}
		});
	th.detach();
}

void Process::cargoStoreSendFlow()
{
	thread th([&]()
		{
			try
			{
				CargoStoresRepos::Instance().sendCargos();
			}
			catch (Exception& ex)
			{
				raiseEvent(Error, make_shared<StrData>(ex.what()));
			}
		});
	th.detach();
}

void Process::cargoWarehouseSendFlow()
{
	thread th([&]()
		{
			try
			{
				CargoWarehouseRepos::Instance().sendCargos();
			}
			catch (Exception& ex)
			{
				raiseEvent(Error, make_shared<StrData>(ex.what()));
			}
		});
	th.detach();
}



void Process::start()
{
	try
	{
		if (start_) return; // для безопасности. 
		start_ = true;
		stop_ = false;
		raiseEvent(Start, nullptr);
		int day = -1;
		while (!stop_)
		{
			unique_lock<mutex> uLock(mtx_);
			condVariable.wait(uLock, std::bind(&Process::state, this));
			raiseEvent(Tick, nullptr);
			if (day < Timer::Instance().day())
			{
				day = Timer::Instance().day();
				controlProcFlow();
				cargoStoreSendFlow();
				cargoWarehouseSendFlow();
			}
			Timer::Instance().delay(1);
		}
	}
	catch (Exception& ex)
	{
		raiseEvent(Error, make_shared<StrData>(ex.what()));
	}
}

void Process::stop()
{
	start_ = false;
	stop_ = true;
}
