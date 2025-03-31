#include<iostream>
#include<cstring>
using namespace std;

class String
{
    char *str;

    public:
    String(const char s[] = "")
    {
        str = new char[strlen(s)+1];
        strcpy(str,s);
    }

    String operator +(String &obj)
    {
        String temp;

        int l_str = strlen(str) ,lo_str = strlen(obj.str);

        temp.str = new char[l_str+lo_str+1];

        for(int i=0;i<l_str;i++)
        {
            temp.str[i] = str[i];
        }

        for(int i=0;i<lo_str;i++)
        {
            temp.str[l_str + i] = obj.str[i];
        }

        temp.str[l_str+lo_str] = '\0';
        return temp;
    }

    bool operator==(String &obj)
    {
        if(strcmp(str,obj.str) == 0)
        {
            return true;   
        }
        else 
            return false;
    }

    void display()
    {
        cout<<"String is "<<str;
    }
};

int main()
{
    String s1("alex"),s2("smith");

    String s3 = s1 + s2;
    
    s3.display();

    if(s1 == s2)
        cout<<"\ns1 and s2 are same.";
    else
        cout<<"\ns1 and s2 are different.";
}