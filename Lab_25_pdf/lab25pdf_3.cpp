#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void findLargerThanLeft(int *a, int n) {
    int count = 0; 

    cout << "Indices of elements larger than their left neighbor:" << endl;
    for (int i = 1; i < n; ++i) {
        if (*(a + i) > *(a + i - 1)) { 
            cout << i << " ";
            count++; 
        }
    }

    cout << endl;
    cout << "Total number of elements larger than their left neighbor: " << count << endl;
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

    findLargerThanLeft(a, n);

    return 0;
}

