/****************************************************************************
** Meta object code from reading C++ file 'pqRenderView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Qt/Core/pqRenderView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pqRenderView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pqRenderView_t {
    QByteArrayData data[29];
    char stringdata0[450];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pqRenderView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pqRenderView_t qt_meta_stringdata_pqRenderView = {
    {
QT_MOC_LITERAL(0, 0, 12), // "pqRenderView"
QT_MOC_LITERAL(1, 13, 21), // "updateInteractionMode"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 4), // "mode"
QT_MOC_LITERAL(4, 41, 28), // "setOrientationAxesVisibility"
QT_MOC_LITERAL(5, 70, 7), // "visible"
QT_MOC_LITERAL(6, 78, 31), // "setOrientationAxesInteractivity"
QT_MOC_LITERAL(7, 110, 11), // "interactive"
QT_MOC_LITERAL(8, 122, 28), // "setOrientationAxesLabelColor"
QT_MOC_LITERAL(9, 151, 30), // "setOrientationAxesOutlineColor"
QT_MOC_LITERAL(10, 182, 19), // "setCenterOfRotation"
QT_MOC_LITERAL(11, 202, 1), // "x"
QT_MOC_LITERAL(12, 204, 1), // "y"
QT_MOC_LITERAL(13, 206, 1), // "z"
QT_MOC_LITERAL(14, 208, 9), // "double[3]"
QT_MOC_LITERAL(15, 218, 3), // "xyz"
QT_MOC_LITERAL(16, 222, 23), // "setCenterAxesVisibility"
QT_MOC_LITERAL(17, 246, 24), // "setResetCenterWithCamera"
QT_MOC_LITERAL(18, 271, 1), // "b"
QT_MOC_LITERAL(19, 273, 37), // "setUseMultipleRepresentationS..."
QT_MOC_LITERAL(20, 311, 15), // "linkToOtherView"
QT_MOC_LITERAL(21, 327, 4), // "undo"
QT_MOC_LITERAL(22, 332, 4), // "redo"
QT_MOC_LITERAL(23, 337, 29), // "resetCenterOfRotationIfNeeded"
QT_MOC_LITERAL(24, 367, 13), // "pqOutputPort*"
QT_MOC_LITERAL(25, 381, 6), // "opPort"
QT_MOC_LITERAL(26, 388, 18), // "onResetCameraEvent"
QT_MOC_LITERAL(27, 407, 18), // "onUndoStackChanged"
QT_MOC_LITERAL(28, 426, 23) // "onInteractionModeChange"

    },
    "pqRenderView\0updateInteractionMode\0\0"
    "mode\0setOrientationAxesVisibility\0"
    "visible\0setOrientationAxesInteractivity\0"
    "interactive\0setOrientationAxesLabelColor\0"
    "setOrientationAxesOutlineColor\0"
    "setCenterOfRotation\0x\0y\0z\0double[3]\0"
    "xyz\0setCenterAxesVisibility\0"
    "setResetCenterWithCamera\0b\0"
    "setUseMultipleRepresentationSelection\0"
    "linkToOtherView\0undo\0redo\0"
    "resetCenterOfRotationIfNeeded\0"
    "pqOutputPort*\0opPort\0onResetCameraEvent\0"
    "onUndoStackChanged\0onInteractionModeChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pqRenderView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,  107,    2, 0x0a /* Public */,
       6,    1,  110,    2, 0x0a /* Public */,
       8,    1,  113,    2, 0x0a /* Public */,
       9,    1,  116,    2, 0x0a /* Public */,
      10,    3,  119,    2, 0x0a /* Public */,
      10,    1,  126,    2, 0x0a /* Public */,
      16,    1,  129,    2, 0x0a /* Public */,
      17,    1,  132,    2, 0x0a /* Public */,
      19,    1,  135,    2, 0x0a /* Public */,
      20,    0,  138,    2, 0x0a /* Public */,
      21,    0,  139,    2, 0x0a /* Public */,
      22,    0,  140,    2, 0x0a /* Public */,
      23,    0,  141,    2, 0x0a /* Public */,
       1,    1,  142,    2, 0x0a /* Public */,
      26,    0,  145,    2, 0x08 /* Private */,
      27,    0,  146,    2, 0x08 /* Private */,
      28,    0,  147,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,   11,   12,   13,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void pqRenderView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        pqRenderView *_t = static_cast<pqRenderView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateInteractionMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setOrientationAxesVisibility((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setOrientationAxesInteractivity((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setOrientationAxesLabelColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 4: _t->setOrientationAxesOutlineColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 5: _t->setCenterOfRotation((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 6: _t->setCenterOfRotation((*reinterpret_cast< double(*)[3]>(_a[1]))); break;
        case 7: _t->setCenterAxesVisibility((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->setResetCenterWithCamera((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->setUseMultipleRepresentationSelection((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->linkToOtherView(); break;
        case 11: _t->undo(); break;
        case 12: _t->redo(); break;
        case 13: _t->resetCenterOfRotationIfNeeded(); break;
        case 14: _t->updateInteractionMode((*reinterpret_cast< pqOutputPort*(*)>(_a[1]))); break;
        case 15: _t->onResetCameraEvent(); break;
        case 16: _t->onUndoStackChanged(); break;
        case 17: _t->onInteractionModeChange(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (pqRenderView::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pqRenderView::updateInteractionMode)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject pqRenderView::staticMetaObject = {
    { &pqRenderViewBase::staticMetaObject, qt_meta_stringdata_pqRenderView.data,
      qt_meta_data_pqRenderView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *pqRenderView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pqRenderView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_pqRenderView.stringdata0))
        return static_cast<void*>(const_cast< pqRenderView*>(this));
    return pqRenderViewBase::qt_metacast(_clname);
}

int pqRenderView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = pqRenderViewBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void pqRenderView::updateInteractionMode(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
