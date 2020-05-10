/****************************************************************************
** Meta object code from reading C++ file 'Manager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../The-Simps/The-Simps/Manager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Manager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Manager_t {
    QByteArrayData data[21];
    char stringdata0[477];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Manager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Manager_t qt_meta_stringdata_Manager = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Manager"
QT_MOC_LITERAL(1, 8, 14), // "setupSalesPage"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 17), // "setupCustomerPage"
QT_MOC_LITERAL(4, 42, 18), // "setupInventoryPage"
QT_MOC_LITERAL(5, 61, 19), // "setupMembershipPage"
QT_MOC_LITERAL(6, 81, 16), // "setupRebatesPage"
QT_MOC_LITERAL(7, 98, 22), // "on_salesButton_clicked"
QT_MOC_LITERAL(8, 121, 25), // "on_customerButton_clicked"
QT_MOC_LITERAL(9, 147, 26), // "on_inventoryButton_clicked"
QT_MOC_LITERAL(10, 174, 27), // "on_membershipButton_clicked"
QT_MOC_LITERAL(11, 202, 24), // "on_rebatesButton_clicked"
QT_MOC_LITERAL(12, 227, 34), // "on_salesPage_previewButton_cl..."
QT_MOC_LITERAL(13, 262, 33), // "on_customerPage_sortBox_activ..."
QT_MOC_LITERAL(14, 296, 5), // "index"
QT_MOC_LITERAL(15, 302, 31), // "on_rebatePage_sortBox_activated"
QT_MOC_LITERAL(16, 334, 36), // "on_customerPage_searchButton_..."
QT_MOC_LITERAL(17, 371, 13), // "refreshSearch"
QT_MOC_LITERAL(18, 385, 38), // "on_membershipPage_searchButto..."
QT_MOC_LITERAL(19, 424, 37), // "on_inventoryPage_searchButton..."
QT_MOC_LITERAL(20, 462, 14) // "generateReport"

    },
    "Manager\0setupSalesPage\0\0setupCustomerPage\0"
    "setupInventoryPage\0setupMembershipPage\0"
    "setupRebatesPage\0on_salesButton_clicked\0"
    "on_customerButton_clicked\0"
    "on_inventoryButton_clicked\0"
    "on_membershipButton_clicked\0"
    "on_rebatesButton_clicked\0"
    "on_salesPage_previewButton_clicked\0"
    "on_customerPage_sortBox_activated\0"
    "index\0on_rebatePage_sortBox_activated\0"
    "on_customerPage_searchButton_clicked\0"
    "refreshSearch\0on_membershipPage_searchButton_clicked\0"
    "on_inventoryPage_searchButton_clicked\0"
    "generateReport"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Manager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x08 /* Private */,
       3,    0,  105,    2, 0x08 /* Private */,
       4,    0,  106,    2, 0x08 /* Private */,
       5,    0,  107,    2, 0x08 /* Private */,
       6,    0,  108,    2, 0x08 /* Private */,
       7,    0,  109,    2, 0x08 /* Private */,
       8,    0,  110,    2, 0x08 /* Private */,
       9,    0,  111,    2, 0x08 /* Private */,
      10,    0,  112,    2, 0x08 /* Private */,
      11,    0,  113,    2, 0x08 /* Private */,
      12,    0,  114,    2, 0x08 /* Private */,
      13,    1,  115,    2, 0x08 /* Private */,
      15,    1,  118,    2, 0x08 /* Private */,
      16,    0,  121,    2, 0x08 /* Private */,
      17,    0,  122,    2, 0x08 /* Private */,
      18,    0,  123,    2, 0x08 /* Private */,
      19,    0,  124,    2, 0x08 /* Private */,
      20,    0,  125,    2, 0x0a /* Public */,

 // slots: parameters
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
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Manager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Manager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setupSalesPage(); break;
        case 1: _t->setupCustomerPage(); break;
        case 2: _t->setupInventoryPage(); break;
        case 3: _t->setupMembershipPage(); break;
        case 4: _t->setupRebatesPage(); break;
        case 5: _t->on_salesButton_clicked(); break;
        case 6: _t->on_customerButton_clicked(); break;
        case 7: _t->on_inventoryButton_clicked(); break;
        case 8: _t->on_membershipButton_clicked(); break;
        case 9: _t->on_rebatesButton_clicked(); break;
        case 10: _t->on_salesPage_previewButton_clicked(); break;
        case 11: _t->on_customerPage_sortBox_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_rebatePage_sortBox_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_customerPage_searchButton_clicked(); break;
        case 14: _t->refreshSearch(); break;
        case 15: _t->on_membershipPage_searchButton_clicked(); break;
        case 16: _t->on_inventoryPage_searchButton_clicked(); break;
        case 17: _t->generateReport(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Manager::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Manager.data,
    qt_meta_data_Manager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Manager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Manager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Manager.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Manager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
