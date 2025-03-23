#include<iostream>
#include<cstring>
using namespace std;

class String
{
    char *str;

    public:
    String(char s[] = "")
    {
        str = new char[strlen(s)];
    }

    String operator +(String &obj)
    {
        String temp;

        int lstr = strlen(str) ,lostr = strlen(obj.str);

        temp.str = new char[lstr+lostr];

        for(int i=0;i<lostr;i++)
        {
            temp.str[lstr+i] = obj.str[i];
        }

    }

    void display()
    {
        cout<<"String is "<<str;
    }
};

int main()
{
    String s1("taksh"),s2("kanz");

    String s3 = s1 + s2;
    
    s3.display();
}