#include<iostream>
using namespace std;

class Sample
{
    int a,b;

    public:

    Sample(int n1,int n2)
    {
        a = n1;
        b = n2;
    }

    friend void calculatemean(Sample &obj);
};

void calculatemean(Sample &obj)
{
    cout<<"Mean is : "<<double(obj.a+obj.b)/2;
}

int main()
{
    Sample s1(21,3);

    calculatemean(s1);
}