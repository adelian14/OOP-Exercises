#include <iostream>

using namespace std;

class Int{
    int val;
public:
    Int(){
        val = 0;
    }
    Int(int x){
        val = x;
    }
    void display(){
        cout << val;
    }
    Int operator+(Int x){
        Int ret = Int(val+x.val);
        return ret;
    }
};

int main(){
    Int x,y(5),z(12);
    x = y+z;
    x.display();
    return 0;
}
