/****************************************************************************
** Meta object code from reading C++ file 'pqTreeViewSelectionHelper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Qt/Widgets/pqTreeViewSelectionHelper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pqTreeViewSelectionHelper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pqTreeViewSelectionHelper_t {
    QByteArrayData data[7];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pqTreeViewSelectionHelper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pqTreeViewSelectionHelper_t qt_meta_stringdata_pqTreeViewSelectionHelper = {
    {
QT_MOC_LITERAL(0, 0, 25), // "pqTreeViewSelectionHelper"
QT_MOC_LITERAL(1, 26, 9), // "onClicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 3), // "idx"
QT_MOC_LITERAL(4, 41, 9), // "onPressed"
QT_MOC_LITERAL(5, 51, 15), // "showContextMenu"
QT_MOC_LITERAL(6, 67, 13) // "saveSelection"

    },
    "pqTreeViewSelectionHelper\0onClicked\0"
    "\0idx\0onPressed\0showContextMenu\0"
    "saveSelection"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pqTreeViewSelectionHelper[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x09 /* Protected */,
       4,    1,   37,    2, 0x09 /* Protected */,
       5,    1,   40,    2, 0x09 /* Protected */,
       6,    0,   43,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,

       0        // eod
};

void pqTreeViewSelectionHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        pqTreeViewSelectionHelper *_t = static_cast<pqTreeViewSelectionHelper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 1: _t->onPressed((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 2: _t->showContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 3: _t->saveSelection(); break;
        default: ;
        }
    }
}

const QMetaObject pqTreeViewSelectionHelper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_pqTreeViewSelectionHelper.data,
      qt_meta_data_pqTreeViewSelectionHelper,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *pqTreeViewSelectionHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pqTreeViewSelectionHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_pqTreeViewSelectionHelper.stringdata0))
        return static_cast<void*>(const_cast< pqTreeViewSelectionHelper*>(this));
    return QObject::qt_metacast(_clname);
}

int pqTreeViewSelectionHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
