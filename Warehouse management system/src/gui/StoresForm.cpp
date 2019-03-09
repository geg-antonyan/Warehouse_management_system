#include "StoresForm.h"
#include "ui_StoresForm.h"

#include "../customers/Stores.h"
#include "../utilites/freeFunc.h"

#include <QMessageBox>

using std::vector;
using std::string;

StoresForm::StoresForm(QWidget *parent)
	: Form(parent)
{
	ui = new Ui::StoresForm();
	ui->setupUi(this);
	
	for (const auto& ptr : StoreType_Str)
		ui->typeBox->addItem(ptr.first.c_str());
	update();
}

StoresForm::~StoresForm()
{
	delete ui;
}

void StoresForm::update()
{
	View view = StoresRepos::Instance().getInfLine();
	handleTableWidget(ui->TW, view, vector<int>{ 50, 210, 200 });
}

void StoresForm::on_add_clicked()
{
	if (ui->storeNameIn->text().isEmpty() || ui->typeBox->currentIndex() < 0)
	{
		QMessageBox::warning(this, "Предупреждение", "Пожалуйста заполните поля");
		return;
	}
	
	QString cmd = "registerStore " + ui->typeBox->itemText(ui->typeBox->currentIndex()) +
		+ ' ' + ui->storeNameIn->text();
	ui->storeNameIn->clear();
	emit sendCommand(cmd);
}

void StoresForm::on_remove_clicked()
{
	int row = ui->TW->currentRow();
	if (row < 0)
	{
		QMessageBox::warning(this, "Предупреждение", "Пожалуйста выберите продукт для удаления");
		return;
	}
	QString cmd = "removeStore " + ui->TW->item(row, 0)->text();
	emit sendCommand(cmd);
}
