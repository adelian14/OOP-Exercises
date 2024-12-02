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
public:
    fraction(string s = ""){
        if(s==""){
            numerator = 0;
            denominator = 1;
            return;
        }
        parseFrac(s);
    }
    void setFrac(string s){
        parseFrac(s);
    }
    void print(){
        cout << numerator << '/' << denominator;
    }
    fraction add(fraction f){
        fraction res;
        res.numerator = numerator*f.denominator + f.numerator*denominator;
        res.denominator = denominator*f.denominator;
        return res;
    }
};

int main(){
    cout << "Enter two fractions to add them.\nIn the form A/B where A is an integer and B is a positive interger (B > 0).\n";
    fraction x,y;
    while(true){
        try{
            string a,b;
            cout << "fraction1: ";
            cin >> a;
            cout << "fraction2: ";
            cin >> b;
            x.setFrac(a);
            y.setFrac(b);
            fraction z = x.add(y);
            x.print();
            cout << " + ";
            y.print();
            cout << " = ";
            z.print();
            cout << "\n";
        }
        catch(const exception& e){
            cout << e.what() << '\n';
        }
        cout << "Press 1 to continue, press any key to exit: ";
        char op = getch();
        cout << op << '\n';
        if(op!='1') break;
    }
    return 0;
}
