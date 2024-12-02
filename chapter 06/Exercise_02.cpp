#include <iostream>
#include <conio.h>

using namespace std;

class tollBooth{
    unsigned int total_cars;
    double money_amount;
public:
    tollBooth(){
        total_cars = 0;
        money_amount = 0;
    }
    void payingCar(){
        total_cars++;
        money_amount+=.5;
    }
    void nopayCar(){
        total_cars++;
    }
    void display(){
        cout << "Total cars passed by : " << total_cars << " cars\n";
        cout << "Total money collected: " << money_amount << "$\n";
        cout << "Non-paying cars      : " << total_cars-(unsigned int)(2*money_amount) << " cars\n";
    }
};

int main(){
    tollBooth Booth;
    cout << "Press 'y' if a paying car goes by, otherwise press 'n'.\npress Esc to exit\n\n";
    while(true){
        char c = getch();
        if(c=='y' || c=='Y') Booth.payingCar();
        else if(c=='n' || c=='N') Booth.nopayCar();
        else if(c==27) break;
    }
    Booth.display();
    return 0;
}
