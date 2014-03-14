#include "mainwindow.h"
#include <QApplication>
#include <QTranslator> //per la traduzione
#include <QLocale>     //per la traduzione
#include <QDebug>      // per scrivere sullo stdo


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //Prelevo la "locale" (ex: it_IT)
    QString locale = QLocale::system().name();
    qDebug() << "Locale:" << locale;


    //Carico la traduzione in base alla locale
    QTranslator* translator = new QTranslator();

    //Si deve caricare il file della traduzione italiana 'logout-it_it.qm'
    // che si trova nella cartella dell'eseguibile. L'estenzione del file .qm si omette
    if (translator->load("logout-"+locale, a.applicationDirPath()+"/../share/logout/" )) {
        a.installTranslator(translator);
    }else{
        qDebug()<< "No traslations.";
    }


    MainWindow w;
    //w.show();



    return a.exec();
}
