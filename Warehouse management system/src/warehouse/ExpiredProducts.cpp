#include "ExpiredProducts.h"

using std::string;
using std::to_string;
using std::vector;
using std::dynamic_pointer_cast;

const string ExpiredProducts::ExpiredPrdUpdate = "ExpiredProductsUpdate";

ExpiredProducts & ExpiredProducts::Instance()
{
	static ExpiredProducts instance;
	return instance;
}

void ExpiredProducts::addExpiredBoxes(const vector<BoxPtr>& _boxes, bool _raise)
{
	for (const auto& ptr : _boxes)
	{
		sum_ += ptr->price();
		repos_[ptr->describe()]++;
	}
	if (_raise)
		raiseEvent(ExpiredPrdUpdate, nullptr);
}

ExpiredProducts::View ExpiredProducts::getLineInf(int _count) const
{
	View res;
	if (_count <= 0 || _count > repos_.size()) _count = repos_.size();
	res.resize(_count + 1);
	size_t i = 0;
	res[i++] = { "Упаковка", "Кол." };
	for (Repos::const_iterator it = repos_.begin(); i < _count + 1; it++)
		res[i++] = { it->first, to_string(it->second) };
	return res;
}

double ExpiredProducts::summary() const
{
	return sum_;
}


ExpiredProducts::ExpiredProducts() :
	sum_(0.0)
{
	registerEvent(ExpiredPrdUpdate);
}

ExpiredProducts::~ExpiredProducts()
{
}
