#include <iostream>

using namespace std;

class employee{
    int number;
    float compensation;
public:
    employee(int num, float comp = 0){
        setNumber(num);
        setCompensation(comp);
    }
    void setNumber(int num){
        if(num < 0) num = 0;
        number = num;
    }
    int getNumber(){
        return number;
    }
    void setCompensation(float comp){
        if(comp < 0) comp = 0;
        compensation = comp;
    }
    float getCompensation(){
        return compensation;
    }
    void display(){
        cout << "Employee number " << number << " has compensation of " << compensation << " $\n";
    }
};

int main(){
    employee e1(1),e2(2,2500),e3(3,3199.99);
    e1.setCompensation(1000);
    e1.display();
    e2.display();
    e3.display();
    return 0;
}
