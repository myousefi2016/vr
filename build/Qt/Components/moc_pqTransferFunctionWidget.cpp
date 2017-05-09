/****************************************************************************
** Meta object code from reading C++ file 'pqTransferFunctionWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Qt/Components/pqTransferFunctionWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pqTransferFunctionWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pqTransferFunctionWidget_t {
    QByteArrayData data[12];
    char stringdata0[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pqTransferFunctionWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pqTransferFunctionWidget_t qt_meta_stringdata_pqTransferFunctionWidget = {
    {
QT_MOC_LITERAL(0, 0, 24), // "pqTransferFunctionWidget"
QT_MOC_LITERAL(1, 25, 19), // "currentPointChanged"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 9), // "vtkIdType"
QT_MOC_LITERAL(4, 56, 5), // "index"
QT_MOC_LITERAL(5, 62, 21), // "controlPointsModified"
QT_MOC_LITERAL(6, 84, 15), // "setCurrentPoint"
QT_MOC_LITERAL(7, 100, 23), // "setCurrentPointPosition"
QT_MOC_LITERAL(8, 124, 4), // "xpos"
QT_MOC_LITERAL(9, 129, 6), // "render"
QT_MOC_LITERAL(10, 136, 21), // "onCurrentChangedEvent"
QT_MOC_LITERAL(11, 158, 14) // "renderInternal"

    },
    "pqTransferFunctionWidget\0currentPointChanged\0"
    "\0vtkIdType\0index\0controlPointsModified\0"
    "setCurrentPoint\0setCurrentPointPosition\0"
    "xpos\0render\0onCurrentChangedEvent\0"
    "renderInternal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pqTransferFunctionWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       5,    0,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   53,    2, 0x0a /* Public */,
       7,    1,   56,    2, 0x0a /* Public */,
       9,    0,   59,    2, 0x0a /* Public */,
      10,    0,   60,    2, 0x09 /* Protected */,
      11,    0,   61,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void pqTransferFunctionWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        pqTransferFunctionWidget *_t = static_cast<pqTransferFunctionWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentPointChanged((*reinterpret_cast< vtkIdType(*)>(_a[1]))); break;
        case 1: _t->controlPointsModified(); break;
        case 2: _t->setCurrentPoint((*reinterpret_cast< vtkIdType(*)>(_a[1]))); break;
        case 3: _t->setCurrentPointPosition((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->render(); break;
        case 5: _t->onCurrentChangedEvent(); break;
        case 6: _t->renderInternal(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (pqTransferFunctionWidget::*_t)(vtkIdType );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pqTransferFunctionWidget::currentPointChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (pqTransferFunctionWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pqTransferFunctionWidget::controlPointsModified)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject pqTransferFunctionWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_pqTransferFunctionWidget.data,
      qt_meta_data_pqTransferFunctionWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *pqTransferFunctionWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pqTransferFunctionWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_pqTransferFunctionWidget.stringdata0))
        return static_cast<void*>(const_cast< pqTransferFunctionWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int pqTransferFunctionWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void pqTransferFunctionWidget::currentPointChanged(vtkIdType _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void pqTransferFunctionWidget::controlPointsModified()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
