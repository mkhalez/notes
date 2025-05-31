/****************************************************************************
** Meta object code from reading C++ file 'authentication.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../try_to_best_ui/notes/notes/authentication.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'authentication.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_authentication_t {
    uint offsetsAndSizes[14];
    char stringdata0[15];
    char stringdata1[31];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[9];
    char stringdata5[10];
    char stringdata6[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_authentication_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_authentication_t qt_meta_stringdata_authentication = {
    {
        QT_MOC_LITERAL(0, 14),  // "authentication"
        QT_MOC_LITERAL(15, 30),  // "finishAuthenticationDialogWork"
        QT_MOC_LITERAL(46, 0),  // ""
        QT_MOC_LITERAL(47, 7),  // "success"
        QT_MOC_LITERAL(55, 8),  // "password"
        QT_MOC_LITERAL(64, 9),  // "CheckUser"
        QT_MOC_LITERAL(74, 12)   // "ShowPassword"
    },
    "authentication",
    "finishAuthenticationDialogWork",
    "",
    "success",
    "password",
    "CheckUser",
    "ShowPassword"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_authentication[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   32,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   37,    2, 0x08,    4 /* Private */,
       6,    0,   38,    2, 0x08,    5 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject authentication::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_authentication.offsetsAndSizes,
    qt_meta_data_authentication,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_authentication_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<authentication, std::true_type>,
        // method 'finishAuthenticationDialogWork'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'CheckUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ShowPassword'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void authentication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<authentication *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->finishAuthenticationDialogWork((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->CheckUser(); break;
        case 2: _t->ShowPassword(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (authentication::*)(bool , const QString & );
            if (_t _q_method = &authentication::finishAuthenticationDialogWork; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *authentication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *authentication::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_authentication.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int authentication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void authentication::finishAuthenticationDialogWork(bool _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
