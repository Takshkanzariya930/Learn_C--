#include<iostream>
using namespace std;

int *carray(int s)
{
    int *arr = new int[s];
    return arr;
}

int main()
{
    int *arr ,s;

    cout<<"Enter size of array : ";
    cin>>s;

    arr = carray(s);

    for(int i=0;i<s;i++)
    {
        cout<<"Enter arr["<<i<<"] : ";
        cin>>arr[i];
    }

    for(int i=0;i<s;i++)
    {
        cout<<"\narr["<<i<<"] : "<<arr[i];
    }
}