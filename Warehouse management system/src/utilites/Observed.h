/*
Observed --- это абстрактный класс, хотя все методы реализованы и не подлежат переопределению. 
Классы наследуются от него protected так как у наследников нету отношении с Observed is a, 
производным классам надо всего лишь иметь в арсенале функциональность данного класса,
а именно:
	-registerEvent --- регистрировать событие
	-addObserver --- добавлять наблюдателя (конкретный Observer) на нужное событие
	-removeObserver --- удалять наблюдателя
	-raiseEvent --- поднять событие с ее данными (EventData)
Есть так же методы findCheckedEvent (один из них константный) для поиска нужного узла по ключу (название событии). 
Observed хранит  события и список наблюдателей наблюдающих эти событие. Конкретный observed регистрирует события, 
добавляет конкретных observer-ов на нужные событие и при определенных случаях поднимает события с данными, которые 
обрабатываются наблюдателями.
*/

#ifndef OBSERVED_H
#define OBSERVED_H

#include "EventData.h"
#include "Observer.h"

#include <unordered_map>
#include <string>
#include <memory>
#include <vector>

using View = std::vector< std::vector<std::string> >;

class Observed
{
public:
	Observed() { }
	
	void addObserver(const std::string& eventName, std::unique_ptr<Observer>);
	std::unique_ptr<Observer> removeObserver(const std::string& eventName, const std::string& observerName);

protected:
    void raiseEvent(const std::string& eventName, std::shared_ptr<EventData>) const;
	void registerEvent(const std::string& eventName);
	virtual ~Observed() { }

private:
	using ObserverList = std::unordered_map<std::string, std::unique_ptr<Observer>>;
	using Events = std::unordered_map<std::string, ObserverList>;

	Events events_;

	Events::iterator findCheckedEvent(const std::string& eventName);
	Events::const_iterator findCheckedEvent(const std::string& eventName) const;
};


#endif // !OBSERVED_H



