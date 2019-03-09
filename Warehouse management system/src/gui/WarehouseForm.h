#ifndef WAREHOUSE_FORM_H
#define WAREHOUSE_FORM_H


#include "Form.h"

namespace Ui { class WarehouseForm; };

class WarehouseForm : public Form
{
	Q_OBJECT

public:
	WarehouseForm(QWidget *parent = Q_NULLPTR);
	~WarehouseForm();
	void update() override;
	void loadFreeBox();
private slots:
	void on_startPB_clicked();
private:
	void on_add_clicked() override;
	void on_remove_clicked() override;
	Ui::WarehouseForm *ui;
};


#endif // !WAREHOUSE_FORM_H
