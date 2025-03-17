#include<iostream>
#include<cstring>
using namespace std;

class Account
{
    string depositor_name;
    long long int account_number;
    string account_type;
    double account_balance;

    public:

    void setdata(const string ac_name,long long int ac_no,string ac_type,double ac_balance)
    {
        depositor_name = ac_name;
        account_number = ac_no;
        account_type = ac_type;
        account_balance = ac_balance;
    }

    void deposit(double amount)
    {
        account_balance += amount;
        cout<<"\n"<<amount<<" has been deposited and your current balance is "<<account_balance;
    }

    void withdraw(double amount)
    {
        if(amount <= account_balance)
        {
            account_balance -= amount;
            cout<<"\n"<<amount<<" has been withdrawn and your current balance is "<<account_balance;
        }
        else
        {
            cout<<"\nInvalid Request because....";
            cout<<"\nYour current balance is "<<account_balance;
        }
    }

    void display()
    {
        cout<<"\nAccount details.................................";
        cout<<"\nName : "<<depositor_name;
        cout<<"\nAccount Number : "<<account_number;
        cout<<"\nAccount Type : "<<account_type;
        cout<<"\nAccount Balance : "<<account_balance;
        cout<<"\n................................................\n";
    }
};

int main()
{
    Account acc1;

    acc1.setdata("Rakesh Sharma",24123315551,"saving",123000.00);
    acc1.display();
    acc1.deposit(3000.50);
    acc1.withdraw(25000);
}