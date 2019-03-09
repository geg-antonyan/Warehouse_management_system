#ifndef BOX_FORM_H
#define BOX_FORM_H

#include "Form.h"

namespace Ui { class BoxForm; };

class BoxForm : public Form
{
	Q_OBJECT

public:
	BoxForm(QWidget *parent = Q_NULLPTR);
	~BoxForm();
	void update() override;
	void loadFreePrd();
signals:

private:
	void on_add_clicked() override;
	void on_remove_clicked() override;

private:
	Ui::BoxForm *ui;

	void loadUnit();
};


#endif // !BOX_FORM_H
