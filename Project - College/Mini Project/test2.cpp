#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

inline string replace(string s)
{
    if(s == "1")
        return "true";
    else
        return "false";
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
            cout<<left<<setw(28)<<"Active Customer : "<<" "<<replace(fields[8])<<endl;
            found = 1;
        }
    }

    cus_ifile.close();

    if(found == 0)
        cout<<"Customer NOT found..................";
}

int main()
{
    search_in_database(7341);
}