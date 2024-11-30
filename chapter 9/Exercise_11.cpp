#include <iostream>
#include <iomanip>
#include <conio.h>
#include <process.h>

using namespace std;

struct Pair{
    int x;
    int y;
};

class Stack
{
protected:                   //NOTE: can’t be private
    enum { MAX = 100 };         //size of stack array
    int st[MAX];              //stack: array of integers
    int top;                  //index to top of stack
public:
    Stack()                   //constructor
    {
        top = -1;
    }
    void push(int var)        //put number on stack
    {
        st[++top] = var;
    }
    int pop()                 //take number off stack
    {
        return st[top--];
    }
};
class Stack2 : public Stack
{
public:
    void push(int var)          //put number on stack
    {
        if(top >= MAX-1)         //error if stack full
        {
            cout << "\nError: stack is full";
            exit(1);
        }
        Stack::push(var);        //call push() in Stack class
    }
    int pop()                   //take number off stack
    {
        if(top < 0)              //error if stack empty
        {
            cout << "\nError: stack is empty\n";
            exit(1);
        }
        return Stack::pop();     //call pop() in Stack class
    }
};

class pairStack : public Stack2{
public:
    void push(Pair p){
        Stack2::push(p.x);
        Stack2::push(p.y);
    }
    Pair pop(){
        Pair p;
        p.y = Stack2::pop();
        p.x = Stack2::pop();
        return p;
    }
};


int main()
{
    Pair a,b,c;
    a.x=1,a.y=2;
    b.x=2,b.y=3;
    c.x=5,c.y=8;
    pairStack s;
    s.push(a);
    s.push(b);
    s.push(c);
    Pair p;
    p = s.pop();
    cout << p.x << ' ' << p.y << '\n';
    p = s.pop();
    cout << p.x << ' ' << p.y << '\n';
    p = s.pop();
    cout << p.x << ' ' << p.y << '\n';
    p = s.pop();
    cout << p.x << ' ' << p.y << '\n';
    return 0;
}
