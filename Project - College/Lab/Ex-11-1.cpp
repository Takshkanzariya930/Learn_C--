#include<iostream>
using namespace std;

class Person
{
    public:

    string name;
    int age;

    Person (string n,int a)
    {
        name = n;
        age = a;
    }

    void display()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
    }
};

class Employee
{
    string name;
    int age;
    int emp_id;
    
    public:
    Employee(string n,int a,int eid)
    {
        name = n;
        age = a;
        emp_id = eid;
    }

    Employee(Person &obj,int eid)
    {
        name = obj.name;
        age = obj.age;
        emp_id = eid;
    }

    void display()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"Employee ID : "<<emp_id<<endl;
    }
};

int main()
{
    Person p1("Alex",32);
    Employee e1(p1,3213);

    p1.display();
    e1.display();

}
