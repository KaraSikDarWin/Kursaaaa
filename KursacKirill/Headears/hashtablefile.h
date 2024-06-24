#pragma once
#include "mainTree.h"
#include "SupportFunctions.h"
#include "QFile"
#include "QIODevice"

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
