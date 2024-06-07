#include "startwindow.h"
#include "ui_startwindow.h"
#include <QApplication>
#include <QFile>
#include <QString>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>

void StartWindow::clHashTableInBtn()
{
    int filesize=0;
    qDebug()<<"Go to MainWindow";
    QFile inputFile("D:/Kursac/untitled/KursaCInput.txt");
    if (inputFile.open(QIODevice::ReadOnly)){
        QTextStream in(&inputFile);
        while(!in.atEnd()){
            filesize++;
            in.readLine();
        }
        inputFile.close();
    }
    mainWin->show();
    ui->HashTableInBtn->setEnabled(false);
    emit ToMainSignal(ui->HashTableSizeIn->value(), filesize);
}

StartWindow::StartWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StartWindow)
{

    ui->setupUi(this);
    mainWin = new MainWindow(this);
    connect(ui->HashTableInBtn, SIGNAL(clicked()), this,SLOT(clHashTableInBtn()));
    connect(this,&StartWindow::ToMainSignal,mainWin, &MainWindow::startSignal);
}

StartWindow::~StartWindow()
{
    delete ui;
}
