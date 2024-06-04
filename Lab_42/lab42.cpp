#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
class Vector {
private:
    static const int SIZE = 10;
    T data[SIZE];

public:
    Vector() {
        for (int i = 0; i < SIZE; ++i) {
            data[i] = T();
        }
    }

    Vector(const T& value) {
        for (int i = 0; i < SIZE; ++i) {
            data[i] = value;
        }
    }

    void inputFromKeyboard() {
        for (int i = 0; i < SIZE; ++i) {
            cout << "Enter element " << i + 1 << ": ";
            cin >> data[i];
        }
    }

    void inputFromRandom() {
        srand(time(0));
        for (int i = 0; i < SIZE; ++i) {
            data[i] = rand() % 100; 
        }
    }

    void print() const {
        for (int i = 0; i < SIZE; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void rearrange() {
        T temp[SIZE];
        int evenIndex = 0;
        int oddIndex = SIZE / 2;
        for (int i = 0; i < SIZE; ++i) {
            if (i % 2 == 0) {
                temp[evenIndex++] = data[i];
            } else {
                temp[oddIndex++] = data[i];
            }
        }
        for (int i = 0; i < SIZE; ++i) {
            data[i] = temp[i];
        }
    }
    void removeElement(const T& value) {
        T temp[SIZE];
        int index = 0;
        for (int i = 0; i < SIZE; ++i) {
            if (data[i] != value) {
                temp[index++] = data[i];
            }
        }
        while (index < SIZE) {
            temp[index++] = T();  
        }
        for (int i = 0; i < SIZE; ++i) {
            data[i] = temp[i];
        }
    }
    Vector<T> operator+(const Vector<T>& other) const {
        Vector<T> result;
        for (int i = 0; i < SIZE; ++i) {
            result.data[i] = this->data[i] + other.data[i];
        }
        return result;
    }
    Vector<T>& operator++() {
        for (int i = 0; i < SIZE; ++i) {
            data[i] += 10;
        }
        return *this;
    }
    bool operator>(const Vector<T>& other) const {
        return this->sum() > other.sum();
    }
    bool operator<(const Vector<T>& other) const {
        return this->sum() < other.sum();
    }
    bool operator==(const Vector<T>& other) const {
        return this->sum() == other.sum();
    }

private:
    T sum() const {
        T total = T();
        for (int i = 0; i < SIZE; ++i) {
            total += data[i];
        }
        return total;
    }
};

int main() 
{
    Vector<int> vec1;
    vec1.inputFromRandom();
    cout << "Vector 1 (random): ";
    vec1.print();
    Vector<int> vec2(5);
    cout << "Vector 2 (initialized to 5): ";
    vec2.print();
    Vector<int> vec3 = vec1 + vec2;
    cout << "Vector 3 (vec1 + vec2): ";
    vec3.print();
    ++vec3;
    cout << "Vector 3 after increment: ";
    vec3.print();
    vec3.removeElement(15);  
    cout << "Vector 3 after removing element 15: ";
    vec3.print();
    vec1.rearrange();
    cout << "Vector 1 after rearrange: ";
    vec1.print();
    cout << "Comparison vec1 > vec2: " << (vec1 > vec2) << endl;
    cout << "Comparison vec1 < vec2: " << (vec1 < vec2) << endl;
    cout << "Comparison vec1 == vec2: " << (vec1 == vec2) << endl;
    return 0;
}

