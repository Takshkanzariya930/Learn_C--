#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double num = 123.456;

    cout << "Using setw(10): " << setw(10) << num << endl;

    cout << "Using setprecision(2): " << setprecision(2) << fixed << num << endl;

    cout << "Using setiosflags(ios::showpoint | ios::fixed): ";
    cout << setiosflags(ios::showpoint | ios::fixed) << num << endl;

    cout << "Using setw(10) and setiosflags(ios::left): ";
    cout << setw(10) << setiosflags(ios::left) << num << endl;

    return 0;
}