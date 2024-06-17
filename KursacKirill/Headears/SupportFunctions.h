#ifndef C___SUPPORTFUNCTIONS_H
#include <iostream>
#include "Structures.h"
#include <vector>
#include <fstream>
#include <set>
#include <cctype>
#include <QMessageBox>

using namespace std;
#define C___SUPPORTFUNCTIONS_H
inline void Rasdel(Elem &p, string str){
    int i;
    string sub;
    p.number.FB=char(str[0]);
    string s= str.substr(1,3);
    p.number.number=s;
    s= str.substr(4,2);
    p.number.SB=s;

    sub = str[7];
    p.phoneNumber.CodeOfCountry= stoi(sub);
    sub = str.substr(8,3);
    p.phoneNumber.CodeOfRegion= stoi(sub);
    sub = str.substr(11,7);
    p.phoneNumber.Numbers=sub;

    i=19;
    sub="";
    while (str[i]!=','){
        sub+=str[i];
        i++;
    }

    p.brandName.Brand=sub;
    i+=1;
    sub ="";
    while (str[i]!=';'){
        sub+=str[i];
        i++;
    }
    p.brandName.Model=sub;

    i++;
    sub = str.substr(i,2);
    p.date.Day= stoi(sub);
    i+=3;
    sub= str.substr(i,2);
    p.date.Month=sub;
    i+=3;
    sub=str.substr(i,4);
    p.date.Year=stoi(sub);
}

inline void Read(vector<Elem>&mas, int N){
    cout<<"Reading data started..."<<endl;
    ifstream fin("KursaCInput.txt");
    string b;

    for (int i=0; i<N;i++){
        getline(fin,b);
        Elem p;
        mas.push_back(p);
        Rasdel(mas[i],b);

        mas[i].NumberOfString=i+1;
    }
    cout<<"Reading data finished..."<<endl;
}

inline int ConvertStringToInt(string str) {
    int ln = str.length();
    int sum = 0;
    for (int i = 0; i < ln; i++) {
        sum += str[i];
    }
    return sum;
};

inline void SplitNum(string str, vector<string> &mas){
    mas.push_back(to_string(str[0]));
    string s= str.substr(1,3);
    mas.push_back(s);
    s = str.substr(4,2);
    mas.push_back(s);
}

inline void SplitPhone(string PhoneNum,vector<string> &mas){
    string sub;
    mas.push_back(PhoneNum.substr(0,1));
    mas.push_back(PhoneNum.substr(1,3));
    mas.push_back(PhoneNum.substr(4,11));
}

inline void SplitBM(string str, vector<string> &mas){
    int i =0;
    string sub="";

    while (str[i]!=' '){
        sub+=str[i];
        i++;
    }

    mas.push_back(sub);
    sub="";

    while (str[i]==' '){
        i++;
    }

    for(;i<str.length();i++){
        sub+=str[i];
    }
    mas.push_back(sub);
}

inline string SborAutoNumber(Number &number){
    string out;
    out = number.FB+ number.number +number.SB;
    return out;
}

inline string SborPhoneNumber(PhoneNumber &phoneNumber){
    string out;
    out = "8"+ to_string(phoneNumber.CodeOfRegion)+phoneNumber.Numbers;
    return out;
}

inline string SborBrandModel(BrandName &brandName){
    string out;
    out = brandName.Brand +','+ brandName.Model;
    return out;
}

inline string SborDate(Date &date){
    string out;
    out = to_string(date.Day)+"."+date.Month+"."+to_string(date.Year);
    return out;
}

inline string StringForOutput(Elem &linknode){
    string out;
    out+= SborAutoNumber(linknode.number)+" "+ SborPhoneNumber(linknode.phoneNumber)+" "+ SborBrandModel(linknode.brandName)+" "+SborDate(linknode.date);
    return out;
}

inline bool IsCorrectGovNum(string input){
    set<char> symbol {'A','B','E','K','M','N','O','P','C','T','Y','X'};
    set<char> numbers {'1','0','2','3','4','5','6','7','8','9'};
    if (input.length()==6){
        if(symbol.count(input[0])){
            string sub = input.substr(1, 3);
            if (sub=="000"){
                return false;
            }else{
                for (int i =0; i<3;i++){
                    if (!(numbers.count(sub[i]))){
                        return false;
                    }
                }
            }
            sub = input.substr(4,2);
            for (int i =0; i<2;i++){
                if (!(symbol.count(sub[i]))){
                    return false;
                }
            }
            return true;
        }else return false;
    }else return false;
}

inline bool IsCorrectNumber(string input){
    set<char> numbers {'1','0','2','3','4','5','6','7','8','9'};
    if (input.length()==11){
        if(input[0]=='8' and input[1]=='9'){
            string sub = input.substr(2,2);
            for (int i =0; i<2;i++){
                if (!(numbers.count(sub[i]))){
                    return false;
                }
            }
            sub = input.substr(4,7);
            for (int i =0; i<7;i++){
                if (!(numbers.count(sub[i]))){
                    return false;
                }
            }
            return true;
        }else return false;
    }else return false;
}

inline bool IsCorrectBrand(string input){
    if (input.length()!=0){
        for (int i = 0; i<input.length(); i++){
            if (!(isalpha(input[i]))){
                return false;
            }
        }
        return true;
    }else return false;
}

inline bool IsCorrectModel(string input){
    set<char> numbers {'1','0','2','3','4','5','6','7','8','9'};
    if (input.length()!=0){
        for (int i = 0; i<input.length(); i++){
            if (!(isalpha(input[i]) or numbers.count(input[i]) or input[i]==' ')){
                return false;
            }
        }
        return true;
    }return false;
}

inline int CheckCorrectField(string GosNum, string Numb, string Brand, string Model){
    if (!IsCorrectGovNum(GosNum)){
        return -1;
    }else if (!IsCorrectNumber(Numb)){
        return -2;
    }else if (!IsCorrectBrand(Brand)){
        return -3;
    }else if(!IsCorrectModel(Model)){
        return -4;
    }else return 1;
}

inline void ErrorHandler(int status){
    QMessageBox Warn;
    Warn.setIcon(QMessageBox::Critical);
switch (status){
    case -1:Warn.setText("Неправильный формат гос. номера");break;
    case -2:Warn.setText("Неправильный формат номера телефона");break;
    case -3:Warn.setText("Неправильный формат марки");break;
    case -4:Warn.setText("Неправильный формат модели");break;
}
    Warn.exec();
}

inline string StringTo(Elem* p){
    string GovNum = SborAutoNumber(p->number);
    string Phone = SborPhoneNumber(p->phoneNumber);
    string BrandModel = SborBrandModel(p->brandName);
    string date = SborDate(p->date);
    return GovNum+";"+Phone+";"+BrandModel+";"+date+";";
}

#endif //C___SUPPORTFUNCTIONS_H
