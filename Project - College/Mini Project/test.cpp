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

int total_cars()
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


int main()
{
    Change_availability(3456,0);
}
