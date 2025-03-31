#include<iostream>
#include<cmath>
using namespace std;

class Polar
{
    float radius,angle;

    public:
    Polar(float r = 0,float a = 0)
    {
        radius = r;
        angle = a;
    }

    void converttorec()
    {
        float x = radius* cos(angle);
        float y = radius* sin(angle);

        cout<<"Rectangular form of ("<<radius<<" , "<<angle<<"') -> ("<<x<<" , "<<y<<")"<<endl;
    }
};

class Rectangular
{
    float x,y;

    public:
    Rectangular(float a = 0,float b = 0)
    {
        x = a;
        y = b;
    }

    void converttopol()
    {
        float r = sqrt(x*x + y*y);
        float a = atan(y/x);

        cout<<"Polar form of ("<<x<<" , "<<y<<")  -> ("<<r<<" , "<<a<<"')"<<endl;
    }
};

int main()
{
    Polar p1(20,10);
    Rectangular r1(10,20);

    p1.converttorec();
    r1.converttopol();
}