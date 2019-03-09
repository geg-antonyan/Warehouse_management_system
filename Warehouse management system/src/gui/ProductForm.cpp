#include "ProductForm.h"
#include "ui_ProductForm.h"

#include "../warehouse/Warehouse.h"
#include "../utilites/freeFunc.h"


#include <QMessageBox>

using std::vector;

ProductForm::ProductForm(QWidget *parent)
	: Form(parent)
{
	ui = new Ui::ProductForm();
	ui->setupUi(this);
}

ProductForm::~ProductForm()
{
	delete ui;
}

void ProductForm::update()
{
	View view = ProductCatalog::Instance().getInfLine();
	handleTableWidget(ui->TW, view, vector<int> { 50, 300 });
}

void ProductForm::on_add_clicked()
{
	if (ui->lifeTimeIn->text().isEmpty() || ui->prdDescribeIn->text().isEmpty())
	{
		QMessageBox::warning(this, "Предупреждение", "Пожалуйста заполните поля");
		return;
	}
	QString cmd = "registerProduct " + ui->lifeTimeIn->text() + ' ' + ui->prdDescribeIn->text();
	ui->lifeTimeIn->clear(); ui->prdDescribeIn->clear();
	emit sendCommand(cmd);
}

void ProductForm::on_remove_clicked()
{
	int row = ui->TW->currentRow();
	if (row < 0)
	{
		QMessageBox::warning(this, "Предупреждение", "Пожалуйста выберите продукт для удаления");
		return;
	}
	QString cmd = "removeProduct " + ui->TW->item(row, 0)->text();
	emit sendCommand(cmd);
}



