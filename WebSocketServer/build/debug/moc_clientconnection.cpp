/****************************************************************************
** Meta object code from reading C++ file 'clientconnection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../clientconnection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientconnection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ClientConnection_t {
    QByteArrayData data[7];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClientConnection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClientConnection_t qt_meta_stringdata_ClientConnection = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ClientConnection"
QT_MOC_LITERAL(1, 17, 14), // "reciveMessages"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 7), // "message"
QT_MOC_LITERAL(4, 41, 11), // "sendMessage"
QT_MOC_LITERAL(5, 53, 10), // "Query::Ptr"
QT_MOC_LITERAL(6, 64, 5) // "query"

    },
    "ClientConnection\0reciveMessages\0\0"
    "message\0sendMessage\0Query::Ptr\0query"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientConnection[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       4,    1,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void ClientConnection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClientConnection *_t = static_cast<ClientConnection *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->reciveMessages((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendMessage((*reinterpret_cast< Query::Ptr(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ClientConnection::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ClientConnection.data,
      qt_meta_data_ClientConnection,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ClientConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ClientConnection.stringdata0))
        return static_cast<void*>(const_cast< ClientConnection*>(this));
    return QObject::qt_metacast(_clname);
}

int ClientConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_END_MOC_NAMESPACE
