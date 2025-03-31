#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char ch;
    char str[100];

    cout << "Using put() to display a character: ";
    cout.put('A');
    cout << endl;

    cout << "Enter a character: ";
    cin.get(ch);
    cout << "You entered: ";
    cout.put(ch);
    cout << endl;
    
    cin.ignore();

    cout << "Enter a line of text: ";
    cin.getline(str, 100);
    cout << "You entered: " << str << endl;

    cout << "Using write() to display part of the string: ";
    cout.write(str, strlen(str));
    cout << endl;
}