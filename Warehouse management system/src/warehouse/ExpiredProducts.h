/*
 ласс ExpiredProducts €вл€етс€ одиночкой и производной от Observe, целю использовании которой €вл€етс€
хранение списанных продуктов(упаковок).  ласс не хранит в себе сами объекты а только их описании и количество.
“ак как выступает в роли хранилище как и все подобные классы имеет возможность подн€ть событи€ при 
изменении состо€нии. ќсновные методы перечислены ниже.

addExpiredBoxes -- ƒобавл€ет продукты (подразумевает просроченные)
getLineInf -- информаци€ дл€ пользовател€
summary -- обща€ сумма хранимых продуктов
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
