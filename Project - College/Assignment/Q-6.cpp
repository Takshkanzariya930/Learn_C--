#include <iostream>
using namespace std;

class EMPLOYEE
{
    int emp_no;
    string emp_name;
    double basic,da,net_salary;

    public:
    void setdata()
    {
        cout<<"Enter Employee Number : ";
        cin>>emp_no;

        getchar();
        cout<<"Enter Employee Name : ";
        getline(cin,emp_name);

        cout<<"Enter Basic salary : ";
        cin>>basic;

        cout<<"Enter DA : ";
        cin>>da;

        net_salary = basic + da ;
    }

    void getdata()
    {
        cout<<"\nEmployee Number : "<<emp_no<<endl;
        cout<<"Employee Name : "<<emp_name<<endl;
        cout<<"Net salary : "<<net_salary<<endl;
    }
};

int main()
{
    EMPLOYEE e1;

    e1.setdata();
    e1.getdata();
}
