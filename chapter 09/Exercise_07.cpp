#include <iostream>
#include <iomanip>
#include <conio.h>
#include <process.h>

using namespace std;

////////////////////////////////////////////////////////////////
class Counter
{
protected:                            //NOTE: not private
    unsigned int count;                //count
public:
    Counter() : count()                //constructor, no args
    {  }
    Counter(int c) : count(c)          //constructor, one arg
    {  }
    unsigned int get_count() const     //return count
    {
        return count;
    }
    Counter operator ++ ()             //incr count (prefix)
    {
        return Counter(++count);
    }
    Counter what(){
        return *this;
    }
};
////////////////////////////////////////////////////////////////
class CountDn : public Counter
{
public:
    CountDn() : Counter()              //constructor, no args
    { }
    CountDn(int c) : Counter(c)        //constructor, 1 arg
    { }
    CountDn operator -- ()             //decr count (prefix)
    {
        return CountDn(--count);
    }
};
class Counter2: public CountDn{
public:
    Counter2() : CountDn()
    {}
    Counter2(int x):CountDn(x)
    {}
    Counter2 operator ++ ()
    {
        CountDn::operator++();
    }
    Counter2 operator -- ()
    {
        CountDn::operator--();
    }
    Counter2 operator ++ (int)
    {
        int temp = count;
        count++;
        return Counter2(temp);
    }
    Counter2 operator -- (int)
    {
        int temp = count;
        count--;
        return Counter2(temp);
    }
};
int main()
{
    Counter2 c1;
    Counter2 c2(100);
    cout << "\nc1=" << c1.get_count();
    cout << "\nc2=" << c2.get_count();
    ++c1;
    ++c1;
    ++c1;
    cout << "\nc1=" << c1.get_count();
    cout << "\nc2=" << c2.get_count();
    Counter2 c3 = c1++;
    Counter2 c4 = c2--;
    cout << "\nc1=" << c1.get_count();
    cout << "\nc2=" << c2.get_count();
    cout << "\nc3=" << c3.get_count();
    cout << "\nc4=" << c4.get_count();
    cout << endl;
    return 0;
}
