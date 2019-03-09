#ifndef COMMAND_DISPATCHER_H
#define COMMAND_DISPATCHER_H

#include "../utilites/EventData.h"

#include "CommandManager.h"

#include <memory>
#include <string>


class UserInterface;


class CommandDispatcher
{
public:
	CommandDispatcher(UserInterface*);
	~CommandDispatcher();

	void commandEntered(const std::string& command);

private:
	CommandManager cd_;
	UserInterface* ui_;
	EventDataPtr makeEvent(const std::string& _cmdName, const std::string& _cmdData);
};



#endif // !COMMAND_DISPATCHER_H


