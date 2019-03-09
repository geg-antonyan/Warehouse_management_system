
#include "CommandManager.h"
#include "Command.h"

void CommandManager::commandExecute(Command * cmd)
{
	cmd->execute();
	delete cmd;
}

