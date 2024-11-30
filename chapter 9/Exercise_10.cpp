#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

const int LEN = 80;

class student                 //educational background
{
private:
    char school[LEN];       //name of school or university
    char degree[LEN];       //highest degree earned
public:
    void getedu()
    {
        cout << "   Enter name of school or university: ";
        cin >> school;
        cout << "   Enter highest degree earned \n";
        cout << "   (Highschool, Bachelor's, Master's, PhD): ";
        cin >> degree;
    }
    void putedu() const
    {
        cout << "\n   School or university: " << school;
        cout << "\n   Highest degree earned: " << degree;
    }
};

class employee
{
private:
    char name[LEN];         //employee name
    unsigned long number;   //employee number
public:
    void getdata()
    {
        cout << "\n   Enter last name: ";
        cin >> name;
        cout << "   Enter number: ";
        cin >> number;
    }
    void putdata() const
    {
        cout << "\n   Name: " << name;
        cout << "\n   Number: " << number;
    }
};

class manager : private employee, private student  //management
{
private:
    char title[LEN];        //"vice-president" etc.
    double dues;            //golf club dues
public:
    void getdata()
    {
        employee::getdata();
        cout << "   Enter title: ";
        cin >> title;
        cout << "   Enter golf club dues: ";
        cin >> dues;
        student::getedu();
    }
    void putdata() const
    {
        employee::putdata();
        cout << "\n   Title: " << title;
        cout << "\n   Golf club dues: " << dues;
        student::putedu();
    }
};

class executive: public manager
{
    int yearlyBonus;
    int shares;
public:
    void getdata()
    {
        manager::getdata();
        cout << "   Enter yearly bonus: ";
        cin >> yearlyBonus;
        cout << "   Enter number of shares: ";
        cin >> shares;
    }
    void putdata()
    {
        manager::putdata();
        cout << "\n   Yearly bonus: " << yearlyBonus;
        cout << "\n   Number of shares: " << shares;
    }
};

int main()
{
    manager m1;
    executive e1, e2;
    cout << endl;
    cout << "\nEnter data for manager 1";
    m1.getdata();
    cout << "\nEnter data for executive 1";
    e1.getdata();
    cout << "\nEnter data for executive 2";
    e2.getdata();
    cout << "\nData on manager 1";
    m1.putdata();
    cout << "\nData on executive 1";
    e1.putdata();
    cout << "\nData on executive 2";
    e2.putdata();
    cout << endl;
    return 0;
}
