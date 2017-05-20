/****************************************************************************
** Meta object code from reading C++ file 'switchbtn.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "components/switchbtn.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'switchbtn.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SwitchBtn_t {
    QByteArrayData data[6];
    char stringdata0[56];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SwitchBtn_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SwitchBtn_t qt_meta_stringdata_SwitchBtn = {
    {
QT_MOC_LITERAL(0, 0, 9), // "SwitchBtn"
QT_MOC_LITERAL(1, 10, 13), // "buttonPressed"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 14), // "buttonReleased"
QT_MOC_LITERAL(4, 40, 7), // "nextPic"
QT_MOC_LITERAL(5, 48, 7) // "prevPic"

    },
    "SwitchBtn\0buttonPressed\0\0buttonReleased\0"
    "nextPic\0prevPic"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SwitchBtn[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SwitchBtn::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SwitchBtn *_t = static_cast<SwitchBtn *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->buttonPressed(); break;
        case 1: _t->buttonReleased(); break;
        case 2: _t->nextPic(); break;
        case 3: _t->prevPic(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SwitchBtn::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SwitchBtn.data,
      qt_meta_data_SwitchBtn,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SwitchBtn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SwitchBtn::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SwitchBtn.stringdata0))
        return static_cast<void*>(const_cast< SwitchBtn*>(this));
    return QDialog::qt_metacast(_clname);
}

int SwitchBtn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_END_MOC_NAMESPACE
