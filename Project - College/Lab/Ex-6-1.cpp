#include<iostream>
using namespace std;

void power(int m,int n)
{
    int result=1;

    for(int i=0;i<n;i++)
    {
        result = result*m;
    }

    cout<<"iResult : "<<result;
}

void power(double m,int n)
{
    double result=1;
    
    for(int i=0;i<n;i++)
    {
        result = result*m;
    }
    
    cout<<"\ndResult : "<<result;
}

int main()
{
    power(12,5);
    power(12.32,5);
}