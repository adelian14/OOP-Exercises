#include <iostream>

using namespace std;

const int minutes_limit = 60;
const int seconds_limit = 60;

class time{
    int hours;
    int minutes;
    int seconds;
    void normalize(){
        minutes+=seconds/seconds_limit;
        seconds%=seconds_limit;
        hours+=minutes/minutes_limit;
        minutes%=minutes_limit;
    }
public:
    time():hours(0),minutes(0),seconds(0){}
    time(int h, int m, int s){
        hours = h;
        minutes = m;
        seconds = s;
        normalize();
    }
    void add(time t1, time t2){
        hours = t1.hours + t2.hours;
        minutes = t1.minutes + t2.minutes;
        seconds = t1.seconds + t2.seconds;
        normalize();
    }
    void display(){
        if(hours < 10) cout << 0;
        cout << hours << ":";
        if(minutes < 10) cout << 0;
        cout << minutes << ":";
        if(seconds < 10) cout << 0;
        cout << seconds;
    }
};

int main(){
    time t1,t2(8,10,48),t3(7,58,30);
    t1.add(t2,t3);
    t1.display();
    return 0;
}
