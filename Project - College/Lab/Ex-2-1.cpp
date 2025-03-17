#include<iostream>
using namespace std;

void swap(int *n1,int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int main()
{
    int a,b,c;

    cout<<"Enter numbers : ";
    cin>>a>>b>>c;

    if(a>b)
        swap(&a,&b);
        
    if(b>c)
        swap(&b,&c);

    cout<<c<<" is the greatest.";

}