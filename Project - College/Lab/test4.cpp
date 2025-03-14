#include <iostream>
using namespace std;

class sptr {

    public:

    char *stringptr;

    void setpointer(char s1[])
    {
        stringptr = s1;
    }

    void display()
    {
        for(int i=0;i<stringptr[i] != '\0';i++)
        {
            cout<<*(stringptr + i);
        }
    }

};

int main()
{
    sptr obj1;

    char str1[100];

    cout<<"Enter String : ";
    cin.getline(str1,100);

    obj1.setpointer(str1);
    obj1.display();

}