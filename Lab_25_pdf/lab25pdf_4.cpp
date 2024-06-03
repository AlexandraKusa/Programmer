#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void findNegativeElements(int *a, int n) {
    int count = 0; 

    cout << "Addresses of elements less than 0:" << endl;
    for (int i = 0; i < n; ++i) {
        if (*(a + i) < 0) { 
            cout << "Address of element at index " << i << ": " << (a + i) << endl;
            count++; 
        }
    }

    cout << "Total number of elements less than 0: " << count << endl;
}

int main() {
    int n;
    cout << "Dimension = ";
    cin >> n;

    int a[n];
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    findNegativeElements(a, n);

    return 0;
}

