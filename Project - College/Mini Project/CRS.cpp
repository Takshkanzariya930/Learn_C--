#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

inline string replace(string s)
{
    if(s == "1")
        return "true";
    else
        return "false";
}

class Car
{
    int Car_ID ;
    string Car_Model ;
    int Number_of_seats ;
    int Number_of_child_seats ;
    bool Availability_of_GPS ;
    bool Availability_of_AC ;
    string Tranmission ;
    bool Car_availability = 1 ;
    double Rental_cost ;
    int Customer_ID = 0 ;

    public:

    void set_data()
    {
        string temp;

        cout<<"Enter Car ID : ";
        cin>>Car_ID;

        getchar();
        cout<<"Enter Car Model : ";
        getline(cin,Car_Model);

        cout<<"Enter Type of Transmission (Manual or Automatic) : ";
        cin>>Tranmission;
        
        cout<<"Enter Number of Seats in Car : ";
        cin>>Number_of_seats;

        cout<<"Enter Number of CHILD Seats in Car : ";
        cin>>Number_of_child_seats;

        cout<<"Enter Availability of GPS (true or false) : ";
        cin>>temp;
        
        if(temp == "true")
            Availability_of_GPS = 1 ;
        else
            Availability_of_GPS = 0 ;
            
        cout<<"Enter Availability of AC (true or false) : ";
        cin>>temp;

        if(temp == "true")
            Availability_of_AC = 1 ;
        else 
            Availability_of_AC = 0 ;

        cout<<"Enter Cost of rental per Day : ";
        cin>>Rental_cost;
    }

    void Register_to_inventory()
    {
        ofstream car_ofile("car_data.csv",ios_base::app);

        car_ofile <<Car_ID<<',' <<Car_Model<<',' <<Tranmission<<',' <<Number_of_seats<<',' <<Number_of_child_seats<<','
                  <<Availability_of_GPS<<',' <<Availability_of_AC<<',' <<Car_availability<<',' <<Rental_cost<<','<<Customer_ID<<endl;

        car_ofile.close();
    }

    static void Search_in_inventory(int ID)
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
                cout<<"Car ID : "<<fields[0]<<endl;
                cout<<"Car Model : "<<fields[1]<<endl;
                cout<<"Type of Transmission : "<<fields[2]<<endl;            
                cout<<"Number of Seats in Car : "<<fields[3]<<endl;
                cout<<"Number of CHILD Seats in Car : "<<fields[4]<<endl;
                cout<<"Availability of GPS : "<<replace(fields[5])<<endl;              
                cout<<"Availability of AC : "<<replace(fields[6])<<endl;            
                cout<<"Availability of Car : "<<replace(fields[7])<<endl;            
                cout<<"Cost of rental per Day : "<<fields[8]<<endl;
                cout<<"Customer ID : "<<fields[9]<<endl;
                found = 1;
            }
        }
    
        car_ifile.close();

        if(found == 0)
            cout<<"\nCar NOT FOUND........................"<<endl;
    }

    static bool check_availability(int ID)
    {
        string line;
        ifstream car_ifile("car_data.csv");

        getline(car_ifile,line);

        while(getline(car_ifile,line))
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
                if(fields[7] == "1")
                    car_ifile.close();
                    return true;
            }
        }
        car_ifile.close();
        return false;
    }

    static void Change_availability(int ID,int ava,int cus_ID = 0)
    {
        int i = 0;
        string lines[total_cars() + 1];
        string line;
        string fields[10];
        int noline = 1;

        ifstream car_ifile("car_data.csv");
        getline(car_ifile,line);

        while(getline(car_ifile,line))
        {
            stringstream ss(line);
            string token;
            int i = 0;

            while(getline(ss,token,',') && i<10)
            {
                fields[i] = token;
                i++;
            }

            if(ID == stoi(fields[0]))
            {
                if(ava == 0)
                    fields[7] = to_string(0);
                else
                    fields[7] = to_string(1);

                fields[9] = to_string(cus_ID);
                break;
            }

            noline++;
        }
        car_ifile.close();

        ifstream car_irfile("car_data.csv");

        while(getline(car_irfile,lines[i])) {i++;}

        car_irfile.close();

        ofstream car_ofile("car_data.csv");

        for(int j = 0;j<i;j++)
        {
            if(j==noline)
                car_ofile <<fields[0]<<',' <<fields[1]<<',' <<fields[2]<<',' <<fields[3]<<',' <<fields[4]<<','
                <<fields[5]<<',' <<fields[6]<<',' <<fields[7]<<',' <<fields[8]<<','<<fields[9]<<endl;
            else
                car_ofile<<lines[j]<<endl;
        }

        car_ofile.close();
    }

    static void rent_a_car(int car_ID,int customer_ID)
    {
        if(check_availability(car_ID))
            Change_availability(car_ID,0,customer_ID);

        else
            cout<<"\nCar is NOT available for Rental.........................";
    }

    static int total_cars()
    {
        int t_cars = -1;
        string line;
    
        ifstream car_ifile("car_data.csv");
    
        while (car_ifile.eof() == 0)
        {
            getline(car_ifile,line);
            t_cars++;
        }
    
        fill(line.begin(), line.end(), '\0');
    
        car_ifile.close();
        return t_cars;
    }

    static int total_available_cars()
    {
        int ta_car = 0;
        string line; 

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

            if(fields[7] == "1")
                ta_car ++ ;
        }

        car_ifile.close();
        return ta_car;
    }

    static void Available_cars()
    {
        string line;
        ifstream car_ifile("car_data.csv");
    
        cout<<"List of AVAILABLE cars............"<<endl;
    
        cout<<"\n"<<left
            <<setw(6)<<"ID"
            <<setw(16)<<"Model"
            <<setw(16)<<"Transmission"
            <<setw(16)<<"No. of Seats"
            <<setw(22)<<"No. of Child Seats"
            <<setw(23)<<"Availability of GPS"
            <<setw(22)<<"Availability of AC"
            <<setw(21)<<"Rental Cost(Per Day)"<<endl;
    
        cout<<string(150,'-')<<endl;
    
        getline(car_ifile,line);
    
        while(getline(car_ifile,line))
        {
            stringstream ss(line);
            string fields[10];
            string tokens;
            int i = 0;
    
            while(getline(ss,tokens,',') && i<10)
            {
                fields[i] = tokens;
                i++;
            }
    
            if(fields[7] == "1")
            {
                cout<<left
                    <<setw(6)<<fields[0]
                    <<setw(16)<<fields[1];
    
                cout<<left
                    <<setw(16)<<fields[2]
                    <<setw(16)<<fields[3]
                    <<setw(22)<<fields[4]
                    <<setw(23)<<replace(fields[5])
                    <<setw(22)<<replace(fields[6])
                    <<setw(21)<<fields[8]<<endl;
            }
        }
        car_ifile.close();
    }

};

class Customer : public Car
{
    
};


int main()
{
    
}