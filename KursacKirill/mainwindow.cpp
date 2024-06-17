#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "D:/NormKursac/KursacKirill/Headears/mainTree.h"
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

class HashTable{
    int size;
    int NonEmptyNodes;
    vector<HashNode> Table;

private:

    int addHashNode(Elem *p){
        int hash = MultHash(p->brandName.Brand,p->brandName.Model,p->number.FB, stoi(p->number.number),p->number.SB);
        if (CheckUnique(p,hash)) {
            Table[hash].LinkNode->AddAVLNode(p);
            NonEmptyNodes++;
            return 1;
        } else {qDebug()<<"Same Element"; return 0; }

    }

    bool CheckUnique(Elem* p, int hash){
        if(!Table[hash].LinkNode->UniqueKeyPublic(int(p->number.FB), p->number.number,p->number.SB, p->brandName.Brand, p->brandName.Model)){
            return false;
        }else return true;
    }

    int MultHash(string Brand, string Model, char FB, int Numb, string SecNum){
        int key = ConvertStringToInt(Brand)+ConvertStringToInt(Model)+ConvertStringToInt(SecNum)+FB+Numb;
        float answ = key * 0.618033;
        answ = answ - int(answ);
        return ::floor(size * answ);
    }

public:


    bool Find(string NUM, string PhoneNumber, string BRAND, string MODEl){
        vector<string> mas;
        SplitNum(NUM,mas);
        SplitPhone(PhoneNumber,mas);
        mas.push_back(BRAND);
        mas.push_back(MODEl);
        int hash = MultHash(BRAND,MODEl,stoi(mas[0]), stoi(mas[1]),mas[2]);
        return Table[hash].LinkNode->IsThisElement(stoi(mas[3]), stoi(mas[4]), mas[5]);

    }

    string FindDateHash(string NUM, string PhoneNumber, string BRAND, string MODEl){
        vector<string> mas;
        SplitNum(NUM,mas);
        SplitPhone(PhoneNumber,mas);
        int hash = MultHash(BRAND,MODEl,stoi(mas[0]), stoi(mas[1]),mas[2]);
        string out =Table[hash].LinkNode->FindDateAVL(mas, BRAND,MODEl);
        if (!out.empty()){
            return out;
        } else return "";
    }

    int PublicAddHashNode(string NUM ,string PhoneNumberIn, string BRAND, string MODEL, int day, string month, int year){
        vector <string> mas;
        SplitNum(NUM,mas);
        SplitPhone(PhoneNumberIn, mas);
        Elem *p = new Elem(stoi(mas[0]), mas[1], mas[2], stoi(mas[4]), mas[5], BRAND, MODEL, day, month, year);
        return addHashNode(p);
    }

    int Delete(string NUM, string PhoneNumberIn, string BRAND, string MODEL, int day, string month, int year){
        vector <string> mas;
        SplitNum(NUM,mas);
        SplitPhone(PhoneNumberIn, mas);
        int hash = MultHash(BRAND,MODEL,stoi(mas[0]), stoi(mas[1]),mas[2]);
        return Table[hash].LinkNode->DeleteNode(mas, BRAND, MODEL,day,month,year);
    }

    void PrintHashTable(){
        for (int i = 0; i<size;i++){
            qDebug()<<to_string(i)+":";
            Table[i].LinkNode->PrintTree();
            qDebug()<<"---------------------------------------------------";
        }
    }

    HashTable(int size):size(size),NonEmptyNodes(0){
        HashNode p(0);
        Table= vector<HashNode> (size, p);
        for (int i=0;i<size;i++){
            Table[i].LinkNode= new AVL();
        }
    }
    HashTable():size(0),NonEmptyNodes(0){}

    void Create(int N, string Name){
        cout<<"Reading data started..."<<endl;
        string b;

        QFile inputFile("D:/NormKursac/KursacKirill/DataBase.txt");
        if (inputFile.open(QIODevice::ReadOnly)){
            QTextStream in(&inputFile);
            for(int i = 0 ; i<N; i++){
                QString line = in.readLine();
                b = line.toStdString();
                Elem* p = new Elem();
                Rasdel(*p,b);
                addHashNode(p);
            }
            inputFile.close();
        }


        cout<<"Reading data finished..."<<endl;
    }

    void ClearTable(){
        Table.clear();
    }

    int IsSize(){
        return size;
    }

    vector<HashNode> isVector(){
        return Table;
    }

    ~HashTable(){
        Table.clear();
    }

};

HashTable * table = nullptr;
int lines =0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->FindNodeBtn, SIGNAL(clicked()), this, SLOT(FindBtnBtn()));
    connect(ui->InitialButton, SIGNAL(clicked()), this, SLOT(Initial()));
    connect(ui->DeleteNodeBtn,SIGNAL(clicked()), this, SLOT(DelBtnBtn()));
    connect(ui->SaveBtnBtn, SIGNAL(clicked()), this, SLOT(SaveBtn()));
    connect(ui->AddNodeBtn,SIGNAL(clicked()),this,SLOT(AddBtnBtn()));
   // connect(this,&MainWindow::startSignal, startWin,&StartWindow::SecondSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::startSignal(int string, int filelength)
{
    HashTable* temptable = new HashTable(10);
    swap(table,temptable);
    delete temptable;
    ui->InitialSpin->setMaximum(filelength);
}

void MainWindow::Initial()
{
    ui->InitialButton->setEnabled(false);
    ui->InitialSpin->setEnabled(false);
    int countOfline = ui->InitialSpin->value();

    table->Create(countOfline,"dadad");
    table->PrintHashTable();
    ui->BaseTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->BaseTable->clearContents();
    ui->BaseTable->setRowCount(0);
    MainWindow::PrintToTable();
}

void MainWindow::SaveBtn(){
    qDebug()<<"Save";
    QFile fileout("D:/NormKursac/KursacKirill/DataBase.txt");
    if(fileout.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream writestream(&fileout);
        PrintToTableWrite(writestream);
    }
    fileout.close();
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
