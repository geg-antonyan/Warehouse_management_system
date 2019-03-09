

//#pragma once
#ifndef COMMAND_MANAGER_H
#define COMMAND_MANAGER_H




class Command;

class CommandManager
{
public:
	CommandManager() { }
	~CommandManager() { }

	void commandExecute(Command* cmd);


private:
	CommandManager(const CommandManager&) = delete;
	CommandManager(CommandManager&&) = delete;
	CommandManager& operator=(CommandManager&) = delete;
	CommandManager& operator=(CommandManager&&) = delete;
};


#endif // !COMMAND_MANAGER_H





