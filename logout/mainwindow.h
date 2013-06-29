#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifdef _WIN32
#include <windows.h>
#endif

#include <QMainWindow>
#include <QSettings>

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

    void halt();
    void reboot();
    void logout();
    #ifdef Q_OS_WIN32
    bool GetWinToken();
    #endif


    void on_cmdCustom_clicked();

    void on_actionAuthors_triggered();

private:
    QString operation, settingsFile;
    QTimer *timer ;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
