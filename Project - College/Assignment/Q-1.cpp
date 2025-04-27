#include<iostream>
using namespace std;

class DISTANCE
{
    double feet,inches;
    
    public:

    void setdata(double f,double i)
    {
        feet = f;
        inches = i;
    }

    void display()
    {
        cout<<"\nDistance : "<<feet<<" feet and "<<inches<<" inches";
    }

    DISTANCE sum(DISTANCE &obj1,DISTANCE &obj2)
    {
        DISTANCE temp;
        temp.feet = obj1.feet + obj2.feet;
        temp.inches = obj1.inches + obj2.inches;

        if(temp.inches > 12)
        {
            temp.feet = temp.feet + (int(temp.inches)/12);

            temp.inches = int(temp.inches)%12 + (temp.inches - int(temp.inches));
        }

        return temp;
    }

};

int main()
{
    DISTANCE obj1,obj2,result;

    obj1.setdata(12.32,7.6);
    obj2.setdata(2.32,6.3);

    result = result.sum(obj1,obj2);
    result.display();
}