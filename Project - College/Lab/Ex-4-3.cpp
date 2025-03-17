#include<iostream>
using namespace std;

class Temperature
{
    public:

    double convert(double temp)
    {
        return ((temp - 32)*(5.0/9.0));
    }
};

int main()
{
    Temperature obj1;
    double fahrenheit,celsius;

    cout<<"Enter temperature in fahrenheit : ";
    cin>>fahrenheit;

    celsius = obj1.convert(fahrenheit);

    cout<<fahrenheit<<" Fahrenheit is "<<celsius<<" Celsius";

}