/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
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
     180,   11,   11,   11, 0x08,
     187,   11,   11,   11, 0x08,
     196,   11,   11,   11, 0x08,
     205,   11,   11,   11, 0x08,
     228,   11,   11,   11, 0x08,
     257,   11,   11,   11, 0x08,
     295,   11,   11,   11, 0x08,
     326,   11,   11,   11, 0x08,
     360,   11,   11,   11, 0x08,
     400,   11,   11,   11, 0x08,
     424,   11,   11,   11, 0x08,
     454,   11,  449,   11, 0x08,
     476,  469,   11,   11, 0x08,
     494,   11,   11,   11, 0x08,
     523,   11,   11,   11, 0x08,
     545,   11,   11,   11, 0x08,
     565,   11,   11,   11, 0x08,
     585,   11,   11,   11, 0x08,
     614,   11,  449,   11, 0x08,
     639,   11,   11,   11, 0x08,
     680,   11,   11,   11, 0x08,
     712,   11,   11,   11, 0x08,
     737,   11,   11,   11, 0x08,
     753,   11,   11,   11, 0x08,
     771,  767,   11,   11, 0x08,
     793,   11,   11,   11, 0x08,
     808,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0checkMyDate()\0"
    "on_cmdCancel_clicked()\0on_cmdHalt_clicked()\0"
    "on_cmdReboot_clicked()\0on_cmdCloseX_clicked()\0"
    "on_checkDateTime_stateChanged()\0"
    "disableGui()\0toggleMainWindow()\0halt()\0"
    "reboot()\0logout()\0on_cmdCustom_clicked()\0"
    "on_actionAuthors_triggered()\0"
    "on_cmdHaltAfterAllDownloads_clicked()\0"
    "on_cmdDownloadFolder_clicked()\0"
    "on_cmdAfterDownloadFile_clicked()\0"
    "on_cmdHaltAfterSingleDownload_clicked()\0"
    "checkAllDownloadsEnds()\0"
    "checkSingleDownloadEnd()\0bool\0"
    "checkIfDirOk()\0folder\0scanDirs(QString)\0"
    "on_cmdEverydayDone_clicked()\0"
    "CheckIfEverydayMode()\0CheckEverydayTime()\0"
    "LastWarningMsgbox()\0on_cmdEverydayStop_clicked()\0"
    "checkIfTaskisInThePast()\0"
    "on_checkBoxEnableEveryday_stateChanged()\0"
    "on_cmdServerStartStop_clicked()\0"
    "checkIfServerAtStartup()\0newConnection()\0"
    "serverStart()\0cmd\0RunServerCmd(QString)\0"
    "setAutostart()\0unsetAutostart()\0"
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
        case 7: _t->toggleMainWindow(); break;
        case 8: _t->halt(); break;
        case 9: _t->reboot(); break;
        case 10: _t->logout(); break;
        case 11: _t->on_cmdCustom_clicked(); break;
        case 12: _t->on_actionAuthors_triggered(); break;
        case 13: _t->on_cmdHaltAfterAllDownloads_clicked(); break;
        case 14: _t->on_cmdDownloadFolder_clicked(); break;
        case 15: _t->on_cmdAfterDownloadFile_clicked(); break;
        case 16: _t->on_cmdHaltAfterSingleDownload_clicked(); break;
        case 17: _t->checkAllDownloadsEnds(); break;
        case 18: _t->checkSingleDownloadEnd(); break;
        case 19: { bool _r = _t->checkIfDirOk();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 20: _t->scanDirs((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: _t->on_cmdEverydayDone_clicked(); break;
        case 22: _t->CheckIfEverydayMode(); break;
        case 23: _t->CheckEverydayTime(); break;
        case 24: _t->LastWarningMsgbox(); break;
        case 25: _t->on_cmdEverydayStop_clicked(); break;
        case 26: { bool _r = _t->checkIfTaskisInThePast();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 27: _t->on_checkBoxEnableEveryday_stateChanged(); break;
        case 28: _t->on_cmdServerStartStop_clicked(); break;
        case 29: _t->checkIfServerAtStartup(); break;
        case 30: _t->newConnection(); break;
        case 31: _t->serverStart(); break;
        case 32: _t->RunServerCmd((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 33: _t->setAutostart(); break;
        case 34: _t->unsetAutostart(); break;
        default: ;
        }
    }
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
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
