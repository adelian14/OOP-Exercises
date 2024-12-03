#include <iostream>
#include <iomanip>
#include <conio.h>
#include <process.h>
#include <CTYPE.H>

using namespace std;

int main()
{
    double p_rate = 1.487, f_rate = 0.172, gd_rate = 0.584, y_rate = 0.00955, usd;
    cout << "Enter amount in dollars: ";
    cin >> usd;
    cout << "$" << usd << " = " << usd/p_rate << " pound\n";
    cout << "$" << usd << " = " << usd/f_rate << " franc\n";
    cout << "$" << usd << " = " << usd/gd_rate << " deutschemark\n";
    cout << "$" << usd << " = " << usd/y_rate << " yen\n";
    return 0;
}
