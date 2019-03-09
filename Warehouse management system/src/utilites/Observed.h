/*
Observed --- ��� ����������� �����, ���� ��� ������ ����������� � �� �������� ���������������. 
������ ����������� �� ���� protected ��� ��� � ����������� ���� ��������� � Observed is a, 
����������� ������� ���� ����� ���� ����� � �������� ���������������� ������� ������,
� ������:
	-registerEvent --- �������������� �������
	-addObserver --- ��������� ����������� (���������� Observer) �� ������ �������
	-removeObserver --- ������� �����������
	-raiseEvent --- ������� ������� � �� ������� (EventData)
���� ��� �� ������ findCheckedEvent (���� �� ��� �����������) ��� ������ ������� ���� �� ����� (�������� �������). 
Observed ������  ������� � ������ ������������ ����������� ��� �������. ���������� observed ������������ �������, 
��������� ���������� observer-�� �� ������ ������� � ��� ������������ ������� ��������� ������� � �������, ������� 
�������������� �������������.
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



