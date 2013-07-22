#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifdef _WIN32
#include <windows.h>
#endif

#include <QMainWindow>
#include <QSettings>

#include <QSystemTrayIcon>
#include <QFileInfo>

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

private:
    QString operation, settingsFile;
    QTimer *timer, *timerDownload ;
    Ui::MainWindow *ui;
    QSystemTrayIcon *trayIcon ;
    QFileInfoList listFilesDownloads;

};

#endif // MAINWINDOW_H
