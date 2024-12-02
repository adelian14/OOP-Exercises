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
    }
};

int main()
{
    pString longString("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM123456789");
    pString shortString("This is a short string");
    cout << "Long string: \n";
    longString.display();
    cout << "\n\nShort string: \n";
    shortString.display();
    return 0;
}
