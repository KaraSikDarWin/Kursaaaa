#pragma once
#include "D:/NormKursac/KursacKirill/mainwindow.h"
#include "Structures.h"
#include <QDebug>
#include <QLine>


inline bool EqvNumbAndMB(Number &Num, BrandName &BM, vector<string> &mas, string Brand, string Model){
    return (Num.FB == stoi(mas[0]) and Num.number == mas[1] and Num.SB==mas[2] and BM.Brand==Brand and BM.Model==Model);
}

inline bool EqDateAndDate(Date &ate , int day, string month, int year){
    return (ate.Day == day and ate.Month==month and ate.Year==year);
}

inline void Add(Circle* &head, Elem* &x){ //Добавление элемента в список который в каждом узле
    Circle* run= head;
    if (head== nullptr){
        head = new Circle(x);
    }else{
        while(run->next!=head){
            run=run->next;
        }
        auto beg =new Circle(x);
        run->next=beg;
        beg->next=head;
        head=beg;
    }
}//

inline void PrintCircle(Circle* head, string &sub){//напечатать список указатель на который в каждом узле
    if (head!= nullptr) {
        Circle *run = head;
        while (run->next != head) {

            //deb << StringForOutput(*run->Circledata);
            sub += StringForOutput(*run->Circledata);
            //deb << "/";
            sub+= "/";
            run = run->next;
        }

        //deb << StringForOutput(*run->Circledata);
        sub += StringForOutput(*run->Circledata);
        qDebug() << sub;


    }
    //else cout<<"List doesn't exist!"<<endl;
}//

inline void DeleteCircleNode(Circle* &head, vector<string> &mas, string Brand, string Model,int day, string month , int year){ //Удалить элемент из списка, указатель которого находится в каждом узле
    Circle* run =head->next;
    Circle* beg =head;
    while (run!=head){
        if(EqDateAndDate(run->Circledata->date, day,month,year) and EqvNumbAndMB(run->Circledata->number, run->Circledata->brandName, mas,Brand,Model)){
            beg->next=run->next;
            delete run;
            run=beg->next;
        }
        beg=beg->next;
        run=run->next;
    }
    if (EqDateAndDate(run->Circledata->date, day,month,year) and EqvNumbAndMB(run->Circledata->number, run->Circledata->brandName, mas,Brand,Model)){
        beg->next=run->next;
        delete run;
        head=beg->next;
    }
}//

inline bool SearchingDate(Circle* head, int day, string month , int year){//Проверка наличия элемента в списке указатель на который находится в каждом узле
    if(head!= nullptr) {
        bool flag = false;
        Circle *run = head;
        while ((run->next != head) and (flag==0)) {
            if (EqDateAndDate(run->Circledata->date, day,month,year)) {
                flag = 1;

            } else run = run->next;
        }
        if (EqDateAndDate(run->Circledata->date, day,month,year)) {
            flag = 1;
        }

        if (flag) {
            return flag;
        } else return flag;
    }
    return 0;
}

inline bool SearchingDateFIND(Circle* &head, vector<string> &mas,string Brand, string Model, string &out){
    if(head!= nullptr) {
        bool flag = false;
        Circle *run = head;
        while ((run->next != head) and (flag==0)) {
            if (EqvNumbAndMB(run->Circledata->number, run->Circledata->brandName, mas,Brand,Model)) {
                flag = 1;
                out = SborDate(run->Circledata->date);
            } else run = run->next;
        }
        if (EqvNumbAndMB(run->Circledata->number, run->Circledata->brandName, mas,Brand,Model)) {
            flag = 1;
            out = SborDate(run->Circledata->date);
        }

        if (flag) {
            return 1;
        } else return 0;
    }
    return 0;
}

inline bool SearchingNumbAndMB(Circle* head, vector<string> &mas, string Brand, string Model) {//Проверка наличия элемента в списке указатель на который находится в каждом узле
    if (head != nullptr) {
        bool flag = false;
        Circle *run = head;
        while ((run->next != head) and (flag == 0)) {
            if (EqvNumbAndMB(run->Circledata->number, run->Circledata->brandName, mas,Brand,Model)) {
                flag = 1;

            } else run = run->next;
        }
        if (EqvNumbAndMB(run->Circledata->number, run->Circledata->brandName, mas,Brand,Model)) {
            flag = 1;
        }

        return flag;

    }
    return 0;
}

inline void DelCircle(Circle* &head){
    Circle* run;
    Circle* beg;
    if (head!= nullptr){
        if (head->next==head){
            delete head;
            head= nullptr;
        }else{
            run=head->next;
            while(run->next!=head){
                beg=run->next;
                delete run;
                run= beg;
            }
            delete run;
            delete head;
            head= nullptr;

        }
    }else cout<<"List doesn't exist!"<<endl;
}
