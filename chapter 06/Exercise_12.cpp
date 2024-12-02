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
        cout << numerator <<'/' <<  denominator;
        int x = numerator, y = denominator;
        int cnt = 1, width = 8;
        do{
            cnt++;
            x/=10;
        }
        while(x);
        do{
            cnt++;
            y/=10;
        }
        while(y);
        while(cnt < width){
            cout << ' ';
            cnt++;
        }
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
    int n;
    cout << "Enter a number n (n > 1) to get a multiplication table from 1/n to n-1/n: ";
    cin >> n;
    cout << '\n';
    for(int i = 0; i < n; i++){
        if(i==0) cout << "        ";
        else{
            fraction f(i,n);
            f.print();
        }
    }
    cout << "\n";
    for(int i = 0; i < 8*(n); i++) cout << '-';
    cout << '\n';
    for(int i = 1; i < n; i++){
        fraction f1(i,n);
        f1.print();
        for(int j = 1; j < n; j++){
            fraction f2(j,n);
            f1.multiply(f2).print();
        }
        cout << '\n';
    }
    return 0;
}
