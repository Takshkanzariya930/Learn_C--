#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char ch;
    char line[100];
    char buffer[20];

    cout << "Enter a character: ";
    cin.get(ch);
    cin.ignore();

    cout << "Enter a line: ";
    cin.getline(line, 100); 

    cout << "Enter a string (at least 10 characters): ";
    cin.read(buffer, 10);
    buffer[10] = '\0';

    double number = 123.456789;

    cout << "\nFormatted Output:\n";

    cout << left << setw(20) << setfill('.') << "Single char:" << ch << endl;
    cout << left << setw(20) << setfill('.') << "Line:" << line << endl;
    cout << left << setw(20) << setfill('.') << "Read (10 chars):" << buffer << endl;

    cout << left << setw(20) << setfill('.') << "Number (2 precision):" 
         << fixed << setprecision(2) << number << endl;

    return 0;
}
