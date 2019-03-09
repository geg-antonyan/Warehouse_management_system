#include "Container.h"

#include "Exception.h"

using std::string;
using std::to_string;
using std::make_shared;
using std::lock_guard;
using std::unique_lock;
using std::mutex;

const string Container::ContainerUpdate = "ContainerUpdate";

void Container::registerElement(ElementsPtr _elem, bool _raise)
{
	mtx.lock();
	Repos::iterator it = repos_.find(_elem->id());
	if (it != repos_.end())
		throw Exception("Елемент с идентификаторным номером \"" + to_string(_elem->id()) + "\" уже находится в каталоге");
	repos_.insert(make_pair(_elem->id(), _elem));
	mtx.unlock();
	if (_raise)
		raiseEvent(ContainerUpdate, nullptr);
}

ElementsPtr Container::removeElement(int _id, bool _raise)
{
	mtx.lock();
	Repos::iterator it = hasKey(_id);
	ElementsPtr tmp = it->second;
	repos_.erase(it);
	mtx.unlock();
	if (_raise)
		raiseEvent(ContainerUpdate, nullptr);
	return tmp;
}

ElementsPtr Container::find(int _id) const
{
	ElementsPtr tmp;
	Repos::const_iterator it = repos_.find(_id);
	if (it != repos_.end())
		tmp = it->second;
	return tmp;
}

ElementsPtr Container::topBack(bool _raise)
{
	ElementsPtr ptr = repos_.rbegin()->second;
	return ptr;
}



ElementsPtr Container::popBack(bool _raise)
{
	if (empty()) throw Exception("Пустой Каталог. не получилось удалять последный элемент");
	ElementsPtr ptr = repos_.rbegin()->second;
	removeElement(ptr->id(), _raise);
	return ptr;
}

ElementsPtr Container::popFront(bool _raise)
{
	if (empty()) throw Exception("Пустой Каталог. не получилось удалять первый элемент");
	ElementsPtr ptr = repos_.begin()->second;
	int id = repos_.begin()->first;
	removeElement(id, _raise);
	return ptr;
}


void Container::clear(bool _raise)
{
	unique_lock<mutex> uLock(mtx);
	if (empty()) return;
	repos_.clear();
	uLock.unlock();
	if (_raise)
		raiseEvent(ContainerUpdate, nullptr);
}

bool Container::empty() const
{
	return repos_.empty();
}

int Container::size() const
{
	return repos_.size();
}

Container::Container()
{
	registerEvent(ContainerUpdate);
}



Container::Repos::iterator Container::hasKey(int _id)
{
	Repos::iterator it = repos_.find(_id);
	if (it == repos_.end())
		throw Exception("Елемент с идентификаторным номером \"" + to_string(_id) + "\" не нейден");
	return it;
}

Container::Repos::const_iterator Container::hasKey(int _id) const
{
	Repos::const_iterator it = repos_.find(_id);
	if (it == repos_.end())
		throw Exception("Ёлемент с идентификаторным номером \"" + to_string(_id) + "\" не нейден");
	return it;
}

