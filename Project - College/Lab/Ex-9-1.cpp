#include<iostream>
using namespace std;

class Array
{
    int **arr;
    int row;
    int col;

    public:
     
    Array(int r,int c)
    {
        row = r;
        col = c;

        arr = new int*[r];

        for(int i=0;i<r;i++)
        {
            arr[i] = new int[c];
        }
    }

    void setvalues()
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cout<<"Enter Value of arr["<<i<<"]["<<j<<"] : ";
                cin>>arr[i][j];
            }
        }
    }

    void getvalues()
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cout<<"\nValue of arr["<<i<<"]["<<j<<"] : "<<arr[i][j];
            }
        }
    }

    ~Array()
    {
        for(int i=0;i<row;i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
};

int main()
{
    Array a1(3,4);

    a1.setvalues();
    a1.getvalues();

}