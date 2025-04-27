#include <iostream>
using namespace std;

class ABC;

class XYZ
{ 
    int x; 

    public: 
    void get_x(int i){x=i;} 

    friend void sum(XYZ,ABC); 
}; 

class ABC
{ 
    int y; 

    public: 
    void get_y(int i){y=i;}

    friend void sum(XYZ,ABC); 
}; 

void sum(XYZ obj1,ABC obj2)
{
    cout<<"x + y = "<<obj1.x+obj2.y;
} 

int main()
{
    XYZ o1;
    ABC o2;

    o1.get_x(32);
    o2.get_y(32);
    sum(o1,o2);
}
