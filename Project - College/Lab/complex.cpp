#include <iostream>
using namespace std;

class complex {

    float real,imaginary;

    public:

    void complexnum(float r,float i)
    {
        real = r;
        imaginary = i;
    }

    void printcomplex()
    {
        cout<<real<<imaginary<<"i";
    }

};

int main()
{
    complex c1;

    c1.complexnum(10,-20);
    c1.printcomplex();
}