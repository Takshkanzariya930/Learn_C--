#include<iostream>
using namespace std;

class Triangle
{
    public:

    double area(double b,double h)
    {
        return 0.5*b*h;
    }
};

class Square
{
    public:

    double area(double l)
    {
        return l*l;
    }
};
class Circle
{
    public:

    double area(double r)
    {
        return 3.14*r*r;
    }
};

int main()
{
    Triangle tri;
    Square squ;
    Circle cir;

    cout<<"\nArea of Triangle : "<<tri.area(10,5);
    cout<<"\nArea of Square : "<<squ.area(10);
    cout<<"\nArea of Circle : "<<cir.area(10);
}