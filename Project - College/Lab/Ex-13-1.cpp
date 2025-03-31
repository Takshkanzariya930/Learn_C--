#include <iostream>
using namespace std;

class Base
{
    int basevalue;
    
    public:
    Base(int value)
    {
        basevalue = value;
        
        cout<<"\nBase Constructor......"<<endl;
        cout<<"basevalue is "<<basevalue<<endl;
    }
};

class Derived : public Base
{
    int derivedvalue;

    public:
    Derived(int bvalue,int dvalue) : Base(bvalue)
    {
        derivedvalue = dvalue;

        cout<<"\nDerived Constructor......"<<endl;
        cout<<"basevalue is "<<bvalue<<endl;
        cout<<"derivedvalue is "<<derivedvalue<<endl;
    }
};

int main()
{
    Derived obj(12,24);
}