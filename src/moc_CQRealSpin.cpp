/****************************************************************************
** Meta object code from reading C++ file 'CQRealSpin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/CQRealSpin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CQRealSpin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CQRealSpin_t {
    QByteArrayData data[6];
    char stringdata[50];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CQRealSpin_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CQRealSpin_t qt_meta_stringdata_CQRealSpin = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 11),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 10),
QT_MOC_LITERAL(4, 35, 8),
QT_MOC_LITERAL(5, 44, 4)
    },
    "CQRealSpin\0stepChanged\0\0updateStep\0"
    "autoStep\0step\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CQRealSpin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       2,   28, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    0,   27,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    2,

 // slots: parameters
    QMetaType::Void,

 // properties: name, type, flags
       4, QMetaType::Bool, 0x00095103,
       5, QMetaType::Double, 0x00095001,

       0        // eod
};

void CQRealSpin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CQRealSpin *_t = static_cast<CQRealSpin *>(_o);
        switch (_id) {
        case 0: _t->stepChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->updateStep(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CQRealSpin::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CQRealSpin::stepChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject CQRealSpin::staticMetaObject = {
    { &QDoubleSpinBox::staticMetaObject, qt_meta_stringdata_CQRealSpin.data,
      qt_meta_data_CQRealSpin,  qt_static_metacall, 0, 0}
};


const QMetaObject *CQRealSpin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CQRealSpin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CQRealSpin.stringdata))
        return static_cast<void*>(const_cast< CQRealSpin*>(this));
    return QDoubleSpinBox::qt_metacast(_clname);
}

int CQRealSpin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDoubleSpinBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = isAutoStep(); break;
        case 1: *reinterpret_cast< double*>(_v) = step(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setAutoStep(*reinterpret_cast< bool*>(_v)); break;
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
void CQRealSpin::stepChanged(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
