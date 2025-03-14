#include<iostream>
using namespace std;

class Person {

    protected:

    int age;
    char name[50];

    public:

    void getdata()
    {
        cout<<"Name : "<<name;
        cout<<"\nAge : "<<age;
    }

    void setdata()
    {
        cout<<"Name : ";
        cin>>name;

        cout<<"Age : ";
        cin>>age;
    }
};

class Sportsman : public Person {

    char sports[50];

    public:

    void getdata()
    {
        cout<<"Name : "<<name;
        cout<<"\nAge : "<<age;
        cout<<"\nSports : "<<sports;

    }

    void setdata()
    {
        cout<<"Name : ";
        cin>>name;

        cout<<"Age : ";
        cin>>age;

        cout<<"Sports : ";
        cin>>sports;
    }

};

int main()
{
    Sportsman s1;

    s1.setdata();
    cout<<"\n";
    s1.getdata();

}
