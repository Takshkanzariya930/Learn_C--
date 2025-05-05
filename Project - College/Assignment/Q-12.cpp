#include <iostream>
using namespace std;

class Employee 
{
    string emp_name;
    int emp_id;

    public:
    void set_data()
    {
        cout<<"\nEnter Employee ID : ";
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

    virtual void calculateSalary() = 0;

    virtual void display_salary() = 0; 
};

class FullTimeEmployee : public Employee
{
    double salary;

    public:
    void calculateSalary() override
    {
        double basic_pay,HRA,DA;

        cout<<"Enter Basic Pay : ";
        cin>>basic_pay;
        
        cout<<"Enter HRA : ";
        cin>>HRA;

        cout<<"Enter DA : ";
        cin>>DA;

        salary = basic_pay + HRA + DA ;
    }

    void display_salary() override
    {
        cout<<"Employee Salary : "<<salary<<endl;
    }
};

class PartTimeEmployee : public Employee
{
    double salary;
    double hour_worked;

    public:
    void calculateSalary() override
    {
        double hourly_wage;

        cout<<"Enter Hourly Wage of Part time employee : ";
        cin>>hourly_wage;

        cout<<"Enter No. of Hours employee Worked for : ";
        cin>>hour_worked;

        salary = hour_worked * hourly_wage;
    }

    void display_salary() override
    {
        cout<<"Employee Salary : "<<salary<<endl;
    }
};

int main()
{
    Employee *ptr;

    cout<<"FullTimeEmployee :-"<<endl;
    ptr = new FullTimeEmployee ;
    ptr->set_data();
    ptr->calculateSalary();
    ptr->get_data();
    ptr->display_salary();
    
    cout<<"\nPartTimeEmployee :-"<<endl;
    ptr = new PartTimeEmployee ;
    ptr->set_data();
    ptr->calculateSalary();
    ptr->get_data();
    ptr->display_salary();

    delete ptr;
}