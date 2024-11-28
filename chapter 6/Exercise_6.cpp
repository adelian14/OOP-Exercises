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
    date(string s = ""){
        day=1;
        month=1;
        year=1900;
        if(s!="" && !parseDate(s)) throw runtime_error(s+ " is invalid date");
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

enum etype { laborer, secretary, manager, accountant, executive, researcher };

class employee{
    int number;
    float compensation;
    date employment_date;
    etype emp_type;

public:
    employee(int num, float comp = 0, etype tp = laborer, date dt = date()){
        setNumber(num);
        setCompensation(comp);
        emp_type = tp;
        employment_date = dt;
    }
    void setNumber(int num){
        if(num < 0) num = 0;
        number = num;
    }
    int getNumber(){
        return number;
    }
    void setCompensation(float comp){
        if(comp < 0) comp = 0;
        compensation = comp;
    }
    float getCompensation(){
        return compensation;
    }
    void setDate(date dt){
        employment_date = dt;
    }
    date getDate(){
        return employment_date;
    }
    void setEmpType(etype tp){
        emp_type = tp;
    }
    string getEmpType(){
        if(emp_type==laborer){
            return "laborer";
        }
        else if(emp_type==secretary){
            return "secretary";
        }
        else if(emp_type==manager){
            return "manager";
        }
        else if(emp_type==accountant){
            return "accountant";
        }
        else if(emp_type==executive){
            return "executive";
        }
        else if(emp_type==researcher){
            return "researcher";
        }
    }
    void display(){
        cout << "Employee number: " << number << "\n";
        cout << "Salary         : " << compensation << " $\n";
        cout << "Position       : " << getEmpType() << "\n";
        cout << "Employment date: ";
        employment_date.showDate();
        cout << '\n';
    }
};

int main(){
    employee e1(1,4000,manager,date("08/25/2001")),e2(2,2500,researcher,date("05/23/2005")),e3(3,3199.99,secretary);
    e3.setDate(date("03/24/2008"));
    e1.setCompensation(1000);
    e1.display();
    cout << "---------------------------------\n";
    e2.display();
    cout << "---------------------------------\n";
    e3.display();
    return 0;
}
