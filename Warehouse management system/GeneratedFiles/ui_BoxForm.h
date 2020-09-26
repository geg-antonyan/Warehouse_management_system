/********************************************************************************
** Form generated from reading UI file 'BoxForm.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOXFORM_H
#define UI_BOXFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BoxForm
{
public:
    QPushButton *backPB;
    QPushButton *nextPB;
    QTableWidget *TW;
    QPushButton *remove;
    QPushButton *add;
    QComboBox *productBox;
    QDoubleSpinBox *priceSB;
    QSpinBox *sizeSB;
    QLabel *priceLbl;
    QLabel *sizeLbl;
    QFrame *line;
    QComboBox *unitBox;
    QLabel *unitLbl;

    void setupUi(QWidget *BoxForm)
    {
        if (BoxForm->objectName().isEmpty())
            BoxForm->setObjectName(QString::fromUtf8("BoxForm"));
        BoxForm->resize(831, 759);
        BoxForm->setMinimumSize(QSize(831, 759));
        BoxForm->setMaximumSize(QSize(831, 759));
        backPB = new QPushButton(BoxForm);
        backPB->setObjectName(QString::fromUtf8("backPB"));
        backPB->setGeometry(QRect(310, 720, 93, 31));
        QFont font;
        font.setPointSize(10);
        backPB->setFont(font);
        nextPB = new QPushButton(BoxForm);
        nextPB->setObjectName(QString::fromUtf8("nextPB"));
        nextPB->setGeometry(QRect(430, 720, 91, 31));
        nextPB->setFont(font);
        TW = new QTableWidget(BoxForm);
        TW->setObjectName(QString::fromUtf8("TW"));
        TW->setGeometry(QRect(20, 20, 771, 621));
        TW->setEditTriggers(QAbstractItemView::NoEditTriggers);
        remove = new QPushButton(BoxForm);
        remove->setObjectName(QString::fromUtf8("remove"));
        remove->setGeometry(QRect(790, 20, 31, 28));
        QFont font1;
        font1.setPointSize(12);
        remove->setFont(font1);
        remove->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        add = new QPushButton(BoxForm);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(790, 640, 31, 31));
        add->setFont(font1);
        add->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));
        productBox = new QComboBox(BoxForm);
        productBox->setObjectName(QString::fromUtf8("productBox"));
        productBox->setGeometry(QRect(20, 640, 351, 31));
        productBox->setFont(font);
        priceSB = new QDoubleSpinBox(BoxForm);
        priceSB->setObjectName(QString::fromUtf8("priceSB"));
        priceSB->setGeometry(QRect(700, 640, 91, 31));
        priceSB->setFont(font);
        priceSB->setDecimals(2);
        priceSB->setMaximum(9999999999.989999771118164);
        sizeSB = new QSpinBox(BoxForm);
        sizeSB->setObjectName(QString::fromUtf8("sizeSB"));
        sizeSB->setGeometry(QRect(570, 640, 71, 31));
        sizeSB->setFont(font);
        sizeSB->setMaximum(9999);
        priceLbl = new QLabel(BoxForm);
        priceLbl->setObjectName(QString::fromUtf8("priceLbl"));
        priceLbl->setGeometry(QRect(650, 650, 40, 22));
        QFont font2;
        font2.setPointSize(11);
        priceLbl->setFont(font2);
        sizeLbl = new QLabel(BoxForm);
        sizeLbl->setObjectName(QString::fromUtf8("sizeLbl"));
        sizeLbl->setGeometry(QRect(530, 650, 31, 22));
        sizeLbl->setFont(font2);
        line = new QFrame(BoxForm);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 700, 831, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        unitBox = new QComboBox(BoxForm);
        unitBox->setObjectName(QString::fromUtf8("unitBox"));
        unitBox->setGeometry(QRect(450, 640, 73, 31));
        unitBox->setFont(font);
        unitLbl = new QLabel(BoxForm);
        unitLbl->setObjectName(QString::fromUtf8("unitLbl"));
        unitLbl->setGeometry(QRect(380, 650, 61, 22));
        unitLbl->setFont(font2);

        retranslateUi(BoxForm);

        QMetaObject::connectSlotsByName(BoxForm);
    } // setupUi

    void retranslateUi(QWidget *BoxForm)
    {
        BoxForm->setWindowTitle(QCoreApplication::translate("BoxForm", "\320\236\320\277\321\202\320\276\320\262\321\213\320\265 \320\243\320\277\320\260\320\272\320\276\320\262\320\272\320\270", nullptr));
        backPB->setText(QCoreApplication::translate("BoxForm", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        nextPB->setText(QCoreApplication::translate("BoxForm", "\320\224\320\260\320\273\320\265\320\265", nullptr));
        remove->setText(QCoreApplication::translate("BoxForm", "X", nullptr));
        add->setText(QCoreApplication::translate("BoxForm", "V", nullptr));
        priceLbl->setText(QCoreApplication::translate("BoxForm", "\320\246\320\265\320\275\320\260", nullptr));
        sizeLbl->setText(QCoreApplication::translate("BoxForm", "\320\232\320\276\320\273", nullptr));
        unitLbl->setText(QCoreApplication::translate("BoxForm", "\320\225\320\264. \320\270\320\267\320\274.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BoxForm: public Ui_BoxForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOXFORM_H
