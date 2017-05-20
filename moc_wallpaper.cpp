/****************************************************************************
** Meta object code from reading C++ file 'wallpaper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "main/wallpaper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wallpaper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WallPaper_t {
    QByteArrayData data[16];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WallPaper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WallPaper_t qt_meta_stringdata_WallPaper = {
    {
QT_MOC_LITERAL(0, 0, 9), // "WallPaper"
QT_MOC_LITERAL(1, 10, 8), // "picSaved"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 8), // "filepath"
QT_MOC_LITERAL(4, 29, 8), // "urlFound"
QT_MOC_LITERAL(5, 38, 3), // "url"
QT_MOC_LITERAL(6, 42, 10), // "findPicUrl"
QT_MOC_LITERAL(7, 53, 14), // "QNetworkReply*"
QT_MOC_LITERAL(8, 68, 5), // "reply"
QT_MOC_LITERAL(9, 74, 11), // "downloadPic"
QT_MOC_LITERAL(10, 86, 7), // "savePic"
QT_MOC_LITERAL(11, 94, 23), // "on_setWallPaper_clicked"
QT_MOC_LITERAL(12, 118, 10), // "textAppear"
QT_MOC_LITERAL(13, 129, 15), // "countDownAndSet"
QT_MOC_LITERAL(14, 145, 13), // "buttonPressed"
QT_MOC_LITERAL(15, 159, 14) // "buttonReleased"

    },
    "WallPaper\0picSaved\0\0filepath\0urlFound\0"
    "url\0findPicUrl\0QNetworkReply*\0reply\0"
    "downloadPic\0savePic\0on_setWallPaper_clicked\0"
    "textAppear\0countDownAndSet\0buttonPressed\0"
    "buttonReleased"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WallPaper[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   70,    2, 0x08 /* Private */,
       9,    1,   73,    2, 0x08 /* Private */,
      10,    1,   76,    2, 0x08 /* Private */,
      11,    0,   79,    2, 0x08 /* Private */,
      12,    0,   80,    2, 0x08 /* Private */,
      13,    0,   81,    2, 0x08 /* Private */,
      14,    0,   82,    2, 0x08 /* Private */,
      15,    0,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QUrl,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QUrl,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WallPaper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WallPaper *_t = static_cast<WallPaper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->picSaved((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->urlFound((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 2: _t->findPicUrl((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->downloadPic((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 4: _t->savePic((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 5: _t->on_setWallPaper_clicked(); break;
        case 6: _t->textAppear(); break;
        case 7: _t->countDownAndSet(); break;
        case 8: _t->buttonPressed(); break;
        case 9: _t->buttonReleased(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WallPaper::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WallPaper::picSaved)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WallPaper::*_t)(QUrl );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WallPaper::urlFound)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject WallPaper::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_WallPaper.data,
      qt_meta_data_WallPaper,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WallPaper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WallPaper::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WallPaper.stringdata0))
        return static_cast<void*>(const_cast< WallPaper*>(this));
    return QDialog::qt_metacast(_clname);
}

int WallPaper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void WallPaper::picSaved(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WallPaper::urlFound(QUrl _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
