#include "CommandDispatcher.h"

#include "../utilites/UserInterface.h"
#include "../utilites/Exception.h"
#include "../warehouse/Warehouse.h"
#include "../customers/Stores.h"

#include "CommandRepository.h"
#include "Command.h"



using std::string;
using std::shared_ptr;
using std::make_shared;

shared_ptr<EventData> makeEvent(const string&, const string&);

string treat(const string&);


CommandDispatcher::CommandDispatcher(UserInterface* _ui) :
	ui_(_ui)
{
}


CommandDispatcher::~CommandDispatcher()
{
}

void CommandDispatcher::commandEntered(const string& _command)
{
	try
	{
		string::size_type k = _command.find(' ');
		string cmdName;
		if (k != string::npos)
			cmdName = _command.substr(0, k);
		else cmdName = _command.substr(0, _command.length());
		string cmdData;
		if (k + 1 != string::npos)
			cmdData = _command.substr(k + 1, _command.length() - k + 1);
		Command* cmd = CommandRepository::Instance().allocateCommand(cmdName, makeEvent(cmdName, (treat(cmdData))));
		cd_.commandExecute(cmd);
	}
	catch (Exception& ex)
	{
		ui_->errorMessage(ex.what());
	}
}

EventDataPtr CommandDispatcher::makeEvent(const string& _cmdName, const string& _cmdData)
{
	if (_cmdName == RegisterProduct::NAME)
		return make_shared<RegPrdData>(_cmdData);
	if (_cmdName == RemoveProduct::NAME)
		return make_shared<IdData>(_cmdData);
	
	if (_cmdName == RegisterBox::NAME)
		return make_shared<RegBoxData>(_cmdData);
	if (_cmdName == RemoveBox::NAME)
		return make_shared<IdData>(_cmdData);

	if (_cmdName == RegisterStore::NAME)
		return make_shared<RegStoreData>(_cmdData);
	if (_cmdName == RemoveStore::NAME)
		return make_shared<IdData>(_cmdData);

	if (_cmdName == RegisterRack::NAME)
		return make_shared<RegRackData>(_cmdData);
	if (_cmdName == RemoveRack::NAME)
		return make_shared<IdData>(_cmdData);

	if (_cmdName == ExecDiscount::NAME)
		return make_shared<IdData>(_cmdData);
	if (_cmdName == RemoveDiscount::NAME)
		return make_shared<IdData>(_cmdData);
	if (_cmdName == ChangeDiscount::NAME)
		return make_shared<DiscountChangeData>(_cmdData);

	if (_cmdName == ConfirmCargoStore::NAME || _cmdName == RemoveCargoStore::NAME ||
		_cmdName == ConfirmCargoWarehouse::NAME || _cmdName == RemoveCargoWarehouse::NAME)
		return make_shared<IdData>(_cmdData);
	

	return nullptr;
}



string treat(const string& _eventData)
{
	string tmpData;

	bool start = true;
	bool fl = false;
	for (size_t i = 0u; i < _eventData.length(); i++)
	{
		if (start)
		{
			if (_eventData[i] == ' ')
				continue;
			else start = false;
		}
		if (_eventData[i] != ' ')
		{
			tmpData += _eventData[i];
			fl = false;
		}
		else if (!fl)
		{
			tmpData += _eventData[i];
			fl = true;
		}
	}
	return tmpData;
}