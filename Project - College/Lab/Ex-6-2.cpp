#include<iostream>
#include<cstring>
using namespace std;

char* reverse(char *str , int count)
{
    char temp;

    for(int i=0;i<count/2;i++)
    {
        temp = str[i];
        str[i] = str[count-i-1];
        str[count-i-1] = temp;
    }

    return str;
}

int main()
{
    char *str;
    int count;

    cout<<"Enter no of character you want to store : ";
    cin>>count;
    cin.ignore();
    
    str = new char[count + 1];

    cout<<"Enter your string : ";
    cin.getline(str,count+1);

    cout<<"Original string : "<<str<<endl;

    str = reverse(str,count);

    cout<<"Reversed string : "<<str;

    delete[] str;
}