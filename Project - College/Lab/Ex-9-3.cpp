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

    Complex operator++()
    {
        Complex temp;
        temp.real = ++real;
        temp.imag = ++imag;

        return temp;
    }

    Complex operator++(int)
    {
        Complex temp;
        temp.real = real++;
        temp.imag = imag++;

        return temp;
    }

    Complex operator--()
    {
        Complex temp;
        temp.real = --real;
        temp.imag = --imag;

        return temp;
    }

    Complex operator--(int)
    {
        Complex temp;
        temp.real = real--;
        temp.imag = imag--;

        return temp;
    }

    void display()
    {
        cout<<"Complex Number : "<<real<<" + "<<imag;
    }
};

int main()
{
    Complex c1(12.3,23);

    cout<<"\n-> Pre increment :-";

    cout<<"\n   Before pre increment c1 : ";
    c1.display();

    Complex c5 = ++c1;
    
    cout<<"\n   After pre increment c1 : ";
    c1.display();

    cout<<"\n   c5 : ";
    c5.display();

    cout<<"\n\n-> Post increment :-";

    cout<<"\n   Before post increment c1 : ";
    c1.display();

    Complex c6 = c1++;
    
    cout<<"\n   After post increment c1 : ";
    c1.display();

    cout<<"\n   c6 : ";
    c6.display();


    cout<<"\n\n-> Pre decrement :-";

    cout<<"\n   Before pre decrement c1 : ";
    c1.display();

    Complex c7 = --c1;
    
    cout<<"\n   After pre decrement c1 : ";
    c1.display();

    cout<<"\n   c7 : ";
    c7.display();

    cout<<"\n\n-> Post decrement  :-";

    cout<<"\n   Before post decrement c1 : ";
    c1.display();

    Complex c8 = c1--;
    
    cout<<"\n   After post decrement c1 : ";
    c1.display();

    cout<<"\n   c8 : ";
    c8.display();

}