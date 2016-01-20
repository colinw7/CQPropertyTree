/****************************************************************************
** Meta object code from reading C++ file 'CQPropertyTree.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/CQPropertyTree.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CQPropertyTree.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CQPropertyTree_t {
    QByteArrayData data[21];
    char stringdata[214];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CQPropertyTree_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CQPropertyTree_t qt_meta_stringdata_CQPropertyTree = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 12),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 3),
QT_MOC_LITERAL(4, 33, 4),
QT_MOC_LITERAL(5, 38, 11),
QT_MOC_LITERAL(6, 50, 4),
QT_MOC_LITERAL(7, 55, 12),
QT_MOC_LITERAL(8, 68, 8),
QT_MOC_LITERAL(9, 77, 4),
QT_MOC_LITERAL(10, 82, 14),
QT_MOC_LITERAL(11, 97, 6),
QT_MOC_LITERAL(12, 104, 4),
QT_MOC_LITERAL(13, 109, 15),
QT_MOC_LITERAL(14, 125, 16),
QT_MOC_LITERAL(15, 142, 4),
QT_MOC_LITERAL(16, 147, 6),
QT_MOC_LITERAL(17, 154, 17),
QT_MOC_LITERAL(18, 172, 21),
QT_MOC_LITERAL(19, 194, 3),
QT_MOC_LITERAL(20, 198, 14)
    },
    "CQPropertyTree\0valueChanged\0\0obj\0name\0"
    "itemClicked\0path\0itemSelected\0menuExec\0"
    "gpos\0expandSelected\0search\0text\0"
    "itemClickedSlot\0QTreeWidgetItem*\0item\0"
    "column\0itemSelectionSlot\0customContextMenuSlot\0"
    "pos\0mouseHighlight\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CQPropertyTree[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       1,   92, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06,
       5,    2,   64,    2, 0x06,
       7,    2,   69,    2, 0x06,
       8,    2,   74,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      10,    0,   79,    2, 0x0a,
      11,    1,   80,    2, 0x0a,
      13,    2,   83,    2, 0x08,
      17,    0,   88,    2, 0x08,
      18,    1,   89,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QString,    3,    6,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QString,    3,    6,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QPoint,    3,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, 0x80000000 | 14, QMetaType::Int,   15,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   19,

 // properties: name, type, flags
      20, QMetaType::Bool, 0x00095103,

       0        // eod
};

void CQPropertyTree::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CQPropertyTree *_t = static_cast<CQPropertyTree *>(_o);
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->itemClicked((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->itemSelected((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->menuExec((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2]))); break;
        case 4: _t->expandSelected(); break;
        case 5: _t->search((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->itemClickedSlot((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->itemSelectionSlot(); break;
        case 8: _t->customContextMenuSlot((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CQPropertyTree::*_t)(QObject * , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CQPropertyTree::valueChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (CQPropertyTree::*_t)(QObject * , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CQPropertyTree::itemClicked)) {
                *result = 1;
            }
        }
        {
            typedef void (CQPropertyTree::*_t)(QObject * , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CQPropertyTree::itemSelected)) {
                *result = 2;
            }
        }
        {
            typedef void (CQPropertyTree::*_t)(QObject * , const QPoint & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CQPropertyTree::menuExec)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject CQPropertyTree::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_CQPropertyTree.data,
      qt_meta_data_CQPropertyTree,  qt_static_metacall, 0, 0}
};


const QMetaObject *CQPropertyTree::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CQPropertyTree::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CQPropertyTree.stringdata))
        return static_cast<void*>(const_cast< CQPropertyTree*>(this));
    return QTreeWidget::qt_metacast(_clname);
}

int CQPropertyTree::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = isMouseHighlight(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setMouseHighlight(*reinterpret_cast< bool*>(_v)); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CQPropertyTree::valueChanged(QObject * _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CQPropertyTree::itemClicked(QObject * _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CQPropertyTree::itemSelected(QObject * _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CQPropertyTree::menuExec(QObject * _t1, const QPoint & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
