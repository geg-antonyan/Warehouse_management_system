#include "Gui.h"

#include "ProductForm.h"
#include "BoxForm.h"
#include "StoresForm.h"
#include "WarehouseForm.h"

#include <QDebug>
#include <QMessageBox>

#include <memory>

#include "../customers/Stores.h"

#include "../utilites/Timer.h"
#include "../utilites/freeFunc.h"

#include "../warehouse/Warehouse.h"
#include "../warehouse/ExpiredProducts.h"

#include "../management/Process.h"
#include "../management/Orders.h"
#include "../management/Cargo.h"
#include "../management/Discounts.h"



using std::vector;
using std::string;
using std::to_string;
using std::shared_ptr;
using std::make_shared;
using std::dynamic_pointer_cast;
using std::map;

Gui::Gui(QWidget *parent)
	: QMainWindow(parent),
	winIndex_(0),
	table(new QTableWidget),
	startProcess(false)
{
	
	ui.setupUi(this);
	ui.btnSoldProducts->hide();
	ProductForm* prdForm = new ProductForm;
	BoxForm* boxForm = new BoxForm;
	StoresForm* storesForm = new StoresForm;
	WarehouseForm* warehouseForm = new WarehouseForm;
	
	windows_ = vector<Form*>{ prdForm, boxForm, storesForm, warehouseForm };

	for (const auto ptr : windows_)
	{
		connect(ptr, SIGNAL(next()), this, SLOT(nextWindow()));
		connect(ptr, SIGNAL(back()), this, SLOT(prewWindow()));
		connect(ptr, SIGNAL(sendCommand(QString&)), this, SLOT(execCommand(QString&)));
	}
	connect(this, SIGNAL(signalProcess()),  SLOT(StartProcess()));
	connect(this, SIGNAL(signalError(QString)), this, SLOT(showErrorMessage(QString)));
	connect(this, SIGNAL(signalPost(QString)), SLOT(showPostMessage(QString)));
	connect(this, SIGNAL(signalTick()), SLOT(changeTime()));
	
	// Изменение в Хранилищах
	connect(this, SIGNAL(signalPrdCatalog()), SLOT(UpdatePrdCatalog()));
	connect(this, SIGNAL(signalBoxCatalog()), SLOT(UpdateBoxCatalog()));
	connect(this, SIGNAL(signalStoreRepos()), SLOT(UpdateStoreRepos()));
	connect(this, SIGNAL(signalWarehouse()), SLOT(UpdateWarehouse()));

	connect(this, SIGNAL(signalStoreOrder()), SLOT(UpdateStoreOrdRepos()));
	connect(this, SIGNAL(signalCargoStore()), SLOT(UpdateCargoStoresRepos()));
	connect(this, SIGNAL(signaleExpiredPrd()), SLOT(UpdateExpiredPrd()));
	connect(this, SIGNAL(signalDiscountsRepos()), SLOT(UpdateDiscountsRepos()));
	connect(this, SIGNAL(signalCargoWarehouse()), SLOT(UpdateCargoWarehouseRepos()));
}

Gui::~Gui()
{
	delete table;
}

void Gui::execute()
{
	dynamic_cast<BoxForm*>(windows_[1])->loadFreePrd();
	dynamic_cast<WarehouseForm*>(windows_[3])->loadFreeBox();
	for (auto ptr : windows_)
		ptr->update();
	windows_[winIndex_]->show();
}


void Gui::closeEvent(QCloseEvent* _event)
{
	execCommand(QString("stopProcess"));
	on_btnSoldProducts_clicked();
	Timer::Instance().delay(1); // для безоапасности, чтобы потоки успели отключится
}

void Gui::on_btnActivateProcess_clicked()
{
	execCommand(QString("ActivateProcess"));
}

void Gui::on_btnDeactivateProcess_clicked()
{
	execCommand(QString("DeactivateProcess"));
}

void Gui::on_btnStopGenOrders_clicked()
{
	int res = QMessageBox::question(this, "Уведамление",
		"Вы действительно хотитет остановить генерацию заказов? После остановки активировать уже не получится",
		"Нет", "Да");
	if (res)
		execCommand(QString("stopGenOrders"));
}

void Gui::on_btnStopProcess_clicked()
{
	int res = QMessageBox::question(this, "Уведамление",
		"Вы действительно хотитет остановить процесс? После остановки активировать уже не получится",
		"Нет", "Да");
	if (res)
	{
		execCommand(QString("stopProcess"));
		ui.btnSoldProducts->show();
	}	
}

void Gui::on_btnSoldProducts_clicked()
{
	View view = StoresRepos::Instance().infProductsSold();
	table->setWindowTitle("Количество проданных таваров");
	handleTableWidget(table, view, vector<int>{250, 110});
	table->setMinimumWidth(380);
	table->setMinimumHeight(700);
	table->show();
}

void Gui::on_btnStoreOrdBrowse_clicked()
{
	int row = ui.twOredersStores->currentRow();
	if (row < 0) return;
	int id = ui.twOredersStores->item(row, 0)->text().toInt();
	StoreOrdersPtr order = dynamic_pointer_cast<StoreOrders>(StoreOrdersRepos::Instance().find(id));
	if (!order) return;
	View view = order->getLineInf();
	table->setWindowTitle("Заказ № " + QString::number(order->id()));
	handleTableWidget(table, view, vector<int>{200, 100, 100});
	table->setMinimumWidth(435);
	table->setMinimumHeight(300);
	table->show();
}

void Gui::on_btnCargoStoreBrowse_clicked()
{
	int row = ui.twCargoStores->currentRow();
	if (row < 0) return;
	int id = ui.twCargoStores->item(row, 0)->text().toInt();
	CargoStoresPtr cargo = dynamic_pointer_cast<CargoStores>(CargoStoresRepos::Instance().find(id));
	if (!cargo) return;
	View view = cargo->getInfLine();
	table->setWindowTitle("Груз № " + QString::number(cargo->id()));
	handleTableWidget(table, view, vector<int>{300, 100});
	table->setMinimumWidth(435);
	table->setMinimumHeight(300);
	table->show();
}

void Gui::on_btnCargoWarehouseBrowse_clicked()
{
	int row = ui.twCargoWarehouse->currentRow();
	if (row < 0) return;
	int id = ui.twCargoWarehouse->item(row, 0)->text().toInt();
	CargoWarehousePtr cargo = dynamic_pointer_cast<CargoWarehouse>(CargoWarehouseRepos::Instance().find(id));
	if (!cargo) return;
	View view = cargo->getInfLine();
	table->setWindowTitle("Заказ на поставку № " + QString::number(cargo->id()));
	handleTableWidget(table, view, vector<int>{300, 100});
	table->setMinimumWidth(435);
	table->setMinimumHeight(300);
	table->show();
}

void Gui::on_btnRackBrowse_clicked()
{
	int row = ui.twWarehouse->currentRow();
	if (row < 0) return;
	int id = ui.twWarehouse->item(row, 0)->text().toInt();
	View view = Warehouse::Instance().getRackInfLine(id);
	table->setWindowTitle("Упаковка № " + QString::number(id));
	handleTableWidget(table, view, vector<int>{1, 170, 80, 80, 100, 80, 120, 100});
	table->setMinimumWidth(850);
	table->setMinimumHeight(700);
	table->show();
}

void Gui::on_btnExecDiscount_clicked()
{
	int row = ui.twDiscount->currentRow();
	if (row < 0) return;
	QString id = ui.twDiscount->item(row, 0)->text();
	execCommand(QString("discountExec " + id));
}

void Gui::on_btnRemoveDiscount_clicked()
{
	int row = ui.twDiscount->currentRow();
	if (row < 0) return;
	QString id = ui.twDiscount->item(row, 0)->text();
	execCommand(QString("discountRemove " + id));
}

void Gui::on_btnChangeDisclount_clicked()
{
	int row = ui.twDiscount->currentRow();
	if (row < 0)
	{
		QMessageBox::warning(this, "Пердупреждение", "Выберите предложение скидки чтобы ее изменить");
		return;
	}
	if (ui.dsbPrecent->value() == 0.0)
	{
		QMessageBox::warning(this, "Пердупреждение", "Вводите процент больше нулья");
		return;
	}
	QString id = ui.twDiscount->item(row, 0)->text();
	execCommand(QString("changeDiscount " + id + ' ' + ui.dsbPrecent->text()));
}

void Gui::on_btnRemoveCargoStore_clicked()
{
	int row = ui.twCargoStores->currentRow();
	if (row < 0) return;
	QString id = ui.twCargoStores->item(row, 0)->text();
	execCommand(QString("removeCargoStore " + id));
}

void Gui::on_btnRemoveCargoWarehouse_clicked()
{
	int row = ui.twCargoWarehouse->currentRow();
	if (row < 0) return;
	QString id = ui.twCargoWarehouse->item(row, 0)->text();
	execCommand(QString("removeCargoWarehouse " + id));
}

void Gui::on_btnConfCargoStore_clicked()
{
	int row = ui.twCargoStores->currentRow();
	if (row < 0) return;
	QString id = ui.twCargoStores->item(row, 0)->text();
	execCommand(QString("confirmCargoStore " + id));
}

void Gui::on_btnConfCargoWarehouse_clicked()
{
	int row = ui.twCargoWarehouse->currentRow();
	if (row < 0) return;
	QString id = ui.twCargoWarehouse->item(row, 0)->text();
	execCommand(QString("confirmCargoWarehouse " + id));
}



void Gui::nextWindow()
{
	windows_[winIndex_++]->close();
	if (winIndex_ < 0 || winIndex_ >= windows_.size())
		return;
	windows_[winIndex_]->show();
}

void Gui::prewWindow()
{
	windows_[winIndex_--]->close();
	if (winIndex_ < 0 || winIndex_ >= windows_.size())
		return;
	windows_[winIndex_]->show();
}


void Gui::execCommand(QString& _cmd)
{
	raiseEvent(CommandEntered, make_shared<CommandData>(_cmd.toStdString()));
}



void Gui::showErrorMessage(QString m)
{
	QMessageBox::critical(this, "Oшибка", m);
}

void Gui::showPostMessage(QString m)
{
	ui.statusBar->showMessage(m, 5000);
	//QMessageBox::information(this, "Уведомление", m);
}

void Gui::changeTime()
{
	ui.lcdTime->display(LocTime().show().c_str());
}

void Gui::UpdatePrdCatalog()
{
	windows_[0]->update();
	dynamic_cast<BoxForm*>(windows_[1])->loadFreePrd();
}

void Gui::UpdateBoxCatalog()
{
	
	windows_[1]->update();
	dynamic_cast<WarehouseForm*>(windows_[3])->loadFreeBox();
	
}

void Gui::UpdateStoreRepos()
{
	windows_[2]->update();
} 

void Gui::UpdateWarehouse()
{

		windows_[3]->update();
		dynamic_cast<WarehouseForm*>(windows_[3])->loadFreeBox();

		View view = Warehouse::Instance().getInfLine();
		handleTableWidget(ui.twWarehouse, view, vector<int>{ 50, 200, 60, 85, 85 });
		ui.lcdBalance->display(treatMoney(to_string(Warehouse::Instance().remaindSum())).c_str());
		ui.lcdSale->display(treatMoney(to_string(Warehouse::Instance().salesSum())).c_str());
		ui.lcdSummary->display(treatMoney(to_string(Warehouse::Instance().summary())).c_str());
		ui.lcdDamages->display(treatMoney(to_string(Warehouse::Instance().damagesSum())).c_str());
		ui.lcdDelivered->display(treatMoney(to_string(Warehouse::Instance().deliverySum())).c_str());
}

void Gui::UpdateStoreOrdRepos()
{
	View view = StoreOrdersRepos::Instance().getInfLine();
	handleTableWidget(ui.twOredersStores, view, vector<int>{1, 110, 125});
}

void Gui::UpdateCargoStoresRepos()
{
	View view = CargoStoresRepos::Instance().getInfLine();
	handleTableWidget(ui.twCargoStores, view, vector<int>{1, 80, 135, 100});
	ui.lcdCargoBalance->display(treatMoney(to_string(CargoStoresRepos::Instance().summary())).c_str());
}

void Gui::UpdateExpiredPrd()
{
	View view = ExpiredProducts::Instance().getLineInf();
	handleTableWidget(ui.twExpiredPrd, view, vector<int>{180, 70});
	ui.lcdExpiredSum->display(treatMoney(to_string(ExpiredProducts::Instance().summary())).c_str());
}

void Gui::UpdateDiscountsRepos()
{
	View view = DiscountsRepos::Instance().getInfLine();
	handleTableWidget(ui.twDiscount, view, vector<int>{1, 150,50,80});
	ui.lcdDiscountSum->display(treatMoney(to_string(DiscountsRepos::Instance().summary())).c_str());
}

void Gui::UpdateCargoWarehouseRepos()
{
	View view = CargoWarehouseRepos::Instance().getInfLine();
	handleTableWidget(ui.twCargoWarehouse, view, vector<int>{1, 110, 130, 100});
}

void Gui::StartProcess()
{
	windows_[winIndex_]->close();
	this->show();
	View view = Warehouse::Instance().getInfLine();
	handleTableWidget(ui.twWarehouse, view, vector<int>{ 50, 200, 60, 85, 85 });
	ui.lcdIntiCapital->display(treatMoney(to_string(Warehouse::Instance().initCapital())).c_str());
	ui.lcdBalance->display(treatMoney(to_string(Warehouse::Instance().remaindSum())).c_str());
}

void Gui::errorMessage(const std::string& m)
{
	emit signalError(QString::fromStdString(m));
	qDebug() << m.c_str();
}

void Gui::postMessage(const std::string& m)
{
	emit signalPost(QString::fromStdString(m));
	qDebug() << m.c_str();
}

void Gui::PrdCatalogUpdate()
{
	emit signalPrdCatalog();
}

void Gui::BoxCatalogUpdate()
{
	emit signalBoxCatalog();
}

void Gui::StoresReposUpdate()
{
	emit signalStoreRepos();
}

void Gui::WarehouseUpdate()
{
	emit signalWarehouse();
}

void Gui::StoreOrdersReposUpdate()
{
	emit signalStoreOrder();
}

void Gui::CargoStoreReposUpdate()
{
	emit signalCargoStore();
}

void Gui::ExpieredPrdUpdate()
{
	emit signaleExpiredPrd();
}

void Gui::DiscountsReposUpdate()
{
	emit signalDiscountsRepos();
}

void Gui::CargoWarehouseReposUpdate()
{
	emit signalCargoWarehouse();
}


void Gui::tick()
{
	emit signalTick();
	
}

void Gui::processStart()
{
	emit signalProcess();
}

