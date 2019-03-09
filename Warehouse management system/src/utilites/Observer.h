/*
Observer --- ��� ����������� ����� --- �����������. ��� �������� ��� ������������ 
��������� �������� �����������. ����� ����� �����������
����� notify(������ �������) ������� �������������� ����������� ������.
������ ������ ��������� ������ ������� � ������������ ��
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
