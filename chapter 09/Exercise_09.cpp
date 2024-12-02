#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

string intToStr(int x){
    string s = "";
    do{
        char c = '0'+x%10;
        x/=10;
        s=c+s;
    }while(x);
    return s;
}

class date{
    int year;
    int month;
    int day;
    bool checkDayAndMonth(int d, int m){
        if(m < 1 || m > 12 || day < 1 || day > 31) return false;
        if(m==4 || m==6 || m==9 || m==11){
            if(d > 30) return false;
        }
        if(m==2 && d > 29) return false;
        return true;
    }
    bool checkLeapYear(int d, int m, int y){
        if(m != 2) return true;
        if(y%4!=0 && d==29) return false;
        return true;
    }
    bool checkYear(int &y){
        if(y < 0 || y >= 10000) return false;
        if(y >= 100) return true;
        y = 2000+y;
        return true;
    }
    bool parseDate(string s){
        int d = 0;
        int m = 0;
        int y = 0;
        int slash = 0;
        bool valid = true;
        for(int i = 0; i < s.size(); i++){
            if(s[i]=='/'){
                slash++;
                if(slash > 2){
                    valid = false;
                    break;
                }
                continue;
            }
            if(s[i] < '0' || s[i] > '9' || d >= 100 || m >= 100 || y >= 10000){
                valid = false;
                break;
            }
            if(slash==0){
                m=m*10+(s[i]-'0');
            }
            if(slash==1){
                d=d*10+(s[i]-'0');
            }
            if(slash==2){
                y=y*10+(s[i]-'0');
            }
        }
        if(valid && checkDayAndMonth(d,m) && checkLeapYear(d,m,y) && checkYear(y)){
            day = d;
            month = m;
            year = y;
        }
        else{
            valid = false;
        }
        return valid;
    }
public:
    date(){
       day=1;
       month=1;
       year=1900;
    }
    ///Pass the date as a string in the format mm/dd/yyyy or mm/dd/yy
    void setDate(string s){
        if(!parseDate(s)) throw runtime_error(s+ " is invalid date");
    }
    ///shows the date in the format dd/mm/yyyy
    void showDate(){
        if(day < 10) cout << 0;
        cout << day << "/";
        if(month < 10) cout << 0;
        cout << month << "/" << year;
    }
    void setDay(int d){
        if(checkDayAndMonth(d,month) && checkLeapYear(d,month,year)){
            day = d;
        }
    }
    void setMonth(int m){
        if(checkDayAndMonth(day,m) && checkLeapYear(day,m,year)){
            month = m;
        }
    }
    void setYear(int y){
        if(checkYear(y) && checkLeapYear(day,month,y)){
            year = y;
        }
    }
    int getDay(){
        return day;
    }
    int getMonth(){
        return month;
    }
    int getYear(){
        return year;
    }
};


class publication{
    string title;
    float price;
public:
    void getData(){
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter price: ";
        cin >> price;
    }
    void putData(){
        cout << "Title: " << title << '\n';
        cout << "Price: " << price << "$" << '\n';
    }

};

class publication2 : public publication{
    date dateOfPublication;
public:
    void getData(){
        publication::getData();
        cout << "Date of publication: ";
        string s;
        cin >> s;
        dateOfPublication.setDate(s);
    }
    void putData(){
        publication::putData();
        cout << "Date of publication: ";
        dateOfPublication.showDate();
        cout << '\n';
    }
};

class book:public publication2{
    int pageCount;
public:
    void getData(){
        publication2::getData();
        cout << "Enter page count: ";
        cin >> pageCount;
    }
    void putData(){
        publication2::putData();
        cout << "Page count: " << pageCount << " pages"<< '\n';
    }
};

class audiocassete:public publication2{
    float duration;
public:
    void getData(){
        publication2::getData();
        cout << "Enter duration: ";
        cin >> duration;
    }
    void putData(){
        publication2::putData();
        cout << "Duration: " << duration << " minutes" << '\n';
    }
};

int main(){
    book b;
    audiocassete a;
    b.getData();
    a.getData();
    b.putData();
    a.putData();
    return 0;
}
