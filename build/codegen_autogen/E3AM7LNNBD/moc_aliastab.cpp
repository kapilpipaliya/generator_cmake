/****************************************************************************
** Meta object code from reading C++ file 'aliastab.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../widgets/bashrcconfig/aliastab.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'aliastab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AliasTabTableWidgetItem_t {
    QByteArrayData data[1];
    char stringdata0[24];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AliasTabTableWidgetItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AliasTabTableWidgetItem_t qt_meta_stringdata_AliasTabTableWidgetItem = {
    {
QT_MOC_LITERAL(0, 0, 23) // "AliasTabTableWidgetItem"

    },
    "AliasTabTableWidgetItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AliasTabTableWidgetItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void AliasTabTableWidgetItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject AliasTabTableWidgetItem::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_AliasTabTableWidgetItem.data,
    qt_meta_data_AliasTabTableWidgetItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AliasTabTableWidgetItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AliasTabTableWidgetItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AliasTabTableWidgetItem.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QTableWidgetItem"))
        return static_cast< QTableWidgetItem*>(this);
    return QObject::qt_metacast(_clname);
}

int AliasTabTableWidgetItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_AliasTab_t {
    QByteArrayData data[1];
    char stringdata0[9];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AliasTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AliasTab_t qt_meta_stringdata_AliasTab = {
    {
QT_MOC_LITERAL(0, 0, 8) // "AliasTab"

    },
    "AliasTab"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AliasTab[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void AliasTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject AliasTab::staticMetaObject = { {
    &Tab::staticMetaObject,
    qt_meta_stringdata_AliasTab.data,
    qt_meta_data_AliasTab,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AliasTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AliasTab::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AliasTab.stringdata0))
        return static_cast<void*>(this);
    return Tab::qt_metacast(_clname);
}

int AliasTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Tab::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
