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

    Complex(Complex &other)
    {
        real = other.real;
        imag = other.imag;;
    }

    void display()
    {
        cout<<"Complex Number : "<<real<<" + "<<imag;
    }

};

int main()
{
    Complex c1(12.3,23);
    Complex c2 = c1;
    c2.display();
}