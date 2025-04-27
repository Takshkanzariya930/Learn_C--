#include <iostream>
using namespace std;

class Shape
{
    public:
    virtual void displayArea()
    {
        cout<<"This is class Shape.";
    }
};

class Circle : public Shape
{
    double radius;

    public:
    Circle(double r)
    {
        radius = r;
    }

    void displayArea() override
    {
        cout<<"Area of circle : "<<3.14*radius*radius<<endl;
    }
};

class Rectangle : public Shape
{
    double length,breadth,height;

    public:
    Rectangle(double l,double b,double h)
    {
        length = l;
        breadth = b;
        height = h;
    }

    void displayArea() override
    {
        cout<<"Area of rectangle : "<<length*breadth*height<<endl;
    }
};

int main()
{
    Shape *ptr;

    ptr = new Circle(4);
    ptr->displayArea();
    
    ptr = new Rectangle(5,3,7);
    ptr->displayArea();

    delete ptr;
}