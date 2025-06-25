#include <iostream>
using namespace std;

void increment(int *x)
{
    (*x)++;
    cout<<"Inside the function : "<<*x<<endl;
}

int main()
{
    int a = 5;

    increment(&a);

    cout<<"Outside the function : "<<a;

}
