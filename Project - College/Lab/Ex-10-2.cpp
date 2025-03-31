#include<iostream>
using namespace std;

class Array
{
    int *arr;
    int size;

    public:
    Array(int s)
    {
        size = s;
        arr = new int[size];

        for(int i=0;i<size;i++)
        {
            cout<<"Enter "<<i<<" element of arr : ";
            cin>>arr[i];
        }
    }

    int operator[] (int i)
    {
        if(i>=size)
        {
            cout<<"Index out of bound.....";
            return 0;
        }
        else
        {
            return arr[i];
        }
    }

};

int main()
{
    Array arr1(5);

    cout<<"Value of arr1[0] : "<<arr1[0]<<endl;
    cout<<"Value of arr1[1] : "<<arr1[1]<<endl;
    cout<<"Value of arr1[2] : "<<arr1[2]<<endl;
    cout<<"Value of arr1[3] : "<<arr1[3]<<endl;
    cout<<"Value of arr1[4] : "<<arr1[4]<<endl;
    cout<<"Value of arr1[5] : "<<arr1[5]<<endl;
}