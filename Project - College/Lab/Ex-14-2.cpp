#include <iostream>
#include <iomanip>  // For manipulators
using namespace std;

int main() {
    const int numItems = 3; // Number of items to input
    string itemName[numItems];
    int itemCode[numItems];
    double cost[numItems];

    // Reading item details
    cout << "Enter details for " << numItems << " items (Name, Code, Cost):\n";
    for (int i = 0; i < numItems; i++) {
        cout << "Item " << i + 1 << " Name: ";
        cin >> ws; // To clear any leftover newline characters
        getline(cin, itemName[i]);

        cout << "Item " << i + 1 << " Code: ";
        cin >> itemCode[i];

        cout << "Item " << i + 1 << " Cost: ";
        cin >> cost[i];
    }

    // Displaying formatted output
    cout << "\n--------------------------------------------------\n";
    cout << setw(20) << left << "Item Name" 
         << setw(10) << "Item Code" 
         << setw(10) << "Cost" << endl;
    cout << "--------------------------------------------------\n";

    for (int i = 0; i < numItems; i++) {
        cout << setw(20) << left << itemName[i]
             << setw(10) << itemCode[i]
             << setw(10) << fixed << setprecision(2) << cost[i] << endl;
    }

    return 0;
}
