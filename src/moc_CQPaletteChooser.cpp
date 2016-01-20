/****************************************************************************
** Meta object code from reading C++ file 'CQPaletteChooser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/CQPaletteChooser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CQPaletteChooser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CQPaletteChooser_t {
    QByteArrayData data[7];
    char stringdata[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CQPaletteChooser_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CQPaletteChooser_t qt_meta_stringdata_CQPaletteChooser = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 14),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 7),
QT_MOC_LITERAL(4, 41, 10),
QT_MOC_LITERAL(5, 52, 13),
QT_MOC_LITERAL(6, 66, 11)
    },
    "CQPaletteChooser\0paletteChanged\0\0"
    "palette\0paletteDef\0choosePalette\0"
    "editPalette\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CQPaletteChooser[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       2,   42, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06,
       1,    1,   37,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    0,   40,    2, 0x08,
       6,    0,   41,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QPalette,    3,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       3, QMetaType::QPalette, 0x00095103,
       4, QMetaType::QString, 0x00095103,

       0        // eod
};

void CQPaletteChooser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CQPaletteChooser *_t = static_cast<CQPaletteChooser *>(_o);
        switch (_id) {
        case 0: _t->paletteChanged((*reinterpret_cast< const QPalette(*)>(_a[1]))); break;
        case 1: _t->paletteChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->choosePalette(); break;
        case 3: _t->editPalette(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CQPaletteChooser::*_t)(const QPalette & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CQPaletteChooser::paletteChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (CQPaletteChooser::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CQPaletteChooser::paletteChanged)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject CQPaletteChooser::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CQPaletteChooser.data,
      qt_meta_data_CQPaletteChooser,  qt_static_metacall, 0, 0}
};


const QMetaObject *CQPaletteChooser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CQPaletteChooser::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CQPaletteChooser.stringdata))
        return static_cast<void*>(const_cast< CQPaletteChooser*>(this));
    return QWidget::qt_metacast(_clname);
}

int CQPaletteChooser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QPalette*>(_v) = palette(); break;
        case 1: *reinterpret_cast< QString*>(_v) = paletteDef(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setPalette(*reinterpret_cast< QPalette*>(_v)); break;
        case 1: setPaletteDef(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
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
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CQPaletteChooser::paletteChanged(const QPalette & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CQPaletteChooser::paletteChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
