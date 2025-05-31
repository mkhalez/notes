/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../try_to_best_ui/notes/notes/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[28];
    char stringdata0[11];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[14];
    char stringdata5[20];
    char stringdata6[13];
    char stringdata7[7];
    char stringdata8[13];
    char stringdata9[18];
    char stringdata10[21];
    char stringdata11[12];
    char stringdata12[21];
    char stringdata13[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 12),  // "PrivateClick"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 8),  // "AddClick"
        QT_MOC_LITERAL(34, 13),  // "AddNoteHelper"
        QT_MOC_LITERAL(48, 19),  // "OpenFileWithContent"
        QT_MOC_LITERAL(68, 12),  // "QPushButton*"
        QT_MOC_LITERAL(81, 6),  // "button"
        QT_MOC_LITERAL(88, 12),  // "name_of_file"
        QT_MOC_LITERAL(101, 17),  // "AddToDoListHelper"
        QT_MOC_LITERAL(119, 20),  // "SearchInitialization"
        QT_MOC_LITERAL(140, 11),  // "FilterClick"
        QT_MOC_LITERAL(152, 20),  // "ShowSortedByAlphabet"
        QT_MOC_LITERAL(173, 16)   // "ShowSortedByData"
    },
    "MainWindow",
    "PrivateClick",
    "",
    "AddClick",
    "AddNoteHelper",
    "OpenFileWithContent",
    "QPushButton*",
    "button",
    "name_of_file",
    "AddToDoListHelper",
    "SearchInitialization",
    "FilterClick",
    "ShowSortedByAlphabet",
    "ShowSortedByData"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x08,    1 /* Private */,
       3,    0,   69,    2, 0x08,    2 /* Private */,
       4,    0,   70,    2, 0x08,    3 /* Private */,
       5,    2,   71,    2, 0x08,    4 /* Private */,
       9,    0,   76,    2, 0x08,    7 /* Private */,
      10,    0,   77,    2, 0x08,    8 /* Private */,
      11,    0,   78,    2, 0x08,    9 /* Private */,
      12,    0,   79,    2, 0x08,   10 /* Private */,
      13,    0,   80,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, QMetaType::QString,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'PrivateClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'AddClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'AddNoteHelper'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OpenFileWithContent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPushButton *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'AddToDoListHelper'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SearchInitialization'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'FilterClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ShowSortedByAlphabet'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ShowSortedByData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->PrivateClick(); break;
        case 1: _t->AddClick(); break;
        case 2: _t->AddNoteHelper(); break;
        case 3: _t->OpenFileWithContent((*reinterpret_cast< std::add_pointer_t<QPushButton*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 4: _t->AddToDoListHelper(); break;
        case 5: _t->SearchInitialization(); break;
        case 6: _t->FilterClick(); break;
        case 7: _t->ShowSortedByAlphabet(); break;
        case 8: _t->ShowSortedByData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QPushButton* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
