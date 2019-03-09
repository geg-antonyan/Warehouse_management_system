#ifndef APP_OBSERVER_H
#define APP_OBSERVER_H

#include "../utilites/Observer.h"

#include <memory>

using std::dynamic_pointer_cast;

class CommandDispatcher;
class UserInterface;

class CommandIssuedOB : public Observer
{
public:
	explicit CommandIssuedOB(CommandDispatcher& _cd);

private:
	void notify(std::shared_ptr<EventData>) override;

	CommandDispatcher& cd_;
};

class PrdCatalogUpdatedOB : public Observer
{
public:
	explicit PrdCatalogUpdatedOB(UserInterface* _ui);

private:
	void notify(std::shared_ptr<EventData>) override;

	UserInterface* ui_;
};

class BoxCatalogUpdatedOB : public Observer
{
public:
	explicit BoxCatalogUpdatedOB(UserInterface* _ui);

private:
	void notify(std::shared_ptr<EventData>) override;

	UserInterface* ui_;
};

class StoresReposUpdatedOB : public Observer
{
public:
	explicit StoresReposUpdatedOB(UserInterface* _ui);

private:
	void notify(std::shared_ptr<EventData>) override;

	UserInterface* ui_;
};

class WarehouseUpdatedOB : public Observer
{
public:
	explicit WarehouseUpdatedOB(UserInterface* _ui);

private:
	void notify(std::shared_ptr<EventData>) override;

	UserInterface* ui_;
};

class TickOB : public Observer
{
public:
	explicit TickOB(UserInterface* _ui);

private:
	void notify(std::shared_ptr<EventData>) override;

	UserInterface* ui_;
};

class ProcessStartOB : public Observer
{
public:
	explicit ProcessStartOB(UserInterface* _ui);

private:
	void notify(std::shared_ptr<EventData>) override;

	UserInterface* ui_;
};

class ProcessErrorOB : public Observer
{
public:
	explicit ProcessErrorOB(UserInterface* _ui);

private:
	void notify(std::shared_ptr<EventData>) override;

	UserInterface* ui_;
};

class StoreOrdRepUpdateOB : public Observer
{
public:
	explicit StoreOrdRepUpdateOB(UserInterface* _ui);

private:
	void notify(std::shared_ptr<EventData>) override;

	UserInterface* ui_;
};

class CargoStoreRepUpdateOB : public Observer
{
public:
	explicit CargoStoreRepUpdateOB(UserInterface* _ui);

private:
	void notify(std::shared_ptr<EventData>) override;

	UserInterface* ui_;
};

class CargoWarehouseRepUpdateOB : public Observer
{
public:
	explicit CargoWarehouseRepUpdateOB(UserInterface* _ui);

private:
	void notify(std::shared_ptr<EventData>) override;

	UserInterface* ui_;
};



class CargoSendedOB : public Observer
{
public:
	explicit CargoSendedOB(UserInterface* _ui);

private:
	void notify(std::shared_ptr<EventData>) override;

	UserInterface* ui_;
};

class NewStoreOrdGenerOB : public Observer
{
public:
	explicit NewStoreOrdGenerOB(UserInterface* _ui);
private:
	void notify(std::shared_ptr<EventData>) override;
	UserInterface* ui_;
};

class ExpiredPrdUpdateOB : public Observer
{
public:
	explicit ExpiredPrdUpdateOB(UserInterface* _ui);

private:
	void notify(std::shared_ptr<EventData>) override;
	UserInterface* ui_;

};

class DiscountsReposUpdateOB : public Observer
{
public:
	explicit DiscountsReposUpdateOB(UserInterface* _ui);

private:
	void notify(std::shared_ptr<EventData>) override;
	UserInterface* ui_;

};


void registerUiObservers(UserInterface* ui);

#endif // !APP_OBSERVER_H
