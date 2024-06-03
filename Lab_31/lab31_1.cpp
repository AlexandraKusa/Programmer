#include <iostream>
#include <stdlib.h>

using namespace std;

void inputArray(int* arr, int n) {
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

void printArray(int* arr, int n) {
    cout << "Array elements:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void removeMultiples(int* arr, int& n, int A) {
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] % A != 0) {
            arr[j] = arr[i];
            ++j;
        }
    }
    n = j;
}

void shiftArray(int* arr, int n, int X) {
    if (X > 0) { 
        for (int i = n - 1; i >= X; --i) {
            arr[i] = arr[i - X];
        }
        for (int i = 0; i < X; ++i) {
            arr[i] = 0; 
        }
    } else if (X < 0) { 
        for (int i = 0; i < n + X; ++i) {
            arr[i] = arr[i - X];
        }
        for (int i = n + X; i < n; ++i) {
            arr[i] = 0; 
        }
    }
}

int* createSubarray(int* arr, int n, bool evenSum) {
    int subarraySize = 0;
    for (int i = 0; i < n; ++i) {
        if ((evenSum && arr[i] % 2 == 0) || (!evenSum && arr[i] % 2 != 0)) {
            ++subarraySize;
        }
    }
    int* subarray = new int[subarraySize];
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if ((evenSum && arr[i] % 2 == 0) || (!evenSum && arr[i] % 2 != 0)) {
            subarray[j] = arr[i];
            ++j;
        }
    }
    return subarray;
}

int main() {
    int n;
    cout << "Dimension = ";
    cin >> n;

    int* arr = new int[n];

    inputArray(arr, n);

    printArray(arr, n);

    int A;
    cout << "Enter the value of A to remove multiples: ";
    cin >> A;
    removeMultiples(arr, n, A);
    cout << "Array after removing multiples of " << A << ":" << endl;
    printArray(arr, n);

    int X;
    cout << "Enter the value of X to shift the array (positive for right, negative for left): ";
    cin >> X;
    shiftArray(arr, n, X);
    cout << "Array after shifting by " << X << " positions:" << endl;
    printArray(arr, n);

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }

    bool evenSum = (sum % 2 == 0);
    int* subarray = createSubarray(arr, n, evenSum);
    int subarraySize = evenSum ? (n - sum) / 2 : sum / 2;
    cout << "Subarray with " << (evenSum ? "even" : "odd") << " elements:" << endl;
    printArray(subarray, subarraySize);

    delete[] arr;
    delete[] subarray;

    return 0;
}

