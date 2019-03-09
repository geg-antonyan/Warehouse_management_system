/*
EventData -- ��� ����������� ����� ������� ����� ������ ����������� ����������, 
��� ����������� � ���������� ������������� �� ����. ������������ ��� ��������
"���������" �� ������������ � �����������
*/

#ifndef EVENT_DATA_H
#define EVENT_DATA_H

#include <string>
#include <memory>

class EventData
{
public:
	virtual ~EventData() { }
	
};

using EventDataPtr = std::shared_ptr<EventData>;


class StrData : public EventData
{
public:
	StrData(const std::string&);
	~StrData() { }
	std::string str() const;
private:
	std::string str_;
};

using StrDataPtr = std::shared_ptr<StrData>;

class IdData : public EventData
{
public:
	IdData(const std::string& _data);
	~IdData();

	int id() const;
private:
	int id_;
	bool isId(const std::string& str);
};

using IdDataPtr = std::shared_ptr<IdData>;


#endif // !EVENT_DATA_H
