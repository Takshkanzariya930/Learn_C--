#include <iostream>
using namespace std;

class COMPLEX
{
    double real,imag;

    public:
    COMPLEX(double r,double i)
    {
        real = r;
        imag = i;
    }

    void getdata()
    {
        cout<<real<<" + "<<imag<<"i"<<endl;
    }

    friend COMPLEX add(COMPLEX &,COMPLEX &);
};

COMPLEX add (COMPLEX &o1,COMPLEX &o2)
{
    COMPLEX temp(0,0);

    temp.real = o1.real + o2.real;
    temp.imag = o1.imag + o2.imag;

    return temp;
}

int main()
{
    COMPLEX c1(3.4,-5.7),c2(6.7,-3.9),c3(0,0);

    cout<<"C1 -> ";
    c1.getdata();

    cout<<"C2 -> ";
    c2.getdata();

    c3 = add(c1,c2);
    cout<<"C3 -> ";
    c3.getdata();
}