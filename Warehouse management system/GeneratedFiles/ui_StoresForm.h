/********************************************************************************
** Form generated from reading UI file 'StoresForm.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STORESFORM_H
#define UI_STORESFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StoresForm
{
public:
    QPushButton *remove;
    QPushButton *add;
    QPushButton *backPB;
    QPushButton *nextPB;
    QTableWidget *TW;
    QFrame *line;
    QLineEdit *storeNameIn;
    QComboBox *typeBox;
    QLabel *storeNameLbl;
    QLabel *typeLbl;

    void setupUi(QWidget *StoresForm)
    {
        if (StoresForm->objectName().isEmpty())
            StoresForm->setObjectName(QStringLiteral("StoresForm"));
        StoresForm->resize(600, 601);
        remove = new QPushButton(StoresForm);
        remove->setObjectName(QStringLiteral("remove"));
        remove->setGeometry(QRect(560, 10, 31, 28));
        QFont font;
        font.setPointSize(12);
        remove->setFont(font);
        remove->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        add = new QPushButton(StoresForm);
        add->setObjectName(QStringLiteral("add"));
        add->setGeometry(QRect(560, 480, 31, 31));
        add->setFont(font);
        add->setStyleSheet(QStringLiteral("color: rgb(0, 170, 0);"));
        backPB = new QPushButton(StoresForm);
        backPB->setObjectName(QStringLiteral("backPB"));
        backPB->setGeometry(QRect(200, 560, 93, 31));
        QFont font1;
        font1.setPointSize(10);
        backPB->setFont(font1);
        nextPB = new QPushButton(StoresForm);
        nextPB->setObjectName(QStringLiteral("nextPB"));
        nextPB->setGeometry(QRect(310, 560, 93, 31));
        nextPB->setFont(font1);
        TW = new QTableWidget(StoresForm);
        TW->setObjectName(QStringLiteral("TW"));
        TW->setGeometry(QRect(20, 10, 541, 471));
        line = new QFrame(StoresForm);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 530, 601, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        storeNameIn = new QLineEdit(StoresForm);
        storeNameIn->setObjectName(QStringLiteral("storeNameIn"));
        storeNameIn->setGeometry(QRect(20, 480, 281, 31));
        storeNameIn->setFont(font1);
        typeBox = new QComboBox(StoresForm);
        typeBox->setObjectName(QStringLiteral("typeBox"));
        typeBox->setGeometry(QRect(330, 480, 231, 31));
        typeBox->setFont(font1);
        storeNameLbl = new QLabel(StoresForm);
        storeNameLbl->setObjectName(QStringLiteral("storeNameLbl"));
        storeNameLbl->setGeometry(QRect(30, 510, 119, 22));
        QFont font2;
        font2.setPointSize(11);
        storeNameLbl->setFont(font2);
        typeLbl = new QLabel(StoresForm);
        typeLbl->setObjectName(QStringLiteral("typeLbl"));
        typeLbl->setGeometry(QRect(340, 510, 121, 22));
        typeLbl->setFont(font2);

        retranslateUi(StoresForm);

        QMetaObject::connectSlotsByName(StoresForm);
    } // setupUi

    void retranslateUi(QWidget *StoresForm)
    {
        StoresForm->setWindowTitle(QApplication::translate("StoresForm", "\320\234\320\260\320\263\320\260\320\267\320\270\320\275\321\213", nullptr));
        remove->setText(QApplication::translate("StoresForm", "X", nullptr));
        add->setText(QApplication::translate("StoresForm", "V", nullptr));
        backPB->setText(QApplication::translate("StoresForm", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        nextPB->setText(QApplication::translate("StoresForm", "\320\224\320\260\320\273\320\265\320\265", nullptr));
        storeNameLbl->setText(QApplication::translate("StoresForm", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        typeLbl->setText(QApplication::translate("StoresForm", "\320\242\320\270\320\277 \320\274\320\260\320\263\320\260\320\270\320\267\320\270\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StoresForm: public Ui_StoresForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STORESFORM_H
