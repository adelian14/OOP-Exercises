#include <iostream>
#include <iomanip>
#include <conio.h>
#include <process.h>

using namespace std;

const int LIMIT = 10000;

class safearay
{
protected:
    int arr[LIMIT];
public:
    int& operator [](int n)  //note: return by reference
    {
        if( n< 0 || n>=LIMIT )
        {
            cout << "\nIndex out of bounds";
            exit(1);
        }
        return arr[n];
    }
};

class safehilo:public safearay{
    int lo;
    int hi;
public:
    safehilo(int l, int h){
        if(l > h){
            cout << "\nLower bound can't be greater than upper bound";
            exit(1);
        }
        lo=l;
        hi=h;
    }
    int& operator [](int n)  //note: return by reference
    {
        if(n < lo || n > hi )
        {
            cout << "\nIndex out of bounds";
            exit(1);
        }
        return arr[n-lo];
    }
};
////////////////////////////////////////////////////////////////
int main()
{
    int lo = 50, hi = 100;
    safehilo sa1(lo,hi);
    for(int j = lo; j <= hi; j++)
        sa1[j] = j*10;
    for(int j = lo; j <= hi; j++){
        int temp = sa1[j];
        cout << "Element " << j << " is " << temp << endl;
    }
    return 0;
}
