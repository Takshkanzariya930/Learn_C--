#include<iostream>
using namespace std;

class Complex
{
    double real,imag;

    public:

    Complex(double r = 0,double i = 0)
    {
        real = r;
        imag = i;
    }

    Complex operator+(Complex &obj)
    {
        Complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;

        return temp;
    }

    Complex operator-(Complex &obj)
    {
        Complex temp;
        temp.real = real - obj.real;
        temp.imag = imag - obj.imag;

        return temp;
    }

    void display()
    {
        cout<<real<<" + "<<imag;
    }
};

int main()
{
    Complex c1(12.3,23),c2(2,-23.4);

    Complex c3 = c1 + c2;

    cout<<"\n--> c1 + c2 = c3";
    cout<<"\nc1 : ";
    c1.display();

    cout<<"\nc2 : ";
    c2.display();

    cout<<"\nc3 : ";
    c3.display();
    
    Complex c4 = c1 - c2;
    
    cout<<"\n\n--> c1 - c2 = c3";
    cout<<"\nc1 : ";
    c1.display();

    cout<<"\nc2 : ";
    c2.display();

    cout<<"\nc3 : ";
    c4.display();

}