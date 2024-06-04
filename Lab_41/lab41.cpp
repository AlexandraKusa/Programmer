#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

template <typename T>
int countEqualToFirst(T* arr, int size) {
    T first = arr[0];
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == first) {
            ++count;
        }
    }
    return count;
}

template <typename T>
void swapElements(T* arr, int index1, int index2) {
    T temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

template <typename T>
void insertElement(T* &arr, int &size, T element, int position) {
    T* newArr = new T[size + 1];
    for (int i = 0; i < position; ++i) {
        newArr[i] = arr[i];
    }
    newArr[position] = element;
    for (int i = position; i < size; ++i) {
        newArr[i + 1] = arr[i];
    }
    ++size;
    delete[] arr;
    arr = newArr;
}

template <typename T>
int longestEqualSubarray(T* arr, int size) {
    int maxLength = 1;
    int currentLength = 1;
    for (int i = 1; i < size; ++i) {
        if (arr[i] == arr[i - 1]) {
            ++currentLength;
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
        } else {
            currentLength = 1;
        }
    }
    return maxLength;
}

template <typename T>
void sortBetweenMinMax(T* arr, int size) {
    if (size < 2) return;
    T minVal = arr[0];
    T maxVal = arr[0];
    int minIndex = 0;
    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
            minIndex = i;
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
            maxIndex = i;
        }
    }
    if (minIndex > maxIndex) {
        swap(minIndex, maxIndex);
    }
    sort(arr + minIndex + 1, arr + maxIndex);
}

int main() {
    srand(time(0));
    const int size = 10;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100; 
    }
    cout << "Array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Number of elements equal to the first element: " << countEqualToFirst(arr, size) << endl;
    swapElements(arr, 2, 5);
    cout << "Array after swapping elements at indices 2 and 5: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int newSize = size;
    insertElement(arr, newSize, 50, 3);
    cout << "Array after inserting 50 at position 3: ";
    for (int i = 0; i < newSize; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Longest subarray of equal elements: " << longestEqualSubarray(arr, newSize) << endl;
    sortBetweenMinMax(arr, newSize);
    cout << "Array after sorting elements between min and max: ";
    for (int i = 0; i < newSize; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
    return 0;
}

