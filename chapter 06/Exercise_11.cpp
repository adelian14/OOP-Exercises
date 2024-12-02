#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

class fraction{
    int numerator;
    int denominator;
    void parseFrac(string s){
        int cnt = 0;
        int x = 0, y = 0, isPositive = 1;
        int start = 0;
        if(s[0]=='-') start = 1, isPositive = -1;
        for(int i = start; i < s.size(); i++){
            if(s[i]=='/'){
                cnt++;
                if(cnt > 1) throw runtime_error("Invalid fraction");
            }
            else if(s[i] < '0' || s[i] > '9'){
                throw runtime_error("Invalid fraction");
            }
            else{
                int d = s[i]-'0';
                if(cnt) y = y*10+d;
                else x = x*10+d;
            }
        }
        if(y==0) throw runtime_error("Denominator can\'t be zero");
        x*=isPositive;
        numerator = x;
        denominator = y;
    }
    void gcd(){
        int x = numerator, y = denominator;
        if(y < 0) y*=-1;
        if(x < 0) x*=-1;
        while(y){
            x%=y;
            int temp = x;
            x = y;
            y = temp;
        }
        numerator/=x;
        denominator/=x;
    }
public:
    fraction(string s = ""){
        if(s==""){
            numerator = 0;
            denominator = 1;
            return;
        }
        parseFrac(s);
    }
    fraction(int x, int y){
        setFrac(x,y);
    }
    void setFrac(string s){
        parseFrac(s);
    }
    void setFrac(int x, int y){
        if(y==0) throw runtime_error("Denominator can\'t be zero");
        if(y < 0) x*=-1;
        numerator = x;
        denominator = y;
    }
    void print(){
        gcd();
        cout << numerator << '/' << denominator;
    }
    fraction add(fraction f){
        fraction res;
        res.numerator = numerator*f.denominator + f.numerator*denominator;
        res.denominator = denominator*f.denominator;
        return res;
    }
    fraction subtract(fraction f){
        fraction res;
        res.numerator = numerator*f.denominator - f.numerator*denominator;
        res.denominator = denominator*f.denominator;
        return res;
    }
    fraction multiply(fraction f){
        fraction res;
        res.numerator = numerator*f.numerator;
        res.denominator = denominator*f.denominator;
        return res;
    }
    fraction divide(fraction f){
        fraction res;
        res.numerator = numerator*f.denominator;
        res.denominator = denominator*f.numerator;
        return res;
    }
};

int main(){
    cout << "Enter two fractions to perform an operation.\nIn the form A/B where A is an integer and B is a positive interger (B > 0).\n";
    fraction x,y;
    while(true){
        try{
            char op;
            string a,b;
            cout << "Choose operation (+,-,*,/): ";
            cin >> op;
            cout << "fraction1: ";
            cin >> a;
            cout << "fraction2: ";
            cin >> b;
            x.setFrac(a);
            y.setFrac(b);
            fraction z;
            if(op=='+') z = x.add(y);
            else if(op=='-') z = x.subtract(y);
            else if(op=='*') z = x.multiply(y);
            else if(op=='/') z = x.divide(y);
            else throw runtime_error("Invalid operation");
            x.print();
            cout << " " << op << " ";
            y.print();
            cout << " = ";
            z.print();
            cout << "\n";
        }
        catch(const exception& e){
            cout << e.what() << '\n';
        }
        cout << "Press 1 to continue, press any key to exit: ";
        char option = getch();
        cout << option << '\n';
        if(option!='1') break;
    }
    return 0;
}
