/*
	����� Timer, ��� � ������ ������ � �������, ������� ����� ����� ���������, 
	�������� ����������  ������ pimpl, � ������ ������ �������� ����������� ��� � ����������� .cpp �����. 
	������� ��� ��� ���� ����� ���������� ������ ������ ��� ����� �� ���������� ������,
	������� ������ ����������.
	����� ������ ������ �������, ����� ��� ������������. ����������� ��� ���������� ������� ������ � ������� �������. ��������������
	��������� ���������.
*/



#ifndef TIMER_H
#define TIMER_H

#include <string>
#include <memory>

class LocTime;

class Timer
{
	struct TimerImpl;
public:
	static Timer& Instance();
	void start();
	void activate();
	void pause();
	LocTime time() const;
	int interval() const;
	int day() const;
	int hour() const;
	void delay(int _hours) const;
private:
	std::unique_ptr<TimerImpl> pimpl_;

	Timer();
	~Timer();

	Timer(const Timer&) = delete;
	Timer(Timer&&) = delete;
	Timer& operator=(const Timer&) = delete;
	Timer& operator=(Timer&&) = delete;
};

class LocTime
{
public:
	LocTime();
	LocTime(int _dd, int _hh);

	LocTime operator+(const LocTime&) const;
	bool operator<(const LocTime&) const;
	bool operator>(const LocTime&) const;
	bool operator==(const LocTime&) const;
	bool operator<=(const LocTime&) const;
	bool operator>=(const LocTime&) const;

	std::string show() const;
	int day() const;
	int hour() const;
private:
	int dd_;
	int hh_;
};

#endif // !TIMER_H

