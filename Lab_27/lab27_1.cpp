#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

void findAndWriteSmallerThanAverage(int **A, int n) {
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum += A[i][j];
        }
    }
    double average = sum / (n * n);

    int *resultArray = new int[n];
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (A[i][j] < average) {
                count++;
            }
        }
        resultArray[i] = count;
    }

    ofstream outputFile("result.txt");
    if (!outputFile) {
        cerr << "Failed to open the file." << endl;
        return;
    }
    for (int i = 0; i < n; ++i) {
        outputFile << resultArray[i] << " ";
    }
    outputFile.close();

    delete[] resultArray;
}

int main() {
    int n;
    cout << "Dimension = ";
    cin >> n;

    int **A = new int*[n];
    for (int i = 0; i < n; ++i) {
        A[i] = new int[n];
    }

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    findAndWriteSmallerThanAverage(A, n);

    for (int i = 0; i < n; ++i) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}

