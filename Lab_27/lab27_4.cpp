#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

bool hasSameDigits(int num) {
    int digit1 = num % 10;
    int digit2 = num / 10 % 10;
    return digit1 == digit2;
}

int main() {
    int n;
    cout << "Dimension = ";
    cin >> n;

    int **A = new int*[n];
    for (int i = 0; i < n; ++i) {
        A[i] = new int[n];
    }

    srand(time(0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = rand() % 90 + 10;
			cout << A[i][j] << " ";
        }
        cout << endl;
    }
    
    int sum = 0;
    for (int j = 0; j < n; ++j) {
        bool containsSameDigits = false;
        for (int i = 0; i < n; ++i) {
            if (hasSameDigits(A[i][j])) {
                containsSameDigits = true;
                break;
            }
        }
        if (!containsSameDigits) {
            for (int i = 0; i < n; ++i) {
                sum += A[i][j];
            }
        }
    }

    cout << "Sum of elements in columns without numbers containing same digits: " << sum << endl;

    for (int i = 0; i < n; ++i) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}

