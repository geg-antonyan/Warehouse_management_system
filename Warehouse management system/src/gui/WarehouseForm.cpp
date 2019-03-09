#include "WarehouseForm.h"
#include "ui_WarehouseForm.h"

#include "../utilites/freeFunc.h"
#include "../warehouse/Warehouse.h"

#include <QMessageBox>

using std::vector;
using std::string;

WarehouseForm::WarehouseForm(QWidget *parent)
	: Form(parent)
{
	ui = new Ui::WarehouseForm();
	ui->setupUi(this);
	update();
	loadFreeBox();
}

WarehouseForm::~WarehouseForm()
{
	delete ui;
}

void WarehouseForm::update()
{
	View view = Warehouse::Instance().getInfLine();
	handleTableWidget(ui->TW, view, vector<int>{ 50, 280, 80, 90, 100});
}

void WarehouseForm::loadFreeBox()
{
	ui->boxesBox->clear();
	vector<string> freeBox = BoxCatalog::Instance().getInfFreeBox();
	for (const auto& ptr : freeBox)
		ui->boxesBox->addItem(ptr.c_str());
}


void WarehouseForm::on_startPB_clicked()
{
	QString cmd = "StartProcess";
	emit sendCommand(cmd);
}

void WarehouseForm::on_add_clicked()
{
	if (ui->maxSizeSB->value() <= 0 || ui->sizeSB->value() == 0 || ui->boxesBox->currentIndex() < 0)
	{
		QMessageBox::warning(this, "Предупреждение", "Пожалуйста заполните поля");
		return;
	}
	string str = ui->boxesBox->itemText(ui->boxesBox->currentIndex()).toStdString();
	str = str.substr(0, str.find(' '));
	QString cmd = "registerRack " + QString::fromStdString(str) + ' ' +  ui->sizeSB->text() +
		' ' + ui->minSizeSB->text() + ' ' + ui->maxSizeSB->text();
	ui->maxSizeSB->setValue(0); ui->minSizeSB->setValue(0); ui->sizeSB->setValue(0);
	emit sendCommand(cmd);
}

void WarehouseForm::on_remove_clicked()
{
	int row = ui->TW->currentRow();
	if (row < 0)
	{
		QMessageBox::warning(this, "Предупреждение", "Пожалуйста выберите продукт для удаления");
		return;
	}
	QString cmd = "removeRack " + ui->TW->item(row, 0)->text();
	emit sendCommand(cmd);
}
