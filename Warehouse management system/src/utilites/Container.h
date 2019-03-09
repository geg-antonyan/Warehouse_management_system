#ifndef CONTAINER_H
#define CONTAINER_H

#include "Observed.h"
#include "Elements.h"

#include <thread>
#include <chrono>
#include <mutex>
#include <map>



class Container : protected Observed
{
protected:
	using Repos = std::map<int, ElementsPtr>;
public:
	static const std::string ContainerUpdate;
	virtual ~Container() { }
	using Observed::addObserver;
	using Observed::removeObserver;

	virtual void registerElement(ElementsPtr, bool _raise = false);
	virtual ElementsPtr removeElement(int _id, bool _raise = false);

	ElementsPtr find(int _id) const;
	ElementsPtr topBack(bool _raise = false);

	ElementsPtr popBack(bool _raise = false);
	ElementsPtr popFront(bool _raise = false);
	
	void clear(bool _raise = true);
	
	bool empty() const;
	int size() const;

protected:
	Container();

	Repos repos_;

	mutable std::mutex mtx;

	Repos::iterator hasKey(int _id);
	Repos::const_iterator hasKey(int _id) const;
};





#endif // !CONTAINER_H


