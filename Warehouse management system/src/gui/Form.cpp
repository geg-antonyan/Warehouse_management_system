#include "Form.h"


Form::Form(QWidget *parent) :
	QWidget(parent)
{

}

Form::~Form()
{
}

void Form::on_nextPB_clicked()
{
	emit next();
}



void Form::on_backPB_clicked()
{
	emit back();
}
