#include <iostream>
using namespace std;

int main() {
    string name;
    int age;

    cout << "Enter your name: ";
    getline(cin,name);

    cout << "Enter your age: ";
    cin >> age;

    cout << "Hello, " << name << "! You are " << age << " years old.\n";

    if (age < 0) {
        cerr << "Error: Age cannot be negative!\n";
    }

    clog << "Log: User input processed successfully.\n";

    return 0;
}