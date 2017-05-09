/****************************************************************************
** Meta object code from reading C++ file 'pqApplicationCore.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Qt/Core/pqApplicationCore.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pqApplicationCore.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pqApplicationCore_t {
    QByteArrayData data[25];
    char stringdata0[332];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pqApplicationCore_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pqApplicationCore_t qt_meta_stringdata_pqApplicationCore = {
    {
QT_MOC_LITERAL(0, 0, 17), // "pqApplicationCore"
QT_MOC_LITERAL(1, 18, 16), // "aboutToLoadState"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 16), // "vtkPVXMLElement*"
QT_MOC_LITERAL(4, 53, 4), // "root"
QT_MOC_LITERAL(5, 58, 11), // "stateLoaded"
QT_MOC_LITERAL(6, 70, 18), // "vtkSMProxyLocator*"
QT_MOC_LITERAL(7, 89, 7), // "locator"
QT_MOC_LITERAL(8, 97, 10), // "stateSaved"
QT_MOC_LITERAL(9, 108, 16), // "undoStackChanged"
QT_MOC_LITERAL(10, 125, 12), // "pqUndoStack*"
QT_MOC_LITERAL(11, 138, 7), // "loadXML"
QT_MOC_LITERAL(12, 146, 22), // "forceFilterMenuRefresh"
QT_MOC_LITERAL(13, 169, 23), // "updateMasterEnableState"
QT_MOC_LITERAL(14, 193, 14), // "prepareForQuit"
QT_MOC_LITERAL(15, 208, 4), // "quit"
QT_MOC_LITERAL(16, 213, 16), // "showOutputWindow"
QT_MOC_LITERAL(17, 230, 17), // "loadConfiguration"
QT_MOC_LITERAL(18, 248, 8), // "filename"
QT_MOC_LITERAL(19, 257, 20), // "loadConfigurationXML"
QT_MOC_LITERAL(20, 278, 11), // "const char*"
QT_MOC_LITERAL(21, 290, 7), // "xmldata"
QT_MOC_LITERAL(22, 298, 6), // "render"
QT_MOC_LITERAL(23, 305, 13), // "onStateLoaded"
QT_MOC_LITERAL(24, 319, 12) // "onStateSaved"

    },
    "pqApplicationCore\0aboutToLoadState\0\0"
    "vtkPVXMLElement*\0root\0stateLoaded\0"
    "vtkSMProxyLocator*\0locator\0stateSaved\0"
    "undoStackChanged\0pqUndoStack*\0loadXML\0"
    "forceFilterMenuRefresh\0updateMasterEnableState\0"
    "prepareForQuit\0quit\0showOutputWindow\0"
    "loadConfiguration\0filename\0"
    "loadConfigurationXML\0const char*\0"
    "xmldata\0render\0onStateLoaded\0onStateSaved"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pqApplicationCore[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       5,    2,   92,    2, 0x06 /* Public */,
       8,    1,   97,    2, 0x06 /* Public */,
       9,    1,  100,    2, 0x06 /* Public */,
      11,    1,  103,    2, 0x06 /* Public */,
      12,    0,  106,    2, 0x06 /* Public */,
      13,    1,  107,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,  110,    2, 0x0a /* Public */,
      15,    0,  111,    2, 0x0a /* Public */,
      16,    0,  112,    2, 0x0a /* Public */,
      17,    1,  113,    2, 0x0a /* Public */,
      19,    1,  116,    2, 0x0a /* Public */,
      22,    0,  119,    2, 0x0a /* Public */,
      23,    2,  120,    2, 0x09 /* Protected */,
      24,    1,  125,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 6,    4,    7,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 6,    4,    7,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void pqApplicationCore::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        pqApplicationCore *_t = static_cast<pqApplicationCore *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->aboutToLoadState((*reinterpret_cast< vtkPVXMLElement*(*)>(_a[1]))); break;
        case 1: _t->stateLoaded((*reinterpret_cast< vtkPVXMLElement*(*)>(_a[1])),(*reinterpret_cast< vtkSMProxyLocator*(*)>(_a[2]))); break;
        case 2: _t->stateSaved((*reinterpret_cast< vtkPVXMLElement*(*)>(_a[1]))); break;
        case 3: _t->undoStackChanged((*reinterpret_cast< pqUndoStack*(*)>(_a[1]))); break;
        case 4: _t->loadXML((*reinterpret_cast< vtkPVXMLElement*(*)>(_a[1]))); break;
        case 5: _t->forceFilterMenuRefresh(); break;
        case 6: _t->updateMasterEnableState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->prepareForQuit(); break;
        case 8: _t->quit(); break;
        case 9: _t->showOutputWindow(); break;
        case 10: _t->loadConfiguration((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->loadConfigurationXML((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 12: _t->render(); break;
        case 13: _t->onStateLoaded((*reinterpret_cast< vtkPVXMLElement*(*)>(_a[1])),(*reinterpret_cast< vtkSMProxyLocator*(*)>(_a[2]))); break;
        case 14: _t->onStateSaved((*reinterpret_cast< vtkPVXMLElement*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (pqApplicationCore::*_t)(vtkPVXMLElement * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pqApplicationCore::aboutToLoadState)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (pqApplicationCore::*_t)(vtkPVXMLElement * , vtkSMProxyLocator * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pqApplicationCore::stateLoaded)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (pqApplicationCore::*_t)(vtkPVXMLElement * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pqApplicationCore::stateSaved)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (pqApplicationCore::*_t)(pqUndoStack * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pqApplicationCore::undoStackChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (pqApplicationCore::*_t)(vtkPVXMLElement * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pqApplicationCore::loadXML)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (pqApplicationCore::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pqApplicationCore::forceFilterMenuRefresh)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (pqApplicationCore::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pqApplicationCore::updateMasterEnableState)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject pqApplicationCore::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_pqApplicationCore.data,
      qt_meta_data_pqApplicationCore,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *pqApplicationCore::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pqApplicationCore::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_pqApplicationCore.stringdata0))
        return static_cast<void*>(const_cast< pqApplicationCore*>(this));
    return QObject::qt_metacast(_clname);
}

int pqApplicationCore::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void pqApplicationCore::aboutToLoadState(vtkPVXMLElement * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void pqApplicationCore::stateLoaded(vtkPVXMLElement * _t1, vtkSMProxyLocator * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void pqApplicationCore::stateSaved(vtkPVXMLElement * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void pqApplicationCore::undoStackChanged(pqUndoStack * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void pqApplicationCore::loadXML(vtkPVXMLElement * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void pqApplicationCore::forceFilterMenuRefresh()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void pqApplicationCore::updateMasterEnableState(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
