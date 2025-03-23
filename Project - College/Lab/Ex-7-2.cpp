#include<iostream>
using namespace std;

class Employee
{
    string e_name;
    int e_id;
    
    public:

    void setdata()
    {
        cout<<"Enter Name of Employee : ";
        cin>>e_name;

        cout<<"Enter Employee ID : ";
        cin>>e_id;
    }

    void getdata()
    {
        cout<<"Name : "<<e_name<<endl;
        cout<<"ID : "<<e_id<<endl;
    }

};

int main()
{
    Employee emp[4];

    for(int i=0;i<4;i++)
    {
        emp[i].setdata();
    }

    for(int i=0;i<4;i++)
    {
        emp[i].getdata();
    }
}