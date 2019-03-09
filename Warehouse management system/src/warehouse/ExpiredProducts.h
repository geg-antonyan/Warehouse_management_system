/*
����� ExpiredProducts �������� ��������� � ����������� �� Observe, ���� ������������� ������� ��������
�������� ��������� ���������(��������). ����� �� ������ � ���� ���� ������� � ������ �� �������� � ����������.
��� ��� ��������� � ���� ��������� ��� � ��� �������� ������ ����� ����������� ������� ������� ��� 
��������� ���������. �������� ������ ����������� ����.

addExpiredBoxes -- ��������� �������� (������������� ������������)
getLineInf -- ���������� ��� ������������
summary -- ����� ����� �������� ���������
*/


#ifndef EXPIRED_PRODUCTS_H
#define EXPIRED_PRODUCTS_H

#include "../utilites/Observed.h"
#include "../warehouse/Box.h"

#include <vector>
#include <map>

class ExpiredProducts : protected Observed
{
	using View = std::vector< std::vector<std::string> >;
	using Repos = std::map<std::string, int>;
public:
	using Observed::addObserver;
	using Observed::removeObserver;

	static const std::string ExpiredPrdUpdate;
	static	ExpiredProducts& Instance();
	void addExpiredBoxes(const std::vector<BoxPtr>&, bool _raise = false);
	View getLineInf(int _count = 0) const;
	double summary() const;
private:
	ExpiredProducts();
	~ExpiredProducts();
	Repos repos_;
	double sum_;
	ExpiredProducts(const ExpiredProducts&) = delete;
	ExpiredProducts(ExpiredProducts&&) = delete;
	ExpiredProducts& operator=(const ExpiredProducts&) = delete;
	ExpiredProducts& operator=(ExpiredProducts&&) = delete;
};


#endif // !EXPIRED_PRODUCTS_H
