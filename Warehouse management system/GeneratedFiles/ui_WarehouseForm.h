/********************************************************************************
** Form generated from reading UI file 'WarehouseForm.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAREHOUSEFORM_H
#define UI_WAREHOUSEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WarehouseForm
{
public:
    QSpinBox *minSizeSB;
    QPushButton *backPB;
    QLabel *maxSizeLbl;
    QTableWidget *TW;
    QPushButton *add;
    QComboBox *boxesBox;
    QLabel *minSizeLbl;
    QLabel *sizeLbl_2;
    QPushButton *startPB;
    QFrame *line;
    QPushButton *remove;
    QSpinBox *sizeSB;
    QSpinBox *maxSizeSB;

    void setupUi(QWidget *WarehouseForm)
    {
        if (WarehouseForm->objectName().isEmpty())
            WarehouseForm->setObjectName(QStringLiteral("WarehouseForm"));
        WarehouseForm->resize(831, 759);
        WarehouseForm->setMinimumSize(QSize(831, 759));
        WarehouseForm->setMaximumSize(QSize(831, 759));
        QFont font;
        font.setPointSize(10);
        WarehouseForm->setFont(font);
        minSizeSB = new QSpinBox(WarehouseForm);
        minSizeSB->setObjectName(QStringLiteral("minSizeSB"));
        minSizeSB->setGeometry(QRect(580, 640, 91, 31));
        minSizeSB->setFont(font);
        minSizeSB->setMaximum(9999);
        backPB = new QPushButton(WarehouseForm);
        backPB->setObjectName(QStringLiteral("backPB"));
        backPB->setGeometry(QRect(310, 720, 93, 31));
        backPB->setFont(font);
        maxSizeLbl = new QLabel(WarehouseForm);
        maxSizeLbl->setObjectName(QStringLiteral("maxSizeLbl"));
        maxSizeLbl->setGeometry(QRect(700, 670, 85, 22));
        QFont font1;
        font1.setPointSize(11);
        maxSizeLbl->setFont(font1);
        TW = new QTableWidget(WarehouseForm);
        TW->setObjectName(QStringLiteral("TW"));
        TW->setGeometry(QRect(20, 20, 771, 611));
        TW->setEditTriggers(QAbstractItemView::NoEditTriggers);
        add = new QPushButton(WarehouseForm);
        add->setObjectName(QStringLiteral("add"));
        add->setGeometry(QRect(790, 640, 31, 31));
        QFont font2;
        font2.setPointSize(12);
        add->setFont(font2);
        add->setStyleSheet(QStringLiteral("color: rgb(0, 170, 0);"));
        boxesBox = new QComboBox(WarehouseForm);
        boxesBox->setObjectName(QStringLiteral("boxesBox"));
        boxesBox->setGeometry(QRect(20, 640, 431, 31));
        boxesBox->setFont(font);
        minSizeLbl = new QLabel(WarehouseForm);
        minSizeLbl->setObjectName(QStringLiteral("minSizeLbl"));
        minSizeLbl->setGeometry(QRect(580, 670, 80, 22));
        minSizeLbl->setFont(font1);
        sizeLbl_2 = new QLabel(WarehouseForm);
        sizeLbl_2->setObjectName(QStringLiteral("sizeLbl_2"));
        sizeLbl_2->setGeometry(QRect(470, 670, 61, 22));
        sizeLbl_2->setFont(font1);
        startPB = new QPushButton(WarehouseForm);
        startPB->setObjectName(QStringLiteral("startPB"));
        startPB->setGeometry(QRect(430, 720, 91, 31));
        startPB->setFont(font);
        line = new QFrame(WarehouseForm);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 700, 831, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        remove = new QPushButton(WarehouseForm);
        remove->setObjectName(QStringLiteral("remove"));
        remove->setGeometry(QRect(790, 20, 31, 28));
        remove->setFont(font2);
        remove->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        sizeSB = new QSpinBox(WarehouseForm);
        sizeSB->setObjectName(QStringLiteral("sizeSB"));
        sizeSB->setGeometry(QRect(470, 640, 91, 31));
        sizeSB->setFont(font);
        sizeSB->setMaximum(9999);
        maxSizeSB = new QSpinBox(WarehouseForm);
        maxSizeSB->setObjectName(QStringLiteral("maxSizeSB"));
        maxSizeSB->setGeometry(QRect(700, 640, 91, 31));
        maxSizeSB->setFont(font);
        maxSizeSB->setMaximum(9999);

        retranslateUi(WarehouseForm);

        QMetaObject::connectSlotsByName(WarehouseForm);
    } // setupUi

    void retranslateUi(QWidget *WarehouseForm)
    {
        WarehouseForm->setWindowTitle(QApplication::translate("WarehouseForm", "\320\241\320\272\320\273\320\260\320\264", nullptr));
        backPB->setText(QApplication::translate("WarehouseForm", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        maxSizeLbl->setText(QApplication::translate("WarehouseForm", "\320\234\320\260\320\272\321\201. \320\272\320\276\320\273.", nullptr));
        add->setText(QApplication::translate("WarehouseForm", "V", nullptr));
        minSizeLbl->setText(QApplication::translate("WarehouseForm", "\320\234\320\270\320\275. \320\272\320\276\320\273.", nullptr));
        sizeLbl_2->setText(QApplication::translate("WarehouseForm", "\320\232\320\276\320\273.", nullptr));
        startPB->setText(QApplication::translate("WarehouseForm", "\320\235\320\260\321\207\320\270\320\275\320\260\321\202\321\214", nullptr));
        remove->setText(QApplication::translate("WarehouseForm", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WarehouseForm: public Ui_WarehouseForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAREHOUSEFORM_H
