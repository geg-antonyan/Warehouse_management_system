#ifndef COMMAND_H
#define COMMAND_H

#include "../utilites/EventData.h"

class Command
{
public:
	virtual ~Command();
	void execute();
	const char* helpMassage() const;
	Command* clone(EventDataPtr) const;

protected:
	Command(EventDataPtr);
	std::shared_ptr<EventData> cmdData_;

private:
	virtual void executeImpl() = 0;
	virtual const char* helpMassageImpl() const = 0;
	virtual Command* cloneImpl(std::shared_ptr<EventData>) const = 0;
	virtual void check() const = 0;


	Command(const Command&) = delete;
	Command(Command&&) = delete;
	Command& operator=(const Command&) = delete;
	Command& operator=(Command&&) = delete;
};


class RegisterProduct : public Command
{
public:
	const static std::string NAME;

	RegisterProduct(EventDataPtr);
	~RegisterProduct();

private:
	void executeImpl() override;
	
	const char* helpMassageImpl() const override;
	Command* cloneImpl(EventDataPtr) const override;

	void check() const override;
	
	
	RegisterProduct(const RegisterProduct&) = delete;
	RegisterProduct(RegisterProduct&&) = delete;
	RegisterProduct& operator=(const RegisterProduct&) = delete;
	RegisterProduct& operator=(RegisterProduct&&) = delete;
};

class RemoveProduct : public Command
{
public:
	const static std::string NAME;

	RemoveProduct(EventDataPtr);
	~RemoveProduct();

private:
	void executeImpl() override;
	const char* helpMassageImpl() const override;
	Command* cloneImpl(EventDataPtr) const override;
	void check() const override;


	RemoveProduct(const RemoveProduct&) = delete;
	RemoveProduct(RemoveProduct&&) = delete;
	RemoveProduct& operator=(const RemoveProduct&) = delete;
	RemoveProduct& operator=(RemoveProduct&&) = delete;
};


class RegisterBox : public Command
{
public:
	const static std::string NAME;

	RegisterBox(EventDataPtr);
	~RegisterBox();
private:
	void executeImpl() override;

	Command* cloneImpl(EventDataPtr) const override;
	const char* helpMassageImpl() const override;
	void check() const override;

	RegisterBox(const RegisterBox&) = delete;
	RegisterBox(RegisterBox&&) = delete;
	RegisterBox& operator=(const RegisterBox&) = delete;
	RegisterBox& operator=(RegisterBox&&) = delete;
};

class RemoveBox : public Command
{
public:
	const static std::string NAME;

	RemoveBox(EventDataPtr);
	~RemoveBox();
private:
	void executeImpl() override;

	Command* cloneImpl(EventDataPtr) const override;
	const char* helpMassageImpl() const override;
	void check() const override;

	RemoveBox(const RemoveBox&) = delete;
	RemoveBox(RemoveBox&&) = delete;
	RemoveBox& operator=(const RegisterBox&) = delete;
	RemoveBox& operator=(RemoveBox&&) = delete;
};




class RegisterStore : public Command
{
public:
	const static std::string NAME;

	RegisterStore(EventDataPtr);
	~RegisterStore();
private:
	void executeImpl() override;
	Command* cloneImpl(EventDataPtr) const override;
	const char* helpMassageImpl() const override;
	void check() const override;

	RegisterStore(const RegisterStore&) = delete;
	RegisterStore(RegisterStore&&) = delete;
	RegisterStore& operator=(const RegisterStore&) = delete;
	RegisterStore& operator=(RegisterStore&&) = delete;
};

class RemoveStore : public Command
{
public:
	const static std::string NAME;

	RemoveStore(EventDataPtr);
	~RemoveStore();
private:
	void executeImpl() override;
	
	Command* cloneImpl(EventDataPtr) const override;
	const char* helpMassageImpl() const override;
	void check() const override;


	RemoveStore(const RemoveStore&) = delete;
	RemoveStore(RemoveStore&&) = delete;
	RemoveStore& operator=(const RemoveStore&) = delete;
	RemoveStore& operator=(RemoveStore&&) = delete;
};


class RegisterRack : public Command
{
public:
	const static std::string NAME;

	RegisterRack(EventDataPtr);
	~RegisterRack();
private:
	void executeImpl() override;
	
	Command* cloneImpl(EventDataPtr) const override;
	const char* helpMassageImpl() const override;
	void check() const override;



	RegisterRack(const RegisterRack&) = delete;
	RegisterRack(RegisterRack&&) = delete;
	RegisterRack& operator=(const RegisterRack&) = delete;
	RegisterRack& operator=(RegisterRack&&) = delete;
};

class RemoveRack : public Command
{
public:
	const static std::string NAME;

	RemoveRack(EventDataPtr);
	~RemoveRack();
private:
	void executeImpl() override;
	Command* cloneImpl(EventDataPtr) const override;
	const char* helpMassageImpl() const override;
	void check() const override;


	RemoveRack(const RemoveRack&) = delete;
	RemoveRack(RemoveRack&&) = delete;
	RemoveRack& operator=(const RemoveRack&) = delete;
	RemoveRack& operator=(RemoveRack&&) = delete;
};

class StartProcess : public Command
{
public:
	const static std::string NAME;

	StartProcess(EventDataPtr);
	~StartProcess();
private:
	void executeImpl() override;
	Command* cloneImpl(EventDataPtr) const override;
	const char* helpMassageImpl() const override;
	void check() const override;


	StartProcess(const StartProcess&) = delete;
	StartProcess(StartProcess&&) = delete;
	StartProcess& operator=(const StartProcess&) = delete;
	StartProcess& operator=(StartProcess&&) = delete;
};

class StopProcess : public Command
{
public:
	const static std::string NAME;

	StopProcess(EventDataPtr);
	~StopProcess();
private:
	void executeImpl() override;
	Command* cloneImpl(EventDataPtr) const override;
	const char* helpMassageImpl() const override;
	void check() const override;


	StopProcess(const StopProcess&) = delete;
	StopProcess(StopProcess&&) = delete;
	StopProcess& operator=(const StopProcess&) = delete;
	StopProcess& operator=(StopProcess&&) = delete;
};

class ActivateProcess : public Command
{
public:
	const static std::string NAME;

	ActivateProcess(EventDataPtr);
	~ActivateProcess();
private:
	void executeImpl() override;
	Command* cloneImpl(EventDataPtr) const override;
	const char* helpMassageImpl() const override;
	void check() const override;


	ActivateProcess(const ActivateProcess&) = delete;
	ActivateProcess(ActivateProcess&&) = delete;
	ActivateProcess& operator=(const ActivateProcess&) = delete;
	ActivateProcess& operator=(ActivateProcess&&) = delete;
};

class DeactivateProcess : public Command
{
public:
	const static std::string NAME;

	DeactivateProcess(EventDataPtr);
	~DeactivateProcess();
private:
	void executeImpl() override;
	Command* cloneImpl(EventDataPtr) const override;
	const char* helpMassageImpl() const override;
	void check() const override;


	DeactivateProcess(const DeactivateProcess&) = delete;
	DeactivateProcess(DeactivateProcess&&) = delete;
	DeactivateProcess& operator=(const DeactivateProcess&) = delete;
	DeactivateProcess& operator=(DeactivateProcess&&) = delete;
};

class ExecDiscount : public Command
{
public:
	const static std::string NAME;

	ExecDiscount(EventDataPtr);
	~ExecDiscount();
private:
	void executeImpl() override;
	Command* cloneImpl(EventDataPtr) const override;
	const char* helpMassageImpl() const override;
	void check() const override;


	ExecDiscount(const ExecDiscount&) = delete;
	ExecDiscount(ExecDiscount&&) = delete;
	ExecDiscount& operator=(const ExecDiscount&) = delete;
	ExecDiscount& operator=(ExecDiscount&&) = delete;
};

class RemoveDiscount : public Command
{
public:
	const static std::string NAME;

	RemoveDiscount(EventDataPtr);
	~RemoveDiscount();
private:
	void executeImpl() override;
	Command* cloneImpl(EventDataPtr) const override;
	const char* helpMassageImpl() const override;
	void check() const override;


	RemoveDiscount(const RemoveDiscount&) = delete;
	RemoveDiscount(RemoveDiscount&&) = delete;
	RemoveDiscount& operator=(const RemoveDiscount&) = delete;
	RemoveDiscount& operator=(RemoveDiscount&&) = delete;
};

class ChangeDiscount : public Command
{
public:
	const static std::string NAME;

	ChangeDiscount(EventDataPtr);
	~ChangeDiscount();
private:
	void executeImpl() override;
	Command* cloneImpl(EventDataPtr) const override;
	const char* helpMassageImpl() const override;
	void check() const override;
	

	ChangeDiscount(const ChangeDiscount&) = delete;
	ChangeDiscount(ChangeDiscount&&) = delete;
	ChangeDiscount& operator=(const ChangeDiscount&) = delete;
	ChangeDiscount& operator=(ChangeDiscount&&) = delete;
};


class ConfirmCargoStore : public Command
{
public:
	const static std::string NAME;

	ConfirmCargoStore(EventDataPtr);
	~ConfirmCargoStore();
private:
	void executeImpl() override;
	Command* cloneImpl(EventDataPtr) const override;
	const char* helpMassageImpl() const override;
	void check() const override;


	ConfirmCargoStore(const ConfirmCargoStore&) = delete;
	ConfirmCargoStore(ConfirmCargoStore&&) = delete;
	ConfirmCargoStore& operator=(const ConfirmCargoStore&) = delete;
	ConfirmCargoStore& operator=(ConfirmCargoStore&&) = delete;
};

class RemoveCargoStore : public Command
{
public:
	const static std::string NAME;

	RemoveCargoStore(EventDataPtr);
	~RemoveCargoStore();
private:
	void executeImpl() override;
	Command* cloneImpl(EventDataPtr) const override;
	const char* helpMassageImpl() const override;
	void check() const override;


	RemoveCargoStore(const RemoveCargoStore&) = delete;
	RemoveCargoStore(RemoveCargoStore&&) = delete;
	RemoveCargoStore& operator=(const RemoveCargoStore&) = delete;
	RemoveCargoStore& operator=(RemoveCargoStore&&) = delete;
};


class ConfirmCargoWarehouse : public Command
{
public:
	const static std::string NAME;

	ConfirmCargoWarehouse(EventDataPtr);
	~ConfirmCargoWarehouse();
private:
	void executeImpl() override;
	Command* cloneImpl(EventDataPtr) const override;
	const char* helpMassageImpl() const override;
	void check() const override;


	ConfirmCargoWarehouse(const ConfirmCargoWarehouse&) = delete;
	ConfirmCargoWarehouse(ConfirmCargoWarehouse&&) = delete;
	ConfirmCargoWarehouse& operator=(const ConfirmCargoWarehouse&) = delete;
	ConfirmCargoWarehouse& operator=(ConfirmCargoWarehouse&&) = delete;
};


class RemoveCargoWarehouse : public Command
{
public:
	const static std::string NAME;

	RemoveCargoWarehouse(EventDataPtr);
	~RemoveCargoWarehouse();
private:
	void executeImpl() override;
	Command* cloneImpl(EventDataPtr) const override;
	const char* helpMassageImpl() const override;
	void check() const override;


	RemoveCargoWarehouse(const RemoveCargoWarehouse&) = delete;
	RemoveCargoWarehouse(RemoveCargoWarehouse&&) = delete;
	RemoveCargoWarehouse& operator=(const RemoveCargoWarehouse&) = delete;
	RemoveCargoWarehouse& operator=(RemoveCargoWarehouse&&) = delete;
};


class StopGenOrders : public Command
{
public:
	const static std::string NAME;

	StopGenOrders(EventDataPtr);
	~StopGenOrders();
private:
	void executeImpl() override;
	Command* cloneImpl(EventDataPtr) const override;
	const char* helpMassageImpl() const override;
	void check() const override;


	StopGenOrders(const StopGenOrders&) = delete;
	StopGenOrders(StopGenOrders&&) = delete;
	StopGenOrders& operator=(const StopGenOrders&) = delete;
	StopGenOrders& operator=(StopGenOrders&&) = delete;
};



class UserInterface;
void commandReigister(UserInterface* _ui);

#endif // !COMMAND_H