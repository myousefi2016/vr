/****************************************************************************
** Meta object code from reading C++ file 'pqFileDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Qt/Core/pqFileDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pqFileDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pqFileDialog_t {
    QByteArrayData data[27];
    char stringdata0[406];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pqFileDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pqFileDialog_t qt_meta_stringdata_pqFileDialog = {
    {
QT_MOC_LITERAL(0, 0, 12), // "pqFileDialog"
QT_MOC_LITERAL(1, 13, 13), // "filesSelected"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 18), // "QList<QStringList>"
QT_MOC_LITERAL(4, 47, 12), // "fileAccepted"
QT_MOC_LITERAL(5, 60, 12), // "onModelReset"
QT_MOC_LITERAL(6, 73, 10), // "onNavigate"
QT_MOC_LITERAL(7, 84, 12), // "onNavigateUp"
QT_MOC_LITERAL(8, 97, 14), // "onNavigateBack"
QT_MOC_LITERAL(9, 112, 17), // "onNavigateForward"
QT_MOC_LITERAL(10, 130, 14), // "onNavigateDown"
QT_MOC_LITERAL(11, 145, 14), // "onFilterChange"
QT_MOC_LITERAL(12, 160, 15), // "onClickedRecent"
QT_MOC_LITERAL(13, 176, 17), // "onClickedFavorite"
QT_MOC_LITERAL(14, 194, 13), // "onClickedFile"
QT_MOC_LITERAL(15, 208, 18), // "onActivateFavorite"
QT_MOC_LITERAL(16, 227, 16), // "onActivateRecent"
QT_MOC_LITERAL(17, 244, 17), // "onDoubleClickFile"
QT_MOC_LITERAL(18, 262, 12), // "onTextEdited"
QT_MOC_LITERAL(19, 275, 17), // "onShowHiddenFiles"
QT_MOC_LITERAL(20, 293, 4), // "hide"
QT_MOC_LITERAL(21, 298, 20), // "fileSelectionChanged"
QT_MOC_LITERAL(22, 319, 22), // "onContextMenuRequested"
QT_MOC_LITERAL(23, 342, 3), // "pos"
QT_MOC_LITERAL(24, 346, 17), // "onCreateNewFolder"
QT_MOC_LITERAL(25, 364, 18), // "addToFilesSelected"
QT_MOC_LITERAL(26, 383, 22) // "emitFilesSelectionDone"

    },
    "pqFileDialog\0filesSelected\0\0"
    "QList<QStringList>\0fileAccepted\0"
    "onModelReset\0onNavigate\0onNavigateUp\0"
    "onNavigateBack\0onNavigateForward\0"
    "onNavigateDown\0onFilterChange\0"
    "onClickedRecent\0onClickedFavorite\0"
    "onClickedFile\0onActivateFavorite\0"
    "onActivateRecent\0onDoubleClickFile\0"
    "onTextEdited\0onShowHiddenFiles\0hide\0"
    "fileSelectionChanged\0onContextMenuRequested\0"
    "pos\0onCreateNewFolder\0addToFilesSelected\0"
    "emitFilesSelectionDone"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pqFileDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  129,    2, 0x06 /* Public */,
       1,    1,  132,    2, 0x06 /* Public */,
       4,    1,  135,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,  138,    2, 0x08 /* Private */,
       6,    1,  139,    2, 0x08 /* Private */,
       7,    0,  142,    2, 0x08 /* Private */,
       8,    0,  143,    2, 0x08 /* Private */,
       9,    0,  144,    2, 0x08 /* Private */,
      10,    1,  145,    2, 0x08 /* Private */,
      11,    1,  148,    2, 0x08 /* Private */,
      12,    1,  151,    2, 0x08 /* Private */,
      13,    1,  154,    2, 0x08 /* Private */,
      14,    1,  157,    2, 0x08 /* Private */,
      15,    1,  160,    2, 0x08 /* Private */,
      16,    1,  163,    2, 0x08 /* Private */,
      17,    1,  166,    2, 0x08 /* Private */,
      18,    1,  169,    2, 0x08 /* Private */,
      19,    1,  172,    2, 0x08 /* Private */,
      21,    0,  175,    2, 0x08 /* Private */,
      22,    1,  176,    2, 0x08 /* Private */,
      24,    0,  179,    2, 0x08 /* Private */,
      25,    1,  180,    2, 0x08 /* Private */,
      26,    0,  183,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QModelIndex,    2,
    QMetaType::Void, QMetaType::QModelIndex,    2,
    QMetaType::Void, QMetaType::QModelIndex,    2,
    QMetaType::Void, QMetaType::QModelIndex,    2,
    QMetaType::Void, QMetaType::QModelIndex,    2,
    QMetaType::Void, QMetaType::QModelIndex,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   23,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void,

       0        // eod
};

void pqFileDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        pqFileDialog *_t = static_cast<pqFileDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->filesSelected((*reinterpret_cast< const QList<QStringList>(*)>(_a[1]))); break;
        case 1: _t->filesSelected((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 2: _t->fileAccepted((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onModelReset(); break;
        case 4: _t->onNavigate((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->onNavigateUp(); break;
        case 6: _t->onNavigateBack(); break;
        case 7: _t->onNavigateForward(); break;
        case 8: _t->onNavigateDown((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 9: _t->onFilterChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->onClickedRecent((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 11: _t->onClickedFavorite((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 12: _t->onClickedFile((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 13: _t->onActivateFavorite((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 14: _t->onActivateRecent((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 15: _t->onDoubleClickFile((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 16: _t->onTextEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->onShowHiddenFiles((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 18: _t->fileSelectionChanged(); break;
        case 19: _t->onContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 20: _t->onCreateNewFolder(); break;
        case 21: _t->addToFilesSelected((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 22: _t->emitFilesSelectionDone(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QStringList> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (pqFileDialog::*_t)(const QList<QStringList> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pqFileDialog::filesSelected)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (pqFileDialog::*_t)(const QStringList & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pqFileDialog::filesSelected)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (pqFileDialog::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pqFileDialog::fileAccepted)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject pqFileDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_pqFileDialog.data,
      qt_meta_data_pqFileDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *pqFileDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pqFileDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_pqFileDialog.stringdata0))
        return static_cast<void*>(const_cast< pqFileDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int pqFileDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void pqFileDialog::filesSelected(const QList<QStringList> & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void pqFileDialog::filesSelected(const QStringList & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void pqFileDialog::fileAccepted(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
