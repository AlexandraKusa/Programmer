#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int** createMatrix(int n) {
    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
    }
    return matrix;
}

void deleteMatrix(int** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

bool isColumnSortedDescending(int** matrix, int n, int column) {
    for (int i = 0; i < n - 1; ++i) {
        if (matrix[i][column] < matrix[i + 1][column]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Dimension = ";
    cin >> n;

    int** matrix = createMatrix(n);

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int countSortedColumns = 0;
    for (int j = 0; j < n; ++j) {
        if (isColumnSortedDescending(matrix, n, j)) {
            ++countSortedColumns;
        }
    }

    cout << "Number of columns sorted in descending order: " << countSortedColumns << endl;

    deleteMatrix(matrix, n);

    return 0;
}

