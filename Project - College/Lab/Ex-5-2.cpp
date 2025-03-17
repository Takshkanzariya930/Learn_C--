#include<iostream>
using namespace std;

double *creating_vector(int m)
{
    double *vector = new double[m];

    for(int i=0;i<m;i++)
    {
        cout<<"Enter "<<i+1<<" element : ";
        cin>>vector[i];
    }

    return vector;
}

int main()
{
    double *vector,m;

    cout<<"\nEnter size of vector : ";
    cin>>m;

    vector = creating_vector(m);

    for(int i=0;i<m;i++)
    {
        cout<<"\n"<<i+1<<" element : "<<vector[i];
    }

    delete[] vector;
}