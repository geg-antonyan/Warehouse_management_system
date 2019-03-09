#ifndef PRODUCT_FORM_H
#define PRODUCT_FORM_H

#include "Form.h"
namespace Ui { class ProductForm; };

class ProductForm : public Form
{
	Q_OBJECT

public:
	ProductForm(QWidget *parent = Q_NULLPTR);
	~ProductForm();
	void update() override;

private:
	void on_add_clicked() override;
	void on_remove_clicked() override;
private:
	Ui::ProductForm *ui;
};



#endif // !PRODUCT_FORM_H

