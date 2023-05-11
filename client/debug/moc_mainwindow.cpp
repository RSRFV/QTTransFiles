/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[15];
    char stringdata0[261];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 9), // "sendStart"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 12), // "filePathList"
QT_MOC_LITERAL(4, 35, 2), // "ip"
QT_MOC_LITERAL(5, 38, 4), // "port"
QT_MOC_LITERAL(6, 43, 9), // "recvStart"
QT_MOC_LITERAL(7, 53, 15), // "closeAllConnect"
QT_MOC_LITERAL(8, 69, 17), // "setSendSocketFlag"
QT_MOC_LITERAL(9, 87, 7), // "checked"
QT_MOC_LITERAL(10, 95, 33), // "on_pushButton_seleectFile_cli..."
QT_MOC_LITERAL(11, 129, 30), // "on_pushButton_sendFile_clicked"
QT_MOC_LITERAL(12, 160, 33), // "on_pushButton_connectSend_cli..."
QT_MOC_LITERAL(13, 194, 33), // "on_pushButton_connectRecv_cli..."
QT_MOC_LITERAL(14, 228, 32) // "on_pushButton_disconnect_clicked"

    },
    "MainWindow\0sendStart\0\0filePathList\0"
    "ip\0port\0recvStart\0closeAllConnect\0"
    "setSendSocketFlag\0checked\0"
    "on_pushButton_seleectFile_clicked\0"
    "on_pushButton_sendFile_clicked\0"
    "on_pushButton_connectSend_clicked\0"
    "on_pushButton_connectRecv_clicked\0"
    "on_pushButton_disconnect_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   59,    2, 0x06 /* Public */,
       6,    2,   66,    2, 0x06 /* Public */,
       7,    0,   71,    2, 0x06 /* Public */,
       8,    1,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   75,    2, 0x08 /* Private */,
      11,    0,   76,    2, 0x08 /* Private */,
      12,    0,   77,    2, 0x08 /* Private */,
      13,    0,   78,    2, 0x08 /* Private */,
      14,    0,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList, QMetaType::QString, QMetaType::UShort,    3,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,    4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendStart((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< ushort(*)>(_a[3]))); break;
        case 1: _t->recvStart((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< ushort(*)>(_a[2]))); break;
        case 2: _t->closeAllConnect(); break;
        case 3: _t->setSendSocketFlag((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_seleectFile_clicked(); break;
        case 5: _t->on_pushButton_sendFile_clicked(); break;
        case 6: _t->on_pushButton_connectSend_clicked(); break;
        case 7: _t->on_pushButton_connectRecv_clicked(); break;
        case 8: _t->on_pushButton_disconnect_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QStringList , QString , ushort );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendStart)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString , ushort );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::recvStart)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::closeAllConnect)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::setSendSocketFlag)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sendStart(QStringList _t1, QString _t2, ushort _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::recvStart(QString _t1, ushort _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::closeAllConnect()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::setSendSocketFlag(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
