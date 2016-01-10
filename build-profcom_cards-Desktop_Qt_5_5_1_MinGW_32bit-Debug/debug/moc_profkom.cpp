/****************************************************************************
** Meta object code from reading C++ file 'profkom.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../profcom_cards/profkom.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'profkom.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Profkom_t {
    QByteArrayData data[12];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Profkom_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Profkom_t qt_meta_stringdata_Profkom = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Profkom"
QT_MOC_LITERAL(1, 8, 11), // "ShowMessage"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "messageText"
QT_MOC_LITERAL(4, 33, 5), // "Title"
QT_MOC_LITERAL(5, 39, 18), // "on_ISU_textChanged"
QT_MOC_LITERAL(6, 58, 4), // "arg1"
QT_MOC_LITERAL(7, 63, 9), // "connectBD"
QT_MOC_LITERAL(8, 73, 12), // "getEventList"
QT_MOC_LITERAL(9, 86, 26), // "on_buttonAddEvents_clicked"
QT_MOC_LITERAL(10, 113, 24), // "on_buttonPayFees_clicked"
QT_MOC_LITERAL(11, 138, 19) // "on_eventAdd_clicked"

    },
    "Profkom\0ShowMessage\0\0messageText\0Title\0"
    "on_ISU_textChanged\0arg1\0connectBD\0"
    "getEventList\0on_buttonAddEvents_clicked\0"
    "on_buttonPayFees_clicked\0on_eventAdd_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Profkom[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x08 /* Private */,
       5,    1,   54,    2, 0x08 /* Private */,
       7,    0,   57,    2, 0x08 /* Private */,
       8,    0,   58,    2, 0x08 /* Private */,
       9,    0,   59,    2, 0x08 /* Private */,
      10,    0,   60,    2, 0x08 /* Private */,
      11,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Profkom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Profkom *_t = static_cast<Profkom *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ShowMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->on_ISU_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->connectBD(); break;
        case 3: _t->getEventList(); break;
        case 4: _t->on_buttonAddEvents_clicked(); break;
        case 5: _t->on_buttonPayFees_clicked(); break;
        case 6: _t->on_eventAdd_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Profkom::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Profkom.data,
      qt_meta_data_Profkom,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Profkom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Profkom::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Profkom.stringdata0))
        return static_cast<void*>(const_cast< Profkom*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Profkom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
