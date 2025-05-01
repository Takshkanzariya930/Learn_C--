#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

inline string replace(string s)
{
    if(s == "1")
        return "true";
    else
        return "false";
}

static void Search_in_inventory_by_carID(int ID)
{ 
    string line; 
    bool found = false;

    ifstream car_ifile("car_data.csv");

    getline(car_ifile,line);

    while (getline(car_ifile,line))
    {
        stringstream ss(line);
        string fields[10];
        string token;
        int i = 0;

        while(getline(ss,token,',') && i<10)
        {
            fields[i] = token ;
            i++;
        }

        if(ID == stoi(fields[0]))
        {
            cout<<left<<setw(34)<<setfill('-')<<"Car ID : "<<" "<<fields[0]<<endl;
            cout<<left<<setw(34)<<setfill('-')<<"Car Model : "<<" "<<fields[1]<<endl;
            cout<<left<<setw(34)<<setfill('-')<<"Type of Transmission : "<<" "<<fields[2]<<endl;            
            cout<<left<<setw(34)<<setfill('-')<<"Number of Seats in Car : "<<" "<<fields[3]<<endl;
            cout<<left<<setw(34)<<setfill('-')<<"Number of CHILD Seats in Car : "<<" "<<fields[4]<<endl;
            cout<<left<<setw(34)<<setfill('-')<<"Availability of GPS : "<<" "<<replace(fields[5])<<endl;              
            cout<<left<<setw(34)<<setfill('-')<<"Availability of AC : "<<" "<<replace(fields[6])<<endl;            
            cout<<left<<setw(34)<<setfill('-')<<"Availability of Car : "<<" "<<replace(fields[7])<<endl;            
            cout<<left<<setw(34)<<setfill('-')<<"Cost of rental per Day : "<<" "<<fields[8]<<endl;
            cout<<left<<setw(34)<<setfill('-')<<"Customer ID : "<<" "<<fields[9]<<endl;
            found = 1;
        }
    }

    car_ifile.close();

    if(found == 0)
        cout<<"\nCar NOT FOUND........................"<<endl;
}

int main()
{
    Search_in_inventory_by_carID(4356);
}
