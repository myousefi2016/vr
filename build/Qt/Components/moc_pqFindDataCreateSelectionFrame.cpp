/****************************************************************************
** Meta object code from reading C++ file 'pqFindDataCreateSelectionFrame.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Qt/Components/pqFindDataCreateSelectionFrame.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pqFindDataCreateSelectionFrame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pqFindDataCreateSelectionFrame_t {
    QByteArrayData data[9];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pqFindDataCreateSelectionFrame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pqFindDataCreateSelectionFrame_t qt_meta_stringdata_pqFindDataCreateSelectionFrame = {
    {
QT_MOC_LITERAL(0, 0, 30), // "pqFindDataCreateSelectionFrame"
QT_MOC_LITERAL(1, 31, 13), // "helpRequested"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 7), // "setPort"
QT_MOC_LITERAL(4, 54, 13), // "pqOutputPort*"
QT_MOC_LITERAL(5, 68, 11), // "dataChanged"
QT_MOC_LITERAL(6, 80, 12), // "refreshQuery"
QT_MOC_LITERAL(7, 93, 8), // "runQuery"
QT_MOC_LITERAL(8, 102, 18) // "onSelectionChanged"

    },
    "pqFindDataCreateSelectionFrame\0"
    "helpRequested\0\0setPort\0pqOutputPort*\0"
    "dataChanged\0refreshQuery\0runQuery\0"
    "onSelectionChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pqFindDataCreateSelectionFrame[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   45,    2, 0x0a /* Public */,
       5,    0,   48,    2, 0x08 /* Private */,
       6,    0,   49,    2, 0x08 /* Private */,
       7,    0,   50,    2, 0x08 /* Private */,
       8,    1,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,

       0        // eod
};

void pqFindDataCreateSelectionFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        pqFindDataCreateSelectionFrame *_t = static_cast<pqFindDataCreateSelectionFrame *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->helpRequested(); break;
        case 1: _t->setPort((*reinterpret_cast< pqOutputPort*(*)>(_a[1]))); break;
        case 2: _t->dataChanged(); break;
        case 3: _t->refreshQuery(); break;
        case 4: _t->runQuery(); break;
        case 5: _t->onSelectionChanged((*reinterpret_cast< pqOutputPort*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (pqFindDataCreateSelectionFrame::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pqFindDataCreateSelectionFrame::helpRequested)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject pqFindDataCreateSelectionFrame::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_pqFindDataCreateSelectionFrame.data,
      qt_meta_data_pqFindDataCreateSelectionFrame,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *pqFindDataCreateSelectionFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pqFindDataCreateSelectionFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_pqFindDataCreateSelectionFrame.stringdata0))
        return static_cast<void*>(const_cast< pqFindDataCreateSelectionFrame*>(this));
    return QWidget::qt_metacast(_clname);
}

int pqFindDataCreateSelectionFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void pqFindDataCreateSelectionFrame::helpRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
