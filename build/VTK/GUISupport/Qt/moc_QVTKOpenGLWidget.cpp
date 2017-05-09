/****************************************************************************
** Meta object code from reading C++ file 'QVTKOpenGLWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/VTK/GUISupport/Qt/QVTKOpenGLWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QVTKOpenGLWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QVTKOpenGLWidget_t {
    QByteArrayData data[18];
    char stringdata0[288];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QVTKOpenGLWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QVTKOpenGLWidget_t qt_meta_stringdata_QVTKOpenGLWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "QVTKOpenGLWidget"
QT_MOC_LITERAL(1, 17, 10), // "mouseEvent"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 12), // "QMouseEvent*"
QT_MOC_LITERAL(4, 42, 5), // "event"
QT_MOC_LITERAL(5, 48, 16), // "cachedImageDirty"
QT_MOC_LITERAL(6, 65, 16), // "cachedImageClean"
QT_MOC_LITERAL(7, 82, 22), // "markCachedImageAsDirty"
QT_MOC_LITERAL(8, 105, 16), // "saveImageToCache"
QT_MOC_LITERAL(9, 122, 11), // "deferRender"
QT_MOC_LITERAL(10, 134, 16), // "doDeferredRender"
QT_MOC_LITERAL(11, 151, 7), // "QEvent*"
QT_MOC_LITERAL(12, 159, 3), // "evt"
QT_MOC_LITERAL(13, 163, 14), // "cleanupContext"
QT_MOC_LITERAL(14, 178, 31), // "defaultFrameBufferObjectChanged"
QT_MOC_LITERAL(15, 210, 26), // "automaticImageCacheEnabled"
QT_MOC_LITERAL(16, 237, 26), // "maxRenderRateForImageCache"
QT_MOC_LITERAL(17, 264, 23) // "deferRenderInPaintEvent"

    },
    "QVTKOpenGLWidget\0mouseEvent\0\0QMouseEvent*\0"
    "event\0cachedImageDirty\0cachedImageClean\0"
    "markCachedImageAsDirty\0saveImageToCache\0"
    "deferRender\0doDeferredRender\0QEvent*\0"
    "evt\0cleanupContext\0defaultFrameBufferObjectChanged\0"
    "automaticImageCacheEnabled\0"
    "maxRenderRateForImageCache\0"
    "deferRenderInPaintEvent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QVTKOpenGLWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       3,   78, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,
       6,    0,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   69,    2, 0x0a /* Public */,
       8,    0,   70,    2, 0x0a /* Public */,
       9,    0,   71,    2, 0x09 /* Protected */,
      10,    0,   72,    2, 0x09 /* Protected */,
       4,    1,   73,    2, 0x09 /* Protected */,
      13,    0,   76,    2, 0x09 /* Protected */,
      14,    0,   77,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      15, QMetaType::Bool, 0x00095103,
      16, QMetaType::Double, 0x00095103,
      17, QMetaType::Bool, 0x00095103,

       0        // eod
};

void QVTKOpenGLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QVTKOpenGLWidget *_t = static_cast<QVTKOpenGLWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mouseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 1: _t->cachedImageDirty(); break;
        case 2: _t->cachedImageClean(); break;
        case 3: _t->markCachedImageAsDirty(); break;
        case 4: _t->saveImageToCache(); break;
        case 5: _t->deferRender(); break;
        case 6: _t->doDeferredRender(); break;
        case 7: { bool _r = _t->event((*reinterpret_cast< QEvent*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: _t->cleanupContext(); break;
        case 9: _t->defaultFrameBufferObjectChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QVTKOpenGLWidget::*_t)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QVTKOpenGLWidget::mouseEvent)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QVTKOpenGLWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QVTKOpenGLWidget::cachedImageDirty)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QVTKOpenGLWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QVTKOpenGLWidget::cachedImageClean)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QVTKOpenGLWidget *_t = static_cast<QVTKOpenGLWidget *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->isAutomaticImageCacheEnabled(); break;
        case 1: *reinterpret_cast< double*>(_v) = _t->maxRenderRateForImageCache(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->deferRenderInPaintEvent(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QVTKOpenGLWidget *_t = static_cast<QVTKOpenGLWidget *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setAutomaticImageCacheEnabled(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setMaxRenderRateForImageCache(*reinterpret_cast< double*>(_v)); break;
        case 2: _t->setDeferRenderInPaintEvent(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject QVTKOpenGLWidget::staticMetaObject = {
    { &QOpenGLWidget::staticMetaObject, qt_meta_stringdata_QVTKOpenGLWidget.data,
      qt_meta_data_QVTKOpenGLWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QVTKOpenGLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QVTKOpenGLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QVTKOpenGLWidget.stringdata0))
        return static_cast<void*>(const_cast< QVTKOpenGLWidget*>(this));
    return QOpenGLWidget::qt_metacast(_clname);
}

int QVTKOpenGLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QVTKOpenGLWidget::mouseEvent(QMouseEvent * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QVTKOpenGLWidget::cachedImageDirty()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void QVTKOpenGLWidget::cachedImageClean()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
