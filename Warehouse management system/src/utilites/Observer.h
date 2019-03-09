/*
Observer --- это абстрактный класс --- наблюдатель. Как аргумент для конструктора 
принимает название наблюдателя. Имеет чисто виртуальный
метод notify(данные события) который переопределяют производные классы.
Задача класса принимать данные события и обрабатывать их
*/

#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include <memory>


class EventData;

class Observer
{
public:
	Observer(const std::string& name) : name_(name) { }
	virtual ~Observer() { }
	
	std::string name() const { return name_; }
	
	virtual void notify(std::shared_ptr<EventData>) = 0;

private:
	std::string name_;
};




#endif // !OBSERVER_H
