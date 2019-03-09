#ifndef COMMAND_REPOSITORY_H
#define COMMAND_REPOSITORY_H



#include <memory>
#include <unordered_map>
#include <string>

class Command;
class EventData;

class CommandRepository
{
	using Repository = std::unordered_map < std::string, std::unique_ptr<Command> >;
public:
	static CommandRepository& Instance();
	void registerCommand(const std::string&, std::unique_ptr<Command>);
	void removeCommand(const std::string& _key);
	Command* allocateCommand(const std::string&, std::shared_ptr<EventData>);

private:
	Repository repository_;

	CommandRepository() { }
	~CommandRepository() { }

	Repository::const_iterator hasKey(const std::string&) const;
	Repository::iterator hasKey(const std::string&);

	CommandRepository(const CommandRepository&) = delete;
	CommandRepository(CommandRepository&&) = delete;
	CommandRepository& operator=(const CommandRepository&) = delete;
	CommandRepository& operator=(CommandRepository&&) = delete;
};



#endif // !COMMAND_REPOSITORY_H



