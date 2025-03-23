#include<iostream>
using namespace std;

class Complex
{
    float real,imag;

    public:

    Complex(float r = 0,float i = 0)
    {
        real = r;
        imag = i;
    }

    void display()
    {
        cout<<"Complex Number : "<<real<<" + "<<imag;
    }

    friend Complex sum(Complex &obj1, Complex &obj2);
};

Complex sum(Complex &obj1, Complex &obj2)     
{
    Complex temp;

    temp.real = obj1.real + obj2.real;
    temp.imag = obj1.imag + obj2.imag;

    return temp;
}

int main()
{
    Complex c1(12.3,23),c2(2,-23.4),c3;
    c3 = sum(c1,c2);
    c3.display();
}