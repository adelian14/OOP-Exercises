#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string.h>      //for strcpy(), strcat()
#include <stdlib.h>      //for exit()

using namespace std;
////////////////////////////////////////////////////////////////
class String             //user-defined string type
{
protected:
    enum { SZ=80 };                //size of String objects
    char str[SZ];                  //holds a string
public:
    String()                       //constructor, no args
    {
        strcpy(str, "");
    }
    String( char s[] )             //constructor, one arg
    {
        strcpy(str, s);
    }
    void display() const           //display the String
    {
        cout << str;
    }
    String operator + (String ss) const  //add StringsOperator Overloading
    {
        String temp;                //make a temporary String
        if( strlen(str) + strlen(ss.str) < SZ )
        {
            strcpy(temp.str, str);   //copy this string to temp
            strcat(temp.str, ss.str);  //add the argument string
        }
        else
        {
            cout << "\nString overflow";
            exit(1);
        }
        return temp;                //return temp String
    }
};

class pString:public String{
public:
    pString(char s[]){
        int i = 0;
        while(s[i]!='\0'){
            if(i+1==SZ){
                str[i]='\0';
                break;
            }
            str[i]=s[i];
            i++;
        }
        str[i]='\0';
    }
};

class pString2:public pString{
    int len;
    void setSize(){
        len = 0;
        while(str[len] != '\0') len++;
    }
public:
    pString2():pString(""){}
    pString2(char s[]):pString(s){
        cout << str << '\n';
        setSize();
    }
    int size(){
        return len;
    }
    void left(pString2 s, int n){
        if(n > s.len){
            cout << "\nOut of bound";
            exit(1);
        }
        for(int i = 0; i < n; i++){
            str[i] = s.str[i];
        }
        str[n]='\0';
        setSize();
    }
    void right(pString2 s, int n){
        if(n > s.len){
            cout << "\nOut of bound";
            exit(1);
        }
        for(int i = s.len-n, j = 0; i < s.len; i++, j++){
            str[j] = s.str[i];
        }
        str[n]='\0';
        setSize();
    }
    void mid(pString2 s, int l, int n){
        if(l+n > s.len){
            cout << "\nOut of bound";
            exit(1);
        }
        for(int i = l, j = 0; i < l+n; i++, j++){
            str[j]=s.str[i];
        }
        str[n]='\0';
    }
};

int main()
{
    pString2 s("123456789");
    pString2 s1;
    pString2 s2;
    pString2 s3;
    for(int i = 1; i <= s.size(); i++){
        s1.left(s,i);
        s1.display();
        cout << '\n';
    }
    cout << '\n';
    for(int i = 1; i <= s.size(); i++){
        s2.right(s,i);
        s2.display();
        cout << '\n';
    }
    cout << '\n';
    for(int i = 0; i < s.size(); i++){
        for(int j = 1; j+i <= s.size(); j++){
            s3.mid(s,i,j);
            s3.display();
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}
