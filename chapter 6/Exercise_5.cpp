#include <iostream>
#include <iomanip>

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

int main(){
    int days[5]={6,28,29,30,31};
    int years[5]={5,24,2005,1997,0};
    for(int i = 0; i < 5; i++){
        for(int j = 1; j <= 12; j++){
            for(int k = 0; k < 5; k++){
                string s = "";
                s+=intToStr(j);
                s+='/';
                s+=intToStr(days[i]);
                s+='/';
                s+=intToStr(years[k]);
                try{
                    date d;
                    d.setDate(s);
                    cout << "Input date: " << setw(10) << s << " --> Output date: ";
                    d.showDate();
                    cout << '\n';
                }
                catch(const exception& e){
                    cout << e.what() << '\n';
                }
            }
        }
    }
    return 0;
}
