#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    int noitems = 3 ;
    string itemname[noitems];
    int itemcode[noitems];
    double itemcost[noitems];

    for(int i = 0;i < noitems;i++)
    {
        cout<<"Item "<<i+1<<" : "<<endl;
        cout<<"Enter Item name : ";
        cin>>itemname[i];

        cout<<"Enter Item code : ";
        cin>>itemcode[i];

        cout<<"Enter Item cost : ";
        cin>>itemcost[i];
    }

    cout<<"\nList of Items ....................\n"<<endl;
    
    cout<<left
        <<setw(15)<<"NAME"
        <<setw(10)<<"CODE"
        <<setw(10)<<"COST"<<endl;

    cout<<string(60,'-')<<endl;

    for(int i = 0;i<noitems;i++)
    {
        cout<<left
            <<setw(15)<<itemname[i]
            <<setw(10)<<itemcode[i]
            <<setw(10)<<itemcost[i]<<endl;
    }

        
}
