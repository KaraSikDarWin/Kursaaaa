#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "D:/NormKursac/KursacKirill/Headears/mainTree.h"
#include "D:/NormKursac/KursacKirill/Headears/hashtablefile.h"
#include <QApplication>
#include <QFile>
#include <QString>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>
#include <QTableWidget>
#include <QStringDecoder>
#include <QDate>
#include <QMessageBox>
#include <QTreeView>
#include <QStandardItemModel>
#include <QTextEdit>

HashTable * table = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    deb = new DebugWindow();
    ui->BaseTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);
    connect(ui->FindNodeBtn, SIGNAL(clicked()), this, SLOT(FindBtnBtn()));
    connect(ui->DeleteNodeBtn,SIGNAL(clicked()), this, SLOT(DelBtnBtn()));
    connect(ui->SaveBtnBtn, SIGNAL(clicked()), this, SLOT(SaveBtn()));
    connect(ui->AddNodeBtn,SIGNAL(clicked()),this,SLOT(AddBtnBtn()));
    connect(this,&MainWindow::toDebugSignal, deb,&DebugWindow::startSignal);
}

void MainWindow::startSignal(int hashsize, int filelength)
{
    HashTable* temptable = new HashTable(hashsize);
    swap(table,temptable);
    delete temptable;
    int LoadedItems = table->Create(filelength);
    table->PrintHashTable();
    ui->BaseTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->BaseTable->clearContents();
    ui->BaseTable->setRowCount(0);
    MainWindow::PrintToTable();
    MainWindow::PrintHashTableDebug();
    QMessageBox Warn;
    Warn.setIcon(QMessageBox::Information);
    string inf = "Было добавлено "+ to_string(LoadedItems)+ " из "+ to_string(filelength);
    Warn.setText(QString::fromStdString(inf));
    Warn.exec();
}

void MainWindow::SaveBtn(){
    qDebug()<<"Save";
    QFile fileout("D:/NormKursac/KursacKirill/DataBase.txt");
    if(fileout.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream writestream(&fileout);
        PrintToTableWrite(writestream);
        fileout.close();
    }
}



void MainWindow::AddBtnBtn()
{
    string GosNum = ui->GovNumbLine->text().toStdString();
    string PhoneNum = ui->PhonLine->text().toStdString();
    string Brand = ui->BrendLine->text().toStdString();
    string Model = ui->ModelLine->text().toStdString();
    int day = ui->DateLine->date().day();
    string month = to_string(ui->DateLine->date().month());
    if (month.length()==1){
        month ="0"+month;
    }
    int year = ui->DateLine->date().year();

    int status = CheckCorrectField(GosNum,PhoneNum, Brand, Model);
    if (status ==1){
        if(table->PublicAddHashNode(GosNum,PhoneNum,Brand,Model,day,month,year)){
            ui->BaseTable->clearContents();
            ui->BaseTable->setRowCount(0);
            PrintToTable();
            table->PrintHashTable();
            MainWindow::PrintHashTableDebug();
        }else{
            QMessageBox Warn;
            Warn.setIcon(QMessageBox::Critical);
            Warn.setText("Такая комбинация уже имеется в базе");
            Warn.exec();
        }
    }else ErrorHandler(status);
}

void MainWindow::DelBtnBtn()
{
    string GosNum = ui->GovNumbLine->text().toStdString();
    string PhoneNum = ui->PhonLine->text().toStdString();
    string Brand = ui->BrendLine->text().toStdString();
    string Model = ui->ModelLine->text().toStdString();
    int day = ui->DateLine->date().day();
    string month = to_string(ui->DateLine->date().month());
    if (month.length()==1){
        month ="0"+month;
    }
    int year = ui->DateLine->date().year();
    int status = CheckCorrectField(GosNum,PhoneNum, Brand, Model);

    if(status==1){
        if(table->Delete(GosNum, PhoneNum, Brand, Model, day, month, year)){
            ui->BaseTable->clearContents();
            ui->BaseTable->setRowCount(0);
            PrintToTable();
            table->PrintHashTable();
            MainWindow::PrintHashTableDebug();
        }else{
            QMessageBox Warn;
            Warn.setIcon(QMessageBox::Critical);
            Warn.setText("Элемент не был удален. Не найден.");
            Warn.exec();
        }
    }else ErrorHandler(status);
}

void MainWindow::FindBtnBtn()
{
    string GosNum = ui->GovNumbLine->text().toStdString();
    string PhoneNum = ui->PhonLine->text().toStdString();
    string Brand = ui->BrendLine->text().toStdString();
    string Model = ui->ModelLine->text().toStdString();
    int status = CheckCorrectField(GosNum,PhoneNum, Brand, Model);

    if (status==1){
        string out =table->FindDateHash(GosNum, PhoneNum, Brand, Model);
        if (out.length()!=0){
            out = "Искомая дата: \n"+out;
            QMessageBox answ ;
            answ.setIcon(QMessageBox::Information);
            answ.setText(QString::fromStdString(out));
            answ.exec();
        }else{
            QMessageBox answ;
            answ.setIcon(QMessageBox::Critical);
            answ.setText("Элемент не был найден");
            answ.exec();
        }
    }else ErrorHandler(status);
}

void MainWindow::AddRow(Circle* p){
    ui->BaseTable->insertRow(ui->BaseTable->rowCount());
    int j = ui->BaseTable->rowCount()-1;

    QTableWidgetItem* item_Gos = new QTableWidgetItem(QString::fromStdString(SborAutoNumber(p->Circledata->number)));
    ui->BaseTable->setItem(j, 0, item_Gos);

    QTableWidgetItem* item_Phon = new QTableWidgetItem(QString::fromStdString(SborPhoneNumber(p->Circledata->phoneNumber)));
    ui->BaseTable->setItem(j, 1, item_Phon);

    QTableWidgetItem* item_Brand = new QTableWidgetItem(QString::fromStdString(p->Circledata->brandName.Brand));
    ui->BaseTable->setItem(j, 2, item_Brand);

    QTableWidgetItem* item_Model = new QTableWidgetItem(QString::fromStdString(p->Circledata->brandName.Model));
    ui->BaseTable->setItem(j, 3, item_Model);

    QTableWidgetItem* item_Date = new QTableWidgetItem(QString::fromStdString(SborDate(p->Circledata->date)));
    ui->BaseTable->setItem(j, 4, item_Date);
}


inline void MainWindow::WalkCirle(Circle* head){//напечатать список указатель на который в каждом узле
    if (head!= nullptr) {
        Circle *run = head;
        if (head->next==head){
            MainWindow::AddRow(head);
        }else{
        while (run->next != head) {
            MainWindow::AddRow(run);
            run = run->next;
        }
        MainWindow::AddRow(run);
        }
    }
}

void MainWindow::WalkTree(Node* t){
    if (t!= nullptr){
        MainWindow::WalkTree(t->left);
        MainWindow::WalkTree(t->right);
        MainWindow::WalkCirle(t->data);
    }
}

void MainWindow::PrintToTable(){
    for(int i =0; i<table->IsSize(); i++){
        MainWindow::WalkTree(table->isVector()[i].LinkNode->rootIs());
    }
}

inline void MainWindow::WalkCirleWrite(Circle* head, QTextStream &writestream){//напечатать список указатель на который в каждом узле
    if (head!= nullptr) {
        Circle *run = head;
        if (head->next==head){
            writestream<<QString::fromStdString(StringTo(head->Circledata))+'\n';

        }else{
            while (run->next != head) {
                writestream<<QString::fromStdString(StringTo(run->Circledata))+'\n';
                run = run->next;
            }
            writestream<<QString::fromStdString(StringTo(run->Circledata))+'\n';
        }
    }
}

void MainWindow::WalkTreeWrite(Node* t,QTextStream &writestream){
    if (t!= nullptr){
        MainWindow::WalkTreeWrite(t->left, writestream);
        MainWindow::WalkTreeWrite(t->right, writestream);
        MainWindow::WalkCirleWrite(t->data, writestream);
    }
}

void MainWindow::PrintToTableWrite(QTextStream &writestream){
    for(int i =0; i<table->IsSize(); i++){
        MainWindow::WalkTreeWrite(table->isVector()[i].LinkNode->rootIs(), writestream);
    }
}

void MainWindow::PrintHashTableDebug(){
    ui->DebugTab->clear();
    for (int i = 0; i<table->IsSize();i++){
        ui->DebugTab->append(QString::fromStdString(to_string(i)+":"));
        MainWindow::PrintTrDebug(table->isVector()[i].LinkNode->rootIs(),1);
        ui->DebugTab->append("===================================================");
    }
}

void MainWindow::PrintTrDebug(Node* t, int n){ //Распечатать дерево
    if (t!= nullptr){
        string sub = "";
        PrintTrDebug(t->left,n+10);
        for (int i =1; i<n; i++ ){
            sub+="-";
        }
        sub+= SborPhoneNumber(t->data->Circledata->phoneNumber) + "      ";
        PrintCircleDebug(t->data, sub);
        PrintTrDebug(t->right,n+10);
    }
}

void MainWindow::PrintCircleDebug(Circle* head, string &sub){//напечатать список указатель на который в каждом узле
    if (head!= nullptr) {
        Circle *run = head;
        while (run->next != head) {
            sub += StringForOutput(*run->Circledata);
            sub+= "/";
            run = run->next;
        }

        sub += StringForOutput(*run->Circledata);
        ui->DebugTab->append(QString::fromStdString(sub+"\n"));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
