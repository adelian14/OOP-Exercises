#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

class object{
    int serialNumber;
    static int cnt;
public:
    object(){
        cnt++;
        serialNumber = cnt;
    }
    void report(){
        cout << "I am object number " << serialNumber << '\n';
    }
};

int object::cnt = 0;

int main(){
    object e1,e2,e3;
    e1.report();
    e2.report();
    e3.report();
    return 0;
}
