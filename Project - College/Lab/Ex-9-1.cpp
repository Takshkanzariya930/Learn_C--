#include<iostream>
using namespace std;

class Array
{
    int **arr;

    public:
    
    Array(int r,int c)
    {
        arr = new int*[r];

        for(int i=0;i<r;i++)
        {
            arr[i] = new int[c];
        }
    }
};