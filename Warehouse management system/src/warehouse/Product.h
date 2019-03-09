/*
По условием задачи в складе хранятся оптовые упаковки, а заказы приходят по количеству продуктов а не 
количество оптовых упаковок. Пользователь должен иметь возможность для моделировании добавить продукты. 
Для этого мы будем использовать абстрактные классы Elements и Conatainer --- 
class Product : public Elemens и class ProductCatalog : public Container.
Для класса Product будем использовать счетчик. Продукт в себе хранит дата производства, срок годности
и описание продукта. Так как каталог продуктов будут хранится в классе одиночке class ProductCatalog
а в течении программы будут создаваться новые продукты, класс Product имеет метод clone, который с 
помощью конструктора копировании копирует себя, изменяя только дату производства, используя эту возможность с 
помощью makeProduct можно создавать определенные продукты использую идентификатор продукта.
Класс Product частично использует идиому pimpl.
*/


#ifndef PRODUCT_H
#define PRODUCT_H

#include "../utilites/Container.h"
#include <vector>


class RegPrdData : public EventData
{
public:
	RegPrdData(const std::string&);
	~RegPrdData();
	std::string describe() const;
	int lifeTime() const;
private:
	int lifeTime_;
	std::string describe_;
	bool isUnsignedDigit(const std::string& str) const;
};

class Product;

using ProductPtr = std::shared_ptr<Product>;

class Product : public Elements
{
	struct ProductImpl;
	static int Count;
public:
	Product(const std::string _describe, int _lifeTime);
	Product(const Product&);
	~Product();

	std::string describe() const;
	int lifeTime() const;
	int shelfTime() const;
	ProductPtr clone() const;

private:
	std::unique_ptr<ProductImpl> pimpl_;

	Product(Product&&) = delete;
	Product& operator=(const Product&) = delete;
	Product& operator=(Product&&) = delete;
};


class UserInterface;

class ProductCatalog : public Container
{

public:
	static ProductCatalog& Instance();

	ProductPtr makeProduct(int _id) const;
	std::vector< std::vector<std::string> > getInfLine(int _count = 0) const;
	std::vector<std::string> getInfFreePrd() const;

private:
	ProductCatalog() { }
	~ProductCatalog() { }

	ProductCatalog(const ProductCatalog&) = delete;
	ProductCatalog(ProductCatalog&&) = delete;
	ProductCatalog operator=(const ProductCatalog&) = delete;
	ProductCatalog operator=(ProductCatalog&&) = delete;
};


void makeProductCatalog(UserInterface* _ui);



#endif // !PRODUCT_H



