#ifndef STORES_FORM_H


#include "Form.h"
namespace Ui { class StoresForm; };

class StoresForm : public Form
{
	Q_OBJECT

public:
	StoresForm(QWidget *parent = Q_NULLPTR);
	~StoresForm();
	void update() override;

private:
	void on_add_clicked() override;
	void on_remove_clicked() override;

	Ui::StoresForm *ui;
};

#endif // !STORES_FORM_H