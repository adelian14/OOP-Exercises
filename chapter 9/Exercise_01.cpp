#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

class publication{
    string title;
    float price;
public:
    void getData(){
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter price: ";
        cin >> price;
    }
    void putData(){
        cout << "Title: " << title << '\n';
        cout << "Price: " << price << "$" << '\n';
    }

};

class book:public publication{
    int pageCount;
public:
    void getData(){
        publication::getData();
        cout << "Enter page count: ";
        cin >> pageCount;
    }
    void putData(){
        publication::putData();
        cout << "Page count: " << pageCount << " pages"<< '\n';
    }
};

class audiocassete:public publication{
    float duration;
public:
    void getData(){
        publication::getData();
        cout << "Enter duration: ";
        cin >> duration;
    }
    void putData(){
        publication::putData();
        cout << "Duration: " << duration << " minutes" << '\n';
    }
};

int main(){
    book b;
    audiocassete a;
    b.getData();
    a.getData();
    b.putData();
    a.putData();
    return 0;
}
