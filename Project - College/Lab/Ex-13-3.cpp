#include <iostream>
// #include <iomanip>
using namespace std;

int main() {
    double num = 123.456;

    cout<<"Using width(10): ";
    cout.width(10);
    cout<<num<<endl;

    cout<<"Using precision(2): ";
    cout.precision(2);
    cout<<fixed<<num<<endl;

    cout<<"Using fill('*') with width(10): ";
    cout.fill('*');
    cout.width(10);
    cout<<num<<endl;

    cout<<"Using setf(ios::showpoint) and setf(ios::fixed): ";
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout<<num<<endl;

    cout.unsetf(ios::fixed);
    cout.unsetf(ios::showpoint);
    cout<<"After unsetting flags, default output: "<<num<<endl;

}