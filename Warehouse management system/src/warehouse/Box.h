/*
Класс Box -- оптовая упаковка и BoxCatalog -- каталог упаковок аналогично как и продукты, 
наследуются от классов Elementsи Container соответственно. Box хранит в себе указатель 
экземпляра класса Product. Как и Product имеет id для каждого типа упаковки, и еще number, 
для однозначной идентификации каждой упаковки, который начинает отсчет при использовании
конструктора копировании, а id при конструктора. Box также хранит данные о цене, 
о скидке и т.д. Присутствует метод clone для копировании где меняется только number
и дата производства. Частично использует идиому pimpl. Для ед. изм. используется перечисление 
enum Unit { kg = 0, pcs, liter };, так же два контейнера map для представления на русском.
Класс BoxCatalog ничем не отличается от класса ProductCatalog, разве что хранит
указатели экземпляров класса  Box

*/


#ifndef BOX_H
#define BOX_H

#include "Product.h"

#include <unordered_map>

enum Unit { kg = 0, pcs, liter };

static const std::unordered_map<Unit, std::string> Unit_KeyUnit =
{
	std::make_pair(kg, "кг"),
	std::make_pair(pcs, "шт."),
	std::make_pair(liter, "литр")
};

static const std::unordered_map<std::string, Unit> Unit_KeyStr =
{
	std::make_pair("кг", kg),
	std::make_pair("шт.", pcs),
	std::make_pair("литр", liter)
};

class RegBoxData : public EventData
{
public:
	RegBoxData(const std::string&);
	~RegBoxData();

	int prdId() const;
	Unit unit() const;
	int size() const;
	double unitPrice() const;
private:
	int prdId_;
	Unit unit_;
	int size_;
	double unitPrice_;
};

class Box;
using BoxPtr = std::shared_ptr<Box>;

class Box : public Elements
{
	static int Count;
	struct PkgeImpl;
public:
	Box(int _prdId, Unit _unit, int _size, double _unitPrice);
	Box(const Box&);
	~Box();
	
	int number() const;
	int shelfTime() const;
	int size() const;
	
	std::string describe() const;
	std::string prdDescribe() const;
	
	double unitPrice() const;
	double price() const;
	double discount() const;
	
	Unit unit() const;
	
	BoxPtr clone() const;

	void setDiscount(double _precent);

private:
	std::unique_ptr<PkgeImpl> pimpl_;

	Box(Box&&) = delete;
	Box& operator= (const Box&) = delete;
	Box& operator= (Box&&) = delete;
};

class UserInterface;

class BoxCatalog : public Container
{
public:
	static BoxCatalog& Instance();
	BoxPtr makeBox(int _id) const;
	std::vector< std::vector<std::string> > getInfLine(int _count = 0) const;
	std::vector<std::string> getInfFreeBox() const;
private:
	BoxCatalog() {  }
	~BoxCatalog() { }

	BoxCatalog(const BoxCatalog&) = delete;
	BoxCatalog(BoxCatalog&&) = delete;
	BoxCatalog operator=(const BoxCatalog&) = delete;
	BoxCatalog operator=(BoxCatalog&&) = delete;
};

void makeBoxesCatalog(UserInterface* _ui);

#endif // !BOX_H


