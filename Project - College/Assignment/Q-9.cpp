#include <iostream>
#include <iomanip>
using namespace std;

class Matrix
{
    double mat[3][3];

    public:
    void setdata()
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<"Enter ["<<i<<"] ["<<j<<"] : ";
                cin>>mat[i][j];
            }
        }
    }

    void getdata()
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<setw(6)<<mat[i][j];
            }
            cout<<"\n";
        }
    }

    Matrix add(Matrix &obj)
    {
        Matrix temp;

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                temp.mat[i][j] = mat[i][j] + obj.mat[i][j] ;
            }
        }

        return temp;
    }
    
    Matrix multi(Matrix &obj)
    {
        Matrix temp;
        
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                temp.mat[i][j] = 0;
                
                for(int k=0;k<3;k++)
                {
                    temp.mat[i][j] += mat[i][k] * obj.mat[k][j] ;
                }
            }
        }

        return temp;
    }
    
    
};

int main()
{
    Matrix m1,m2,add,multi;

    cout<<"Enter m1 : \n";
    m1.setdata();
    cout<<"\nEnter m2 : \n";
    m2.setdata();
    
    cout<<"\nm1 : "<<endl;
    m1.getdata();
    cout<<"\nm2 : "<<endl;
    m2.getdata();

    cout<<"\nAddition of m1 and m2 :"<<endl;

    add = m1.add(m2);
    add.getdata();

    cout<<"\nMultiplication of m1 and m2 :"<<endl;

    multi = m1.multi(m2);
    multi.getdata();
}
