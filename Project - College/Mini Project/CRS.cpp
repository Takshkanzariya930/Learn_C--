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
                cout<<left<<setw(34)<<setfill('-')<<"Customer ID : "<<" "<<fields[9]<<setfill(' ')<<endl;
                found = 1;
            }
        }
    
        car_ifile.close();

        if(found == 0)
            cout<<"\nCar NOT FOUND........................"<<endl;
    }

    static void Search_in_inventory_by_customerID(int ID)
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
    
            if(ID == stoi(fields[9]))
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
                cout<<left<<setw(34)<<setfill('-')<<"Customer ID : "<<" "<<fields[9]<<setfill(' ')<<endl;
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

    static void Change_availability(int ID,bool ava,int cus_ID = 0)
    {
        string lines[total_cars() + 1];
        string line;
        string fields[10];
        int i = 0;
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

    static void delete_car(int ID)
    {
        string lines[total_cars() + 1];
        string line;
        int i = 0;
        int noline = 1;
        
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
                fields[i] = token;
                i++;
            }
    
            if(ID == stoi(fields[0]))
            {
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
                continue;
            else
                car_ofile<<lines[j]<<endl;
        }
    
        car_ofile.close();
    }

};

class Customer
{
    int Customer_ID ;
    int Car_ID ;
    string Customer_license_no ;
    string Customer_Name ;
    string Customer_Address ;
    long int Customer_PhoneNo ;
    double Security_deposit ;
    int No_days ;
    bool active_service = 1 ;

    public:

    void set_data()
    {
        cout<<"Enter Customer ID : ";
        cin>>Customer_ID;

        getchar();
        cout<<"Enter Customer Name : ";
        getline(cin,Customer_Name);
        
        cout<<"Enter Customer License No. : ";
        getline(cin,Customer_license_no);;   

        cout<<"Enter Customer Address : ";
        getline(cin,Customer_Address);

        cout<<"Enter Customer Phone No. : ";
        cin>>Customer_PhoneNo ;

        cout<<"Enter Amount of Security deposit given by Customer : ";
        cin>>Security_deposit;

        cout<<"Enter Car ID which Customer rented : ";
        cin>>Car_ID;

        cout<<"Enter No. of days Customer rented a car : ";
        cin>>No_days;
    }

    void Register_to_database()
    {
        ofstream cus_ofile("customer_data.csv",ios_base::app);

        cus_ofile<<Customer_ID<<','<<Customer_Name<<','<<Customer_license_no<<','<<Customer_Address<<','
                 <<Customer_PhoneNo<<','<<Security_deposit<<','<<Car_ID<<','<<No_days<<','<<active_service<<endl;

        cus_ofile.close();

        Car::rent_a_car(Car_ID,Customer_ID);
    }

    static void search_in_database(int ID)
    {
        string line;
        int found = 0 ;
    
        ifstream cus_ifile("customer_data.csv");
    
        getline(cus_ifile,line);
    
        while(getline(cus_ifile,line))
        {
            stringstream ss(line);
            string fields[10];
            string token;
            int i = 0;
    
            while(getline(ss,token,',') && i<10)
            {
                fields[i] = token;
                i++;
            }
    
            if(ID == stoi(fields[0]))
            {
                cout<<left<<setw(28)<<setfill('-')<<"Customer ID : "<<" "<<fields[0]<<endl;
                cout<<left<<setw(28)<<"Customer Name : "<<" "<<fields[1]<<endl;
                cout<<left<<setw(28)<<"Customer License No. : "<<" "<<fields[2]<<endl;
                cout<<left<<setw(28)<<"Customer Address : "<<" "<<fields[3]<<endl;
                cout<<left<<setw(28)<<"Customer Phone No. : "<<" "<<fields[4]<<endl;
                cout<<left<<setw(28)<<"Security deposit : "<<" "<<fields[5]<<endl;
                cout<<left<<setw(28)<<"Car ID : "<<" "<<fields[6]<<endl;
                cout<<left<<setw(28)<<"Car rented for No. days : "<<" "<<fields[7]<<endl;
                cout<<left<<setw(28)<<"Active Customer : "<<" "<<replace(fields[8])<<setfill(' ')<<endl;
                found = 1;
            }
        }
    
        cus_ifile.close();
    
        if(found == 0)
            cout<<"Customer NOT found..................";
    }

    static void change_active_status_to_inactive(int ID)
    {
        string lines[total_customer() + 1];
        string line;
        bool found = 0;
        int i = 0;
        int noline = 1;

        ifstream cus_ifile("customer_data.csv");

        getline(cus_ifile,line);

        while(getline(cus_ifile,line))
        {
            int i = 0;
            stringstream ss(line);
            string token;
            string field[9];

            while(getline(ss,token,','))
            {
                field[i] = token;
                i++;
            }

            if(ID == stoi(field[0]))
            {
                field[8] = "0";
                
                line = field[0];

                for(int j=1;j<9;j++)
                {
                    line += ","+field[j];
                }

                found = 1;
                break;
            }

            noline++;
        }
        
        cus_ifile.close();

        if(found == 0)
        {
            cout<<"Customer NOT found..................."<<endl;
        }
        else
        {
            ifstream cus_irfile("customer_data.csv");

            while(getline(cus_irfile,lines[i])) {i++;}

            cus_irfile.close();

            ofstream cus_ofile("customer_data.csv");

            for(int j=0;j<i;j++)
            {
                if(j == noline)
                    cus_ofile<<line<<endl;
                else
                    cus_ofile<<lines[j]<<endl;
            }

            cus_ofile.close();
        }
        
    }

    static void active_customer()
    {
        string line;
        ifstream cus_ifile("customer_data.csv");

        cout<<"\n"<<left
        <<setw(6)<<"ID"
        <<setw(16)<<"Name"
        <<setw(16)<<"Licence No."
        <<setw(22)<<"Address"
        <<setw(16)<<"Phone No."
        <<setw(23)<<"Security Deposit"
        <<setw(15)<<"Car ID"
        <<setw(21)<<"No. Rental Days"<<endl;

        cout<<string(150,'-')<<endl;

        getline(cus_ifile,line);

        while(getline(cus_ifile,line))
        {
            stringstream ss(line);
            string fields[9];
            string token ;
            int i = 0;

            while(getline(ss,token,',') && i<9)
            {
                fields[i] = token;
                i++;
            }

            if(fields[8] == "1")
            {
                cout<<left
                    <<setw(6)<<fields[0]
                    <<setw(16)<<fields[1];

                cout<<left
                    <<setw(16)<<fields[2]
                    <<setw(22)<<fields[3]
                    <<setw(16)<<fields[4]
                    <<setw(23)<<fields[5]
                    <<setw(15)<<fields[6]
                    <<setw(21)<<fields[7]<<endl;   
            }
        }
        cus_ifile.close();
    }

    static int total_customer()
    {
        int t_customer = -1;
        string line;
    
        ifstream cus_ifile("customer_data.csv");
    
        while (getline(cus_ifile,line))
        {
            t_customer++;
        }
    
        fill(line.begin(), line.end(), '\0');
    
        cus_ifile.close();
        return t_customer;
    }
};

int main()
{
    Car car1;
    Customer cus1;

    string cchoice ;
    int choice = 0;
    int temp;
    bool tof;

    cout<<"Car Rental System"<<endl;

    cout<<"\n"<<left<<setw(10)<<"Press"<<setw(10)<<"Action"<<endl;
    
    cout<<string(30,'-')<<setfill('-')<<endl; 
    
    cout<<"\n"<<left<<setfill('-')<<setw(10)<<"1  "<<setw(10)<<" Add Car to Inventory"<<endl;
    cout<<left<<setw(10)<<"2  "<<setw(10)<<" Search Car in Inventory (By Car ID)"<<endl;
    cout<<left<<setw(10)<<"3  "<<setw(10)<<" Search Car in Inventory (By Customer ID)"<<endl;
    cout<<left<<setw(10)<<"4  "<<setw(10)<<" Check Availability of Car"<<endl;
    cout<<left<<setw(10)<<"5  "<<setw(10)<<" Change Availability of Car"<<endl;
    cout<<left<<setw(10)<<"6  "<<setw(10)<<" List out Available Cars"<<endl;
    cout<<left<<setw(10)<<"7  "<<setw(10)<<" Delete Car from Inventory"<<endl;
    cout<<left<<setw(10)<<"8  "<<setw(10)<<" Add Customer To Database and Rent a Car"<<endl;
    cout<<left<<setw(10)<<"9  "<<setw(10)<<" Search Customer in Database (By Customer ID)"<<endl;
    cout<<left<<setw(10)<<"10 "<<setw(10)<<" Change Active service to Inactive of an Customer"<<endl;
    cout<<left<<setw(10)<<"11 "<<setw(10)<<" List out Active Customer"<<endl;
    cout<<left<<setw(10)<<"99 "<<setw(10)<<" To EXIT PROGRAM"<<setfill(' ')<<endl;
    
    while(true)
    {
        cout<<"\n--> Enter your choice : "; cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"\nAdd Car to Inventory :-"<<endl;
                car1.set_data();
                car1.Register_to_inventory();
                break;

            case 2:
                cout<<"\nSearch Car in Inventory (By Car ID) :-"<<endl;

                cout<<"\nEnter Car ID to search from inventory : ";
                cin>>temp;
                cout<<endl;

                Car::Search_in_inventory_by_carID(temp);
                break;

            case 3:
                cout<<"\nSearch Car in Inventory (By Customer ID) :-"<<endl;

                cout<<"\nEnter Customer ID to search from inventory : ";
                cin>>temp;
                cout<<endl;

                Car::Search_in_inventory_by_customerID(temp);
                break;

            case 4:
                cout<<"\nCheck Availability of Car :-"<<endl;

                cout<<"\nEnter Car ID to check availability : ";
                cin>>temp;
                cout<<endl;

                if(Car::check_availability(temp) == true)
                    cout<<"--> Car "<<temp<<" is AVAILABLE for Rental.";
                else
                    cout<<"--> Car "<<temp<<" is NOT AVAILABLE for Rental.";

                break;

            case 5:
                cout<<"\nChange Availability of Car :-"<<endl;

                cout<<"\nEnter Car ID to Change Availability : ";
                cin>>temp;

                cout<<"Enter '1' to change status to available and '2' to NOT available : ";
                cin>>tof;

                Car::Change_availability(temp,tof);
                break;
            
            case 6:
                cout<<"\nList out Available Cars :-"<<endl;

                Car::Available_cars();
                break;

            case 7:
                cout<<"\nDelete Car from Inventory :-"<<endl;

                cout<<"\nEnter Car ID which you want to delete : ";
                cin>>temp;

                Car::delete_car(temp);

                cout<<"\nDELETED Car with ID "<<temp<<" from inventory...";

                break;

            case 8:
                cout<<"\nAdd Customer To Database and Rent a Car :-"<<endl;

                cus1.set_data();
                cus1.Register_to_database();

                break;

            case 9:
                cout<<"\nSearch Customer in Database (By Customer ID) :-"<<endl;
                
                cout<<"Enter Customer ID which you want to search : ";
                cin>>temp;
                
                Customer::search_in_database(temp);
                
                break;
                
            case 10:
                cout<<"\nChange Active service to Inactive of an Customer :-"<<endl;
                
                cout<<"Enter Customer ID which you want to change service status : ";
                cin>>temp;
                
                Customer::change_active_status_to_inactive(temp);

                cout<<"\nChanged service status to in inactive for "<<temp<<" .";
                
                break;

            case 11:
                cout<<"\nList out Active Customer :-"<<endl;

                Customer::active_customer();
                break;

                
                
            default :
                cout<<"\n................... Incorrect choice please try again ................";
                break;
        }

        cout<<"\n\n"<<string(150,'-')<<endl;
        cout<<"\n--> Press 'Y' to continue : "; cin>>cchoice;

        if(cchoice != "Y" || cchoice != "y" || cchoice != " Y" || cchoice != " y") 
            break;

    }

    cout<<"\nEXITED program..............................";
}