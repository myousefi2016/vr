/****************************************************************************
** Meta object code from reading C++ file 'pqAnimationTimeWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Qt/ApplicationComponents/pqAnimationTimeWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pqAnimationTimeWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pqAnimationTimeWidget_t {
    QByteArrayData data[15];
    char stringdata0[229];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pqAnimationTimeWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pqAnimationTimeWidget_t qt_meta_stringdata_pqAnimationTimeWidget = {
    {
QT_MOC_LITERAL(0, 0, 21), // "pqAnimationTimeWidget"
QT_MOC_LITERAL(1, 22, 16), // "timeValueChanged"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 15), // "playModeChanged"
QT_MOC_LITERAL(4, 56, 11), // "dummySignal"
QT_MOC_LITERAL(5, 68, 17), // "setAnimationScene"
QT_MOC_LITERAL(6, 86, 11), // "vtkSMProxy*"
QT_MOC_LITERAL(7, 98, 14), // "animationScene"
QT_MOC_LITERAL(8, 113, 34), // "updateTimestepCountLabelVisib..."
QT_MOC_LITERAL(9, 148, 20), // "timestepValueChanged"
QT_MOC_LITERAL(10, 169, 9), // "timeValue"
QT_MOC_LITERAL(11, 179, 13), // "timeStepCount"
QT_MOC_LITERAL(12, 193, 8), // "playMode"
QT_MOC_LITERAL(13, 202, 16), // "playModeReadOnly"
QT_MOC_LITERAL(14, 219, 9) // "timeLabel"

    },
    "pqAnimationTimeWidget\0timeValueChanged\0"
    "\0playModeChanged\0dummySignal\0"
    "setAnimationScene\0vtkSMProxy*\0"
    "animationScene\0updateTimestepCountLabelVisibility\0"
    "timestepValueChanged\0timeValue\0"
    "timeStepCount\0playMode\0playModeReadOnly\0"
    "timeLabel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pqAnimationTimeWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       5,   52, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   47,    2, 0x0a /* Public */,
       8,    0,   50,    2, 0x08 /* Private */,
       9,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      10, QMetaType::Double, 0x00495103,
      11, QMetaType::Int, 0x00095103,
      12, QMetaType::QString, 0x00095103,
      13, QMetaType::Bool, 0x00095103,
      14, QMetaType::QString, 0x00095103,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       0,

       0        // eod
};

void pqAnimationTimeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        pqAnimationTimeWidget *_t = static_cast<pqAnimationTimeWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->timeValueChanged(); break;
        case 1: _t->playModeChanged(); break;
        case 2: _t->dummySignal(); break;
        case 3: _t->setAnimationScene((*reinterpret_cast< vtkSMProxy*(*)>(_a[1]))); break;
        case 4: _t->updateTimestepCountLabelVisibility(); break;
        case 5: _t->timestepValueChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (pqAnimationTimeWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pqAnimationTimeWidget::timeValueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (pqAnimationTimeWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pqAnimationTimeWidget::playModeChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (pqAnimationTimeWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pqAnimationTimeWidget::dummySignal)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        pqAnimationTimeWidget *_t = static_cast<pqAnimationTimeWidget *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< double*>(_v) = _t->timeValue(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->timeStepCount(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->playMode(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->playModeReadOnly(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->timeLabel(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        pqAnimationTimeWidget *_t = static_cast<pqAnimationTimeWidget *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setTimeValue(*reinterpret_cast< double*>(_v)); break;
        case 1: _t->setTimeStepCount(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setPlayMode(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setPlayModeReadOnly(*reinterpret_cast< bool*>(_v)); break;
        case 4: _t->setTimeLabel(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject pqAnimationTimeWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_pqAnimationTimeWidget.data,
      qt_meta_data_pqAnimationTimeWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *pqAnimationTimeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pqAnimationTimeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_pqAnimationTimeWidget.stringdata0))
        return static_cast<void*>(const_cast< pqAnimationTimeWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int pqAnimationTimeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void pqAnimationTimeWidget::timeValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void pqAnimationTimeWidget::playModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void pqAnimationTimeWidget::dummySignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
