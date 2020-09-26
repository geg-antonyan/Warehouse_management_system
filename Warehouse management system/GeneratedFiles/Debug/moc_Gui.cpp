/****************************************************************************
** Meta object code from reading C++ file 'Gui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/gui/Gui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Gui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Gui_t {
    QByteArrayData data[52];
    char stringdata0[1001];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Gui_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Gui_t qt_meta_stringdata_Gui = {
    {
QT_MOC_LITERAL(0, 0, 3), // "Gui"
QT_MOC_LITERAL(1, 4, 10), // "signalPost"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 11), // "signalError"
QT_MOC_LITERAL(4, 28, 10), // "signalTick"
QT_MOC_LITERAL(5, 39, 13), // "signalProcess"
QT_MOC_LITERAL(6, 53, 16), // "signalPrdCatalog"
QT_MOC_LITERAL(7, 70, 16), // "signalBoxCatalog"
QT_MOC_LITERAL(8, 87, 16), // "signalStoreRepos"
QT_MOC_LITERAL(9, 104, 15), // "signalWarehouse"
QT_MOC_LITERAL(10, 120, 16), // "signalStoreOrder"
QT_MOC_LITERAL(11, 137, 16), // "signalCargoStore"
QT_MOC_LITERAL(12, 154, 17), // "signaleExpiredPrd"
QT_MOC_LITERAL(13, 172, 20), // "signalDiscountsRepos"
QT_MOC_LITERAL(14, 193, 20), // "signalCargoWarehouse"
QT_MOC_LITERAL(15, 214, 10), // "closeEvent"
QT_MOC_LITERAL(16, 225, 12), // "QCloseEvent*"
QT_MOC_LITERAL(17, 238, 6), // "_event"
QT_MOC_LITERAL(18, 245, 29), // "on_btnActivateProcess_clicked"
QT_MOC_LITERAL(19, 275, 31), // "on_btnDeactivateProcess_clicked"
QT_MOC_LITERAL(20, 307, 27), // "on_btnStopGenOrders_clicked"
QT_MOC_LITERAL(21, 335, 25), // "on_btnStopProcess_clicked"
QT_MOC_LITERAL(22, 361, 26), // "on_btnSoldProducts_clicked"
QT_MOC_LITERAL(23, 388, 28), // "on_btnStoreOrdBrowse_clicked"
QT_MOC_LITERAL(24, 417, 30), // "on_btnCargoStoreBrowse_clicked"
QT_MOC_LITERAL(25, 448, 34), // "on_btnCargoWarehouseBrowse_cl..."
QT_MOC_LITERAL(26, 483, 24), // "on_btnRackBrowse_clicked"
QT_MOC_LITERAL(27, 508, 26), // "on_btnExecDiscount_clicked"
QT_MOC_LITERAL(28, 535, 28), // "on_btnRemoveDiscount_clicked"
QT_MOC_LITERAL(29, 564, 29), // "on_btnChangeDisclount_clicked"
QT_MOC_LITERAL(30, 594, 30), // "on_btnRemoveCargoStore_clicked"
QT_MOC_LITERAL(31, 625, 34), // "on_btnRemoveCargoWarehouse_cl..."
QT_MOC_LITERAL(32, 660, 28), // "on_btnConfCargoStore_clicked"
QT_MOC_LITERAL(33, 689, 32), // "on_btnConfCargoWarehouse_clicked"
QT_MOC_LITERAL(34, 722, 10), // "nextWindow"
QT_MOC_LITERAL(35, 733, 10), // "prewWindow"
QT_MOC_LITERAL(36, 744, 11), // "execCommand"
QT_MOC_LITERAL(37, 756, 8), // "QString&"
QT_MOC_LITERAL(38, 765, 4), // "_cmd"
QT_MOC_LITERAL(39, 770, 16), // "showErrorMessage"
QT_MOC_LITERAL(40, 787, 15), // "showPostMessage"
QT_MOC_LITERAL(41, 803, 10), // "changeTime"
QT_MOC_LITERAL(42, 814, 16), // "UpdatePrdCatalog"
QT_MOC_LITERAL(43, 831, 16), // "UpdateBoxCatalog"
QT_MOC_LITERAL(44, 848, 16), // "UpdateStoreRepos"
QT_MOC_LITERAL(45, 865, 15), // "UpdateWarehouse"
QT_MOC_LITERAL(46, 881, 19), // "UpdateStoreOrdRepos"
QT_MOC_LITERAL(47, 901, 22), // "UpdateCargoStoresRepos"
QT_MOC_LITERAL(48, 924, 16), // "UpdateExpiredPrd"
QT_MOC_LITERAL(49, 941, 20), // "UpdateDiscountsRepos"
QT_MOC_LITERAL(50, 962, 25), // "UpdateCargoWarehouseRepos"
QT_MOC_LITERAL(51, 988, 12) // "StartProcess"

    },
    "Gui\0signalPost\0\0signalError\0signalTick\0"
    "signalProcess\0signalPrdCatalog\0"
    "signalBoxCatalog\0signalStoreRepos\0"
    "signalWarehouse\0signalStoreOrder\0"
    "signalCargoStore\0signaleExpiredPrd\0"
    "signalDiscountsRepos\0signalCargoWarehouse\0"
    "closeEvent\0QCloseEvent*\0_event\0"
    "on_btnActivateProcess_clicked\0"
    "on_btnDeactivateProcess_clicked\0"
    "on_btnStopGenOrders_clicked\0"
    "on_btnStopProcess_clicked\0"
    "on_btnSoldProducts_clicked\0"
    "on_btnStoreOrdBrowse_clicked\0"
    "on_btnCargoStoreBrowse_clicked\0"
    "on_btnCargoWarehouseBrowse_clicked\0"
    "on_btnRackBrowse_clicked\0"
    "on_btnExecDiscount_clicked\0"
    "on_btnRemoveDiscount_clicked\0"
    "on_btnChangeDisclount_clicked\0"
    "on_btnRemoveCargoStore_clicked\0"
    "on_btnRemoveCargoWarehouse_clicked\0"
    "on_btnConfCargoStore_clicked\0"
    "on_btnConfCargoWarehouse_clicked\0"
    "nextWindow\0prewWindow\0execCommand\0"
    "QString&\0_cmd\0showErrorMessage\0"
    "showPostMessage\0changeTime\0UpdatePrdCatalog\0"
    "UpdateBoxCatalog\0UpdateStoreRepos\0"
    "UpdateWarehouse\0UpdateStoreOrdRepos\0"
    "UpdateCargoStoresRepos\0UpdateExpiredPrd\0"
    "UpdateDiscountsRepos\0UpdateCargoWarehouseRepos\0"
    "StartProcess"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Gui[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      46,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  244,    2, 0x06 /* Public */,
       3,    1,  247,    2, 0x06 /* Public */,
       4,    0,  250,    2, 0x06 /* Public */,
       5,    0,  251,    2, 0x06 /* Public */,
       6,    0,  252,    2, 0x06 /* Public */,
       7,    0,  253,    2, 0x06 /* Public */,
       8,    0,  254,    2, 0x06 /* Public */,
       9,    0,  255,    2, 0x06 /* Public */,
      10,    0,  256,    2, 0x06 /* Public */,
      11,    0,  257,    2, 0x06 /* Public */,
      12,    0,  258,    2, 0x06 /* Public */,
      13,    0,  259,    2, 0x06 /* Public */,
      14,    0,  260,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    1,  261,    2, 0x08 /* Private */,
      18,    0,  264,    2, 0x08 /* Private */,
      19,    0,  265,    2, 0x08 /* Private */,
      20,    0,  266,    2, 0x08 /* Private */,
      21,    0,  267,    2, 0x08 /* Private */,
      22,    0,  268,    2, 0x08 /* Private */,
      23,    0,  269,    2, 0x08 /* Private */,
      24,    0,  270,    2, 0x08 /* Private */,
      25,    0,  271,    2, 0x08 /* Private */,
      26,    0,  272,    2, 0x08 /* Private */,
      27,    0,  273,    2, 0x08 /* Private */,
      28,    0,  274,    2, 0x08 /* Private */,
      29,    0,  275,    2, 0x08 /* Private */,
      30,    0,  276,    2, 0x08 /* Private */,
      31,    0,  277,    2, 0x08 /* Private */,
      32,    0,  278,    2, 0x08 /* Private */,
      33,    0,  279,    2, 0x08 /* Private */,
      34,    0,  280,    2, 0x08 /* Private */,
      35,    0,  281,    2, 0x08 /* Private */,
      36,    1,  282,    2, 0x08 /* Private */,
      39,    1,  285,    2, 0x08 /* Private */,
      40,    1,  288,    2, 0x08 /* Private */,
      41,    0,  291,    2, 0x08 /* Private */,
      42,    0,  292,    2, 0x08 /* Private */,
      43,    0,  293,    2, 0x08 /* Private */,
      44,    0,  294,    2, 0x08 /* Private */,
      45,    0,  295,    2, 0x08 /* Private */,
      46,    0,  296,    2, 0x08 /* Private */,
      47,    0,  297,    2, 0x08 /* Private */,
      48,    0,  298,    2, 0x08 /* Private */,
      49,    0,  299,    2, 0x08 /* Private */,
      50,    0,  300,    2, 0x08 /* Private */,
      51,    0,  301,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 37,   38,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Gui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Gui *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalPost((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->signalError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->signalTick(); break;
        case 3: _t->signalProcess(); break;
        case 4: _t->signalPrdCatalog(); break;
        case 5: _t->signalBoxCatalog(); break;
        case 6: _t->signalStoreRepos(); break;
        case 7: _t->signalWarehouse(); break;
        case 8: _t->signalStoreOrder(); break;
        case 9: _t->signalCargoStore(); break;
        case 10: _t->signaleExpiredPrd(); break;
        case 11: _t->signalDiscountsRepos(); break;
        case 12: _t->signalCargoWarehouse(); break;
        case 13: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 14: _t->on_btnActivateProcess_clicked(); break;
        case 15: _t->on_btnDeactivateProcess_clicked(); break;
        case 16: _t->on_btnStopGenOrders_clicked(); break;
        case 17: _t->on_btnStopProcess_clicked(); break;
        case 18: _t->on_btnSoldProducts_clicked(); break;
        case 19: _t->on_btnStoreOrdBrowse_clicked(); break;
        case 20: _t->on_btnCargoStoreBrowse_clicked(); break;
        case 21: _t->on_btnCargoWarehouseBrowse_clicked(); break;
        case 22: _t->on_btnRackBrowse_clicked(); break;
        case 23: _t->on_btnExecDiscount_clicked(); break;
        case 24: _t->on_btnRemoveDiscount_clicked(); break;
        case 25: _t->on_btnChangeDisclount_clicked(); break;
        case 26: _t->on_btnRemoveCargoStore_clicked(); break;
        case 27: _t->on_btnRemoveCargoWarehouse_clicked(); break;
        case 28: _t->on_btnConfCargoStore_clicked(); break;
        case 29: _t->on_btnConfCargoWarehouse_clicked(); break;
        case 30: _t->nextWindow(); break;
        case 31: _t->prewWindow(); break;
        case 32: _t->execCommand((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 33: _t->showErrorMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 34: _t->showPostMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 35: _t->changeTime(); break;
        case 36: _t->UpdatePrdCatalog(); break;
        case 37: _t->UpdateBoxCatalog(); break;
        case 38: _t->UpdateStoreRepos(); break;
        case 39: _t->UpdateWarehouse(); break;
        case 40: _t->UpdateStoreOrdRepos(); break;
        case 41: _t->UpdateCargoStoresRepos(); break;
        case 42: _t->UpdateExpiredPrd(); break;
        case 43: _t->UpdateDiscountsRepos(); break;
        case 44: _t->UpdateCargoWarehouseRepos(); break;
        case 45: _t->StartProcess(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Gui::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gui::signalPost)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Gui::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gui::signalError)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Gui::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gui::signalTick)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Gui::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gui::signalProcess)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Gui::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gui::signalPrdCatalog)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Gui::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gui::signalBoxCatalog)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Gui::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gui::signalStoreRepos)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Gui::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gui::signalWarehouse)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Gui::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gui::signalStoreOrder)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Gui::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gui::signalCargoStore)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Gui::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gui::signaleExpiredPrd)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Gui::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gui::signalDiscountsRepos)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (Gui::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gui::signalCargoWarehouse)) {
                *result = 12;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Gui::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Gui.data,
    qt_meta_data_Gui,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Gui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Gui::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Gui.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "UserInterface"))
        return static_cast< UserInterface*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Gui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 46)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 46;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 46)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 46;
    }
    return _id;
}

// SIGNAL 0
void Gui::signalPost(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Gui::signalError(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Gui::signalTick()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Gui::signalProcess()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Gui::signalPrdCatalog()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Gui::signalBoxCatalog()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Gui::signalStoreRepos()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Gui::signalWarehouse()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Gui::signalStoreOrder()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void Gui::signalCargoStore()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void Gui::signaleExpiredPrd()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void Gui::signalDiscountsRepos()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void Gui::signalCargoWarehouse()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
