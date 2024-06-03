#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int main() {
    int n;
    cout << "Dimension = ";
    cin >> n;

    double *a = new double[n]; 
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> *(a + i);
    }

    double *tempArray = new double[2 * n]; 
    int newSize = n; 

    int j = 0; 
    for (int i = 0; i < n; ++i) {
        *(tempArray + j) = *(a + i); 
        j++;

        if (((int)*(a + i)) % 5 == 0) { 
            double sum = 0;
            for (int k = 0; k < i; ++k) {
                sum += *(a + k);
            }
            *(tempArray + j) = sum; 
            j++;
            newSize++; 
        }
    }

    cout << "Array after inserting sums:" << endl;
    for (int i = 0; i < newSize; ++i) {
        cout << *(tempArray + i) << " ";
    }
    cout << endl;

    delete[] a; 
    delete[] tempArray; 

    return 0;
}

