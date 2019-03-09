#include "Observed.h"

#include "Exception.h"


using std::string;
using std::unique_ptr;
using std::shared_ptr;
using std::make_pair;
using std::move;


Observed::Events::iterator Observed::findCheckedEvent(const string& _eventName)
{
	Events::iterator it = events_.find(_eventName);
	if (it == events_.end())
		throw Exception("Издатель не поддерживает собыите \"" + _eventName + "\"");
	return it;
}

Observed::Events::const_iterator Observed::findCheckedEvent(const string & _eventName) const
{
	Events::const_iterator it = events_.find(_eventName);
	if (it == events_.end())
		throw Exception("Издатель не поддерживает собыите \"" + _eventName + "\"");
	return it;
}

void Observed::addObserver(const string& _eventName, unique_ptr<Observer> _observer)
{
	Events::iterator ev = findCheckedEvent(_eventName);
	ObserverList& obList = ev->second;
	ObserverList::const_iterator obs = obList.find(_observer->name());
	if (obs != obList.end())
		throw Exception("Наблюдатель \"" + _observer->name() + "\" уже существует");
	obList.insert(make_pair(_observer->name(), move(_observer)));
}

unique_ptr<Observer> Observed::removeObserver(const string& _eventName, const string& _observerName)
{
	Events::iterator ev = findCheckedEvent(_eventName);
	ObserverList& obList = ev->second;
	ObserverList::iterator obs = obList.find(_observerName);
	if (obs == obList.end())
		throw Exception("Наблюдатель \"" + _observerName + "\" для событии \"" + _eventName + "\" не сущемтвует");
	unique_ptr<Observer> tmp = move(obs->second);
	obList.erase(obs);
	return tmp;
}

void Observed::raiseEvent(const string& _eventName, shared_ptr<EventData> _eventData) const
{
	Events::const_iterator ev = findCheckedEvent(_eventName);
	const ObserverList& obList = ev->second;
	for (ObserverList::const_iterator it = obList.begin(); it != obList.end(); it++)
		it->second->notify(_eventData);
}

void Observed::registerEvent(const string& _eventName)
{
	Events::iterator it = events_.find(_eventName);
	if (it != events_.end())
		throw Exception("Событие \"" + _eventName + "\" уже регистрирована");
	events_[_eventName] = ObserverList{};
}

