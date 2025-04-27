#include <iostream>
using namespace std;

double volume(double l)
{
    return l*l*l;
}

double volume(double r,double h)
{
    return 3.14*r*r*h;
}

double volume(double l,double b,double h)
{
    return l*b*h;
}


int main()
{
    cout<<"Volume of Cube : "<<volume(3.1)<<endl;
    cout<<"Volume of Cylinder : "<<volume(3.1,6.1)<<endl;
    cout<<"Volume of Cuboid : "<<volume(3.1,4.1,5.1);
}