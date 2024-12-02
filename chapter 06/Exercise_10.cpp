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
    char showAngle(){
        cout << fixed << setprecision(2) << degree << "\xF8" << minute << "\' " << direction;
        return '\0';
    }
    char getDir(){
        return direction;
    }
};

class ship{
    int shipNumber;
    angle longitude;
    angle latitude;
    static int cnt;
public:
    ship(angle lat = angle(), angle lon = angle(0,0,'W')){
        setLocation(lat,lon);
        cnt++;
        shipNumber = cnt;
    }
    void setLocation(angle lat, angle lon){
        setLatitude(lat);
        setLongitude(lon);
    }
    void setLatitude(angle lat){
        if(lat.getDir()=='W'||lat.getDir()=='E') throw runtime_error("Invalid latitude");
        latitude = lat;
    }
    void setLongitude(angle lon){
        if(lon.getDir()=='N' || lon.getDir()=='S') throw runtime_error("Invalid longitude");
        longitude = lon;
    }
    angle getLatitude(){
        return latitude;
    }
    angle getLongitude(){
        return longitude;
    }
    int getShipNumber(){
        return shipNumber;
    }
    void report(){
        cout << "Ship number: " << shipNumber << " at " << latitude.showAngle() << ", " << longitude.showAngle() << '\n';
    }
};

int ship::cnt = 0;

int main(){
    ship s[3];
    for(int i = 0; i < 3; i++){
        int degree;
        float minute;
        char dir;
        angle lat,lon;
        try{
            cout << "Enter location for ship #" << s[i].getShipNumber() << ":\n";
            cout << "--------------------------\n";
            cout << "Latitude:\n";
            cout << "Degree: ";
            cin >> degree;
            cout << "Minute: ";
            cin >> minute;
            cout << "Direction (N,S): ";
            cin >> dir;
            lat = angle(degree,minute,dir);
            cout << "--------------------------\n";
            cout << "Longitude:\n";
            cout << "Degree: ";
            cin >> degree;
            cout << "Minute: ";
            cin >> minute;
            cout << "Direction (W,E): ";
            cin >> dir;
            lon = angle(degree,minute,dir);
            s[i].setLocation(lat,lon);
        }
        catch(const exception& e){
            cout << e.what() << '\n';
            i--;
        }
    }
    for(int i = 0; i < 3; i++) s[i].report();
    return 0;
}
