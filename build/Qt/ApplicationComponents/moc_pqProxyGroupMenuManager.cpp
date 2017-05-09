/****************************************************************************
** Meta object code from reading C++ file 'pqProxyGroupMenuManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Qt/ApplicationComponents/pqProxyGroupMenuManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pqProxyGroupMenuManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pqProxyGroupMenuManager_t {
    QByteArrayData data[16];
    char stringdata0[250];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pqProxyGroupMenuManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pqProxyGroupMenuManager_t qt_meta_stringdata_pqProxyGroupMenuManager = {
    {
QT_MOC_LITERAL(0, 0, 23), // "pqProxyGroupMenuManager"
QT_MOC_LITERAL(1, 24, 9), // "triggered"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 5), // "group"
QT_MOC_LITERAL(4, 41, 4), // "name"
QT_MOC_LITERAL(5, 46, 13), // "menuPopulated"
QT_MOC_LITERAL(6, 60, 17), // "loadConfiguration"
QT_MOC_LITERAL(7, 78, 16), // "vtkPVXMLElement*"
QT_MOC_LITERAL(8, 95, 21), // "lookForNewDefinitions"
QT_MOC_LITERAL(9, 117, 36), // "removeProxyDefinitionUpdateOb..."
QT_MOC_LITERAL(10, 154, 33), // "addProxyDefinitionUpdateObser..."
QT_MOC_LITERAL(11, 188, 10), // "setEnabled"
QT_MOC_LITERAL(12, 199, 6), // "enable"
QT_MOC_LITERAL(13, 206, 12), // "populateMenu"
QT_MOC_LITERAL(14, 219, 11), // "quickLaunch"
QT_MOC_LITERAL(15, 231, 18) // "switchActiveServer"

    },
    "pqProxyGroupMenuManager\0triggered\0\0"
    "group\0name\0menuPopulated\0loadConfiguration\0"
    "vtkPVXMLElement*\0lookForNewDefinitions\0"
    "removeProxyDefinitionUpdateObservers\0"
    "addProxyDefinitionUpdateObservers\0"
    "setEnabled\0enable\0populateMenu\0"
    "quickLaunch\0switchActiveServer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pqProxyGroupMenuManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       5,    0,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   75,    2, 0x0a /* Public */,
       8,    0,   78,    2, 0x0a /* Public */,
       9,    0,   79,    2, 0x0a /* Public */,
      10,    0,   80,    2, 0x0a /* Public */,
      11,    1,   81,    2, 0x0a /* Public */,
      13,    0,   84,    2, 0x0a /* Public */,
       1,    0,   85,    2, 0x09 /* Protected */,
      14,    0,   86,    2, 0x09 /* Protected */,
      15,    0,   87,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void pqProxyGroupMenuManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        pqProxyGroupMenuManager *_t = static_cast<pqProxyGroupMenuManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->triggered((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->menuPopulated(); break;
        case 2: _t->loadConfiguration((*reinterpret_cast< vtkPVXMLElement*(*)>(_a[1]))); break;
        case 3: _t->lookForNewDefinitions(); break;
        case 4: _t->removeProxyDefinitionUpdateObservers(); break;
        case 5: _t->addProxyDefinitionUpdateObservers(); break;
        case 6: _t->setEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->populateMenu(); break;
        case 8: _t->triggered(); break;
        case 9: _t->quickLaunch(); break;
        case 10: _t->switchActiveServer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (pqProxyGroupMenuManager::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pqProxyGroupMenuManager::triggered)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (pqProxyGroupMenuManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pqProxyGroupMenuManager::menuPopulated)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject pqProxyGroupMenuManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_pqProxyGroupMenuManager.data,
      qt_meta_data_pqProxyGroupMenuManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *pqProxyGroupMenuManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pqProxyGroupMenuManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_pqProxyGroupMenuManager.stringdata0))
        return static_cast<void*>(const_cast< pqProxyGroupMenuManager*>(this));
    return QObject::qt_metacast(_clname);
}

int pqProxyGroupMenuManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void pqProxyGroupMenuManager::triggered(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void pqProxyGroupMenuManager::menuPopulated()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
