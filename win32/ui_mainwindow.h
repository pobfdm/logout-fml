/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Mar 11 09:48:53 2014
**      by: Qt User Interface Compiler version 4.8.1
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
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTimeEdit>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAuthors;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tabStandard;
    QLineEdit *txtCustom;
    QPushButton *cmdCloseX;
    QPushButton *cmdReboot;
    QCheckBox *checkDateTime;
    QPushButton *cmdCustom;
    QDateTimeEdit *dateTimeEdit;
    QPushButton *cmdHalt;
    QWidget *tabDownloads;
    QLineEdit *txtDownloadSuffix;
    QLabel *lblDownloadSuffix;
    QLineEdit *txtDownloasFolder;
    QLabel *lblDownloadsFolder;
    QToolButton *cmdDownloadFolder;
    QToolButton *cmdAfterDownloadFile;
    QLabel *lblDownloadFile;
    QLineEdit *txtAfterDownloadFile;
    QPushButton *cmdHaltAfterAllDownloads;
    QPushButton *cmdHaltAfterSingleDownload;
    QLabel *lblDownloadsStatus;
    QWidget *tabEveryday;
    QCheckBox *checkBoxEnableEveryday;
    QTimeEdit *timeEditEveryDay;
    QLabel *lblTimeEveryDay;
    QComboBox *cmbEverydayCmd;
    QLabel *lblCmdEveryDay;
    QPushButton *cmdEverydayDone;
    QCheckBox *checkBoxEverydayRunMinimized;
    QPushButton *cmdEverydayStop;
    QPushButton *cmdCancel;
    QMenuBar *menuBar;
    QMenu *menuInfo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(450, 350);
        MainWindow->setMinimumSize(QSize(450, 350));
        MainWindow->setMaximumSize(QSize(450, 350));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/logout.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionAuthors = new QAction(MainWindow);
        actionAuthors->setObjectName(QString::fromUtf8("actionAuthors"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(30, 10, 391, 271));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setTabsClosable(false);
        tabStandard = new QWidget();
        tabStandard->setObjectName(QString::fromUtf8("tabStandard"));
        txtCustom = new QLineEdit(tabStandard);
        txtCustom->setObjectName(QString::fromUtf8("txtCustom"));
        txtCustom->setGeometry(QRect(100, 200, 113, 20));
        cmdCloseX = new QPushButton(tabStandard);
        cmdCloseX->setObjectName(QString::fromUtf8("cmdCloseX"));
        cmdCloseX->setGeometry(QRect(100, 160, 161, 27));
        cmdReboot = new QPushButton(tabStandard);
        cmdReboot->setObjectName(QString::fromUtf8("cmdReboot"));
        cmdReboot->setGeometry(QRect(100, 120, 161, 27));
        checkDateTime = new QCheckBox(tabStandard);
        checkDateTime->setObjectName(QString::fromUtf8("checkDateTime"));
        checkDateTime->setGeometry(QRect(100, 10, 251, 20));
        cmdCustom = new QPushButton(tabStandard);
        cmdCustom->setObjectName(QString::fromUtf8("cmdCustom"));
        cmdCustom->setGeometry(QRect(220, 200, 41, 21));
        dateTimeEdit = new QDateTimeEdit(tabStandard);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setEnabled(false);
        dateTimeEdit->setGeometry(QRect(100, 30, 161, 22));
        cmdHalt = new QPushButton(tabStandard);
        cmdHalt->setObjectName(QString::fromUtf8("cmdHalt"));
        cmdHalt->setGeometry(QRect(100, 80, 161, 27));
        tabWidget->addTab(tabStandard, QString());
        tabDownloads = new QWidget();
        tabDownloads->setObjectName(QString::fromUtf8("tabDownloads"));
        txtDownloadSuffix = new QLineEdit(tabDownloads);
        txtDownloadSuffix->setObjectName(QString::fromUtf8("txtDownloadSuffix"));
        txtDownloadSuffix->setGeometry(QRect(80, 40, 113, 20));
        lblDownloadSuffix = new QLabel(tabDownloads);
        lblDownloadSuffix->setObjectName(QString::fromUtf8("lblDownloadSuffix"));
        lblDownloadSuffix->setGeometry(QRect(80, 20, 151, 16));
        txtDownloasFolder = new QLineEdit(tabDownloads);
        txtDownloasFolder->setObjectName(QString::fromUtf8("txtDownloasFolder"));
        txtDownloasFolder->setGeometry(QRect(80, 90, 113, 20));
        txtDownloasFolder->setReadOnly(true);
        lblDownloadsFolder = new QLabel(tabDownloads);
        lblDownloadsFolder->setObjectName(QString::fromUtf8("lblDownloadsFolder"));
        lblDownloadsFolder->setGeometry(QRect(80, 70, 151, 16));
        cmdDownloadFolder = new QToolButton(tabDownloads);
        cmdDownloadFolder->setObjectName(QString::fromUtf8("cmdDownloadFolder"));
        cmdDownloadFolder->setGeometry(QRect(200, 90, 30, 18));
        cmdAfterDownloadFile = new QToolButton(tabDownloads);
        cmdAfterDownloadFile->setObjectName(QString::fromUtf8("cmdAfterDownloadFile"));
        cmdAfterDownloadFile->setGeometry(QRect(200, 140, 30, 18));
        lblDownloadFile = new QLabel(tabDownloads);
        lblDownloadFile->setObjectName(QString::fromUtf8("lblDownloadFile"));
        lblDownloadFile->setGeometry(QRect(80, 120, 151, 16));
        txtAfterDownloadFile = new QLineEdit(tabDownloads);
        txtAfterDownloadFile->setObjectName(QString::fromUtf8("txtAfterDownloadFile"));
        txtAfterDownloadFile->setGeometry(QRect(80, 140, 113, 20));
        txtAfterDownloadFile->setReadOnly(true);
        cmdHaltAfterAllDownloads = new QPushButton(tabDownloads);
        cmdHaltAfterAllDownloads->setObjectName(QString::fromUtf8("cmdHaltAfterAllDownloads"));
        cmdHaltAfterAllDownloads->setGeometry(QRect(250, 77, 125, 27));
        cmdHaltAfterSingleDownload = new QPushButton(tabDownloads);
        cmdHaltAfterSingleDownload->setObjectName(QString::fromUtf8("cmdHaltAfterSingleDownload"));
        cmdHaltAfterSingleDownload->setGeometry(QRect(250, 130, 125, 27));
        lblDownloadsStatus = new QLabel(tabDownloads);
        lblDownloadsStatus->setObjectName(QString::fromUtf8("lblDownloadsStatus"));
        lblDownloadsStatus->setGeometry(QRect(0, 220, 381, 20));
        lblDownloadsStatus->setFrameShape(QFrame::Panel);
        lblDownloadsStatus->setFrameShadow(QFrame::Sunken);
        tabWidget->addTab(tabDownloads, QString());
        tabEveryday = new QWidget();
        tabEveryday->setObjectName(QString::fromUtf8("tabEveryday"));
        tabEveryday->setStyleSheet(QString::fromUtf8(""));
        checkBoxEnableEveryday = new QCheckBox(tabEveryday);
        checkBoxEnableEveryday->setObjectName(QString::fromUtf8("checkBoxEnableEveryday"));
        checkBoxEnableEveryday->setGeometry(QRect(100, 30, 81, 19));
        timeEditEveryDay = new QTimeEdit(tabEveryday);
        timeEditEveryDay->setObjectName(QString::fromUtf8("timeEditEveryDay"));
        timeEditEveryDay->setGeometry(QRect(100, 80, 71, 24));
        lblTimeEveryDay = new QLabel(tabEveryday);
        lblTimeEveryDay->setObjectName(QString::fromUtf8("lblTimeEveryDay"));
        lblTimeEveryDay->setGeometry(QRect(100, 60, 61, 14));
        cmbEverydayCmd = new QComboBox(tabEveryday);
        cmbEverydayCmd->setObjectName(QString::fromUtf8("cmbEverydayCmd"));
        cmbEverydayCmd->setGeometry(QRect(180, 80, 141, 24));
        lblCmdEveryDay = new QLabel(tabEveryday);
        lblCmdEveryDay->setObjectName(QString::fromUtf8("lblCmdEveryDay"));
        lblCmdEveryDay->setGeometry(QRect(180, 60, 61, 14));
        cmdEverydayDone = new QPushButton(tabEveryday);
        cmdEverydayDone->setObjectName(QString::fromUtf8("cmdEverydayDone"));
        cmdEverydayDone->setGeometry(QRect(240, 150, 85, 27));
        checkBoxEverydayRunMinimized = new QCheckBox(tabEveryday);
        checkBoxEverydayRunMinimized->setObjectName(QString::fromUtf8("checkBoxEverydayRunMinimized"));
        checkBoxEverydayRunMinimized->setGeometry(QRect(100, 110, 221, 19));
        cmdEverydayStop = new QPushButton(tabEveryday);
        cmdEverydayStop->setObjectName(QString::fromUtf8("cmdEverydayStop"));
        cmdEverydayStop->setEnabled(false);
        cmdEverydayStop->setGeometry(QRect(100, 150, 85, 27));
        tabWidget->addTab(tabEveryday, QString());
        cmdCancel = new QPushButton(centralWidget);
        cmdCancel->setObjectName(QString::fromUtf8("cmdCancel"));
        cmdCancel->setGeometry(QRect(320, 290, 101, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 450, 22));
        menuInfo = new QMenu(menuBar);
        menuInfo->setObjectName(QString::fromUtf8("menuInfo"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuInfo->menuAction());
        menuInfo->addAction(actionAuthors);

        retranslateUi(MainWindow);
        QObject::connect(MainWindow, SIGNAL(timeout()), MainWindow, SLOT(checkMyDate()));

        tabWidget->setCurrentIndex(2);
        cmbEverydayCmd->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Logout ", 0, QApplication::UnicodeUTF8));
        actionAuthors->setText(QApplication::translate("MainWindow", "Authors", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tabWidget->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_ACCESSIBILITY
        tabWidget->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        cmdCloseX->setText(QApplication::translate("MainWindow", "Close session", 0, QApplication::UnicodeUTF8));
        cmdReboot->setText(QApplication::translate("MainWindow", "Reboot", 0, QApplication::UnicodeUTF8));
        checkDateTime->setText(QApplication::translate("MainWindow", "Enable date time", 0, QApplication::UnicodeUTF8));
        cmdCustom->setText(QApplication::translate("MainWindow", "Run", 0, QApplication::UnicodeUTF8));
        dateTimeEdit->setDisplayFormat(QApplication::translate("MainWindow", "dd/MM/yyyy HH:mm", 0, QApplication::UnicodeUTF8));
        cmdHalt->setText(QApplication::translate("MainWindow", "Halt", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabStandard), QApplication::translate("MainWindow", "Standard commands", 0, QApplication::UnicodeUTF8));
        lblDownloadSuffix->setText(QApplication::translate("MainWindow", "Suffix filename", 0, QApplication::UnicodeUTF8));
        lblDownloadsFolder->setText(QApplication::translate("MainWindow", "Dowloads folder", 0, QApplication::UnicodeUTF8));
        cmdDownloadFolder->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        cmdAfterDownloadFile->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        lblDownloadFile->setText(QApplication::translate("MainWindow", "After dowload file:", 0, QApplication::UnicodeUTF8));
        cmdHaltAfterAllDownloads->setText(QApplication::translate("MainWindow", "Halt after all", 0, QApplication::UnicodeUTF8));
        cmdHaltAfterSingleDownload->setText(QApplication::translate("MainWindow", "Halt after this", 0, QApplication::UnicodeUTF8));
        lblDownloadsStatus->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabDownloads), QApplication::translate("MainWindow", "Downloads", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tabEveryday->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        checkBoxEnableEveryday->setText(QApplication::translate("MainWindow", "Enable", 0, QApplication::UnicodeUTF8));
        lblTimeEveryDay->setText(QApplication::translate("MainWindow", "Time", 0, QApplication::UnicodeUTF8));
        cmbEverydayCmd->clear();
        cmbEverydayCmd->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Halt", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Reboot", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Custom command (from standard tab)", 0, QApplication::UnicodeUTF8)
        );
        lblCmdEveryDay->setText(QApplication::translate("MainWindow", "Command", 0, QApplication::UnicodeUTF8));
        cmdEverydayDone->setText(QApplication::translate("MainWindow", "Done", 0, QApplication::UnicodeUTF8));
        checkBoxEverydayRunMinimized->setText(QApplication::translate("MainWindow", "Hide main window", 0, QApplication::UnicodeUTF8));
        cmdEverydayStop->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabEveryday), QApplication::translate("MainWindow", "Everyday", 0, QApplication::UnicodeUTF8));
        cmdCancel->setText(QApplication::translate("MainWindow", "Cancel", 0, QApplication::UnicodeUTF8));
        menuInfo->setTitle(QApplication::translate("MainWindow", "Info", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
