/****************************************************************************
** Meta object code from reading C++ file 'pqDoubleRangeWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Qt/Widgets/pqDoubleRangeWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pqDoubleRangeWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pqDoubleRangeWidget_t {
    QByteArrayData data[19];
    char stringdata0[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pqDoubleRangeWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pqDoubleRangeWidget_t qt_meta_stringdata_pqDoubleRangeWidget = {
    {
QT_MOC_LITERAL(0, 0, 19), // "pqDoubleRangeWidget"
QT_MOC_LITERAL(1, 20, 12), // "valueChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 11), // "valueEdited"
QT_MOC_LITERAL(4, 46, 8), // "setValue"
QT_MOC_LITERAL(5, 55, 10), // "setMinimum"
QT_MOC_LITERAL(6, 66, 10), // "setMaximum"
QT_MOC_LITERAL(7, 77, 14), // "setStrictRange"
QT_MOC_LITERAL(8, 92, 13), // "setResolution"
QT_MOC_LITERAL(9, 106, 13), // "sliderChanged"
QT_MOC_LITERAL(10, 120, 11), // "textChanged"
QT_MOC_LITERAL(11, 132, 15), // "editingFinished"
QT_MOC_LITERAL(12, 148, 15), // "updateValidator"
QT_MOC_LITERAL(13, 164, 12), // "updateSlider"
QT_MOC_LITERAL(14, 177, 5), // "value"
QT_MOC_LITERAL(15, 183, 7), // "minimum"
QT_MOC_LITERAL(16, 191, 7), // "maximum"
QT_MOC_LITERAL(17, 199, 11), // "strictRange"
QT_MOC_LITERAL(18, 211, 10) // "resolution"

    },
    "pqDoubleRangeWidget\0valueChanged\0\0"
    "valueEdited\0setValue\0setMinimum\0"
    "setMaximum\0setStrictRange\0setResolution\0"
    "sliderChanged\0textChanged\0editingFinished\0"
    "updateValidator\0updateSlider\0value\0"
    "minimum\0maximum\0strictRange\0resolution"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pqDoubleRangeWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       5,  104, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       3,    1,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   80,    2, 0x0a /* Public */,
       5,    1,   83,    2, 0x0a /* Public */,
       6,    1,   86,    2, 0x0a /* Public */,
       7,    1,   89,    2, 0x0a /* Public */,
       8,    1,   92,    2, 0x0a /* Public */,
       9,    1,   95,    2, 0x08 /* Private */,
      10,    1,   98,    2, 0x08 /* Private */,
      11,    0,  101,    2, 0x08 /* Private */,
      12,    0,  102,    2, 0x08 /* Private */,
      13,    0,  103,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      14, QMetaType::Double, 0x00195103,
      15, QMetaType::Double, 0x00095103,
      16, QMetaType::Double, 0x00095103,
      17, QMetaType::Bool, 0x00095103,
      18, QMetaType::Int, 0x00095103,

       0        // eod
};

void pqDoubleRangeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        pqDoubleRangeWidget *_t = static_cast<pqDoubleRangeWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->valueEdited((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->setValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->setMinimum((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->setMaximum((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->setStrictRange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->setResolution((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->sliderChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->editingFinished(); break;
        case 10: _t->updateValidator(); break;
        case 11: _t->updateSlider(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (pqDoubleRangeWidget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pqDoubleRangeWidget::valueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (pqDoubleRangeWidget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pqDoubleRangeWidget::valueEdited)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        pqDoubleRangeWidget *_t = static_cast<pqDoubleRangeWidget *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< double*>(_v) = _t->value(); break;
        case 1: *reinterpret_cast< double*>(_v) = _t->minimum(); break;
        case 2: *reinterpret_cast< double*>(_v) = _t->maximum(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->strictRange(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->resolution(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        pqDoubleRangeWidget *_t = static_cast<pqDoubleRangeWidget *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setValue(*reinterpret_cast< double*>(_v)); break;
        case 1: _t->setMinimum(*reinterpret_cast< double*>(_v)); break;
        case 2: _t->setMaximum(*reinterpret_cast< double*>(_v)); break;
        case 3: _t->setStrictRange(*reinterpret_cast< bool*>(_v)); break;
        case 4: _t->setResolution(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject pqDoubleRangeWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_pqDoubleRangeWidget.data,
      qt_meta_data_pqDoubleRangeWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *pqDoubleRangeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pqDoubleRangeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_pqDoubleRangeWidget.stringdata0))
        return static_cast<void*>(const_cast< pqDoubleRangeWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int pqDoubleRangeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void pqDoubleRangeWidget::valueChanged(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void pqDoubleRangeWidget::valueEdited(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
