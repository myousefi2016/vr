/****************************************************************************
** Meta object code from reading C++ file 'pqOutputWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Qt/Core/pqOutputWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pqOutputWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pqOutputWindow_t {
    QByteArrayData data[18];
    char stringdata0[255];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pqOutputWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pqOutputWindow_t qt_meta_stringdata_pqOutputWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "pqOutputWindow"
QT_MOC_LITERAL(1, 15, 13), // "onDisplayText"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 18), // "onDisplayErrorText"
QT_MOC_LITERAL(4, 49, 20), // "onDisplayWarningText"
QT_MOC_LITERAL(5, 70, 27), // "onDisplayGenericWarningText"
QT_MOC_LITERAL(6, 98, 21), // "onDisplayTextInWindow"
QT_MOC_LITERAL(7, 120, 26), // "onDisplayErrorTextInWindow"
QT_MOC_LITERAL(8, 147, 6), // "accept"
QT_MOC_LITERAL(9, 154, 6), // "reject"
QT_MOC_LITERAL(10, 161, 5), // "clear"
QT_MOC_LITERAL(11, 167, 14), // "setConsoleView"
QT_MOC_LITERAL(12, 182, 2), // "on"
QT_MOC_LITERAL(13, 185, 12), // "errorToggled"
QT_MOC_LITERAL(14, 198, 7), // "checked"
QT_MOC_LITERAL(15, 206, 14), // "warningToggled"
QT_MOC_LITERAL(16, 221, 12), // "debugToggled"
QT_MOC_LITERAL(17, 234, 20) // "onProgressStartEvent"

    },
    "pqOutputWindow\0onDisplayText\0\0"
    "onDisplayErrorText\0onDisplayWarningText\0"
    "onDisplayGenericWarningText\0"
    "onDisplayTextInWindow\0onDisplayErrorTextInWindow\0"
    "accept\0reject\0clear\0setConsoleView\0"
    "on\0errorToggled\0checked\0warningToggled\0"
    "debugToggled\0onProgressStartEvent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pqOutputWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x0a /* Public */,
       3,    1,   87,    2, 0x0a /* Public */,
       4,    1,   90,    2, 0x0a /* Public */,
       5,    1,   93,    2, 0x0a /* Public */,
       6,    1,   96,    2, 0x0a /* Public */,
       7,    1,   99,    2, 0x0a /* Public */,
       8,    0,  102,    2, 0x08 /* Private */,
       9,    0,  103,    2, 0x08 /* Private */,
      10,    0,  104,    2, 0x08 /* Private */,
      11,    1,  105,    2, 0x08 /* Private */,
      13,    1,  108,    2, 0x08 /* Private */,
      15,    1,  111,    2, 0x08 /* Private */,
      16,    1,  114,    2, 0x08 /* Private */,
      17,    0,  117,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void,

       0        // eod
};

void pqOutputWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        pqOutputWindow *_t = static_cast<pqOutputWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onDisplayText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onDisplayErrorText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->onDisplayWarningText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onDisplayGenericWarningText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->onDisplayTextInWindow((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->onDisplayErrorTextInWindow((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->accept(); break;
        case 7: _t->reject(); break;
        case 8: _t->clear(); break;
        case 9: _t->setConsoleView((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->errorToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->warningToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->debugToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->onProgressStartEvent(); break;
        default: ;
        }
    }
}

const QMetaObject pqOutputWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_pqOutputWindow.data,
      qt_meta_data_pqOutputWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *pqOutputWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pqOutputWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_pqOutputWindow.stringdata0))
        return static_cast<void*>(const_cast< pqOutputWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int pqOutputWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
