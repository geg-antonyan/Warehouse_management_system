/*
�� �������� ������ � ������ �������� ������� ��������, � ������ �������� �� ���������� ��������� � �� 
���������� ������� ��������. ������������ ������ ����� ����������� ��� ������������� �������� ��������. 
��� ����� �� ����� ������������ ����������� ������ Elements � Conatainer --- 
class Product : public Elemens � class ProductCatalog : public Container.
��� ������ Product ����� ������������ �������. ������� � ���� ������ ���� ������������, ���� ��������
� �������� ��������. ��� ��� ������� ��������� ����� �������� � ������ �������� class ProductCatalog
� � ������� ��������� ����� ����������� ����� ��������, ����� Product ����� ����� clone, ������� � 
������� ������������ ����������� �������� ����, ������� ������ ���� ������������, ��������� ��� ����������� � 
������� makeProduct ����� ��������� ������������ �������� ��������� ������������� ��������.
����� Product �������� ���������� ������ pimpl.
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



