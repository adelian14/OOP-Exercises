#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

class publication{
    string title;
    float price;
public:
    void getData(){
        cout << "\n\nEnter title: ";
        cin >> title;
        cout << "Enter price: ";
        cin >> price;
    }
    void putData(){
        cout << "\n\nTitle: " << title << '\n';
        cout << "Price: " << price << "$" << '\n';
    }

};

class sales{
    enum {len = 3};
    float lastSales[len];
public:
    void getData(){
        cout << "\nEnter sales data for last " << len << " months:\n\n";
        for(int i = 0; i < len; i++){
            cout << "Month " << i+1 << ": ";
            cin >> lastSales[i];
        }
    }
    void putData(){
        cout << "\nSales for last " << len << " months:\n";
        for(int i = 0; i < len; i++){
            cout << "Month " << i+1 << ": " << lastSales[i] << "$\n";
        }
    }
};

class book:public publication, public sales{
    int pageCount;
public:
    void getData(){
        publication::getData();
        cout << "Enter page count: ";
        cin >> pageCount;
        sales::getData();
    }
    void putData(){
        publication::putData();
        cout << "Page count: " << pageCount << " pages"<< '\n';
        sales::putData();
    }
};

class audiocassete:public publication, public sales{
    float duration;
public:
    void getData(){
        publication::getData();
        cout << "Enter duration: ";
        cin >> duration;
        sales::getData();
    }
    void putData(){
        publication::putData();
        cout << "Duration: " << duration << " minutes" << '\n';
        sales::putData();
    }
};

class disk:public publication, public sales{
    enum {CD = 'c', DVD = 'd'};
    char diskType;
public:
    void getData(){
        publication::getData();
        cout << "Enter disk type (c for CD, d for DVD): ";
        cin >> diskType;
        sales::getData();
    }
    void putData(){
        publication::putData();
        cout << "Media type: " ;
        if(diskType==CD) cout <<  "CD\n";
        else if(diskType==DVD) cout << "DVD\n";
        sales::putData();
    }
};

int main(){
    book b;
    audiocassete a;
    disk d;
    b.getData();
    a.getData();
    d.getData();
    b.putData();
    a.putData();
    d.putData();
    return 0;
}
