#include<iostream>
using namespace std;

class student
{
    char name[20];
    int age;
    static int count;
    public:
    
    void setdata()
    {
        cout<<"Enter Name : ";
        cin.getline(name,20);
        cout<<"Enter age : ";
        cin>>age;
        count++;
    }

    void getdata()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
    }

    static void showcount()
    {
        cout<<"No of students are : "<<count;
    }
};

int student::count;

int main()
{
    student obj1,obj2;

    obj1.setdata();
    obj1.getdata();
    student::showcount();
    cin.ignore();
    
    obj2.setdata();
    obj2.getdata();
    student::showcount();

}