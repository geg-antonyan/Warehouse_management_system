#ifndef PROCESS_H
#define PROCESS_H

#include "../utilites/Observed.h"

#include <thread>
#include <condition_variable>
#include <mutex>


class UserInterface;

class Process : protected Observed
{
	
public:
	using Observed::addObserver;
	using Observed::removeObserver;

	static const std::string Tick;
	static const std::string Error;
	static const std::string Start;

	static Process& Instance();

	void start();
	void stop();
	void activate();
	void deactivate();
	void setGenOrders(bool);
	bool started();
	bool state();
	bool stateOrders();
	void wait(std::unique_lock<std::mutex>& _ulook);
private:

	void controlProcFlow();
	void cargoStoreSendFlow();
	void cargoWarehouseSendFlow();

	std::condition_variable condVariable;
	std::mutex mtx_;
	bool state_;
	bool start_;
	bool stop_;
	bool genOrders_;
	
	Process();
	~Process();
};




#endif // !PROCESS_H
