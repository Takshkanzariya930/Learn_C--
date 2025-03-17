#include<iostream>
using namespace std;

class arithmetic
{
    public:

    double add(double a,double b)
    {
        return a+b;
    }

    double sub(double a,double b)
    {
        return a-b;
    }
    double multi(double a,double b)
    {
        return a*b;
    }
    double div(double a,double b)
    {    
        return a/b;
    }
};

int main()
{
    arithmetic obj;
    double num1,num2;

    cout<<"Enter num1 : "<<endl;
    cin>>num1;
    cout<<"Enter num2 : ";
    cin>>num2;

    cout<<"Addition of "<<num1<<" and "<<num2<<" is "<<obj.add(num1,num2)<<endl;
    cout<<"Subtraction of "<<num1<<" and "<<num2<<" is "<<obj.sub(num1,num2)<<endl;
    cout<<"Multiplication of "<<num1<<" and "<<num2<<" is "<<obj.multi(num1,num2)<<endl;
    cout<<"Division of "<<num1<<" and "<<num2<<" is "<<obj.div(num1,num2)<<endl;
}