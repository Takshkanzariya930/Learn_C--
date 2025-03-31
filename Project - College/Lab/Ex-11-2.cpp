#include<iostream>
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

    Polar operator+(Polar &obj)
    {
        Polar temp(radius + obj.radius,angle + obj.angle);
        return temp;
    }

    void display()
    {
        cout<<" -> ("<<radius<<" , "<<angle<<"')"<<endl;
    }
};

int main()
{
    Polar p1(6,43),p2(13,17),p3;

    p3 = p1 + p2;

    cout<<"p1";
    p1.display();
    cout<<"p2";
    p2.display();
    cout<<"p3";
    p3.display();
}