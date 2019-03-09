#include "Timer.h"

#include <ctime>
#include <chrono>
#include <thread>


using std::thread;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;
using std::string;
using std::to_string;

struct Timer::TimerImpl
{
	int interval_ = 1000;
	int pauseTime_;
	int pause_;

	int pauseHour_;
	int pauseDay_;

	int startTime_;

	bool pauseState_;
};

Timer::Timer() : pimpl_(new TimerImpl)
{
	pimpl_->pauseTime_ = 0;
	pimpl_->pause_ = 0;
	pimpl_->startTime_ = 0;
	pimpl_->pauseDay_ = 0;
	pimpl_->pauseHour_ = 0;
	pimpl_->pauseState_ = true;
}

Timer::~Timer()
{
}

Timer& Timer::Instance()
{
	static Timer instance;
	return instance;
}

void Timer::start()
{
	pimpl_->startTime_ = (int)clock();
	pimpl_->pauseState_ = false;
}

void Timer::activate()
{
	int inter = (int)clock() - pimpl_->pause_;
	pimpl_->pauseTime_ += inter;
	pimpl_->pauseState_ = false;
}

void Timer::pause()
{
	pimpl_->pause_ = clock();
	pimpl_->pauseDay_ = ((int)clock() - pimpl_->pauseTime_ - pimpl_->startTime_) / pimpl_->interval_ / 24;
	pimpl_->pauseHour_ = ((int)clock() - pimpl_->pauseTime_ - pimpl_->startTime_) / pimpl_->interval_ % 24;
	pimpl_->pauseState_ = true;
}



LocTime Timer::time() const
{
	return LocTime();
}

int Timer::interval() const
{
	return pimpl_->interval_;
}

int Timer::day() const
{
	if (pimpl_->pauseState_)
		return pimpl_->pauseDay_;
	return ((int)clock() - pimpl_->pauseTime_ - pimpl_->startTime_) / pimpl_->interval_ / 24;
	  
}

int Timer::hour() const
{
	if (pimpl_->pauseState_)
		return pimpl_->pauseHour_;
	return ((int)clock() - pimpl_->pauseTime_ - pimpl_->startTime_) / pimpl_->interval_ % 24;
}

void Timer::delay(int _hours) const
{
	_hours *= pimpl_->interval_;
	if (_hours < 0) return;
	sleep_for(milliseconds(_hours));
}

LocTime::LocTime() :
	dd_(Timer::Instance().day()),
	hh_(Timer::Instance().hour())
{
}

LocTime::LocTime(int _dd, int _hh) :
	dd_(_dd),
	hh_(_hh)
{
}



LocTime LocTime::operator+(const LocTime& time) const
{
	int dd = this->dd_ + time.dd_;
	int hh = this->hh_ + time.hh_;
	if (hh >= 24)
	{
		dd += hh / 24;
		hh %= 24;
	}
	return LocTime(dd, hh);
}

bool LocTime::operator<(const LocTime& _time) const
{
	if (dd_ < _time.dd_) return true;
	else if (dd_ == _time.dd_ && hh_ < _time.hh_) return true;
	return false;
}

bool LocTime::operator>(const LocTime& _time) const
{
	if (dd_ > _time.dd_) return true;
	else if (dd_ == _time.dd_ && hh_ > _time.hh_) return true;
	return false;
}

bool LocTime::operator==(const LocTime& _time) const
{
	return (dd_ == _time.dd_ && hh_ == _time.hh_);
}

bool LocTime::operator<=(const LocTime& _time) const
{
	return (*this < _time || *this == _time);
}

bool LocTime::operator>=(const LocTime& _time) const
{
	return (*this > _time || *this == _time);
}

string LocTime::show() const
{
	string str = to_string(dd_) + ':' + to_string(hh_);
	if (dd_ < 10)
		str = '0' + str;
	if (hh_ < 10)
		str.insert(str.end() - 1, '0');
	return str;
}

int LocTime::day() const
{
	return dd_;
}

int LocTime::hour() const
{
	return hh_;
}
