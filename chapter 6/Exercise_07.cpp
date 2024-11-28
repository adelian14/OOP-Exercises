#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

class angle{
    int degree;
    float minute;
    char direction;
public:
    angle(){
        degree = 0;
        minute = 0;
        direction = 'N';
    }
    angle(int deg, float mint, char dir){
        setAngle(deg,mint,dir);
    }
    void setAngle(int deg, float mint, char dir){
        if(dir > 'Z') dir-=32;
        if(dir != 'N' && dir != 'S' && dir != 'E' && dir != 'W') throw runtime_error("Invalid direction");
        if(mint < 0 || deg < 0) throw runtime_error("Invalid angle");
        int k = mint/60;
        deg+=k;
        mint-=60*k;
        if(dir=='N' || dir=='S'){
            if(deg > 90 || (deg==90 && mint > 0)) throw runtime_error("Invalid angle");
            degree = deg;
            minute = mint;
            direction = dir;
        }
        else{
            if(deg > 180 || (deg==180 && mint > 0)) throw runtime_error("Invalid angle");
            degree = deg;
            minute = mint;
            direction = dir;
        }
    }
    void showAngle(){
        if(direction=='N' || direction=='S') cout << "latitude: ";
        else cout << "longitude: ";
        cout << fixed << setprecision(2) << degree << "\xF8" << minute << "\' " << direction << '\n';
    }
};

int main(){
    angle a(34,56.455,'N');
    cout << "Example: ";
    a.showAngle();
    while(true){
        char op;
        cout << "To enter an angle press 1, to exit press any key: ";
        op = getch();
        cout << op << '\n';
        if(op!='1') break;
        int degree;
        float minute;
        char dir;
        try{
            cout << "Degree: ";
            cin >> degree;
            cout << "Minute: ";
            cin >> minute;
            cout << "Direction: ";
            cin >> dir;
            a.setAngle(degree,minute,dir);
            a.showAngle();
            cout << '\n';
        }
        catch(const exception& e){
            cout << e.what() << '\n';
        }
    }
    return 0;
}
