#ifndef DISCOUNTS_H
#define DISCOUNTS_H

#include "../utilites/Container.h"

#include <vector>

class Discount : public Elements
{
	struct DiscountImpl;
	static int Count;
public:
	Discount(int _boxId, std::vector<int> _numbers, double _precent);
	~Discount();

	int boxId() const;
	std::string boxDescribe() const;
	double precent() const;
	std::vector<int> numbers() const;
	int size() const;
	bool empty() const;
	void changePrecent(double _precent);

private:
	std::unique_ptr<DiscountImpl> pimpl_;
};


using DiscountPtr = std::shared_ptr<Discount>;

class DiscountChangeData : public EventData
{
public:
	DiscountChangeData(const std::string&);
	~DiscountChangeData();
	int id() const;
	double precent() const;
private:
	int id_;
	double precent_;
};

class DiscountsRepos : public Container
{
public:
	static DiscountsRepos& Instance();
	std::vector< std::vector<std::string> > DiscountsRepos::getInfLine(int _count = 0) const;
	double changeDiscount(int _id, double _precent, bool _raise = true);
	void addSumm(double _summ, bool _raise = false);
	double summary() const;
private:

	double summary_;

	DiscountsRepos();
	~DiscountsRepos();
	DiscountsRepos(const DiscountsRepos&) = delete;
	DiscountsRepos(DiscountsRepos&&) = delete;
	DiscountsRepos operator=(const DiscountsRepos&) = delete;
	DiscountsRepos operator=(DiscountsRepos&&) = delete;
};



#endif // !DISCOUNTS_H


