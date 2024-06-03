#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    string products[] = {"Milk", "Bread", "Chocolate", "Apple"};
    double prices[] = {23.50, 12.75, 28.99, 16.99};
    cout << left << setw(20) << "Product" << right << setw(10) << "Price" << endl;
    cout << setfill('-') << setw(30) << "" << setfill(' ') << endl;
    for (int i = 0; i < 4; ++i) {
        cout << left << setw(20) << products[i] << right << setw(10) << fixed << setprecision(2) << prices[i] << endl;
    }
    return 0;
}

