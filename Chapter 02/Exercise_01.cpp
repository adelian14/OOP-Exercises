#include <iostream>
#include <iomanip>
#include <conio.h>
#include <process.h>

using namespace std;

class sterling{

};

int main()
{
    int g;
    float rate = 7.481;
    cout << "Enter number of gallons: ";
    cin >> g;
    cout << g << " gallons = " << g*rate << " cubic feet";
    return 0;
}
