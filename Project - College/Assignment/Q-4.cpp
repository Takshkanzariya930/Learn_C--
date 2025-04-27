#include <iostream>
using namespace std;

class Y;

class X
{
    int p;

    public:
    void setdata(int p) {this->p = p;}
    
    friend void product(X,Y);
};

class Y
{
    int q;
    
    public:
    void setdata(int q) {this->q = q;}

    friend void product(X,Y);
};

void product(X obj1,Y obj2)
{
    cout<<"p * q = "<<obj1.p*obj2.q;
}

int main()
{
    X obj1;
    Y obj2;

    obj1.setdata(5);
    obj2.setdata(6);

    product(obj1,obj2);
}