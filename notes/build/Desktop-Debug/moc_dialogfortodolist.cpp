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
    uint offsetsAndSizes[16];
    char stringdata0[18];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[10];
    char stringdata5[12];
    char stringdata6[13];
    char stringdata7[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_dialogfortodolist_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_dialogfortodolist_t qt_meta_stringdata_dialogfortodolist = {
    {
        QT_MOC_LITERAL(0, 17),  // "dialogfortodolist"
        QT_MOC_LITERAL(18, 7),  // "AddTask"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 4),  // "text"
        QT_MOC_LITERAL(32, 9),  // "RemoveAll"
        QT_MOC_LITERAL(42, 11),  // "CorrectTask"
        QT_MOC_LITERAL(54, 12),  // "CrossOutTask"
        QT_MOC_LITERAL(67, 10)   // "RemoveTask"
    },
    "dialogfortodolist",
    "AddTask",
    "",
    "text",
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
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x08,    1 /* Private */,
       1,    0,   53,    2, 0x28,    3 /* Private | MethodCloned */,
       4,    0,   54,    2, 0x08,    4 /* Private */,
       5,    0,   55,    2, 0x08,    5 /* Private */,
       6,    0,   56,    2, 0x08,    6 /* Private */,
       7,    0,   57,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
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
        // method 'AddTask'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
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
        case 0: _t->AddTask((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->AddTask(); break;
        case 2: _t->RemoveAll(); break;
        case 3: _t->CorrectTask(); break;
        case 4: _t->CrossOutTask(); break;
        case 5: _t->RemoveTask(); break;
        default: ;
        }
    }
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
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
