#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

const int LEN = 80;                //maximum length of names
////////////////////////////////////////////////////////////////
class employee                     //employee class
{
private:
    char name[LEN];              //employee name
    unsigned long number;        //employee number
public:
    void getdata()
    {
        cout << "\n   Enter last name: ";
        cin >> name;
        cout << "   Enter number: ";
        cin >> number;
    }
    void putdata()
    {
        cout << "\n   Name: " << name;
        cout << "\n   Number: " << number;
    }
};
class employee2:public employee{
    double compensation;
    enum {Hourly = 'h', Weekly = 'w', Monthly = 'm'};
    char period;
public:
    void getdata(){
        employee::getdata();
        cout << "   Enter compensation: ";
        cin >> compensation;
        cout << "   Enter paying period (h for hourly, w for weekly, m for monthly): ";
        cin >> period;
    }
    void putdata(){
        employee::putdata();
        cout << "\n   Compensation: " << compensation << "$ ";
        if(period == Hourly) cout << "hourly";
        if(period == Weekly) cout << "weekly";
        if(period == Monthly) cout << "monthly";
    }
};
////////////////////////////////////////////////////////////////
class manager : public employee2    //management class
{
private:
    char title[LEN];             //"vice-president" etc.
    double dues;                 //golf club dues
public:
    void getdata()
    {
        employee2::getdata();
        cout << "   Enter title: ";
        cin >> title;
        cout << "   Enter golf club dues: ";
        cin >> dues;
    }
    void putdata()
    {
        employee2::putdata();
        cout << "\n   Title: " << title;
        cout << "\n   Golf club dues: " << dues;
    }
};
////////////////////////////////////////////////////////////////
class scientist : public employee2  //scientist class
{
private:
    int pubs;                    //number of publications
public:
    void getdata()
    {
        employee2::getdata();
        cout << "   Enter number of pubs: ";
        cin >> pubs;
    }
    void putdata()
    {
        employee2::putdata();
        cout << "\n   Number of publications: " << pubs;
    }
};
////////////////////////////////////////////////////////////////
class laborer : public employee2    //laborer class
{
};
////////////////////////////////////////////////////////////////
int main()
{
    manager m1, m2;
    scientist s1;
    laborer l1;
    cout << endl;           //get data for several employees
    cout << "\nEnter data for manager 1";
    m1.getdata();
    cout << "\nEnter data for manager 2";
    m2.getdata();
    cout << "\nEnter data for scientist 1";
    s1.getdata();
    cout << "\nEnter data for laborer 1";
    l1.getdata();
//display data for several employees
    cout << "\nData on manager 1";
    m1.putdata();
    cout << "\nData on manager 2";
    m2.putdata();
    cout << "\nData on scientist 1";
    s1.putdata();
    cout << "\nData on laborer 1";
    l1.putdata();
    cout << endl;
    return 0;
}
