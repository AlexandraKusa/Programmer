#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void calculateAveragesAndZeroCount(int *A, int n, int m, double &posAvg, double &negAvg, int &zeroCount) {
    int posSum = 0, posCount = 0;
    int negSum = 0, negCount = 0;
    zeroCount = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int value = *(A + i * m + j);
            if (value > 0) {
                posSum += value;
                posCount++;
            } else if (value < 0) {
                negSum += value;
                negCount++;
            } else {
                zeroCount++;
            }
        }
    }

    if (posCount > 0) {
        posAvg = posSum / (double)posCount;
    } else {
        posAvg = 0;
    }

    if (negCount > 0) {
        negAvg = negSum / (double)negCount;
    } else {
        negAvg = 0;
    }
}

int main() {
    int n, m;
    cout << "Dimension = ";
    cin >> n >> m;

    int A[n][m];
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
        }
    }

    double posAvg, negAvg;
    int zeroCount;

    calculateAveragesAndZeroCount(&A[0][0], n, m, posAvg, negAvg, zeroCount);

    cout << "Average of positive numbers: " << posAvg << endl;
    cout << "Average of negative numbers: " << negAvg << endl;
    cout << "Count of zeros: " << zeroCount << endl;

    return 0;
}

