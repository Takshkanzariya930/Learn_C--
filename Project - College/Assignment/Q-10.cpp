#include <iostream>
using namespace std;

class Employee 
{
    string emp_name;
    int emp_id;

    public:
    void set_data()
    {
        cout<<"Enter Employee ID : ";
        cin>>emp_id;

        getchar();
        cout<<"Enter Employee Name : ";
        getline(cin,emp_name);
    }

    void get_data()
    {
        cout<<"\nEmployee Number : "<<emp_id<<endl;
        cout<<"Employee Name : "<<emp_name<<endl;
    }
};

class Salary : public Employee
{
    double salary;

    public:
    void calculate_salary()
    {
        double basic_pay,HRA,DA;

        cout<<"\nEnter Basic Pay : ";
        cin>>basic_pay;
        
        cout<<"Enter HRA : ";
        cin>>HRA;

        cout<<"Enter DA : ";
        cin>>DA;

        salary = basic_pay + HRA + DA ;
    }

    void display_salary()
    {
        cout<<"Employee Salary : "<<salary<<endl;
    }
};

int main()
{
    Salary emp;

    emp.set_data();
    emp.calculate_salary();
    emp.get_data();
    emp.display_salary();
}