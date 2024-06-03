#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

double findMinEvenIndex(double *a, int n) {
    double minElement;
    bool firstEvenIndexFound = false;

    for (int i = 1; i < n; i += 2) { 
        if (!firstEvenIndexFound) {
            minElement = *(a + i);
            firstEvenIndexFound = true;
        } else if (*(a + i) < minElement) {
            minElement = *(a + i);
        }
    }

    return minElement;
}

int main() {
    int n;
    cout << "Dimension = ";
    cin >> n;

    double a[n];
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    double minElement = findMinEvenIndex(a, n);
    cout << "The minimum element at even indices is: " << minElement << endl;

    return 0;
}

