/********************************************************************************
** Form generated from reading UI file 'Gui.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiClass
{
public:
    QWidget *centralWidget;
    QTableWidget *twOredersStores;
    QTableWidget *twCargoStores;
    QTableWidget *twDiscount;
    QPushButton *btnStoreOrdBrowse;
    QPushButton *btnCargoStoreBrowse;
    QPushButton *btnConfCargoStore;
    QPushButton *btnRemoveCargoStore;
    QFrame *line;
    QFrame *line_2;
    QLabel *lblDiscountTW;
    QLabel *lblStoreOrdersTW;
    QLabel *lblCargoStoresTW;
    QFrame *line_3;
    QTableWidget *twWarehouse;
    QLabel *lblWarehouseTW;
    QTableWidget *twExpiredPrd;
    QLabel *lblExpiredPrdTW;
    QLCDNumber *lcdExpiredSum;
    QLabel *lblExpiredSum;
    QPushButton *btnRackBrowse;
    QLCDNumber *lcdDiscountSum;
    QLabel *lblDiscountSum;
    QPushButton *btnExecDiscount;
    QPushButton *btnRemoveDiscount;
    QDoubleSpinBox *dsbPrecent;
    QLabel *lblPrecent;
    QPushButton *btnChangeDisclount;
    QTableWidget *twCargoWarehouse;
    QLabel *lblCargoWarehouseTW;
    QLCDNumber *lcdCargoBalance;
    QLabel *lblCargoBalance;
    QPushButton *btnConfCargoWarehouse;
    QPushButton *btnCargoWarehouseBrowse;
    QPushButton *btnRemoveCargoWarehouse;
    QGroupBox *financeBox;
    QLCDNumber *lcdSummary;
    QLabel *lblSummary;
    QLCDNumber *lcdIntiCapital;
    QLCDNumber *lcdSale;
    QLCDNumber *lcdDelivered;
    QLCDNumber *lcdBalance;
    QLabel *lblIntiCapital;
    QLabel *lblSale;
    QLabel *lblDelivered;
    QLabel *lblBalance;
    QLabel *lblDamages;
    QLCDNumber *lcdDamages;
    QGroupBox *processBox;
    QLabel *lblTime;
    QLCDNumber *lcdTime;
    QPushButton *btnDeactivateProcess;
    QPushButton *btnActivateProcess;
    QPushButton *btnStopProcess;
    QPushButton *btnSoldProducts;
    QPushButton *btnStopGenOrders;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GuiClass)
    {
        if (GuiClass->objectName().isEmpty())
            GuiClass->setObjectName(QString::fromUtf8("GuiClass"));
        GuiClass->resize(1450, 846);
        GuiClass->setMinimumSize(QSize(1325, 815));
        GuiClass->setMaximumSize(QSize(1450, 900));
        centralWidget = new QWidget(GuiClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        twOredersStores = new QTableWidget(centralWidget);
        twOredersStores->setObjectName(QString::fromUtf8("twOredersStores"));
        twOredersStores->setGeometry(QRect(410, 470, 451, 301));
        QFont font;
        font.setPointSize(9);
        twOredersStores->setFont(font);
        twOredersStores->setEditTriggers(QAbstractItemView::NoEditTriggers);
        twCargoStores = new QTableWidget(centralWidget);
        twCargoStores->setObjectName(QString::fromUtf8("twCargoStores"));
        twCargoStores->setGeometry(QRect(900, 470, 511, 271));
        twCargoStores->setFont(font);
        twCargoStores->setEditTriggers(QAbstractItemView::NoEditTriggers);
        twDiscount = new QTableWidget(centralWidget);
        twDiscount->setObjectName(QString::fromUtf8("twDiscount"));
        twDiscount->setGeometry(QRect(10, 470, 361, 271));
        twDiscount->setFont(font);
        twDiscount->setEditTriggers(QAbstractItemView::NoEditTriggers);
        btnStoreOrdBrowse = new QPushButton(centralWidget);
        btnStoreOrdBrowse->setObjectName(QString::fromUtf8("btnStoreOrdBrowse"));
        btnStoreOrdBrowse->setGeometry(QRect(860, 470, 31, 28));
        QFont font1;
        font1.setPointSize(10);
        btnStoreOrdBrowse->setFont(font1);
        btnStoreOrdBrowse->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);"));
        btnCargoStoreBrowse = new QPushButton(centralWidget);
        btnCargoStoreBrowse->setObjectName(QString::fromUtf8("btnCargoStoreBrowse"));
        btnCargoStoreBrowse->setGeometry(QRect(1410, 470, 31, 28));
        btnCargoStoreBrowse->setFont(font1);
        btnCargoStoreBrowse->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);"));
        btnConfCargoStore = new QPushButton(centralWidget);
        btnConfCargoStore->setObjectName(QString::fromUtf8("btnConfCargoStore"));
        btnConfCargoStore->setGeometry(QRect(1410, 500, 31, 28));
        QFont font2;
        font2.setPointSize(11);
        btnConfCargoStore->setFont(font2);
        btnConfCargoStore->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));
        btnRemoveCargoStore = new QPushButton(centralWidget);
        btnRemoveCargoStore->setObjectName(QString::fromUtf8("btnRemoveCargoStore"));
        btnRemoveCargoStore->setGeometry(QRect(1410, 530, 31, 28));
        btnRemoveCargoStore->setFont(font2);
        btnRemoveCargoStore->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(90, 421, 1361, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(400, 430, 20, 341));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        lblDiscountTW = new QLabel(centralWidget);
        lblDiscountTW->setObjectName(QString::fromUtf8("lblDiscountTW"));
        lblDiscountTW->setGeometry(QRect(30, 440, 210, 22));
        lblDiscountTW->setFont(font2);
        lblStoreOrdersTW = new QLabel(centralWidget);
        lblStoreOrdersTW->setObjectName(QString::fromUtf8("lblStoreOrdersTW"));
        lblStoreOrdersTW->setGeometry(QRect(560, 440, 171, 21));
        lblStoreOrdersTW->setFont(font1);
        lblCargoStoresTW = new QLabel(centralWidget);
        lblCargoStoresTW->setObjectName(QString::fromUtf8("lblCargoStoresTW"));
        lblCargoStoresTW->setGeometry(QRect(1070, 440, 151, 21));
        lblCargoStoresTW->setFont(font1);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(0, 761, 1451, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        twWarehouse = new QTableWidget(centralWidget);
        twWarehouse->setObjectName(QString::fromUtf8("twWarehouse"));
        twWarehouse->setGeometry(QRect(10, 40, 631, 391));
        twWarehouse->setEditTriggers(QAbstractItemView::NoEditTriggers);
        lblWarehouseTW = new QLabel(centralWidget);
        lblWarehouseTW->setObjectName(QString::fromUtf8("lblWarehouseTW"));
        lblWarehouseTW->setGeometry(QRect(290, 10, 49, 22));
        lblWarehouseTW->setFont(font2);
        twExpiredPrd = new QTableWidget(centralWidget);
        twExpiredPrd->setObjectName(QString::fromUtf8("twExpiredPrd"));
        twExpiredPrd->setGeometry(QRect(680, 40, 341, 171));
        QFont font3;
        font3.setBold(false);
        font3.setWeight(50);
        twExpiredPrd->setFont(font3);
        twExpiredPrd->setEditTriggers(QAbstractItemView::NoEditTriggers);
        lblExpiredPrdTW = new QLabel(centralWidget);
        lblExpiredPrdTW->setObjectName(QString::fromUtf8("lblExpiredPrdTW"));
        lblExpiredPrdTW->setGeometry(QRect(730, 10, 204, 22));
        lblExpiredPrdTW->setFont(font2);
        lcdExpiredSum = new QLCDNumber(centralWidget);
        lcdExpiredSum->setObjectName(QString::fromUtf8("lcdExpiredSum"));
        lcdExpiredSum->setGeometry(QRect(780, 210, 241, 31));
        lcdExpiredSum->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));
        lcdExpiredSum->setFrameShape(QFrame::StyledPanel);
        lcdExpiredSum->setSmallDecimalPoint(false);
        lcdExpiredSum->setDigitCount(16);
        lcdExpiredSum->setSegmentStyle(QLCDNumber::Flat);
        lblExpiredSum = new QLabel(centralWidget);
        lblExpiredSum->setObjectName(QString::fromUtf8("lblExpiredSum"));
        lblExpiredSum->setGeometry(QRect(680, 220, 59, 22));
        lblExpiredSum->setFont(font2);
        lblExpiredSum->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));
        btnRackBrowse = new QPushButton(centralWidget);
        btnRackBrowse->setObjectName(QString::fromUtf8("btnRackBrowse"));
        btnRackBrowse->setGeometry(QRect(640, 40, 31, 31));
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setWeight(75);
        btnRackBrowse->setFont(font4);
        btnRackBrowse->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);"));
        lcdDiscountSum = new QLCDNumber(centralWidget);
        lcdDiscountSum->setObjectName(QString::fromUtf8("lcdDiscountSum"));
        lcdDiscountSum->setGeometry(QRect(100, 740, 271, 31));
        lcdDiscountSum->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));
        lcdDiscountSum->setFrameShape(QFrame::StyledPanel);
        lcdDiscountSum->setSmallDecimalPoint(false);
        lcdDiscountSum->setDigitCount(18);
        lcdDiscountSum->setSegmentStyle(QLCDNumber::Flat);
        lblDiscountSum = new QLabel(centralWidget);
        lblDiscountSum->setObjectName(QString::fromUtf8("lblDiscountSum"));
        lblDiscountSum->setGeometry(QRect(10, 740, 61, 31));
        lblDiscountSum->setFont(font2);
        lblDiscountSum->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));
        btnExecDiscount = new QPushButton(centralWidget);
        btnExecDiscount->setObjectName(QString::fromUtf8("btnExecDiscount"));
        btnExecDiscount->setGeometry(QRect(370, 470, 31, 28));
        btnExecDiscount->setFont(font2);
        btnExecDiscount->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));
        btnRemoveDiscount = new QPushButton(centralWidget);
        btnRemoveDiscount->setObjectName(QString::fromUtf8("btnRemoveDiscount"));
        btnRemoveDiscount->setGeometry(QRect(370, 500, 31, 28));
        btnRemoveDiscount->setFont(font2);
        btnRemoveDiscount->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));
        dsbPrecent = new QDoubleSpinBox(centralWidget);
        dsbPrecent->setObjectName(QString::fromUtf8("dsbPrecent"));
        dsbPrecent->setGeometry(QRect(270, 440, 71, 31));
        dsbPrecent->setFont(font1);
        lblPrecent = new QLabel(centralWidget);
        lblPrecent->setObjectName(QString::fromUtf8("lblPrecent"));
        lblPrecent->setGeometry(QRect(350, 440, 21, 31));
        lblPrecent->setFont(font2);
        btnChangeDisclount = new QPushButton(centralWidget);
        btnChangeDisclount->setObjectName(QString::fromUtf8("btnChangeDisclount"));
        btnChangeDisclount->setGeometry(QRect(370, 440, 31, 28));
        btnChangeDisclount->setFont(font2);
        btnChangeDisclount->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);"));
        twCargoWarehouse = new QTableWidget(centralWidget);
        twCargoWarehouse->setObjectName(QString::fromUtf8("twCargoWarehouse"));
        twCargoWarehouse->setGeometry(QRect(680, 250, 551, 181));
        twCargoWarehouse->setFont(font3);
        twCargoWarehouse->setEditTriggers(QAbstractItemView::NoEditTriggers);
        lblCargoWarehouseTW = new QLabel(centralWidget);
        lblCargoWarehouseTW->setObjectName(QString::fromUtf8("lblCargoWarehouseTW"));
        lblCargoWarehouseTW->setGeometry(QRect(1050, 220, 160, 31));
        lblCargoWarehouseTW->setFont(font2);
        lcdCargoBalance = new QLCDNumber(centralWidget);
        lcdCargoBalance->setObjectName(QString::fromUtf8("lcdCargoBalance"));
        lcdCargoBalance->setGeometry(QRect(1230, 740, 181, 31));
        lcdCargoBalance->setStyleSheet(QString::fromUtf8("color: rgb(170, 85, 0);"));
        lcdCargoBalance->setFrameShape(QFrame::StyledPanel);
        lcdCargoBalance->setSmallDecimalPoint(false);
        lcdCargoBalance->setDigitCount(13);
        lcdCargoBalance->setSegmentStyle(QLCDNumber::Flat);
        lblCargoBalance = new QLabel(centralWidget);
        lblCargoBalance->setObjectName(QString::fromUtf8("lblCargoBalance"));
        lblCargoBalance->setGeometry(QRect(900, 740, 238, 31));
        lblCargoBalance->setFont(font2);
        lblCargoBalance->setStyleSheet(QString::fromUtf8("color: rgb(170, 85, 0);"));
        btnConfCargoWarehouse = new QPushButton(centralWidget);
        btnConfCargoWarehouse->setObjectName(QString::fromUtf8("btnConfCargoWarehouse"));
        btnConfCargoWarehouse->setGeometry(QRect(1230, 280, 31, 28));
        btnConfCargoWarehouse->setFont(font2);
        btnConfCargoWarehouse->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));
        btnCargoWarehouseBrowse = new QPushButton(centralWidget);
        btnCargoWarehouseBrowse->setObjectName(QString::fromUtf8("btnCargoWarehouseBrowse"));
        btnCargoWarehouseBrowse->setGeometry(QRect(1230, 250, 31, 28));
        btnCargoWarehouseBrowse->setFont(font1);
        btnCargoWarehouseBrowse->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);"));
        btnRemoveCargoWarehouse = new QPushButton(centralWidget);
        btnRemoveCargoWarehouse->setObjectName(QString::fromUtf8("btnRemoveCargoWarehouse"));
        btnRemoveCargoWarehouse->setGeometry(QRect(1230, 310, 31, 28));
        btnRemoveCargoWarehouse->setFont(font2);
        btnRemoveCargoWarehouse->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));
        financeBox = new QGroupBox(centralWidget);
        financeBox->setObjectName(QString::fromUtf8("financeBox"));
        financeBox->setGeometry(QRect(1030, 10, 411, 211));
        QFont font5;
        font5.setPointSize(12);
        financeBox->setFont(font5);
        lcdSummary = new QLCDNumber(financeBox);
        lcdSummary->setObjectName(QString::fromUtf8("lcdSummary"));
        lcdSummary->setGeometry(QRect(170, 20, 241, 31));
        lcdSummary->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        lcdSummary->setFrameShape(QFrame::StyledPanel);
        lcdSummary->setSmallDecimalPoint(false);
        lcdSummary->setDigitCount(16);
        lcdSummary->setSegmentStyle(QLCDNumber::Flat);
        lblSummary = new QLabel(financeBox);
        lblSummary->setObjectName(QString::fromUtf8("lblSummary"));
        lblSummary->setGeometry(QRect(110, 20, 45, 22));
        lblSummary->setFont(font2);
        lblSummary->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        lcdIntiCapital = new QLCDNumber(financeBox);
        lcdIntiCapital->setObjectName(QString::fromUtf8("lcdIntiCapital"));
        lcdIntiCapital->setGeometry(QRect(170, 50, 241, 31));
        lcdIntiCapital->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 0);"));
        lcdIntiCapital->setFrameShape(QFrame::StyledPanel);
        lcdIntiCapital->setSmallDecimalPoint(false);
        lcdIntiCapital->setDigitCount(16);
        lcdIntiCapital->setSegmentStyle(QLCDNumber::Flat);
        lcdSale = new QLCDNumber(financeBox);
        lcdSale->setObjectName(QString::fromUtf8("lcdSale"));
        lcdSale->setGeometry(QRect(170, 80, 241, 31));
        lcdSale->setStyleSheet(QString::fromUtf8("color: rgb(170, 85, 0);"));
        lcdSale->setFrameShape(QFrame::StyledPanel);
        lcdSale->setSmallDecimalPoint(false);
        lcdSale->setDigitCount(16);
        lcdSale->setSegmentStyle(QLCDNumber::Flat);
        lcdDelivered = new QLCDNumber(financeBox);
        lcdDelivered->setObjectName(QString::fromUtf8("lcdDelivered"));
        lcdDelivered->setGeometry(QRect(170, 110, 241, 31));
        lcdDelivered->setStyleSheet(QString::fromUtf8("color: rgb(85, 85, 0);"));
        lcdDelivered->setFrameShape(QFrame::StyledPanel);
        lcdDelivered->setSmallDecimalPoint(false);
        lcdDelivered->setDigitCount(16);
        lcdDelivered->setSegmentStyle(QLCDNumber::Flat);
        lcdBalance = new QLCDNumber(financeBox);
        lcdBalance->setObjectName(QString::fromUtf8("lcdBalance"));
        lcdBalance->setGeometry(QRect(170, 140, 241, 31));
        lcdBalance->setStyleSheet(QString::fromUtf8("color: rgb(170, 85, 0);"));
        lcdBalance->setFrameShape(QFrame::StyledPanel);
        lcdBalance->setSmallDecimalPoint(false);
        lcdBalance->setDigitCount(16);
        lcdBalance->setSegmentStyle(QLCDNumber::Flat);
        lblIntiCapital = new QLabel(financeBox);
        lblIntiCapital->setObjectName(QString::fromUtf8("lblIntiCapital"));
        lblIntiCapital->setGeometry(QRect(30, 50, 126, 22));
        lblIntiCapital->setFont(font2);
        lblIntiCapital->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 0);"));
        lblSale = new QLabel(financeBox);
        lblSale->setObjectName(QString::fromUtf8("lblSale"));
        lblSale->setGeometry(QRect(80, 80, 71, 22));
        lblSale->setFont(font2);
        lblSale->setStyleSheet(QString::fromUtf8("color: rgb(170, 85, 0);"));
        lblDelivered = new QLabel(financeBox);
        lblDelivered->setObjectName(QString::fromUtf8("lblDelivered"));
        lblDelivered->setGeometry(QRect(60, 110, 101, 22));
        lblDelivered->setFont(font2);
        lblDelivered->setStyleSheet(QString::fromUtf8("color: rgb(85, 85, 0);"));
        lblBalance = new QLabel(financeBox);
        lblBalance->setObjectName(QString::fromUtf8("lblBalance"));
        lblBalance->setGeometry(QRect(90, 140, 65, 22));
        lblBalance->setFont(font2);
        lblBalance->setStyleSheet(QString::fromUtf8("color: rgb(170, 85, 0);"));
        lblDamages = new QLabel(financeBox);
        lblDamages->setObjectName(QString::fromUtf8("lblDamages"));
        lblDamages->setGeometry(QRect(100, 170, 59, 22));
        lblDamages->setFont(font2);
        lblDamages->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));
        lcdDamages = new QLCDNumber(financeBox);
        lcdDamages->setObjectName(QString::fromUtf8("lcdDamages"));
        lcdDamages->setGeometry(QRect(170, 170, 241, 31));
        lcdDamages->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));
        lcdDamages->setFrameShape(QFrame::StyledPanel);
        lcdDamages->setSmallDecimalPoint(false);
        lcdDamages->setDigitCount(16);
        lcdDamages->setSegmentStyle(QLCDNumber::Flat);
        processBox = new QGroupBox(centralWidget);
        processBox->setObjectName(QString::fromUtf8("processBox"));
        processBox->setGeometry(QRect(1270, 230, 171, 201));
        processBox->setFont(font2);
        lblTime = new QLabel(processBox);
        lblTime->setObjectName(QString::fromUtf8("lblTime"));
        lblTime->setGeometry(QRect(10, 170, 52, 22));
        lblTime->setFont(font1);
        lblTime->setStyleSheet(QString::fromUtf8("color: rgb(85, 85, 0);"));
        lcdTime = new QLCDNumber(processBox);
        lcdTime->setObjectName(QString::fromUtf8("lcdTime"));
        lcdTime->setGeometry(QRect(70, 160, 101, 31));
        lcdTime->setStyleSheet(QString::fromUtf8("color: rgb(85, 85, 0);"));
        lcdTime->setFrameShape(QFrame::StyledPanel);
        lcdTime->setSmallDecimalPoint(false);
        lcdTime->setDigitCount(6);
        lcdTime->setSegmentStyle(QLCDNumber::Flat);
        btnDeactivateProcess = new QPushButton(processBox);
        btnDeactivateProcess->setObjectName(QString::fromUtf8("btnDeactivateProcess"));
        btnDeactivateProcess->setGeometry(QRect(90, 120, 31, 31));
        QFont font6;
        font6.setPointSize(10);
        font6.setBold(true);
        font6.setWeight(75);
        btnDeactivateProcess->setFont(font6);
        btnDeactivateProcess->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);"));
        btnActivateProcess = new QPushButton(processBox);
        btnActivateProcess->setObjectName(QString::fromUtf8("btnActivateProcess"));
        btnActivateProcess->setGeometry(QRect(130, 120, 31, 31));
        QFont font7;
        font7.setPointSize(12);
        font7.setBold(true);
        font7.setWeight(75);
        btnActivateProcess->setFont(font7);
        btnActivateProcess->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 0);"));
        btnStopProcess = new QPushButton(processBox);
        btnStopProcess->setObjectName(QString::fromUtf8("btnStopProcess"));
        btnStopProcess->setGeometry(QRect(10, 120, 71, 31));
        btnStopProcess->setFont(font2);
        btnStopProcess->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));
        btnSoldProducts = new QPushButton(processBox);
        btnSoldProducts->setObjectName(QString::fromUtf8("btnSoldProducts"));
        btnSoldProducts->setGeometry(QRect(10, 80, 155, 28));
        btnSoldProducts->setFont(font);
        btnStopGenOrders = new QPushButton(processBox);
        btnStopGenOrders->setObjectName(QString::fromUtf8("btnStopGenOrders"));
        btnStopGenOrders->setGeometry(QRect(0, 20, 171, 51));
        QFont font8;
        font8.setPointSize(9);
        font8.setKerning(true);
        btnStopGenOrders->setFont(font8);
        btnStopGenOrders->setAutoFillBackground(false);
        btnStopGenOrders->setCheckable(false);
        btnStopGenOrders->setAutoRepeat(false);
        btnStopGenOrders->setAutoExclusive(false);
        btnStopGenOrders->setAutoDefault(false);
        GuiClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GuiClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1450, 26));
        GuiClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GuiClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GuiClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GuiClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setFont(font5);
        GuiClass->setStatusBar(statusBar);

        retranslateUi(GuiClass);

        QMetaObject::connectSlotsByName(GuiClass);
    } // setupUi

    void retranslateUi(QMainWindow *GuiClass)
    {
        GuiClass->setWindowTitle(QCoreApplication::translate("GuiClass", "\320\241\320\270\321\201\321\202\320\265\320\274\320\260 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217 \320\276\320\277\321\202\320\276\320\262\321\213\320\274 \321\201\320\272\320\273\320\260\320\264\320\276\320\274", nullptr));
        btnStoreOrdBrowse->setText(QCoreApplication::translate("GuiClass", "?", nullptr));
        btnCargoStoreBrowse->setText(QCoreApplication::translate("GuiClass", "?", nullptr));
        btnConfCargoStore->setText(QCoreApplication::translate("GuiClass", "V", nullptr));
        btnRemoveCargoStore->setText(QCoreApplication::translate("GuiClass", "X", nullptr));
        lblDiscountTW->setText(QCoreApplication::translate("GuiClass", "\320\237\321\200\320\265\320\264\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\264\320\273\321\217 \321\201\320\272\320\270\320\264\320\276\320\272", nullptr));
        lblStoreOrdersTW->setText(QCoreApplication::translate("GuiClass", "\320\227\320\260\320\272\320\260\320\267\321\213 \320\276\321\202 \320\274\320\260\320\263\320\260\320\267\320\270\320\275\320\276\320\262", nullptr));
        lblCargoStoresTW->setText(QCoreApplication::translate("GuiClass", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\277\320\265\321\200\320\265\320\262\320\276\320\267\320\276\320\272", nullptr));
        lblWarehouseTW->setText(QCoreApplication::translate("GuiClass", "\320\241\320\272\320\273\320\260\320\264", nullptr));
        lblExpiredPrdTW->setText(QCoreApplication::translate("GuiClass", "\320\237\321\200\320\276\321\201\321\200\320\276\321\207\320\265\320\275\320\275\321\213\320\265 \320\277\321\200\320\276\320\264\321\203\320\272\321\202\321\213", nullptr));
        lblExpiredSum->setText(QCoreApplication::translate("GuiClass", "\320\243\320\261\321\213\321\202\320\272\320\270", nullptr));
        btnRackBrowse->setText(QCoreApplication::translate("GuiClass", "?", nullptr));
        lblDiscountSum->setText(QCoreApplication::translate("GuiClass", "\320\243\320\261\321\213\321\202\320\272\320\270", nullptr));
        btnExecDiscount->setText(QCoreApplication::translate("GuiClass", "V", nullptr));
        btnRemoveDiscount->setText(QCoreApplication::translate("GuiClass", "X", nullptr));
        lblPrecent->setText(QCoreApplication::translate("GuiClass", "%", nullptr));
        btnChangeDisclount->setText(QCoreApplication::translate("GuiClass", "!", nullptr));
        lblCargoWarehouseTW->setText(QCoreApplication::translate("GuiClass", "\320\227\320\260\320\272\320\260\320\267\321\213 \320\275\320\260 \320\277\320\276\321\201\321\202\320\260\320\262\320\272\321\203", nullptr));
        lblCargoBalance->setText(QCoreApplication::translate("GuiClass", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \321\201\321\203\320\274\320\274\320\260  \320\277\320\265\321\200\320\265\320\262\320\276\320\267\320\276\320\272", nullptr));
        btnConfCargoWarehouse->setText(QCoreApplication::translate("GuiClass", "V", nullptr));
        btnCargoWarehouseBrowse->setText(QCoreApplication::translate("GuiClass", "?", nullptr));
        btnRemoveCargoWarehouse->setText(QCoreApplication::translate("GuiClass", "X", nullptr));
        financeBox->setTitle(QCoreApplication::translate("GuiClass", "\320\244\320\270\320\275\320\260\320\275\321\201\321\213", nullptr));
        lblSummary->setText(QCoreApplication::translate("GuiClass", "\320\222\321\201\320\265\320\263\320\276", nullptr));
        lblIntiCapital->setText(QCoreApplication::translate("GuiClass", "\320\235\320\260\321\207\320\260\320\273. \320\272\320\260\320\277\320\270\321\202\320\260\320\273", nullptr));
        lblSale->setText(QCoreApplication::translate("GuiClass", "\320\237\321\200\320\276\320\264\320\260\320\275\320\276", nullptr));
        lblDelivered->setText(QCoreApplication::translate("GuiClass", "\320\237\320\276\321\201\321\202\320\262\320\260\320\273\320\265\320\275\320\276", nullptr));
        lblBalance->setText(QCoreApplication::translate("GuiClass", "\320\236\321\201\321\202\320\260\321\202\320\276\320\272", nullptr));
        lblDamages->setText(QCoreApplication::translate("GuiClass", "\320\243\320\261\321\213\321\202\320\272\320\270", nullptr));
        processBox->setTitle(QCoreApplication::translate("GuiClass", "\320\237\321\200\320\276\321\206\320\265\321\201\321\201", nullptr));
        lblTime->setText(QCoreApplication::translate("GuiClass", "\320\224\320\224:\320\247\320\247", nullptr));
        btnDeactivateProcess->setText(QCoreApplication::translate("GuiClass", "||", nullptr));
        btnActivateProcess->setText(QCoreApplication::translate("GuiClass", ">", nullptr));
        btnStopProcess->setText(QCoreApplication::translate("GuiClass", "STOP", nullptr));
        btnSoldProducts->setText(QCoreApplication::translate("GuiClass", "\320\237\321\200\320\276\320\264\320\260\320\275\320\275\321\213\320\265 \320\277\321\200\320\276\320\264\321\203\320\272\321\202\321\213", nullptr));
#if QT_CONFIG(tooltip)
        btnStopGenOrders->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        btnStopGenOrders->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        btnStopGenOrders->setText(QCoreApplication::translate("GuiClass", "\320\236\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\263\320\265\320\275\320\265\321\200\320\260\321\206\320\270\321\216 \n"
"\320\267\320\260\320\272\320\260\320\267\320\276\320\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GuiClass: public Ui_GuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
