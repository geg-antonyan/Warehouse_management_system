#include "Discounts.h"

#include "../warehouse/Warehouse.h"
#include "../utilites/Exception.h"
#include "../utilites/freeFunc.h"

using std::string;
using std::to_string;
using std::vector;
using std::make_unique;
using std::dynamic_pointer_cast;


struct Discount::DiscountImpl
{
	int boxId_;
	vector<int> numbers_;
	double precent_;
	string boxDescribe_;
};

int Discount::Count = 0;



Discount::Discount(int _boxId, vector<int> _numbers, double _precent)
{
	pimpl_ = make_unique<DiscountImpl>();
	id_ = ++Count;
	pimpl_->boxId_ = _boxId;
	pimpl_->numbers_ = _numbers;
	pimpl_->precent_ = _precent;
	BoxPtr ptr = dynamic_pointer_cast<Box>(BoxCatalog::Instance().find(pimpl_->boxId_));
	if (ptr)
		pimpl_->boxDescribe_ = ptr->describe();
	else pimpl_->boxDescribe_ = "Неизвестная упаковка";
}

Discount::~Discount()
{
}

int Discount::boxId() const
{
	return pimpl_->boxId_;
}

std::string Discount::boxDescribe() const
{
	return pimpl_->boxDescribe_;
}

double Discount::precent() const
{
	return pimpl_->precent_;
}

std::vector<int> Discount::numbers() const
{
	return pimpl_->numbers_;
}

int Discount::size() const
{
	return pimpl_->numbers_.size();
}

bool Discount::empty() const
{
	return pimpl_->numbers_.empty();
}



void Discount::changePrecent(double _precent)
{
	pimpl_->precent_ = _precent;
}


DiscountChangeData::DiscountChangeData(const std::string& _data)
{
	string str = _data;
	string::size_type k =_data.find(' ');
	if (k == string::npos) throw Exception("Некоррктные данные для измеинения процента скидки");
	id_ = atoi(_data.substr(0, k++).c_str());
	if (k == string::npos) throw Exception("Некоррктные данные для измеинения предложения скидки № " + to_string(id_));
	string precentStr = _data.substr(k, _data.length() - k);
	k = precentStr.find(',');
	if (k != string::npos)
		precentStr[k] = '.';
	precent_ = atof(precentStr.c_str());
}

DiscountChangeData::~DiscountChangeData()
{
}

int DiscountChangeData::id() const
{
	return id_;
}

double DiscountChangeData::precent() const
{
	return precent_;
}



DiscountsRepos& DiscountsRepos::Instance()
{
	static DiscountsRepos instance;
	return instance;
}

vector< vector<string> > DiscountsRepos::getInfLine(int _count) const
{
	vector< vector<string> > res;
	if (_count <= 0 || _count > repos_.size()) _count = repos_.size();
	res.resize(_count + 1);
	size_t i = 0;
	res[i] = { "ID", "Упаковка", "Кол.", "Скидка %" };
	for (Repos::const_reverse_iterator it = repos_.rbegin(); i < _count; it++)
	{
		DiscountPtr discount = dynamic_pointer_cast<Discount>(it->second);
		res[++i] =
		{
			to_string(discount->id()), discount->boxDescribe(), 
			to_string(discount->size()), treatMoney(to_string(discount->precent()))
		};
	}
	return res;
}

double DiscountsRepos::changeDiscount(int _id, double _precent, bool _raise)
{
	Repos::iterator it = hasKey(_id);
	DiscountPtr discount = dynamic_pointer_cast<Discount>(it->second);
	double oldprecent = discount->precent();
	discount->changePrecent(_precent);
	if (_raise)
		raiseEvent(ContainerUpdate, nullptr);
	return oldprecent;
}

void DiscountsRepos::addSumm(double _summ, bool _raise)
{
	summary_ += _summ;
	if (_raise)
		raiseEvent(ContainerUpdate, nullptr);
}

double DiscountsRepos::summary() const
{
	return summary_;
}





DiscountsRepos::DiscountsRepos() :
	summary_(0.0)
{

}

DiscountsRepos::~DiscountsRepos()
{
}

