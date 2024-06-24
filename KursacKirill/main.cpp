#include "mainwindow.h"
#include "startwindow.h"
#include "D:/NormKursac/KursacKirill/Headears/mainTree.h"
#include <QApplication>
#include <QFile>
#include <QString>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartWindow startwin;


    startwin.show();
    return a.exec();
}
