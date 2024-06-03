#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void sortDescending(int *arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
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
            A[i][j] = rand() % 900 + 100; 
        }
    }

    for (int i = 0; i < n; ++i) {
        sortDescending(A[i], n);
    }

    cout << "Sorted matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    ofstream outputFile("sorted_matrix.txt");
    if (!outputFile) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            outputFile << A[i][j] << " ";
        }
        outputFile << endl;
    }
    outputFile.close();

    for (int i = 0; i < n; ++i) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}

