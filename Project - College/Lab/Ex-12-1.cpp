#include <iostream>
using namespace std;

class Student
{
    protected:
    int roll_no;

    public:
    Student()
    {
        cout<<"Enter Roll No. : ";
        cin>>roll_no;
    }
};

class Test : protected Student
{
    protected:
    int marks[2];

    public:
    Test()
    {
        cout<<"\nEnter Marks of first subject : ";
        cin>>marks[0];

        cout<<"Enter Marks of second subject : ";
        cin>>marks[1];
    }
};

class Result : protected Test
{
    int total = marks[0] + marks[1];

    public:
    void display()
    {
        cout<<"\nRoll No. : "<<roll_no;
        cout<<"\nTotal Marks : "<<total;
    }
};

int main()
{
    Result s1;

    s1.display();
}