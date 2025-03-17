#include<iostream>
#include<cstring>
using namespace std;

class Class1
{
    char *name;
    
    public:

    Class1(char str[])
    {
        name = new char[strlen(str)];
        name = str;
    }

    void display()
    {
        cout<<name;
    }

    ~Class1()
    {
        delete[] name;
    }
};

int main()
{
    Class1 obj1("Hello");

    obj1.display();
}