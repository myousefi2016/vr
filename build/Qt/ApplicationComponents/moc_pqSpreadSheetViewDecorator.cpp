/****************************************************************************
** Meta object code from reading C++ file 'pqSpreadSheetViewDecorator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Qt/ApplicationComponents/pqSpreadSheetViewDecorator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pqSpreadSheetViewDecorator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pqSpreadSheetViewDecorator_t {
    QByteArrayData data[12];
    char stringdata0[230];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pqSpreadSheetViewDecorator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pqSpreadSheetViewDecorator_t qt_meta_stringdata_pqSpreadSheetViewDecorator = {
    {
QT_MOC_LITERAL(0, 0, 26), // "pqSpreadSheetViewDecorator"
QT_MOC_LITERAL(1, 27, 19), // "currentIndexChanged"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 13), // "pqOutputPort*"
QT_MOC_LITERAL(4, 62, 7), // "showing"
QT_MOC_LITERAL(5, 70, 21), // "pqDataRepresentation*"
QT_MOC_LITERAL(6, 92, 23), // "displayPrecisionChanged"
QT_MOC_LITERAL(7, 116, 25), // "showToggleColumnPopupMenu"
QT_MOC_LITERAL(8, 142, 21), // "resetColumnVisibility"
QT_MOC_LITERAL(9, 164, 22), // "updateColumnVisibility"
QT_MOC_LITERAL(10, 187, 22), // "toggleCellConnectivity"
QT_MOC_LITERAL(11, 210, 19) // "allowChangeOfSource"

    },
    "pqSpreadSheetViewDecorator\0"
    "currentIndexChanged\0\0pqOutputPort*\0"
    "showing\0pqDataRepresentation*\0"
    "displayPrecisionChanged\0"
    "showToggleColumnPopupMenu\0"
    "resetColumnVisibility\0updateColumnVisibility\0"
    "toggleCellConnectivity\0allowChangeOfSource"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pqSpreadSheetViewDecorator[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       1,   62, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x09 /* Protected */,
       4,    1,   52,    2, 0x09 /* Protected */,
       6,    1,   55,    2, 0x09 /* Protected */,
       7,    0,   58,    2, 0x09 /* Protected */,
       8,    0,   59,    2, 0x09 /* Protected */,
       9,    0,   60,    2, 0x09 /* Protected */,
      10,    0,   61,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      11, QMetaType::Bool, 0x00095103,

       0        // eod
};

void pqSpreadSheetViewDecorator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        pqSpreadSheetViewDecorator *_t = static_cast<pqSpreadSheetViewDecorator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentIndexChanged((*reinterpret_cast< pqOutputPort*(*)>(_a[1]))); break;
        case 1: _t->showing((*reinterpret_cast< pqDataRepresentation*(*)>(_a[1]))); break;
        case 2: _t->displayPrecisionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->showToggleColumnPopupMenu(); break;
        case 4: _t->resetColumnVisibility(); break;
        case 5: _t->updateColumnVisibility(); break;
        case 6: _t->toggleCellConnectivity(); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        pqSpreadSheetViewDecorator *_t = static_cast<pqSpreadSheetViewDecorator *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->allowChangeOfSource(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        pqSpreadSheetViewDecorator *_t = static_cast<pqSpreadSheetViewDecorator *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setAllowChangeOfSource(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject pqSpreadSheetViewDecorator::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_pqSpreadSheetViewDecorator.data,
      qt_meta_data_pqSpreadSheetViewDecorator,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *pqSpreadSheetViewDecorator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pqSpreadSheetViewDecorator::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_pqSpreadSheetViewDecorator.stringdata0))
        return static_cast<void*>(const_cast< pqSpreadSheetViewDecorator*>(this));
    return QObject::qt_metacast(_clname);
}

int pqSpreadSheetViewDecorator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
