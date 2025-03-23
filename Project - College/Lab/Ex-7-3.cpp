#include <iostream>
using namespace std;

class Time
{
    int h,m,s;

    public:

    Time (int hour=0,int min=0, int sec=0)
    {
        h = hour;
        m = min;
        s = sec;
    }

    void add(Time &obj1)
    {

        h = h + obj1.h;
        m = m + obj1.m;
        s = s + obj1.s;

        if (s > 60)
        {
            m += s/60;
            s = s % 60;
        }
        if (m > 60)
        {
            h += m/60;
            m = m % 60;
        }

    }

    void display()
    {
        cout<<"\n"<<h<<" hours "<<m<<" minutes "<<s<<" second.";
    }
};

int main()
{
    Time t1(2,34,44),t2(3,43,33);

    t1.add(t2);

    t1.display();
}