/****************************************************************************
** Meta object code from reading C++ file 'pqIntRangeWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Qt/Components/pqIntRangeWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pqIntRangeWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pqIntRangeWidget_t {
    QByteArrayData data[17];
    char stringdata0[195];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pqIntRangeWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pqIntRangeWidget_t qt_meta_stringdata_pqIntRangeWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "pqIntRangeWidget"
QT_MOC_LITERAL(1, 17, 12), // "valueChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 11), // "valueEdited"
QT_MOC_LITERAL(4, 43, 8), // "setValue"
QT_MOC_LITERAL(5, 52, 10), // "setMinimum"
QT_MOC_LITERAL(6, 63, 10), // "setMaximum"
QT_MOC_LITERAL(7, 74, 14), // "setStrictRange"
QT_MOC_LITERAL(8, 89, 13), // "sliderChanged"
QT_MOC_LITERAL(9, 103, 11), // "textChanged"
QT_MOC_LITERAL(10, 115, 15), // "editingFinished"
QT_MOC_LITERAL(11, 131, 15), // "updateValidator"
QT_MOC_LITERAL(12, 147, 13), // "domainChanged"
QT_MOC_LITERAL(13, 161, 5), // "value"
QT_MOC_LITERAL(14, 167, 7), // "minimum"
QT_MOC_LITERAL(15, 175, 7), // "maximum"
QT_MOC_LITERAL(16, 183, 11) // "strictRange"

    },
    "pqIntRangeWidget\0valueChanged\0\0"
    "valueEdited\0setValue\0setMinimum\0"
    "setMaximum\0setStrictRange\0sliderChanged\0"
    "textChanged\0editingFinished\0updateValidator\0"
    "domainChanged\0value\0minimum\0maximum\0"
    "strictRange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pqIntRangeWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       4,   96, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       3,    1,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   75,    2, 0x0a /* Public */,
       5,    1,   78,    2, 0x0a /* Public */,
       6,    1,   81,    2, 0x0a /* Public */,
       7,    1,   84,    2, 0x0a /* Public */,
       8,    1,   87,    2, 0x08 /* Private */,
       9,    1,   90,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    0,   95,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      13, QMetaType::Int, 0x00195103,
      14, QMetaType::Int, 0x00095103,
      15, QMetaType::Int, 0x00095103,
      16, QMetaType::Bool, 0x00095103,

       0        // eod
};

void pqIntRangeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        pqIntRangeWidget *_t = static_cast<pqIntRangeWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->valueEdited((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setMinimum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setMaximum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setStrictRange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->sliderChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->editingFinished(); break;
        case 9: _t->updateValidator(); break;
        case 10: _t->domainChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (pqIntRangeWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pqIntRangeWidget::valueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (pqIntRangeWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pqIntRangeWidget::valueEdited)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        pqIntRangeWidget *_t = static_cast<pqIntRangeWidget *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->value(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->minimum(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->maximum(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->strictRange(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        pqIntRangeWidget *_t = static_cast<pqIntRangeWidget *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setValue(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setMinimum(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setMaximum(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setStrictRange(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject pqIntRangeWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_pqIntRangeWidget.data,
      qt_meta_data_pqIntRangeWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *pqIntRangeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pqIntRangeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_pqIntRangeWidget.stringdata0))
        return static_cast<void*>(const_cast< pqIntRangeWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int pqIntRangeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void pqIntRangeWidget::valueChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void pqIntRangeWidget::valueEdited(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
