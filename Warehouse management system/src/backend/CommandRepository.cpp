#include "CommandRepository.h"

#include "../utilites/Exception.h"
#include "../utilites/EventData.h"
#include "Command.h"



using std::make_pair;
using std::unique_ptr;
using std::move;
using std::shared_ptr;
using std::string;

CommandRepository& CommandRepository::Instance()
{
	static CommandRepository instance;
	return instance;
}

void CommandRepository::registerCommand(const string& _key, unique_ptr<Command> _command)
{
	Repository::const_iterator it = repository_.find(_key);
	if (it != repository_.end())
		throw Exception("команда \"" + _key + "\" уже зарешистрирована");
	repository_.insert(make_pair(_key, move(_command)));
}

void CommandRepository::removeCommand(const string & _key)
{
	auto it = hasKey(_key);
	repository_.erase(it);
}

Command * CommandRepository::allocateCommand(const string& _key, shared_ptr<EventData> _eventData)
{
	Repository::const_iterator it = hasKey(_key);
	return it->second->clone(_eventData);
}

CommandRepository::Repository::const_iterator CommandRepository::hasKey(const string& _key) const
{
	Repository::const_iterator it = repository_.find(_key);
	if (it == repository_.end())
	 	throw Exception("\"" + _key + "\" команда не найдена");
	return it;
}

CommandRepository::Repository::iterator CommandRepository::hasKey(const string& key)
{
	Repository::iterator it = repository_.find(key);
	if (it == repository_.end())
		throw Exception("\"" + key + "\" команда не найдена");
	return it;
}

