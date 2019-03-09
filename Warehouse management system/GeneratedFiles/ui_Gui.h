/********************************************************************************
** Form generated from reading UI file 'Gui.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
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
            GuiClass->setObjectName(QStringLiteral("GuiClass"));
        GuiClass->resize(1450, 846);
        GuiClass->setMinimumSize(QSize(1325, 815));
        GuiClass->setMaximumSize(QSize(1450, 900));
        centralWidget = new QWidget(GuiClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        twOredersStores = new QTableWidget(centralWidget);
        twOredersStores->setObjectName(QStringLiteral("twOredersStores"));
        twOredersStores->setGeometry(QRect(410, 470, 451, 301));
        QFont font;
        font.setPointSize(9);
        twOredersStores->setFont(font);
        twOredersStores->setEditTriggers(QAbstractItemView::NoEditTriggers);
        twCargoStores = new QTableWidget(centralWidget);
        twCargoStores->setObjectName(QStringLiteral("twCargoStores"));
        twCargoStores->setGeometry(QRect(900, 470, 511, 271));
        twCargoStores->setFont(font);
        twCargoStores->setEditTriggers(QAbstractItemView::NoEditTriggers);
        twDiscount = new QTableWidget(centralWidget);
        twDiscount->setObjectName(QStringLiteral("twDiscount"));
        twDiscount->setGeometry(QRect(10, 470, 361, 271));
        twDiscount->setFont(font);
        twDiscount->setEditTriggers(QAbstractItemView::NoEditTriggers);
        btnStoreOrdBrowse = new QPushButton(centralWidget);
        btnStoreOrdBrowse->setObjectName(QStringLiteral("btnStoreOrdBrowse"));
        btnStoreOrdBrowse->setGeometry(QRect(860, 470, 31, 28));
        QFont font1;
        font1.setPointSize(10);
        btnStoreOrdBrowse->setFont(font1);
        btnStoreOrdBrowse->setStyleSheet(QStringLiteral("color: rgb(255, 170, 0);"));
        btnCargoStoreBrowse = new QPushButton(centralWidget);
        btnCargoStoreBrowse->setObjectName(QStringLiteral("btnCargoStoreBrowse"));
        btnCargoStoreBrowse->setGeometry(QRect(1410, 470, 31, 28));
        btnCargoStoreBrowse->setFont(font1);
        btnCargoStoreBrowse->setStyleSheet(QStringLiteral("color: rgb(255, 170, 0);"));
        btnConfCargoStore = new QPushButton(centralWidget);
        btnConfCargoStore->setObjectName(QStringLiteral("btnConfCargoStore"));
        btnConfCargoStore->setGeometry(QRect(1410, 500, 31, 28));
        QFont font2;
        font2.setPointSize(11);
        btnConfCargoStore->setFont(font2);
        btnConfCargoStore->setStyleSheet(QStringLiteral("color: rgb(0, 170, 0);"));
        btnRemoveCargoStore = new QPushButton(centralWidget);
        btnRemoveCargoStore->setObjectName(QStringLiteral("btnRemoveCargoStore"));
        btnRemoveCargoStore->setGeometry(QRect(1410, 530, 31, 28));
        btnRemoveCargoStore->setFont(font2);
        btnRemoveCargoStore->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(90, 421, 1361, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(400, 430, 20, 341));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        lblDiscountTW = new QLabel(centralWidget);
        lblDiscountTW->setObjectName(QStringLiteral("lblDiscountTW"));
        lblDiscountTW->setGeometry(QRect(30, 440, 210, 22));
        lblDiscountTW->setFont(font2);
        lblStoreOrdersTW = new QLabel(centralWidget);
        lblStoreOrdersTW->setObjectName(QStringLiteral("lblStoreOrdersTW"));
        lblStoreOrdersTW->setGeometry(QRect(560, 440, 171, 21));
        lblStoreOrdersTW->setFont(font1);
        lblCargoStoresTW = new QLabel(centralWidget);
        lblCargoStoresTW->setObjectName(QStringLiteral("lblCargoStoresTW"));
        lblCargoStoresTW->setGeometry(QRect(1070, 440, 151, 21));
        lblCargoStoresTW->setFont(font1);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(0, 761, 1451, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        twWarehouse = new QTableWidget(centralWidget);
        twWarehouse->setObjectName(QStringLiteral("twWarehouse"));
        twWarehouse->setGeometry(QRect(10, 40, 631, 391));
        twWarehouse->setEditTriggers(QAbstractItemView::NoEditTriggers);
        lblWarehouseTW = new QLabel(centralWidget);
        lblWarehouseTW->setObjectName(QStringLiteral("lblWarehouseTW"));
        lblWarehouseTW->setGeometry(QRect(290, 10, 49, 22));
        lblWarehouseTW->setFont(font2);
        twExpiredPrd = new QTableWidget(centralWidget);
        twExpiredPrd->setObjectName(QStringLiteral("twExpiredPrd"));
        twExpiredPrd->setGeometry(QRect(680, 40, 341, 171));
        QFont font3;
        font3.setBold(false);
        font3.setWeight(50);
        twExpiredPrd->setFont(font3);
        twExpiredPrd->setEditTriggers(QAbstractItemView::NoEditTriggers);
        lblExpiredPrdTW = new QLabel(centralWidget);
        lblExpiredPrdTW->setObjectName(QStringLiteral("lblExpiredPrdTW"));
        lblExpiredPrdTW->setGeometry(QRect(730, 10, 204, 22));
        lblExpiredPrdTW->setFont(font2);
        lcdExpiredSum = new QLCDNumber(centralWidget);
        lcdExpiredSum->setObjectName(QStringLiteral("lcdExpiredSum"));
        lcdExpiredSum->setGeometry(QRect(780, 210, 241, 31));
        lcdExpiredSum->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));
        lcdExpiredSum->setFrameShape(QFrame::StyledPanel);
        lcdExpiredSum->setSmallDecimalPoint(false);
        lcdExpiredSum->setDigitCount(16);
        lcdExpiredSum->setSegmentStyle(QLCDNumber::Flat);
        lblExpiredSum = new QLabel(centralWidget);
        lblExpiredSum->setObjectName(QStringLiteral("lblExpiredSum"));
        lblExpiredSum->setGeometry(QRect(680, 220, 59, 22));
        lblExpiredSum->setFont(font2);
        lblExpiredSum->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));
        btnRackBrowse = new QPushButton(centralWidget);
        btnRackBrowse->setObjectName(QStringLiteral("btnRackBrowse"));
        btnRackBrowse->setGeometry(QRect(640, 40, 31, 31));
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setWeight(75);
        btnRackBrowse->setFont(font4);
        btnRackBrowse->setStyleSheet(QStringLiteral("color: rgb(255, 170, 0);"));
        lcdDiscountSum = new QLCDNumber(centralWidget);
        lcdDiscountSum->setObjectName(QStringLiteral("lcdDiscountSum"));
        lcdDiscountSum->setGeometry(QRect(100, 740, 271, 31));
        lcdDiscountSum->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));
        lcdDiscountSum->setFrameShape(QFrame::StyledPanel);
        lcdDiscountSum->setSmallDecimalPoint(false);
        lcdDiscountSum->setDigitCount(18);
        lcdDiscountSum->setSegmentStyle(QLCDNumber::Flat);
        lblDiscountSum = new QLabel(centralWidget);
        lblDiscountSum->setObjectName(QStringLiteral("lblDiscountSum"));
        lblDiscountSum->setGeometry(QRect(10, 740, 61, 31));
        lblDiscountSum->setFont(font2);
        lblDiscountSum->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));
        btnExecDiscount = new QPushButton(centralWidget);
        btnExecDiscount->setObjectName(QStringLiteral("btnExecDiscount"));
        btnExecDiscount->setGeometry(QRect(370, 470, 31, 28));
        btnExecDiscount->setFont(font2);
        btnExecDiscount->setStyleSheet(QStringLiteral("color: rgb(0, 170, 0);"));
        btnRemoveDiscount = new QPushButton(centralWidget);
        btnRemoveDiscount->setObjectName(QStringLiteral("btnRemoveDiscount"));
        btnRemoveDiscount->setGeometry(QRect(370, 500, 31, 28));
        btnRemoveDiscount->setFont(font2);
        btnRemoveDiscount->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));
        dsbPrecent = new QDoubleSpinBox(centralWidget);
        dsbPrecent->setObjectName(QStringLiteral("dsbPrecent"));
        dsbPrecent->setGeometry(QRect(270, 440, 71, 31));
        dsbPrecent->setFont(font1);
        lblPrecent = new QLabel(centralWidget);
        lblPrecent->setObjectName(QStringLiteral("lblPrecent"));
        lblPrecent->setGeometry(QRect(350, 440, 21, 31));
        lblPrecent->setFont(font2);
        btnChangeDisclount = new QPushButton(centralWidget);
        btnChangeDisclount->setObjectName(QStringLiteral("btnChangeDisclount"));
        btnChangeDisclount->setGeometry(QRect(370, 440, 31, 28));
        btnChangeDisclount->setFont(font2);
        btnChangeDisclount->setStyleSheet(QStringLiteral("color: rgb(255, 170, 0);"));
        twCargoWarehouse = new QTableWidget(centralWidget);
        twCargoWarehouse->setObjectName(QStringLiteral("twCargoWarehouse"));
        twCargoWarehouse->setGeometry(QRect(680, 250, 551, 181));
        twCargoWarehouse->setFont(font3);
        twCargoWarehouse->setEditTriggers(QAbstractItemView::NoEditTriggers);
        lblCargoWarehouseTW = new QLabel(centralWidget);
        lblCargoWarehouseTW->setObjectName(QStringLiteral("lblCargoWarehouseTW"));
        lblCargoWarehouseTW->setGeometry(QRect(1050, 220, 160, 31));
        lblCargoWarehouseTW->setFont(font2);
        lcdCargoBalance = new QLCDNumber(centralWidget);
        lcdCargoBalance->setObjectName(QStringLiteral("lcdCargoBalance"));
        lcdCargoBalance->setGeometry(QRect(1230, 740, 181, 31));
        lcdCargoBalance->setStyleSheet(QStringLiteral("color: rgb(170, 85, 0);"));
        lcdCargoBalance->setFrameShape(QFrame::StyledPanel);
        lcdCargoBalance->setSmallDecimalPoint(false);
        lcdCargoBalance->setDigitCount(13);
        lcdCargoBalance->setSegmentStyle(QLCDNumber::Flat);
        lblCargoBalance = new QLabel(centralWidget);
        lblCargoBalance->setObjectName(QStringLiteral("lblCargoBalance"));
        lblCargoBalance->setGeometry(QRect(900, 740, 238, 31));
        lblCargoBalance->setFont(font2);
        lblCargoBalance->setStyleSheet(QStringLiteral("color: rgb(170, 85, 0);"));
        btnConfCargoWarehouse = new QPushButton(centralWidget);
        btnConfCargoWarehouse->setObjectName(QStringLiteral("btnConfCargoWarehouse"));
        btnConfCargoWarehouse->setGeometry(QRect(1230, 280, 31, 28));
        btnConfCargoWarehouse->setFont(font2);
        btnConfCargoWarehouse->setStyleSheet(QStringLiteral("color: rgb(0, 170, 0);"));
        btnCargoWarehouseBrowse = new QPushButton(centralWidget);
        btnCargoWarehouseBrowse->setObjectName(QStringLiteral("btnCargoWarehouseBrowse"));
        btnCargoWarehouseBrowse->setGeometry(QRect(1230, 250, 31, 28));
        btnCargoWarehouseBrowse->setFont(font1);
        btnCargoWarehouseBrowse->setStyleSheet(QStringLiteral("color: rgb(255, 170, 0);"));
        btnRemoveCargoWarehouse = new QPushButton(centralWidget);
        btnRemoveCargoWarehouse->setObjectName(QStringLiteral("btnRemoveCargoWarehouse"));
        btnRemoveCargoWarehouse->setGeometry(QRect(1230, 310, 31, 28));
        btnRemoveCargoWarehouse->setFont(font2);
        btnRemoveCargoWarehouse->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));
        financeBox = new QGroupBox(centralWidget);
        financeBox->setObjectName(QStringLiteral("financeBox"));
        financeBox->setGeometry(QRect(1030, 10, 411, 211));
        QFont font5;
        font5.setPointSize(12);
        financeBox->setFont(font5);
        lcdSummary = new QLCDNumber(financeBox);
        lcdSummary->setObjectName(QStringLiteral("lcdSummary"));
        lcdSummary->setGeometry(QRect(170, 20, 241, 31));
        lcdSummary->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255);"));
        lcdSummary->setFrameShape(QFrame::StyledPanel);
        lcdSummary->setSmallDecimalPoint(false);
        lcdSummary->setDigitCount(16);
        lcdSummary->setSegmentStyle(QLCDNumber::Flat);
        lblSummary = new QLabel(financeBox);
        lblSummary->setObjectName(QStringLiteral("lblSummary"));
        lblSummary->setGeometry(QRect(110, 20, 45, 22));
        lblSummary->setFont(font2);
        lblSummary->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255);"));
        lcdIntiCapital = new QLCDNumber(financeBox);
        lcdIntiCapital->setObjectName(QStringLiteral("lcdIntiCapital"));
        lcdIntiCapital->setGeometry(QRect(170, 50, 241, 31));
        lcdIntiCapital->setStyleSheet(QStringLiteral("color: rgb(0, 85, 0);"));
        lcdIntiCapital->setFrameShape(QFrame::StyledPanel);
        lcdIntiCapital->setSmallDecimalPoint(false);
        lcdIntiCapital->setDigitCount(16);
        lcdIntiCapital->setSegmentStyle(QLCDNumber::Flat);
        lcdSale = new QLCDNumber(financeBox);
        lcdSale->setObjectName(QStringLiteral("lcdSale"));
        lcdSale->setGeometry(QRect(170, 80, 241, 31));
        lcdSale->setStyleSheet(QStringLiteral("color: rgb(170, 85, 0);"));
        lcdSale->setFrameShape(QFrame::StyledPanel);
        lcdSale->setSmallDecimalPoint(false);
        lcdSale->setDigitCount(16);
        lcdSale->setSegmentStyle(QLCDNumber::Flat);
        lcdDelivered = new QLCDNumber(financeBox);
        lcdDelivered->setObjectName(QStringLiteral("lcdDelivered"));
        lcdDelivered->setGeometry(QRect(170, 110, 241, 31));
        lcdDelivered->setStyleSheet(QStringLiteral("color: rgb(85, 85, 0);"));
        lcdDelivered->setFrameShape(QFrame::StyledPanel);
        lcdDelivered->setSmallDecimalPoint(false);
        lcdDelivered->setDigitCount(16);
        lcdDelivered->setSegmentStyle(QLCDNumber::Flat);
        lcdBalance = new QLCDNumber(financeBox);
        lcdBalance->setObjectName(QStringLiteral("lcdBalance"));
        lcdBalance->setGeometry(QRect(170, 140, 241, 31));
        lcdBalance->setStyleSheet(QStringLiteral("color: rgb(170, 85, 0);"));
        lcdBalance->setFrameShape(QFrame::StyledPanel);
        lcdBalance->setSmallDecimalPoint(false);
        lcdBalance->setDigitCount(16);
        lcdBalance->setSegmentStyle(QLCDNumber::Flat);
        lblIntiCapital = new QLabel(financeBox);
        lblIntiCapital->setObjectName(QStringLiteral("lblIntiCapital"));
        lblIntiCapital->setGeometry(QRect(30, 50, 126, 22));
        lblIntiCapital->setFont(font2);
        lblIntiCapital->setStyleSheet(QStringLiteral("color: rgb(0, 85, 0);"));
        lblSale = new QLabel(financeBox);
        lblSale->setObjectName(QStringLiteral("lblSale"));
        lblSale->setGeometry(QRect(80, 80, 71, 22));
        lblSale->setFont(font2);
        lblSale->setStyleSheet(QStringLiteral("color: rgb(170, 85, 0);"));
        lblDelivered = new QLabel(financeBox);
        lblDelivered->setObjectName(QStringLiteral("lblDelivered"));
        lblDelivered->setGeometry(QRect(60, 110, 101, 22));
        lblDelivered->setFont(font2);
        lblDelivered->setStyleSheet(QStringLiteral("color: rgb(85, 85, 0);"));
        lblBalance = new QLabel(financeBox);
        lblBalance->setObjectName(QStringLiteral("lblBalance"));
        lblBalance->setGeometry(QRect(90, 140, 65, 22));
        lblBalance->setFont(font2);
        lblBalance->setStyleSheet(QStringLiteral("color: rgb(170, 85, 0);"));
        lblDamages = new QLabel(financeBox);
        lblDamages->setObjectName(QStringLiteral("lblDamages"));
        lblDamages->setGeometry(QRect(100, 170, 59, 22));
        lblDamages->setFont(font2);
        lblDamages->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));
        lcdDamages = new QLCDNumber(financeBox);
        lcdDamages->setObjectName(QStringLiteral("lcdDamages"));
        lcdDamages->setGeometry(QRect(170, 170, 241, 31));
        lcdDamages->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));
        lcdDamages->setFrameShape(QFrame::StyledPanel);
        lcdDamages->setSmallDecimalPoint(false);
        lcdDamages->setDigitCount(16);
        lcdDamages->setSegmentStyle(QLCDNumber::Flat);
        processBox = new QGroupBox(centralWidget);
        processBox->setObjectName(QStringLiteral("processBox"));
        processBox->setGeometry(QRect(1270, 230, 171, 201));
        processBox->setFont(font2);
        lblTime = new QLabel(processBox);
        lblTime->setObjectName(QStringLiteral("lblTime"));
        lblTime->setGeometry(QRect(10, 170, 52, 22));
        lblTime->setFont(font1);
        lblTime->setStyleSheet(QStringLiteral("color: rgb(85, 85, 0);"));
        lcdTime = new QLCDNumber(processBox);
        lcdTime->setObjectName(QStringLiteral("lcdTime"));
        lcdTime->setGeometry(QRect(70, 160, 101, 31));
        lcdTime->setStyleSheet(QStringLiteral("color: rgb(85, 85, 0);"));
        lcdTime->setFrameShape(QFrame::StyledPanel);
        lcdTime->setSmallDecimalPoint(false);
        lcdTime->setDigitCount(6);
        lcdTime->setSegmentStyle(QLCDNumber::Flat);
        btnDeactivateProcess = new QPushButton(processBox);
        btnDeactivateProcess->setObjectName(QStringLiteral("btnDeactivateProcess"));
        btnDeactivateProcess->setGeometry(QRect(90, 120, 31, 31));
        QFont font6;
        font6.setPointSize(10);
        font6.setBold(true);
        font6.setWeight(75);
        btnDeactivateProcess->setFont(font6);
        btnDeactivateProcess->setStyleSheet(QStringLiteral("color: rgb(255, 170, 0);"));
        btnActivateProcess = new QPushButton(processBox);
        btnActivateProcess->setObjectName(QStringLiteral("btnActivateProcess"));
        btnActivateProcess->setGeometry(QRect(130, 120, 31, 31));
        QFont font7;
        font7.setPointSize(12);
        font7.setBold(true);
        font7.setWeight(75);
        btnActivateProcess->setFont(font7);
        btnActivateProcess->setStyleSheet(QStringLiteral("color: rgb(0, 85, 0);"));
        btnStopProcess = new QPushButton(processBox);
        btnStopProcess->setObjectName(QStringLiteral("btnStopProcess"));
        btnStopProcess->setGeometry(QRect(10, 120, 71, 31));
        btnStopProcess->setFont(font2);
        btnStopProcess->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));
        btnSoldProducts = new QPushButton(processBox);
        btnSoldProducts->setObjectName(QStringLiteral("btnSoldProducts"));
        btnSoldProducts->setGeometry(QRect(10, 80, 155, 28));
        btnSoldProducts->setFont(font);
        btnStopGenOrders = new QPushButton(processBox);
        btnStopGenOrders->setObjectName(QStringLiteral("btnStopGenOrders"));
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
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1450, 26));
        GuiClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GuiClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GuiClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GuiClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setFont(font5);
        GuiClass->setStatusBar(statusBar);

        retranslateUi(GuiClass);

        QMetaObject::connectSlotsByName(GuiClass);
    } // setupUi

    void retranslateUi(QMainWindow *GuiClass)
    {
        GuiClass->setWindowTitle(QApplication::translate("GuiClass", "\320\241\320\270\321\201\321\202\320\265\320\274\320\260 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217 \320\276\320\277\321\202\320\276\320\262\321\213\320\274 \321\201\320\272\320\273\320\260\320\264\320\276\320\274", nullptr));
        btnStoreOrdBrowse->setText(QApplication::translate("GuiClass", "?", nullptr));
        btnCargoStoreBrowse->setText(QApplication::translate("GuiClass", "?", nullptr));
        btnConfCargoStore->setText(QApplication::translate("GuiClass", "V", nullptr));
        btnRemoveCargoStore->setText(QApplication::translate("GuiClass", "X", nullptr));
        lblDiscountTW->setText(QApplication::translate("GuiClass", "\320\237\321\200\320\265\320\264\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\264\320\273\321\217 \321\201\320\272\320\270\320\264\320\276\320\272", nullptr));
        lblStoreOrdersTW->setText(QApplication::translate("GuiClass", "\320\227\320\260\320\272\320\260\320\267\321\213 \320\276\321\202 \320\274\320\260\320\263\320\260\320\267\320\270\320\275\320\276\320\262", nullptr));
        lblCargoStoresTW->setText(QApplication::translate("GuiClass", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\277\320\265\321\200\320\265\320\262\320\276\320\267\320\276\320\272", nullptr));
        lblWarehouseTW->setText(QApplication::translate("GuiClass", "\320\241\320\272\320\273\320\260\320\264", nullptr));
        lblExpiredPrdTW->setText(QApplication::translate("GuiClass", "\320\237\321\200\320\276\321\201\321\200\320\276\321\207\320\265\320\275\320\275\321\213\320\265 \320\277\321\200\320\276\320\264\321\203\320\272\321\202\321\213", nullptr));
        lblExpiredSum->setText(QApplication::translate("GuiClass", "\320\243\320\261\321\213\321\202\320\272\320\270", nullptr));
        btnRackBrowse->setText(QApplication::translate("GuiClass", "?", nullptr));
        lblDiscountSum->setText(QApplication::translate("GuiClass", "\320\243\320\261\321\213\321\202\320\272\320\270", nullptr));
        btnExecDiscount->setText(QApplication::translate("GuiClass", "V", nullptr));
        btnRemoveDiscount->setText(QApplication::translate("GuiClass", "X", nullptr));
        lblPrecent->setText(QApplication::translate("GuiClass", "%", nullptr));
        btnChangeDisclount->setText(QApplication::translate("GuiClass", "!", nullptr));
        lblCargoWarehouseTW->setText(QApplication::translate("GuiClass", "\320\227\320\260\320\272\320\260\320\267\321\213 \320\275\320\260 \320\277\320\276\321\201\321\202\320\260\320\262\320\272\321\203", nullptr));
        lblCargoBalance->setText(QApplication::translate("GuiClass", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \321\201\321\203\320\274\320\274\320\260  \320\277\320\265\321\200\320\265\320\262\320\276\320\267\320\276\320\272", nullptr));
        btnConfCargoWarehouse->setText(QApplication::translate("GuiClass", "V", nullptr));
        btnCargoWarehouseBrowse->setText(QApplication::translate("GuiClass", "?", nullptr));
        btnRemoveCargoWarehouse->setText(QApplication::translate("GuiClass", "X", nullptr));
        financeBox->setTitle(QApplication::translate("GuiClass", "\320\244\320\270\320\275\320\260\320\275\321\201\321\213", nullptr));
        lblSummary->setText(QApplication::translate("GuiClass", "\320\222\321\201\320\265\320\263\320\276", nullptr));
        lblIntiCapital->setText(QApplication::translate("GuiClass", "\320\235\320\260\321\207\320\260\320\273. \320\272\320\260\320\277\320\270\321\202\320\260\320\273", nullptr));
        lblSale->setText(QApplication::translate("GuiClass", "\320\237\321\200\320\276\320\264\320\260\320\275\320\276", nullptr));
        lblDelivered->setText(QApplication::translate("GuiClass", "\320\237\320\276\321\201\321\202\320\262\320\260\320\273\320\265\320\275\320\276", nullptr));
        lblBalance->setText(QApplication::translate("GuiClass", "\320\236\321\201\321\202\320\260\321\202\320\276\320\272", nullptr));
        lblDamages->setText(QApplication::translate("GuiClass", "\320\243\320\261\321\213\321\202\320\272\320\270", nullptr));
        processBox->setTitle(QApplication::translate("GuiClass", "\320\237\321\200\320\276\321\206\320\265\321\201\321\201", nullptr));
        lblTime->setText(QApplication::translate("GuiClass", "\320\224\320\224:\320\247\320\247", nullptr));
        btnDeactivateProcess->setText(QApplication::translate("GuiClass", "||", nullptr));
        btnActivateProcess->setText(QApplication::translate("GuiClass", ">", nullptr));
        btnStopProcess->setText(QApplication::translate("GuiClass", "STOP", nullptr));
        btnSoldProducts->setText(QApplication::translate("GuiClass", "\320\237\321\200\320\276\320\264\320\260\320\275\320\275\321\213\320\265 \320\277\321\200\320\276\320\264\321\203\320\272\321\202\321\213", nullptr));
#ifndef QT_NO_TOOLTIP
        btnStopGenOrders->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnStopGenOrders->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        btnStopGenOrders->setText(QApplication::translate("GuiClass", "\320\236\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\263\320\265\320\275\320\265\321\200\320\260\321\206\320\270\321\216 \n"
"\320\267\320\260\320\272\320\260\320\267\320\276\320\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GuiClass: public Ui_GuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
