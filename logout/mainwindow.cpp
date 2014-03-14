#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>
#include <QDir>
#include <QSettings>
#include <QProcess>
#include <QMessageBox>
#include <QFileDialog>
#include <QFileInfo>
#include <QStringList>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Show first tab
    ui->tabWidget->setCurrentIndex(0);

    //Grab Current date and time
    ui->dateTimeEdit->setDate(QDate::currentDate());
    ui->dateTimeEdit->setTime(QTime::currentTime());
#ifdef Q_OS_LINUX
    //Folder for settings (.ini file)
    QString settingsHome=QDir::homePath()+"/.config/logout" ;
    if (!QDir(settingsHome).exists()) QDir().mkdir(settingsHome);

    //Settings file (.ini)
    settingsFile=settingsHome+"/settings.ini";
#endif
#ifdef Q_OS_WIN32
    //Folder for settings (.ini file)
    QString settingsHome=QDir::homePath()+"/logout" ;
    if (!QDir(settingsHome).exists()) QDir().mkdir(settingsHome);

    //Settings file (.ini)
    settingsFile=settingsHome+"/settings.ini";
#endif



    if (!QFile(settingsFile).exists())
    {
        QSettings settings(settingsFile, QSettings::IniFormat);
        settings.setValue("haltCommand","sudo halt");
        settings.setValue("rebootCommand","sudo reboot");
        settings.setValue("logoutCommand","killall X");
        settings.setValue("customCommand","ls");
        settings.setValue("suffixDownloads",".part");
        settings.setValue("downloadsFolder","");
        settings.setValue("downloadFile","");

    }

    //Load custom command in lineedit txtCustom
    QSettings settings(settingsFile, QSettings::IniFormat);
    ui->txtCustom->setText(settings.value("customCommand").toString());

    //Load Downloads preferences
    ui->txtDownloadSuffix->setText(settings.value("suffixDownloads").toString());
    ui->txtDownloasFolder->setText(settings.value("downloadsFolder").toString());
    ui->txtAfterDownloadFile->setText(settings.value("downloadFile").toString());

    //Load Everyday preferences
    if (settings.value("everyDayMode").toString()=="on") ui->checkBoxEnableEveryday->setChecked(true);


    #ifdef Q_OS_WIN32
    QTime Time= settings.value("everyDayTime").toTime();  //Load preference for timeEditEveryDay
    ui->timeEditEveryDay->setTime(Time);
    #endif

    #ifdef Q_OS_LINUX
    QString Time= settings.value("everyDayTime").toString();  //Load preference for timeEditEveryDay
    QStringList query = Time.split(":");
    int h=query[0].toInt();
    int m=query[1].toInt();

    QTime FilterTime;
    FilterTime.setHMS(h,m,0);
    ui->timeEditEveryDay->setTime(FilterTime);
    #endif

    QString tmpcmd= settings.value("everyDayCmd").toString();
    if (tmpcmd=="halt") ui->cmbEverydayCmd->setCurrentIndex(0);
    if (tmpcmd=="reboot") ui->cmbEverydayCmd->setCurrentIndex(1);
    if (tmpcmd=="custom") ui->cmbEverydayCmd->setCurrentIndex(2);

    if (settings.value("everyDayRunMinimized").toString()=="true") ui->checkBoxEverydayRunMinimized->setChecked(true);




    //System tray
    trayIcon = new QSystemTrayIcon(QIcon(":/icons/logout.png"));
    trayIcon->show();
    connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,
                SLOT(toggleMainWindow()));



    //Enable/disable everyDayMode
    CheckIfEverydayMode();
    on_checkBoxEnableEveryday_stateChanged();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::toggleMainWindow()
{
    if (this->isVisible())
    {  this->hide();
        trayIcon->showMessage ( tr("Information"), tr("I stay minimized here"));
    }else this->show();
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
    ui->tabDownloads->setEnabled(false);
    //toggleMainWindow();
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
    QSettings settings(settingsFile, QSettings::IniFormat);
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
        QMessageBox::critical(0, tr("Warning"),
                              tr("It was not possible to turn off the computer.\n"), QMessageBox::Ok);

    }else{
        wprintf(L"spegnimento in corso...\n");
    }
    #endif
}

void MainWindow::reboot()
{
    #ifdef Q_OS_LINUX
    QSettings settings(settingsFile, QSettings::IniFormat);
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
        QMessageBox::critical(0, tr("Warning"),
                    tr("It was not possible to reboot the computer.\n"), QMessageBox::Ok);
    }else{
        wprintf(L"spegnimento in corso...\n");
    }
    #endif

}

void MainWindow::logout()
{
    #ifdef Q_OS_LINUX
    QSettings settings(settingsFile, QSettings::IniFormat);
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
        QMessageBox::critical(0, tr("Warning"),
                    tr("It was not possible to logout.\n"), QMessageBox::Ok);

    }else{
        wprintf(L"Logout in corso...\n");
    }
    #endif

}

void MainWindow::on_cmdCustom_clicked()
{

    QSettings settings(settingsFile, QSettings::IniFormat);
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
    QMessageBox::information(0, tr("Authors"),
                tr("Fabio Di Matteo - (fadimatteo@gmail.com) \n www.freemedialab.org \n\n released under GNU/GPL v3"), QMessageBox::Ok);
}

void MainWindow::on_cmdHaltAfterAllDownloads_clicked()
{
    QSettings settings(settingsFile, QSettings::IniFormat);
    settings.setValue("suffixDownloads",ui->txtDownloadSuffix->text());
    settings.setValue("downloadsFolder",ui->txtDownloasFolder->text());

    if (checkIfDirOk())
    {
        timerDownload = new QTimer(this);
        connect(timerDownload, SIGNAL(timeout()), this, SLOT(checkAllDownloadsEnds()));
        timerDownload->start(5000);
        disableGui();
    }else{
        QMessageBox::information(0, tr("Warning"),
                    tr("In this folder there are no active downloads "), QMessageBox::Ok);
    }
    ui->lblDownloadsStatus->setText(tr("Waiting..."));
}

void MainWindow::checkAllDownloadsEnds()
{

   bool allEnds=true;

   listFilesDownloads.clear();
   this->scanDirs(ui->txtDownloasFolder->text());
   if (listFilesDownloads.size()>0)
   {
       allEnds=false;
       //qDebug()<< "Waiting for " <<listFilesDownloads.size() << " downloads";
       ui->lblDownloadsStatus->setText(tr("Waiting for ")+QString::number(listFilesDownloads.size())+tr(" downloads."));

   }

   if (allEnds==true)
   {
       //qDebug() << "All downloads are done.";
       ui->lblDownloadsStatus->setText(tr("All downloads are done."));
       timerDownload->stop();
       this->halt();
   }


}

void MainWindow::scanDirs(QString folder)
{
    QDir dir(folder);
    if (dir.exists())
    {
        foreach(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Files | QDir::AllDirs ))
        {

            if (info.isFile())
            {

                //Do something with file
                if ("."+info.suffix()==ui->txtDownloadSuffix->text())
                {
                    listFilesDownloads.append(info);
                    //qDebug() << info.fileName();
                }
            }
            if (info.isDir())
            {
                //Do something with folders
                this->scanDirs(info.absoluteFilePath());

            }
        }
    }
}

void MainWindow::on_cmdDownloadFolder_clicked()
{
  ui->txtDownloasFolder->setText(QFileDialog::getExistingDirectory(this, tr("Open Directory"),"", QFileDialog::ShowDirsOnly
                                                   | QFileDialog::DontResolveSymlinks));
}

void MainWindow::on_cmdAfterDownloadFile_clicked()
{
    ui->txtAfterDownloadFile->setText(QFileDialog::getOpenFileName(this, tr("Open File"),  "",  tr("Files (*.*)")));


}

void MainWindow::on_cmdHaltAfterSingleDownload_clicked()
{
    QSettings settings(settingsFile, QSettings::IniFormat);
    settings.setValue("downloadFile",ui->txtAfterDownloadFile->text());

    timerDownload = new QTimer(this);
    connect(timerDownload, SIGNAL(timeout()), this, SLOT( checkSingleDownloadEnd()));
    timerDownload->start(5000);
    disableGui();
    ui->lblDownloadsStatus->setText(tr("Shutdown after ")+ui->txtAfterDownloadFile->text());

}

void MainWindow::checkSingleDownloadEnd()
{

    //You have to check if filename without .suffix exists
    QFileInfo file(ui->txtAfterDownloadFile->text());
    QString baseName = file.completeBaseName();
    QString path= file.absoluteDir().filePath(baseName);

    QFile f(path);
    QFile fpart(ui->txtAfterDownloadFile->text());

    if (f.exists() && !fpart.exists() )
    {
        this->halt() ;
        qDebug() << "Download END :" << path;
        ui->lblDownloadsStatus->setText(tr("Download done."));
    }

    ui->lblDownloadsStatus->setText(tr("Shutdown after ")+file.fileName());

}


bool MainWindow::checkIfDirOk()
{
    bool ret=false;
    /*QDir dir (ui->txtDownloasFolder->text());
    if (QDir(dir).exists())
    {
       QStringList filters ("*"+ui->txtDownloadSuffix->text());
       QFileInfoList list = dir.entryInfoList (filters);
       if (list.size()>0) ret=true;
    }*/
    scanDirs(ui->txtDownloasFolder->text());
    if (listFilesDownloads.size()>0)ret=true;
    listFilesDownloads.clear();
    return ret;
}


bool MainWindow::checkIfTaskisInThePast()
{
    QTime nowTime= QTime::currentTime();

    if ( nowTime.msecsTo(ui->timeEditEveryDay->time()) < 0 )
    {
        timerEveryday->stop();
        ui->cmdEverydayDone->setEnabled(true);
        ui->cmdEverydayStop->setEnabled(false);
        return true;
    }else{ return false; }
}


void MainWindow::on_cmdEverydayDone_clicked()
{

    LastWarningEveryday=true;

    //Write configuration file
    QSettings settings(settingsFile, QSettings::IniFormat);
    if (ui->checkBoxEnableEveryday->isChecked())
    {
        settings.setValue("everyDayMode","on");
        settings.setValue("everyDayTime",ui->timeEditEveryDay->text());
        if (ui->cmbEverydayCmd->currentIndex()==0) settings.setValue("everyDayCmd","halt");
        if (ui->cmbEverydayCmd->currentIndex()==1) settings.setValue("everyDayCmd","reboot");
        if (ui->cmbEverydayCmd->currentIndex()==2) settings.setValue("everyDayCmd","custom");
        if (ui->checkBoxEverydayRunMinimized->isChecked()) { settings.setValue("everyDayRunMinimized","true");}else{ settings.setValue("everyDayRunMinimized","false");}
        CheckIfEverydayMode();
        if (checkIfTaskisInThePast()==true)
        {
            trayIcon->showMessage ( tr("Warning"), tr("Task is in the past."));
        }else{
            if (!ui->checkBoxEverydayRunMinimized->isChecked())
            { QMessageBox::information(0, tr("Information"), tr("Activities planned"), QMessageBox::Ok);
            }else{ trayIcon->showMessage ( tr("Warning"), tr("Activities planned"));}
        }




        //Autostart in Linux Desktop
        #ifdef Q_OS_LINUX
        if (QDir(QDir::homePath()+"/.config/autostart").exists())
        {
            if (QFile::exists("/usr/share/applications/logout.desktop"))
            {
               QFile::copy("/usr/share/applications/logout.desktop", QDir::homePath()+"/.config/autostart/logout-fml.desktop");
            }

        }
        #endif

        //Autostart in Win32 Desktop
        #ifdef Q_OS_WIN32
        QSettings registry("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
        registry.setValue("Logout-fml", QCoreApplication::applicationFilePath().replace('/','\\'));
        #endif

    }else{
        settings.setValue("everyDayMode","off");
        timerEveryday->stop();

        //Remove autostart in Linux Desktop
        #ifdef Q_OS_LINUX
        //Remove .desktop file in autostart dir
        if (QDir(QDir::homePath()+"/.config/autostart/logout.desktop").exists())
        {
            QFile::remove(QDir::homePath()+"/.config/autostart/logout.desktop");
        }
        #endif

        //Remove Autostart in Win32 desktop
        #ifdef Q_OS_WIN32
        QSettings registry("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
        registry.remove("Logout-fml");
        #endif

        QSettings settings(settingsFile, QSettings::IniFormat);
        if (settings.value("everyDayMode").toString()=="off")
                    QMessageBox::information(0, tr("Information"), tr("The task is not run automatically"), QMessageBox::Ok);





    }

}

void MainWindow::CheckIfEverydayMode()
{
    QSettings settings(settingsFile, QSettings::IniFormat);
    //enable timer for everyday tasks
    timerEveryday = new QTimer(this);
    connect(timerEveryday, SIGNAL(timeout()), this, SLOT(CheckEverydayTime()));


    if (settings.value("everyDayMode").toString()=="on")
    {
        qDebug() << "Every day mode: ON";
        if (settings.value("everyDayRunMinimized").toString()=="false") { this->show();}else this->hide();

        if (!checkIfTaskisInThePast())
        {
            ui->cmdEverydayDone->setEnabled(false);
            ui->cmdEverydayStop->setEnabled(true);
            timerEveryday->start(1000);
        }else{
            timerEveryday->stop();
            ui->cmdEverydayDone->setEnabled(true);
            ui->cmdEverydayStop->setEnabled(false);
        }

    }else{
        this->show();
        timerEveryday->stop();
        ui->cmdEverydayDone->setEnabled(true);
        ui->cmdEverydayStop->setEnabled(false);
    }

}


void MainWindow::CheckEverydayTime()
{
    QTime nowTime= QTime::currentTime();
    QSettings settings(settingsFile, QSettings::IniFormat);
    QString operation=settings.value("everyDayCmd").toString();

    //Last warning - (300000 millisec/ 5 minutes)
    if ( nowTime.msecsTo(ui->timeEditEveryDay->time())<=180000 && LastWarningEveryday==true )
    {

        CancelOperation=tr("If you do not want to click here and click cancels");
        if (operation=="logout") WarningOperation=tr("Soon the computer will logout. Do you want that to happen?") ;
        if (operation=="halt")  WarningOperation=tr("Soon the computer will shut down. Do you want that to happen?") ;
        if (operation=="reboot")  WarningOperation=tr("Soon the computer will reboot. Do you want that to happen?") ;
        if (operation=="custom")  WarningOperation=tr("Soon the computer will execute a task. Do you want that to happen?") ;

        trayIcon->showMessage ( tr("Information"), WarningOperation+CancelOperation,QSystemTrayIcon::Warning);
        LastWarningEveryday=false;

        QTimer::singleShot(1, this, SLOT(LastWarningMsgbox()));
    }


    //Finally perform the task
    if ( nowTime.msecsTo(ui->timeEditEveryDay->time())<=1000 )
    {
        qDebug() << "It is time to... ";
        if (operation=="logout") this->logout();
        if (operation=="halt") this->halt();
        if (operation=="reboot") this->reboot();
        if (operation=="custom") QProcess::execute (ui->txtCustom->text());
        timerEveryday->stop();
        ui->cmdEverydayDone->setEnabled(true);
        ui->cmdEverydayStop->setEnabled(false);
    }

}

void MainWindow::LastWarningMsgbox()
{
    this->show();

    /* I wont to be don't blocking*/
    QMessageBox msgBox;
    msgBox.setWindowTitle(tr("Warning"));
    msgBox.setText(WarningOperation);
    msgBox.setIcon ( QMessageBox::Warning );
    msgBox.setStandardButtons(QMessageBox::Yes| QMessageBox::No);
    msgBox.setButtonText(QMessageBox::Yes, tr("Yes"));
    msgBox.setButtonText(QMessageBox::No, tr("No"));
    msgBox.setModal( false );
    msgBox.setWindowModality(Qt::NonModal);

    if(msgBox.exec() == QMessageBox::No)
    {
      timerEveryday->stop();
      ui->cmdEverydayDone->setEnabled(true);
      ui->cmdEverydayStop->setEnabled(false);
    }

    this->hide();
}

void MainWindow::on_cmdEverydayStop_clicked()
{
    timerEveryday->stop();
    ui->cmdEverydayDone->setEnabled(true);
    ui->cmdEverydayStop->setEnabled(false);
    trayIcon->showMessage ( tr("Information"), tr("All scheduled tasks from this tab have been canceled."),QSystemTrayIcon::Warning);

}

void MainWindow::on_checkBoxEnableEveryday_stateChanged()
{
    if (ui->checkBoxEnableEveryday->isChecked())
    {
        ui->timeEditEveryDay->setEnabled(true);
        ui->cmbEverydayCmd->setEnabled(true);
        ui->checkBoxEverydayRunMinimized->setEnabled(true);
    }else{
        ui->timeEditEveryDay->setEnabled(false);
        ui->cmbEverydayCmd->setEnabled(false);
        ui->checkBoxEverydayRunMinimized->setEnabled(false);
    }
}
