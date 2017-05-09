/****************************************************************************
** Meta object code from reading C++ file 'pqCustomViewButtonDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Qt/Components/pqCustomViewButtonDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pqCustomViewButtonDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pqCustomViewButtonDialog_t {
    QByteArrayData data[11];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pqCustomViewButtonDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pqCustomViewButtonDialog_t qt_meta_stringdata_pqCustomViewButtonDialog = {
    {
QT_MOC_LITERAL(0, 0, 24), // "pqCustomViewButtonDialog"
QT_MOC_LITERAL(1, 25, 20), // "importConfigurations"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 20), // "exportConfigurations"
QT_MOC_LITERAL(4, 68, 8), // "clearAll"
QT_MOC_LITERAL(5, 77, 17), // "assignCurrentView"
QT_MOC_LITERAL(6, 95, 2), // "id"
QT_MOC_LITERAL(7, 98, 18), // "assignCurrentView0"
QT_MOC_LITERAL(8, 117, 18), // "assignCurrentView1"
QT_MOC_LITERAL(9, 136, 18), // "assignCurrentView2"
QT_MOC_LITERAL(10, 155, 18) // "assignCurrentView3"

    },
    "pqCustomViewButtonDialog\0importConfigurations\0"
    "\0exportConfigurations\0clearAll\0"
    "assignCurrentView\0id\0assignCurrentView0\0"
    "assignCurrentView1\0assignCurrentView2\0"
    "assignCurrentView3"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pqCustomViewButtonDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    1,   57,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void pqCustomViewButtonDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        pqCustomViewButtonDialog *_t = static_cast<pqCustomViewButtonDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->importConfigurations(); break;
        case 1: _t->exportConfigurations(); break;
        case 2: _t->clearAll(); break;
        case 3: _t->assignCurrentView((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->assignCurrentView0(); break;
        case 5: _t->assignCurrentView1(); break;
        case 6: _t->assignCurrentView2(); break;
        case 7: _t->assignCurrentView3(); break;
        default: ;
        }
    }
}

const QMetaObject pqCustomViewButtonDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_pqCustomViewButtonDialog.data,
      qt_meta_data_pqCustomViewButtonDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *pqCustomViewButtonDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pqCustomViewButtonDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_pqCustomViewButtonDialog.stringdata0))
        return static_cast<void*>(const_cast< pqCustomViewButtonDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int pqCustomViewButtonDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
