#include <iostream>
#include <iomanip>
#include <conio.h>
#include <process.h>
#include <CTYPE.H>

using namespace std;

int main()
{
    char x;
    cout << "Enter a letter: ";
    cin >> x;
    cout << islower(x);
    return 0;
}
