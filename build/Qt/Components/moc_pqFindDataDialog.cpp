/****************************************************************************
** Meta object code from reading C++ file 'pqFindDataDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Qt/Components/pqFindDataDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pqFindDataDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pqFindDataDialog_t {
    QByteArrayData data[8];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pqFindDataDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pqFindDataDialog_t qt_meta_stringdata_pqFindDataDialog = {
    {
QT_MOC_LITERAL(0, 0, 16), // "pqFindDataDialog"
QT_MOC_LITERAL(1, 17, 13), // "helpRequested"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 7), // "showing"
QT_MOC_LITERAL(4, 40, 13), // "pqOutputPort*"
QT_MOC_LITERAL(5, 54, 15), // "freezeSelection"
QT_MOC_LITERAL(6, 70, 16), // "extractSelection"
QT_MOC_LITERAL(7, 87, 24) // "extractSelectionOverTime"

    },
    "pqFindDataDialog\0helpRequested\0\0showing\0"
    "pqOutputPort*\0freezeSelection\0"
    "extractSelection\0extractSelectionOverTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pqFindDataDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   40,    2, 0x08 /* Private */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void pqFindDataDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        pqFindDataDialog *_t = static_cast<pqFindDataDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->helpRequested(); break;
        case 1: _t->showing((*reinterpret_cast< pqOutputPort*(*)>(_a[1]))); break;
        case 2: _t->freezeSelection(); break;
        case 3: _t->extractSelection(); break;
        case 4: _t->extractSelectionOverTime(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (pqFindDataDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pqFindDataDialog::helpRequested)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject pqFindDataDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_pqFindDataDialog.data,
      qt_meta_data_pqFindDataDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *pqFindDataDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pqFindDataDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_pqFindDataDialog.stringdata0))
        return static_cast<void*>(const_cast< pqFindDataDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int pqFindDataDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void pqFindDataDialog::helpRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
