#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    for (int i = 1; i <= 15; ++i) {
        cout << "Decimal: " << i << ", ";
        cout << "Hexadecimal: ";
        if (i < 16)
            cout << "0"; 
        cout << hex << i << ", ";

        cout << "Octal: " << oct << i << endl; 
    }
    return 0;
}

