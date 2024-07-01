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
    QFile inputFile("D:/NormKursac/KursacKirill/DataBase.txt");
    if (inputFile.open(QIODevice::ReadOnly)){
        QTextStream in(&inputFile);
        while(!in.atEnd()){
            filesize++;
            in.readLine();
        }
        inputFile.close();
        mainWin->setFixedSize(QSize(907,500));
        mainWin->show();
        this->close();
        ui->HashTableInBtn->setEnabled(false);
        emit ToMainSignal(ui->HashTableSizeIn->value(), filesize);
    }else {
        QMessageBox Alarm;
        Alarm.setIcon(QMessageBox::Critical);
        Alarm.setText("Не найден файл для считывания DataBase.txt");
        Alarm.exec();
    }

}

StartWindow::StartWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StartWindow)
{

    ui->setupUi(this);
    this->setFixedSize(QSize(231,187));
    mainWin = new MainWindow();
    connect(ui->HashTableInBtn, SIGNAL(clicked()), this,SLOT(clHashTableInBtn()));
    connect(this,&StartWindow::ToMainSignal,mainWin, &MainWindow::startSignal);
}

StartWindow::~StartWindow()
{
    delete ui;
}
