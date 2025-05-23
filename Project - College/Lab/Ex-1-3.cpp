#include<iostream>
using namespace std;

class String 
{

    public:
    int stringlen(char *ptr)
    {
        int i=0;
        while(*(ptr + i) != '\0')
        {
            i = i + 1;
        }
        return i;
    }
    
    void stringcopy(char *ptr1,char *ptr2)
    {
        int l,i;
        l = stringlen(ptr1);

        for(i=0;i<l;i++)
        {
            *(ptr2+i) = *(ptr1+i);
        }
        
        ptr2[l] = '\0';
    }

    int stringcomp(char *ptr1,char *ptr2)
    {
        int i,l1 = stringlen(ptr1),l2 = stringlen(ptr2);
        
        if(l1 != l2)
        {
            return 0;
        }
        
        for(i=0;i<l1;i++)
        {
            if(*ptr1+i != *ptr2+i)
            {
                return 0;
            }
        }
        
        return 1;
    }
    
    void stringconcat(char *ptr1,char *ptr2)
    {
        int i,l1 = stringlen(ptr1),l2 = stringlen(ptr2);
        ptr1 = ptr1 + l1;
        
        for(i=0;i<l2;i++)
        {
            *ptr1 = *ptr2;
            ptr1++;
            ptr2++;
        }
        
        ptr1[l1+l2] = '\0';
    }

    int stringsearch(char *ptr1,char *ptr2)
    {
        int i,j,l1 = stringlen(ptr1),l2 = stringlen(ptr2);
        
        for(i=0;i<l1;i++)
        {
            for(j=0;j<l2;j++)
            {
                if(ptr1[i+j] != ptr2[j])
                {
                    break;
                }
            }
            
            if(j == l2)
            {
                return (i+1);
            }
        }
        
        return 0;
    }
};

int main()
{
    String s;
    int result,choice;
    char str1[100],str2[100];

    cout<<"Enter '1' for finding length of string.";
    cout<<"\nEnter '2' for copying string from first to second";
    cout<<"\nEnter '3' for comparing string and it returns 0 if they are not same and 1 if they are same.";
    cout<<"\nEnter '4' for concatenate second string to first.";
    cout<<"\nEnter '5' for searching second string in first if string is found it returns it's starting position and returns 0 if not found.";
    cout<<"\nEnter your choice : ";
    cin>>choice;
    getchar();

    switch (choice)
    {
        case 1:
            cout<<"\nEnter string : ";
            cin.getline(str1,100);
            result = s.stringlen(str1);
            cout<<"\nLength of string "<<str1<<" is "<<result;
            break;

        case 2:
            cout<<"\nEnter string : ";
            cin.getline(str1,100);
            
            cout<<"Enter string : ";
            cin.getline(str2,100);

            s.stringcopy(str1,str2);
            cout<<"\nfirst string : "<<str1;
            cout<<"\nsecond string : "<<str2;
            break;

        case 3:
            cout<<"\nEnter string : ";
            cin.getline(str1,100);
            
            cout<<"Enter string : ";
            cin.getline(str2,100);
            result = s.stringcomp(str1,str2);
            if(result == 0)
                cout<<"\nString '"<<str1<<"' and '"<<str2<<"' are NOT SAME";
            else
                cout<<"\nString '"<<str1<<"' and '"<<str2<<"' are SAME";
            break;
            
        case 4:
            cout<<"\nEnter string : ";
            cin.getline(str1,100);
            
            cout<<"Enter string : ";
            cin.getline(str2,100);
            s.stringconcat(str1,str2);
            cout<<"\nfirst string : "<<str1;
            cout<<"\nsecond string : "<<str2;
            break;
            
        case 5:
            cout<<"\nEnter string : ";
            cin.getline(str1,100);
            
            cout<<"Enter string : ";
            cin.getline(str2,100);
            result = s.stringsearch(str1,str2);
            if(result == 0)
                cout<<"String '"<<str2<<"' NOT found in '"<<str1<<"'";
            else
                cout<<"String '"<<str2<<"' is at "<<result<<" position in '"<<str1<<"' ";
            break;
    
        default:
            cout<<"\nInvalid Choice";
            break;
    }
}