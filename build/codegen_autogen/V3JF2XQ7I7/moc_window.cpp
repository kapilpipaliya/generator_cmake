/****************************************************************************
** Meta object code from reading C++ file 'window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../widgets/bashhistoryviewer/window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_widgets__bashHistoryViewer__Window_t {
    QByteArrayData data[12];
    char stringdata0[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_widgets__bashHistoryViewer__Window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_widgets__bashHistoryViewer__Window_t qt_meta_stringdata_widgets__bashHistoryViewer__Window = {
    {
QT_MOC_LITERAL(0, 0, 34), // "widgets::bashHistoryViewer::W..."
QT_MOC_LITERAL(1, 35, 15), // "addToolBarItems"
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 15), // "addToFavourites"
QT_MOC_LITERAL(4, 68, 15), // "writeFavourites"
QT_MOC_LITERAL(5, 84, 6), // "string"
QT_MOC_LITERAL(6, 91, 10), // "favourites"
QT_MOC_LITERAL(7, 102, 11), // "execCommand"
QT_MOC_LITERAL(8, 114, 11), // "const char*"
QT_MOC_LITERAL(9, 126, 3), // "cmd"
QT_MOC_LITERAL(10, 130, 15), // "deleteTableLine"
QT_MOC_LITERAL(11, 146, 10) // "copyToClip"

    },
    "widgets::bashHistoryViewer::Window\0"
    "addToolBarItems\0\0addToFavourites\0"
    "writeFavourites\0string\0favourites\0"
    "execCommand\0const char*\0cmd\0deleteTableLine\0"
    "copyToClip"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_widgets__bashHistoryViewer__Window[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    1,   46,    2, 0x08 /* Private */,
       7,    1,   49,    2, 0x08 /* Private */,
      10,    0,   52,    2, 0x08 /* Private */,
      11,    0,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, 0x80000000 | 5,    6,
    0x80000000 | 5, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Int,

       0        // eod
};

void widgets::bashHistoryViewer::Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addToolBarItems(); break;
        case 1: _t->addToFavourites(); break;
        case 2: { int _r = _t->writeFavourites((*reinterpret_cast< string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { string _r = _t->execCommand((*reinterpret_cast< const char*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< string*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->deleteTableLine(); break;
        case 5: { int _r = _t->copyToClip();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject widgets::bashHistoryViewer::Window::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_widgets__bashHistoryViewer__Window.data,
    qt_meta_data_widgets__bashHistoryViewer__Window,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *widgets::bashHistoryViewer::Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *widgets::bashHistoryViewer::Window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_widgets__bashHistoryViewer__Window.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int widgets::bashHistoryViewer::Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
