#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void sortArray(int *a, int n) {
    for (int i = 0; i < n; i += 2) {
        for (int j = i + 2; j < n; j += 2) {
            if (*(a + i) > *(a + j)) {
                int temp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = temp;
            }
        }
    }

    for (int i = 1; i < n; i += 2) {
        for (int j = i + 2; j < n; j += 2) {
            if (*(a + i) < *(a + j)) {
                int temp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Dimension = ";
    cin >> n;

    int *a = new int[n]; 
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> *(a + i);
    }

    sortArray(a, n); 

    cout << "Array after sorting:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *(a + i) << " ";
    }
    cout << endl;

    delete[] a; 

    return 0;
}

