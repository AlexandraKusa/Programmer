#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void findDescendingTriplets(double *a, int n) {
    bool found = false;

    for (int i = 0; i < n - 2; ++i) { 
        if (*(a + i) > *(a + i + 1) && *(a + i + 1) > *(a + i + 2)) { 
            found = true;
            cout << "Descending triplet found at indices " << i << ", " << i + 1 << ", " << i + 2 << ": ";
            cout << *(a + i) << ", " << *(a + i + 1) << ", " << *(a + i + 2) << endl;
        }
    }

    if (!found) {
        cout << "No descending triplets found." << endl;
    }
}

int main() {
    int n;
    cout << "Dimension = ";
    cin >> n;

    if (n < 3) {
        cout << "Array should have at least 3 elements to form a triplet." << endl;
        return 1;
    }

    double a[n];
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    findDescendingTriplets(a, n);

    return 0;
}

