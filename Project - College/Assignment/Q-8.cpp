#include <iostream>
using namespace std;

class DB
{
    public:
    double feet,inch;

    void setdata()
    {
        cout<<"Enter Feet and Inch : ";
        cin>>feet>>inch;
    }

    void getdata()
    {
        cout<<feet<<" Feet and "<<inch<<" Inches"<<endl;
    }

    // void add(DM &obj)
    // {
    //   double temp = (obj.meter*100 + obj.centimeter) * 0.39 ;

    //   feet += int((temp - int(temp)%12)/12);
    //   inch += int(temp)%12 + temp - int(temp);
    // }
};

class DM
{
    public:
    double meter,centimeter;

    void setdata()
    {
        cout<<"Enter Meter and Centimeter : ";
        cin>>meter>>centimeter;
    }

    void getdata()
    {
        cout<<meter<<" Meters and "<<centimeter<<" Centimeter"<<endl;
    }

    void add(DB &obj)
    {
        double temp = (meter *100) + centimeter ;

        temp += (obj.feet*12 + obj.inch) * 2.54 ;

        meter = int(temp/100) ;

        // centimeter = int(temp)%100 + temp - int(temp);
        centimeter = temp - (meter*100);
    }
};

int main()
{
    DM obj1;
    DB obj2;

    obj1.setdata();
    obj1.getdata();

    obj2.setdata();
    obj2.getdata();

    cout<<"\nAdded obj2 in obj1 : ";
    obj1.add(obj2);
    obj1.getdata();
}