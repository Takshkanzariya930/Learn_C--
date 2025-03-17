#include <iostream>
using namespace std;

class employee {

    char e_name[100];
    int e_num ;
    float e_salary;
    
    public:
    void getinfo()
    {
        cout<<"Enter Name of employee : ";
        cin.getline(e_name,100);
        
        cout<<"Enter Number of employee : ";
        cin>>e_num;
        
        cout<<"Enter salary of employee : ";
        cin>>e_salary; 
    }

    void printinfo()
    {
        cout<<"---------------------------"<<endl;
        cout<<"Name : "<<e_name<<endl;
        cout<<"No. : "<<e_num<<endl;
        cout<<"Salary : "<<e_salary<<"\n";
        cout<<"---------------------------"<<endl;
    }

};

int main()
{
    employee e[5];

    for(int i = 0;i<5;i++)
    {
        e[i].getinfo();
        e[i].printinfo();
        getchar();
    }

}