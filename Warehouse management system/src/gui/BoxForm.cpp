#include "BoxForm.h"
#include "ui_BoxForm.h"

#include "../warehouse/Box.h"
#include "../utilites/freeFunc.h"

#include <vector>
#include <string>

#include <QMessageBox>

using std::vector;
using std::string;

BoxForm::BoxForm(QWidget *parent)
	: Form(parent)
{
	ui = new Ui::BoxForm();
	ui->setupUi(this);
	loadUnit();
	update();
}

BoxForm::~BoxForm()
{
	delete ui;
}

void BoxForm::update()
{
	loadFreePrd();
	View view = BoxCatalog::Instance().getInfLine();
	handleTableWidget(ui->TW, view, vector<int>{ 50, 280, 70, 70, 110, 160 });
}



void BoxForm::on_add_clicked()
{
	if (ui->productBox->currentIndex() < 0 || ui->sizeSB->value() == 0 || ui->priceSB->value() == 0.0)
	{
		QMessageBox::warning(this, "Предупреждение", "Пожалуйста заполните поля");
		return;
	}
	string str = ui->productBox->itemText(ui->productBox->currentIndex()).toStdString();
	str = str.substr(0, str.find(' '));
	QString cmd = "registerBox " + QString::fromStdString(str) + ' ' +
		ui->unitBox->itemText(ui->unitBox->currentIndex()) + ' ' + ui->sizeSB->text() + ' ' + ui->priceSB->text();
	ui->sizeSB->setValue(0); ui->priceSB->setValue(0.0);
	emit sendCommand(cmd);
}

void BoxForm::on_remove_clicked()
{
	int row = ui->TW->currentRow();
	if (row < 0)
	{
		QMessageBox::warning(this, "Предупреждение", "Пожалуйста выберите Упаковку для удаления");
		return;
	}
	QString cmd = "removeBox " + ui->TW->item(row, 0)->text();
	emit sendCommand(cmd);
}

void BoxForm::loadUnit()
{
	for (const auto& ptr : Unit_KeyStr)
		ui->unitBox->addItem(ptr.first.c_str());
}

void BoxForm::loadFreePrd()
{
	ui->productBox->clear();
	vector<string> freePrd = ProductCatalog::Instance().getInfFreePrd();
	for (const auto& ptr : freePrd)
		ui->productBox->addItem(ptr.c_str());
}
