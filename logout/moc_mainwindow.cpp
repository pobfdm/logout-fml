/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu Jun 27 19:33:13 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      26,   11,   11,   11, 0x08,
      49,   11,   11,   11, 0x08,
      70,   11,   11,   11, 0x08,
      93,   11,   11,   11, 0x08,
     116,   11,   11,   11, 0x08,
     148,   11,   11,   11, 0x08,
     161,   11,   11,   11, 0x08,
     168,   11,   11,   11, 0x08,
     177,   11,   11,   11, 0x08,
     186,   11,   11,   11, 0x08,
     209,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0checkMyDate()\0"
    "on_cmdCancel_clicked()\0on_cmdHalt_clicked()\0"
    "on_cmdReboot_clicked()\0on_cmdCloseX_clicked()\0"
    "on_checkDateTime_stateChanged()\0"
    "disableGui()\0halt()\0reboot()\0logout()\0"
    "on_cmdCustom_clicked()\0"
    "on_actionAuthors_triggered()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->checkMyDate(); break;
        case 1: _t->on_cmdCancel_clicked(); break;
        case 2: _t->on_cmdHalt_clicked(); break;
        case 3: _t->on_cmdReboot_clicked(); break;
        case 4: _t->on_cmdCloseX_clicked(); break;
        case 5: _t->on_checkDateTime_stateChanged(); break;
        case 6: _t->disableGui(); break;
        case 7: _t->halt(); break;
        case 8: _t->reboot(); break;
        case 9: _t->logout(); break;
        case 10: _t->on_cmdCustom_clicked(); break;
        case 11: _t->on_actionAuthors_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
