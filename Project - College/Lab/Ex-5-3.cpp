#include<iostream>
using namespace std;

void swap_value(int a,int b)
{
    int temp = a;
    a = b;
    b = temp;

    cout<<"\nInside function : \n    a = "<<a<<"\n    b = "<<b;
}	

void swap_reference(int *p1,int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int main()
{
	int a,b,choice;

	cout<<"Enter first number(a) : ";
	cin>>a;

	cout<<"Enter second number(b) : ";
	cin>>b;

	cout<<"\nPress '1' to swap values by passing value.";
	cout<<"\nPress '2' to swap values by passing address.";
	cout<<"\nEnter your choice : ";
	cin>>choice;

	switch(choice)
	{
		case 1:
			cout<<"\nSwapping by passing values......"<<endl;
			cout<<"\nBefore calling function : \n    a = "<<a<<"\n    b = "<<b;
			
			swap_value(a,b);
			cout<<"\nAfter calling function : \n    a = "<<a<<"\n    b = "<<b;
			
			break;
			
		case 2:
			cout<<"\nSwapping by passing address......"<<endl;
			cout<<"\nBefore calling function : \n    a = "<<a<<"\n    b = "<<b;

			swap_reference(&a,&b);
			cout<<"\n\nAfter calling function : \n    a = "<<a<<"\n    b = "<<b;
			
	}
}