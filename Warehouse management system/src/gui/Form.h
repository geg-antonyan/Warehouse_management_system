#ifndef FORM_H
#define FORM_H

#include <QWidget>

class Form : public QWidget
{
	Q_OBJECT

public:
	Form(QWidget *parent = Q_NULLPTR);
	~Form();
	virtual void update() = 0;

signals:
	void next();
	void back();

	void sendCommand(QString&);

private slots:
	void on_nextPB_clicked();
	void on_backPB_clicked();

	virtual void on_add_clicked() = 0;
	virtual	void on_remove_clicked() = 0;

private:

};



#endif // !FORM_H

