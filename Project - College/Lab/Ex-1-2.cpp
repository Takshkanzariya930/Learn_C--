#include<iostream>
using namespace std;

class student
{
    char name[20];
    int age;

    public:
    
    void setdata()
    {
        cout<<"Enter Name : ";
        cin.getline(name,20);
        cout<<"Enter age : ";
        cin>>age;
    }

    void getdata()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age;
    }

};

int main()
{
    student obj1;

    obj1.setdata();
    obj1.getdata();
}