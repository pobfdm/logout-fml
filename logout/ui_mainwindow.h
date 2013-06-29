/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Jun 27 19:33:08 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAuthors;
    QWidget *centralWidget;
    QPushButton *cmdHalt;
    QPushButton *cmdReboot;
    QPushButton *cmdCancel;
    QPushButton *cmdCloseX;
    QDateTimeEdit *dateTimeEdit;
    QCheckBox *checkDateTime;
    QLineEdit *txtCustom;
    QPushButton *cmdCustom;
    QMenuBar *menuBar;
    QMenu *menuInfo;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 350);
        MainWindow->setMinimumSize(QSize(400, 350));
        MainWindow->setMaximumSize(QSize(400, 350));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../../../home/fabio/progetti/logout/share/logout/logout.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionAuthors = new QAction(MainWindow);
        actionAuthors->setObjectName(QString::fromUtf8("actionAuthors"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        cmdHalt = new QPushButton(centralWidget);
        cmdHalt->setObjectName(QString::fromUtf8("cmdHalt"));
        cmdHalt->setGeometry(QRect(120, 80, 161, 27));
        cmdReboot = new QPushButton(centralWidget);
        cmdReboot->setObjectName(QString::fromUtf8("cmdReboot"));
        cmdReboot->setGeometry(QRect(120, 120, 161, 27));
        cmdCancel = new QPushButton(centralWidget);
        cmdCancel->setObjectName(QString::fromUtf8("cmdCancel"));
        cmdCancel->setGeometry(QRect(150, 250, 101, 27));
        cmdCloseX = new QPushButton(centralWidget);
        cmdCloseX->setObjectName(QString::fromUtf8("cmdCloseX"));
        cmdCloseX->setGeometry(QRect(120, 160, 161, 27));
        dateTimeEdit = new QDateTimeEdit(centralWidget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setEnabled(false);
        dateTimeEdit->setGeometry(QRect(123, 40, 161, 22));
        checkDateTime = new QCheckBox(centralWidget);
        checkDateTime->setObjectName(QString::fromUtf8("checkDateTime"));
        checkDateTime->setGeometry(QRect(120, 20, 251, 20));
        txtCustom = new QLineEdit(centralWidget);
        txtCustom->setObjectName(QString::fromUtf8("txtCustom"));
        txtCustom->setGeometry(QRect(120, 200, 113, 20));
        cmdCustom = new QPushButton(centralWidget);
        cmdCustom->setObjectName(QString::fromUtf8("cmdCustom"));
        cmdCustom->setGeometry(QRect(240, 200, 41, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        menuInfo = new QMenu(menuBar);
        menuInfo->setObjectName(QString::fromUtf8("menuInfo"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuInfo->menuAction());
        menuInfo->addAction(actionAuthors);

        retranslateUi(MainWindow);
        QObject::connect(MainWindow, SIGNAL(timeout()), MainWindow, SLOT(checkMyDate()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Logout ", 0, QApplication::UnicodeUTF8));
        actionAuthors->setText(QApplication::translate("MainWindow", "Authors", 0, QApplication::UnicodeUTF8));
        cmdHalt->setText(QApplication::translate("MainWindow", "Halt", 0, QApplication::UnicodeUTF8));
        cmdReboot->setText(QApplication::translate("MainWindow", "Reboot", 0, QApplication::UnicodeUTF8));
        cmdCancel->setText(QApplication::translate("MainWindow", "Cancel", 0, QApplication::UnicodeUTF8));
        cmdCloseX->setText(QApplication::translate("MainWindow", "Close session", 0, QApplication::UnicodeUTF8));
        dateTimeEdit->setDisplayFormat(QApplication::translate("MainWindow", "dd/MM/yyyy HH:mm", 0, QApplication::UnicodeUTF8));
        checkDateTime->setText(QApplication::translate("MainWindow", "Enable date time", 0, QApplication::UnicodeUTF8));
        cmdCustom->setText(QApplication::translate("MainWindow", "Run", 0, QApplication::UnicodeUTF8));
        menuInfo->setTitle(QApplication::translate("MainWindow", "Info", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
