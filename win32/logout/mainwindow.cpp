#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>
#include <QDir>
#include <QSettings>
#include <QProcess>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //this->setWindowFlags( Qt::CustomizeWindowHint );

    //Grab Current date and time
    ui->dateTimeEdit->setDate(QDate::currentDate());
    ui->dateTimeEdit->setTime(QTime::currentTime());

    //Folder for settings (.ini file)
    QString settingsHome=QDir::homePath()+"/.config/logout" ;
    if (!QDir(settingsHome).exists()) QDir().mkdir(settingsHome);

    //Settings file (.ini)
    settingsFile=settingsHome+"/settings.ini";
    if (!QFile(settingsFile).exists())
    {
        QSettings settings(settingsFile, QSettings::NativeFormat);
        settings.setValue("haltCommand","sudo halt");
        settings.setValue("rebootCommand","sudo reboot");
        settings.setValue("logoutCommand","killall X");
        settings.setValue("customCommand","ls");
    }

    //Load custom command in lineedit txtCustom
    QSettings settings(settingsFile, QSettings::NativeFormat);
    QString customCommand = settings.value("customCommand").toString();
    ui->txtCustom->setText(customCommand);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_cmdCancel_clicked()
{
    qApp->quit();
}

void MainWindow::disableGui()
{
    ui->cmdHalt->setEnabled(false);
    ui->cmdReboot->setEnabled(false);
    ui->cmdCloseX->setEnabled(false);
    ui->txtCustom->setEnabled(false);
    ui->cmdCustom->setEnabled(false);
}

void MainWindow::on_cmdHalt_clicked()
{
    disableGui();
    if (ui->checkDateTime->isChecked())
    {
        operation="halt";
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(checkMyDate()));
        timer->start(500);
    }else{
        this->halt();
    }
}

void MainWindow::on_cmdReboot_clicked()
{
    disableGui();
    if (ui->checkDateTime->isChecked())
    {
        operation="reboot";
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(checkMyDate()));
        timer->start(500);
    }else{
        this->reboot();
    }
}

void MainWindow::checkMyDate()
{
    //qDebug() << "Timer eseguito";
    QDate nowDate= QDate::currentDate();
    QTime nowTime= QTime::currentTime();


    if ( nowDate.daysTo(ui->dateTimeEdit->date())==0 && nowTime.msecsTo(ui->dateTimeEdit->time())<=1000 )
    {
        qDebug() << "Data e ora coincidono";
        if (operation=="logout") this->logout();
        if (operation=="halt") this->halt();
        if (operation=="reboot") this->reboot();
        if (operation=="custom") QProcess::execute (ui->txtCustom->text());
        timer->stop();
    }
}

void MainWindow::on_cmdCloseX_clicked()
{
    disableGui();
    if (ui->checkDateTime->isChecked())
    {
        operation="logout";
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(checkMyDate()));
        timer->start(500);
    }else{
        this->logout();
    }
}



void MainWindow::on_checkDateTime_stateChanged()
{
    if (ui->checkDateTime->isChecked())
    {
        ui->dateTimeEdit->setEnabled(true);
    }else{
        ui->dateTimeEdit->setEnabled(false);
    }

}

#ifdef Q_OS_WIN32
bool MainWindow::GetWinToken()
{

    HANDLE hToken;
    TOKEN_PRIVILEGES tkp;

   // Prende un token per i concedere i privilegi a questo processo
    if (!OpenProcessToken(GetCurrentProcess(),TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
    {
      wprintf(L"Qualcosa e' andato storto ...\n");
      return( FALSE );
    }
   // Prende il LogonID (LUID)
   LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid);

   //Quanti e che tipo di privilegi servono
   tkp.PrivilegeCount = 1;
   tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

   // Get the shutdown privilege for this process.

   AdjustTokenPrivileges(hToken, FALSE, &tkp, 0,
        (PTOKEN_PRIVILEGES)NULL, 0);


   //Verifica se alla fine della richiesta dei privilegi ci siano stati problemi
   if (GetLastError() != ERROR_SUCCESS)
   {
      wprintf(L"Qualcosa e' andato storto ...\n");
      return FALSE;
    }

}
#endif

//Q_OS_SYMBIAN, Q_OS_UNIX, Q_OS_SOLARIS, Q_OS_LINUX, Q_OS_FREEBSD, Q_OS_MAC etc etc.
void MainWindow::halt()
{
    #ifdef Q_OS_LINUX
    QSettings settings(settingsFile, QSettings::NativeFormat);
    QString haltCommand = settings.value("haltCommand").toString();

    if (haltCommand=="")
    {
        QProcess::execute ("sudo halt");
    }else{
        QProcess::execute (haltCommand);
    }

    #endif

    #ifdef Q_OS_WIN32
    //Richiedo i privilegi necessari
    this->GetWinToken();

    if (!ExitWindowsEx(EWX_POWEROFF, 0) )
    {
        QMessageBox::critical(0, qApp->tr("Warning"),
                    qApp->tr("It was not possible to turn off the computer.\n"), QMessageBox::Ok);

    }else{
        wprintf(L"spegnimento in corso...\n");
    }
    #endif
}

void MainWindow::reboot()
{
    #ifdef Q_OS_LINUX
    QSettings settings(settingsFile, QSettings::NativeFormat);
    QString rebootCommand = settings.value("rebootCommand").toString();

    if (rebootCommand=="")
    {
        QProcess::execute ("sudo reboot");
    }else{
        QProcess::execute (rebootCommand);
    }
    #endif

    #ifdef Q_OS_WIN32
    //Richiedo i privilegi necessari
   this->GetWinToken();

    // ExitWindowsEx() fa il lavoro sporco. Puo' spegnere o riavviare il sistema
    // in base ai vari flag che gli siano dati come parametro.
    if (!ExitWindowsEx(EWX_REBOOT, 0) )
    {
        QMessageBox::critical(0, qApp->tr("Warning"),
                    qApp->tr("It was not possible to reboot the computer.\n"), QMessageBox::Ok);
    }else{
        wprintf(L"spegnimento in corso...\n");
    }
    #endif

}

void MainWindow::logout()
{
    #ifdef Q_OS_LINUX
    QSettings settings(settingsFile, QSettings::NativeFormat);
    QString logoutCommand = settings.value("logoutCommand").toString();

    if (logoutCommand=="")
    {
        QProcess::execute ("killall X");
    }else{
        QProcess::execute (logoutCommand);
    }
    #endif

    #ifdef Q_OS_WIN32
    //Richiedo i privilegi necessari
   this->GetWinToken();

    if (!ExitWindowsEx(EWX_LOGOFF, 0) )
    {
        QMessageBox::critical(0, qApp->tr("Warning"),
                    qApp->tr("It was not possible to logout.\n"), QMessageBox::Ok);

    }else{
        wprintf(L"Logout in corso...\n");
    }
    #endif

}

void MainWindow::on_cmdCustom_clicked()
{

    QSettings settings(settingsFile, QSettings::NativeFormat);
    settings.setValue("customCommand",ui->txtCustom->text());

    if (ui->checkDateTime->isChecked())
    {
        disableGui();
        operation="custom";
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(checkMyDate()));
        timer->start(500);
    }else{
        QProcess::execute (ui->txtCustom->text());
    }
}



void MainWindow::on_actionAuthors_triggered()
{
    QMessageBox::information(0, qApp->tr("Authors"),
                qApp->tr("Fabio Di Matteo - (fadimatteo@gmail.com) \n www.freemedialab.org \n\n released under GNU/GPL v3"), QMessageBox::Ok);
}
