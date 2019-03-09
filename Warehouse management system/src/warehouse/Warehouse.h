/* Класс Racks (полка)производный класс от  Elements , который хранит определенный вид упаковки -- 
экземпляры класса  Box. Экземпляры \verb | Racks | имеют максимальный размер(maxSize_ ), 
минимальный размер(minSize_) - когда уже надо заказывать продукты, состояние заказа -- ждет ли 
поставки заказа или нет(state_, enum RackState { NoWaitingOrder, WaitingOrder }; ) и т.д.Есть дружественный
класс  Warehouse, так как в основном все действия с полками происходят через интерфейс класса одиночке
Warehouse. Для отображении своего содержания использует в арсенале есть метод getInfLine.

Класс Warehouse наследуется от класса Container, в роли элемента хранит экземпляры Racks.
Класс переопределяет метод базового класс registerElement, так как надо считать сумму 
если добавленный полк не пустой. Ниже перечислены все методы класса Warehouse многие из
них использую классы про которых еще не было сказано, эти классы будут описаны позже 
(не следует забыть и о методах наследованных от Container.

registerElement -- регистрирует полку (экземпляр Racks)
addBox -- добавляет упаковку
receiveDelivery -- получает упаковки от поставщика
setRackState -- устанавливает статус полки (NoWaitingOrder или WaitingOrder)
handleStoreOrder -- обрабатывает заказ от магазина (использует объекты SoreOrders, будет описан позже).
setDiscount -- устанавливает скидку
generateDiscount -- генерирует скидку по установленным параметрам (использует объекты Dsicounts, 
					будет описан позже)
controlDecrease -- контроль убыль продуктов (использует объекты Warehouse Orders и класс одиночка
				   CargoWarehouseRepos, будут описаны позже)
controlOverdue -- контроль просроченных продуктов (использует класс одиночку ExpiredProducts)
setSaleSumm -- добавляет сумму проданных продуктов
getInfLine -- информация о складе
getRackInfLine -- информация о конкретном полке
InfForStores -- информация для магазинов
summary -- общая сумма поступающих и изначальных продуктов
initCapital -- сумма продуктов при начале моделировании программы
salesSum -- сумма проданных продуктов
remaindSum -- сумма продуктов на данный момент (учитывается сумма уже приготовленных но не отправленных грузов)
deliverySum -- сумма поступивших товаров
damagesSum -- сумма убытков
fullSize -- количество не пустых полок
Как и любой производный класс от Container при изменении своего состоянии имеет возможность
поднят событие.
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

