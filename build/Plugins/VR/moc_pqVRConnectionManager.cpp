/****************************************************************************
** Meta object code from reading C++ file 'pqVRConnectionManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Plugins/VR/pqVRConnectionManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pqVRConnectionManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pqVRConnectionManager_t {
    QByteArrayData data[12];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pqVRConnectionManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pqVRConnectionManager_t qt_meta_stringdata_pqVRConnectionManager = {
    {
QT_MOC_LITERAL(0, 0, 21), // "pqVRConnectionManager"
QT_MOC_LITERAL(1, 22, 18), // "connectionsChanged"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 5), // "start"
QT_MOC_LITERAL(4, 48, 4), // "stop"
QT_MOC_LITERAL(5, 53, 20), // "configureConnections"
QT_MOC_LITERAL(6, 74, 16), // "vtkPVXMLElement*"
QT_MOC_LITERAL(7, 91, 3), // "xml"
QT_MOC_LITERAL(8, 95, 18), // "vtkSMProxyLocator*"
QT_MOC_LITERAL(9, 114, 7), // "locator"
QT_MOC_LITERAL(10, 122, 28), // "saveConnectionsConfiguration"
QT_MOC_LITERAL(11, 151, 4) // "root"

    },
    "pqVRConnectionManager\0connectionsChanged\0"
    "\0start\0stop\0configureConnections\0"
    "vtkPVXMLElement*\0xml\0vtkSMProxyLocator*\0"
    "locator\0saveConnectionsConfiguration\0"
    "root"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pqVRConnectionManager[] = {

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
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    2,   42,    2, 0x0a /* Public */,
      10,    1,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8,    7,    9,
    QMetaType::Void, 0x80000000 | 6,   11,

       0        // eod
};

void pqVRConnectionManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        pqVRConnectionManager *_t = static_cast<pqVRConnectionManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectionsChanged(); break;
        case 1: _t->start(); break;
        case 2: _t->stop(); break;
        case 3: _t->configureConnections((*reinterpret_cast< vtkPVXMLElement*(*)>(_a[1])),(*reinterpret_cast< vtkSMProxyLocator*(*)>(_a[2]))); break;
        case 4: _t->saveConnectionsConfiguration((*reinterpret_cast< vtkPVXMLElement*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (pqVRConnectionManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pqVRConnectionManager::connectionsChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject pqVRConnectionManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_pqVRConnectionManager.data,
      qt_meta_data_pqVRConnectionManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *pqVRConnectionManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pqVRConnectionManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_pqVRConnectionManager.stringdata0))
        return static_cast<void*>(const_cast< pqVRConnectionManager*>(this));
    return QObject::qt_metacast(_clname);
}

int pqVRConnectionManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void pqVRConnectionManager::connectionsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
