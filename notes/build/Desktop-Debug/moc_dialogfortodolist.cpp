/****************************************************************************
** Meta object code from reading C++ file 'dialogfortodolist.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../dialogfortodolist.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogfortodolist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_dialogfortodolist_t {
    uint offsetsAndSizes[18];
    char stringdata0[18];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[23];
    char stringdata4[8];
    char stringdata5[10];
    char stringdata6[12];
    char stringdata7[13];
    char stringdata8[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_dialogfortodolist_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_dialogfortodolist_t qt_meta_stringdata_dialogfortodolist = {
    {
        QT_MOC_LITERAL(0, 17),  // "dialogfortodolist"
        QT_MOC_LITERAL(18, 13),  // "onItemClicked"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 22),  // "onItemSelectionChanged"
        QT_MOC_LITERAL(56, 7),  // "AddTask"
        QT_MOC_LITERAL(64, 9),  // "RemoveAll"
        QT_MOC_LITERAL(74, 11),  // "CorrectTask"
        QT_MOC_LITERAL(86, 12),  // "CrossOutTask"
        QT_MOC_LITERAL(99, 10)   // "RemoveTask"
    },
    "dialogfortodolist",
    "onItemClicked",
    "",
    "onItemSelectionChanged",
    "AddTask",
    "RemoveAll",
    "CorrectTask",
    "CrossOutTask",
    "RemoveTask"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_dialogfortodolist[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    0,   62,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject dialogfortodolist::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_dialogfortodolist.offsetsAndSizes,
    qt_meta_data_dialogfortodolist,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_dialogfortodolist_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<dialogfortodolist, std::true_type>,
        // method 'onItemClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onItemSelectionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'AddTask'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'RemoveAll'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'CorrectTask'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'CrossOutTask'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'RemoveTask'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void dialogfortodolist::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<dialogfortodolist *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onItemClicked(); break;
        case 1: _t->onItemSelectionChanged(); break;
        case 2: _t->AddTask(); break;
        case 3: _t->RemoveAll(); break;
        case 4: _t->CorrectTask(); break;
        case 5: _t->CrossOutTask(); break;
        case 6: _t->RemoveTask(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *dialogfortodolist::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dialogfortodolist::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dialogfortodolist.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int dialogfortodolist::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
