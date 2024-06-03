#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void sortMainDiagonal(int *A, int n, int m) {
    int minDim = (n < m) ? n : m; 
    int *diagonal = new int[minDim];

    for (int i = 0; i < minDim; ++i) {
        diagonal[i] = *(A + i * m + i);
    }

    for (int i = 0; i < minDim - 1; ++i) {
        for (int j = 0; j < minDim - i - 1; ++j) {
            if (diagonal[j] > diagonal[j + 1]) {
                int temp = diagonal[j];
                diagonal[j] = diagonal[j + 1];
                diagonal[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < minDim; ++i) {
        *(A + i * m + i) = diagonal[i];
    }

    delete[] diagonal; 
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

    sortMainDiagonal(&A[0][0], n, m);

    cout << "Matrix after sorting the main diagonal:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

