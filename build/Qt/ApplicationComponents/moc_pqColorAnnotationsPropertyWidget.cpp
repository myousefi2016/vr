/****************************************************************************
** Meta object code from reading C++ file 'pqColorAnnotationsPropertyWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Qt/ApplicationComponents/pqColorAnnotationsPropertyWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pqColorAnnotationsPropertyWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pqColorAnnotationsPropertyWidget_t {
    QByteArrayData data[22];
    char stringdata0[353];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pqColorAnnotationsPropertyWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pqColorAnnotationsPropertyWidget_t qt_meta_stringdata_pqColorAnnotationsPropertyWidget = {
    {
QT_MOC_LITERAL(0, 0, 32), // "pqColorAnnotationsPropertyWidget"
QT_MOC_LITERAL(1, 33, 18), // "annotationsChanged"
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 20), // "indexedColorsChanged"
QT_MOC_LITERAL(4, 74, 13), // "addAnnotation"
QT_MOC_LITERAL(5, 88, 16), // "removeAnnotation"
QT_MOC_LITERAL(6, 105, 20), // "addActiveAnnotations"
QT_MOC_LITERAL(7, 126, 38), // "addActiveAnnotationsFromVisib..."
QT_MOC_LITERAL(8, 165, 20), // "removeAllAnnotations"
QT_MOC_LITERAL(9, 186, 13), // "onDataChanged"
QT_MOC_LITERAL(10, 200, 7), // "topleft"
QT_MOC_LITERAL(11, 208, 8), // "btmright"
QT_MOC_LITERAL(12, 217, 15), // "onDoubleClicked"
QT_MOC_LITERAL(13, 233, 3), // "idx"
QT_MOC_LITERAL(14, 237, 12), // "choosePreset"
QT_MOC_LITERAL(15, 250, 11), // "const char*"
QT_MOC_LITERAL(16, 262, 10), // "presetName"
QT_MOC_LITERAL(17, 273, 12), // "saveAsPreset"
QT_MOC_LITERAL(18, 286, 24), // "updateIndexedLookupState"
QT_MOC_LITERAL(19, 311, 15), // "editPastLastRow"
QT_MOC_LITERAL(20, 327, 11), // "annotations"
QT_MOC_LITERAL(21, 339, 13) // "indexedColors"

    },
    "pqColorAnnotationsPropertyWidget\0"
    "annotationsChanged\0\0indexedColorsChanged\0"
    "addAnnotation\0removeAnnotation\0"
    "addActiveAnnotations\0"
    "addActiveAnnotationsFromVisibleSources\0"
    "removeAllAnnotations\0onDataChanged\0"
    "topleft\0btmright\0onDoubleClicked\0idx\0"
    "choosePreset\0const char*\0presetName\0"
    "saveAsPreset\0updateIndexedLookupState\0"
    "editPastLastRow\0annotations\0indexedColors"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pqColorAnnotationsPropertyWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       2,  106, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    2,   91,    2, 0x08 /* Private */,
      12,    1,   96,    2, 0x08 /* Private */,
      14,    1,   99,    2, 0x08 /* Private */,
      14,    0,  102,    2, 0x28 /* Private | MethodCloned */,
      17,    0,  103,    2, 0x08 /* Private */,
      18,    0,  104,    2, 0x08 /* Private */,
      19,    0,  105,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,   10,   11,
    QMetaType::Void, QMetaType::QModelIndex,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      20, QMetaType::QVariantList, 0x00095103,
      21, QMetaType::QVariantList, 0x00095103,

       0        // eod
};

void pqColorAnnotationsPropertyWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        pqColorAnnotationsPropertyWidget *_t = static_cast<pqColorAnnotationsPropertyWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->annotationsChanged(); break;
        case 1: _t->indexedColorsChanged(); break;
        case 2: _t->addAnnotation(); break;
        case 3: _t->removeAnnotation(); break;
        case 4: _t->addActiveAnnotations(); break;
        case 5: _t->addActiveAnnotationsFromVisibleSources(); break;
        case 6: _t->removeAllAnnotations(); break;
        case 7: _t->onDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 8: _t->onDoubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 9: _t->choosePreset((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 10: _t->choosePreset(); break;
        case 11: _t->saveAsPreset(); break;
        case 12: _t->updateIndexedLookupState(); break;
        case 13: _t->editPastLastRow(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (pqColorAnnotationsPropertyWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pqColorAnnotationsPropertyWidget::annotationsChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (pqColorAnnotationsPropertyWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pqColorAnnotationsPropertyWidget::indexedColorsChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        pqColorAnnotationsPropertyWidget *_t = static_cast<pqColorAnnotationsPropertyWidget *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QList<QVariant>*>(_v) = _t->annotations(); break;
        case 1: *reinterpret_cast< QList<QVariant>*>(_v) = _t->indexedColors(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        pqColorAnnotationsPropertyWidget *_t = static_cast<pqColorAnnotationsPropertyWidget *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setAnnotations(*reinterpret_cast< QList<QVariant>*>(_v)); break;
        case 1: _t->setIndexedColors(*reinterpret_cast< QList<QVariant>*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject pqColorAnnotationsPropertyWidget::staticMetaObject = {
    { &pqPropertyWidget::staticMetaObject, qt_meta_stringdata_pqColorAnnotationsPropertyWidget.data,
      qt_meta_data_pqColorAnnotationsPropertyWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *pqColorAnnotationsPropertyWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pqColorAnnotationsPropertyWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_pqColorAnnotationsPropertyWidget.stringdata0))
        return static_cast<void*>(const_cast< pqColorAnnotationsPropertyWidget*>(this));
    return pqPropertyWidget::qt_metacast(_clname);
}

int pqColorAnnotationsPropertyWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = pqPropertyWidget::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void pqColorAnnotationsPropertyWidget::annotationsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void pqColorAnnotationsPropertyWidget::indexedColorsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
