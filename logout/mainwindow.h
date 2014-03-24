#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifdef _WIN32
#include <windows.h>
#endif

#include <QMainWindow>
#include <QSettings>

#include <QSystemTrayIcon>
#include <QFileInfo>

#include <QTcpServer>
#include <QTcpSocket>
#include <QThread>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:


private slots:

    void checkMyDate();

    void on_cmdCancel_clicked();

    void on_cmdHalt_clicked();

    void on_cmdReboot_clicked();

    void on_cmdCloseX_clicked();

    void on_checkDateTime_stateChanged();

    void disableGui();
    void toggleMainWindow();

    void halt();
    void reboot();
    void logout();
    #ifdef Q_OS_WIN32
    bool GetWinToken();
    #endif


    void on_cmdCustom_clicked();

    void on_actionAuthors_triggered();

    void on_cmdHaltAfterAllDownloads_clicked();

    void on_cmdDownloadFolder_clicked();

    void on_cmdAfterDownloadFile_clicked();

    void on_cmdHaltAfterSingleDownload_clicked();

    void checkAllDownloadsEnds();
    void checkSingleDownloadEnd();
    bool checkIfDirOk();
    void scanDirs(QString folder);

    void on_cmdEverydayDone_clicked();

    void CheckIfEverydayMode();
    void CheckEverydayTime();
    void LastWarningMsgbox();

    void on_cmdEverydayStop_clicked();
    bool checkIfTaskisInThePast();

    void on_checkBoxEnableEveryday_stateChanged();

    void on_cmdServerStartStop_clicked();
    void checkIfServerAtStartup();

    void newConnection();
    void serverStart();
    void RunServerCmd(QString cmd);
    void setAutostart();
    void unsetAutostart();



private:
    QString operation, settingsFile,WarningOperation, CancelOperation;
    QTimer *timer, *timerDownload, *timerEveryday ;
    Ui::MainWindow *ui;
    QSystemTrayIcon *trayIcon ;
    QFileInfoList listFilesDownloads;
    bool LastWarningEveryday;
    QTcpServer *server;
    QTcpSocket *socket;

};

#endif // MAINWINDOW_H

