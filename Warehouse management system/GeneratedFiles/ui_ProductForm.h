/********************************************************************************
** Form generated from reading UI file 'ProductForm.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTFORM_H
#define UI_PRODUCTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProductForm
{
public:
    QTableWidget *TW;
    QPushButton *remove;
    QPushButton *add;
    QLineEdit *prdDescribeIn;
    QLabel *decribeLbl;
    QLineEdit *lifeTimeIn;
    QLabel *lifeTimeLBL;
    QPushButton *nextPB;
    QFrame *line;

    void setupUi(QWidget *ProductForm)
    {
        if (ProductForm->objectName().isEmpty())
            ProductForm->setObjectName(QString::fromUtf8("ProductForm"));
        ProductForm->resize(600, 600);
        ProductForm->setMinimumSize(QSize(568, 380));
        ProductForm->setMaximumSize(QSize(600, 600));
        TW = new QTableWidget(ProductForm);
        TW->setObjectName(QString::fromUtf8("TW"));
        TW->setGeometry(QRect(20, 20, 541, 471));
        QFont font;
        font.setPointSize(10);
        TW->setFont(font);
        TW->setEditTriggers(QAbstractItemView::NoEditTriggers);
        remove = new QPushButton(ProductForm);
        remove->setObjectName(QString::fromUtf8("remove"));
        remove->setGeometry(QRect(560, 20, 31, 28));
        QFont font1;
        font1.setPointSize(12);
        remove->setFont(font1);
        remove->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        add = new QPushButton(ProductForm);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(560, 490, 31, 31));
        add->setFont(font1);
        add->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));
        prdDescribeIn = new QLineEdit(ProductForm);
        prdDescribeIn->setObjectName(QString::fromUtf8("prdDescribeIn"));
        prdDescribeIn->setGeometry(QRect(20, 490, 341, 31));
        prdDescribeIn->setFont(font);
        prdDescribeIn->setContextMenuPolicy(Qt::DefaultContextMenu);
        prdDescribeIn->setLayoutDirection(Qt::LeftToRight);
        prdDescribeIn->setAutoFillBackground(false);
        decribeLbl = new QLabel(ProductForm);
        decribeLbl->setObjectName(QString::fromUtf8("decribeLbl"));
        decribeLbl->setGeometry(QRect(20, 520, 153, 21));
        decribeLbl->setFont(font);
        lifeTimeIn = new QLineEdit(ProductForm);
        lifeTimeIn->setObjectName(QString::fromUtf8("lifeTimeIn"));
        lifeTimeIn->setGeometry(QRect(450, 490, 111, 31));
        lifeTimeIn->setFont(font);
        lifeTimeLBL = new QLabel(ProductForm);
        lifeTimeLBL->setObjectName(QString::fromUtf8("lifeTimeLBL"));
        lifeTimeLBL->setGeometry(QRect(370, 500, 71, 21));
        lifeTimeLBL->setFont(font);
        nextPB = new QPushButton(ProductForm);
        nextPB->setObjectName(QString::fromUtf8("nextPB"));
        nextPB->setGeometry(QRect(260, 560, 93, 31));
        nextPB->setFont(font);
        line = new QFrame(ProductForm);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 540, 601, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        retranslateUi(ProductForm);

        QMetaObject::connectSlotsByName(ProductForm);
    } // setupUi

    void retranslateUi(QWidget *ProductForm)
    {
        ProductForm->setWindowTitle(QCoreApplication::translate("ProductForm", "\320\237\321\200\320\276\320\264\321\203\320\272\321\202\321\213", nullptr));
        remove->setText(QCoreApplication::translate("ProductForm", "X", nullptr));
        add->setText(QCoreApplication::translate("ProductForm", "V", nullptr));
#if QT_CONFIG(tooltip)
        prdDescribeIn->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        prdDescribeIn->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(accessibility)
        prdDescribeIn->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        prdDescribeIn->setInputMask(QString());
        prdDescribeIn->setText(QString());
        prdDescribeIn->setPlaceholderText(QString());
        decribeLbl->setText(QCoreApplication::translate("ProductForm", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\277\321\200\320\276\320\264\321\203\320\272\321\202\320\260", nullptr));
        lifeTimeLBL->setText(QCoreApplication::translate("ProductForm", "\320\241\321\200\320\276\320\272 \320\263\320\276\320\264.", nullptr));
        nextPB->setText(QCoreApplication::translate("ProductForm", "\320\224\320\260\320\273\320\265\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductForm: public Ui_ProductForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTFORM_H
