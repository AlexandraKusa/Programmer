#include <iostream>
#include <stdlib.h>
#include <time.h> 
using namespace std;

int* generateRandomArray(int size = 10, int minValue = 0, int maxValue = 100) {
    srand(time(0));
    int* arr = new int[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % (maxValue - minValue + 1) + minValue;
    }

    return arr;
}

int main() {
    int* randomArray = generateRandomArray(5, 0, 100);

    cout << "Random array:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << randomArray[i] << " ";
    }
    cout << endl;

    delete[] randomArray;

    return 0;
}

