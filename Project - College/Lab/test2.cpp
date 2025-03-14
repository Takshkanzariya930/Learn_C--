#include<iostream>
using namespace std;

class Area {

    float base,height,length,radius;

    public:

    float areaoftriangle(float base,float height)
    {
        return 0.5*base*height;
    }

    float areaofcircle(float radius)
    {
        return 3.14*radius*radius;
    }

    float areaofsquare(float length)
    {
        return length*length;
    }

};


int main()
{
    Area a1;

    int choice;
    float value1,value2;

    cout<<"Press 1 to calculate area of triangle";
    cout<<"\nPress 2 to calculate area of circle";
    cout<<"\nPress 3 to calculate area of square";
    cout<<"\nYour choice : ";
    cin>>choice;

    switch (choice)
    {
        case 1:

            cout<<"\nEnter base of triangle : ";
            cin>>value1;
            cout<<"\nEnter height of triangle : ";
            cin>>value2;

            cout<<"\nArea of traingle is : "<<a1.areaoftriangle(value1,value2);
            break;

        case 2:

            cout<<"\nEnter radius of circle : ";
            cin>>value1;

            cout<<"\nArea of circle is : "<<a1.areaofcircle(value1);
            break;

        case 3:

            cout<<"\nEnter length of square : ";
            cin>>value1;

            cout<<"\nArea of square is : "<<a1.areaofsquare(value1);
            break;

        default:
            cout<<"Invalid choice";
            break;
    }
}