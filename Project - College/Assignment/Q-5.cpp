#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    double x,y;

    public:

    void setdata()
    {
        cout<<"Enter X : ";
        cin>>x;
        
        cout<<"Enter Y : ";
        cin>>y;
    }

    void getdata()
    {
        cout<<"X : "<<x<<" and Y : "<<y<<endl;
    }

    double euclidean_distance(Point &obj1)
    {
        return sqrt(((obj1.x - x)*(obj1.x - x) + ((obj1.y - y)*(obj1.y-y))));
    }
};

int main()
{
    Point P,Q ;

    P.setdata();
    Q.setdata();

    cout<<"\nP -> ";
    P.getdata();
    cout<<"Q -> ";
    Q.getdata();

    cout<<"\nEuclidean distance between P and Q is "<<P.euclidean_distance(Q);
}