/* ����� Racks (�����)����������� ����� ��  Elements , ������� ������ ������������ ��� �������� -- 
���������� ������  Box. ���������� \verb | Racks | ����� ������������ ������(maxSize_ ), 
����������� ������(minSize_) - ����� ��� ���� ���������� ��������, ��������� ������ -- ���� �� 
�������� ������ ��� ���(state_, enum RackState { NoWaitingOrder, WaitingOrder }; ) � �.�.���� �������������
�����  Warehouse, ��� ��� � �������� ��� �������� � ������� ���������� ����� ��������� ������ ��������
Warehouse. ��� ����������� ������ ���������� ���������� � �������� ���� ����� getInfLine.

����� Warehouse ����������� �� ������ Container, � ���� �������� ������ ���������� Racks.
����� �������������� ����� �������� ����� registerElement, ��� ��� ���� ������� ����� 
���� ����������� ���� �� ������. ���� ����������� ��� ������ ������ Warehouse ������ ��
��� ��������� ������ ��� ������� ��� �� ���� �������, ��� ������ ����� ������� ����� 
(�� ������� ������ � � ������� ������������� �� Container.

registerElement -- ������������ ����� (��������� Racks)
addBox -- ��������� ��������
receiveDelivery -- �������� �������� �� ����������
setRackState -- ������������� ������ ����� (NoWaitingOrder ��� WaitingOrder)
handleStoreOrder -- ������������ ����� �� �������� (���������� ������� SoreOrders, ����� ������ �����).
setDiscount -- ������������� ������
generateDiscount -- ���������� ������ �� ������������� ���������� (���������� ������� Dsicounts, 
					����� ������ �����)
controlDecrease -- �������� ����� ��������� (���������� ������� Warehouse Orders � ����� ��������
				   CargoWarehouseRepos, ����� ������� �����)
controlOverdue -- �������� ������������ ��������� (���������� ����� �������� ExpiredProducts)
setSaleSumm -- ��������� ����� ��������� ���������
getInfLine -- ���������� � ������
getRackInfLine -- ���������� � ���������� �����
InfForStores -- ���������� ��� ���������
summary -- ����� ����� ����������� � ����������� ���������
initCapital -- ����� ��������� ��� ������ ������������� ���������
salesSum -- ����� ��������� ���������
remaindSum -- ����� ��������� �� ������ ������ (����������� ����� ��� �������������� �� �� ������������ ������)
deliverySum -- ����� ����������� �������
damagesSum -- ����� �������
fullSize -- ���������� �� ������ �����
��� � ����� ����������� ����� �� Container ��� ��������� ������ ��������� ����� �����������
������ �������.
*/

#ifndef WAREHOUSE_H
#define WAREHOUSE_H


#include "../utilites/Container.h"
#include "../management/Orders.h"
#include "../management/Discounts.h"

#include "Box.h"

#include <deque>

class Warehouse;
class UserInterface;



enum RackState { NoWaitingOrder, WaitingOrder };

class RegRackData : public EventData
{
public:
	RegRackData(const std::string&);
	~RegRackData();
	int id() const;
	int size() const;
	int minSize() const;
	int maxSize() const;

	RackState state() const;
private:
	int id_;
	int size_;
	int minSize_;
	int maxSize_;
	RackState state_;
};

class Racks : public Elements
{
public:
	friend class Warehouse;
	Racks(int _id, int _size, int _minSize, int _maxSize);
	~Racks() { }
	int size() const;
	int minSize() const;
	int maxSize() const;
	std::deque<BoxPtr> boxes() const;
	double summary() const;
	RackState state() const;
	View getInfLine(int _count = 0);
private:
	using Elements::id_;
	std::string describe_;
	int minSize_;
	int maxSize_;
	std::deque<BoxPtr> boxes_;
	RackState state_;
};
using RacksPtr = std::shared_ptr<Racks>;



class Warehouse : public Container
{
public:
	enum Operation { Delivery, RetCargo };
	static Warehouse& Instance();
	void registerElement(ElementsPtr, bool _raise = false) override;
	
	void addBox(BoxPtr, Operation, bool _raise = false);
	void receiveDelivery(const std::vector<BoxPtr>&,  bool _raise = false);
	void setRackState(int _id, RackState, bool _raise = false);
	std::vector<BoxPtr> handleStoreOrder(const StoreOrdersPtr, bool _raise = false);
	void setDiscount(const DiscountPtr&, bool _raise = false);
	
	void generateDiscount(int _shelfTime, double _precent);
	void controlDecrease(bool _raise = false);
	void controlOverdue(bool _raise = false);
	void setSaleSumm(double _summ, bool _raise = false);
	
	View getInfLine(int _count = 0) const;
	View getRackInfLine(int _id, int _count = 0) const;
	std::map<int, double> InfForStores() const;
	
	double summary() const;
	double initCapital() const;
	double salesSum() const;
	
	double remaindSum() const;
	double deliverySum() const;
	double damagesSum() const;
	int fullSize() const;
private:
	Warehouse();
	~Warehouse();

	double initCapital_;
	double deliverySum_;
	double overdueSum_;
	double salesSum_;
	double discountSum_;


	Warehouse(const Warehouse&) = delete;
	Warehouse(Warehouse&&) = delete;
	Warehouse& operator= (const Warehouse&) = delete;
	Warehouse& operator= (Warehouse&&) = delete;
};

void makeWarehouse(UserInterface*);


#endif // !WAREHOUSE_H

