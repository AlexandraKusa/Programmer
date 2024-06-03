#include <iostream>
#include <cstdlib> 
#include <ctime>   

using namespace std;

class Matrix {
private:
    int **data;
    int size;

public:
    Matrix(int n) : size(n) {
        data = new int*[size];
        for (int i = 0; i < size; ++i) {
            data[i] = new int[size];
        }
    }

    ~Matrix() {
        for (int i = 0; i < size; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    void fillRandom(int min, int max) {
        srand(time(0)); 
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                data[i][j] = rand() % (max - min + 1) + min;
            }
        }
    }

    void display() const {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    friend Matrix operator+(const Matrix& m1, const Matrix& m2);
    friend Matrix operator-(const Matrix& m1, const Matrix& m2);
    friend Matrix operator*(const Matrix& m1, const Matrix& m2);
    friend bool operator==(const Matrix& m1, const Matrix& m2);
};

Matrix operator+(const Matrix& m1, const Matrix& m2) {
    Matrix result(m1.size);
    for (int i = 0; i < m1.size; ++i) {
        for (int j = 0; j < m1.size; ++j) {
            result.data[i][j] = m1.data[i][j] + m2.data[i][j];
        }
    }
    return result;
}

Matrix operator-(const Matrix& m1, const Matrix& m2) {
    Matrix result(m1.size);
    for (int i = 0; i < m1.size; ++i) {
        for (int j = 0; j < m1.size; ++j) {
            result.data[i][j] = m1.data[i][j] - m2.data[i][j];
        }
    }
    return result;
}

Matrix operator*(const Matrix& m1, const Matrix& m2) {
    Matrix result(m1.size);
    for (int i = 0; i < m1.size; ++i) {
        for (int j = 0; j < m1.size; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < m1.size; ++k) {
                result.data[i][j] += m1.data[i][k] * m2.data[k][j];
            }
        }
    }
    return result;
}

bool operator==(const Matrix& m1, const Matrix& m2) {
    if (m1.size != m2.size)
        return false;

    for (int i = 0; i < m1.size; ++i) {
        for (int j = 0; j < m1.size; ++j) {
            if (m1.data[i][j] != m2.data[i][j])
                return false;
        }
    }
    return true;
}

int main() {
    int size = 3;
    Matrix m1(size), m2(size), result(size);

    m1.fillRandom(1, 10);
    m2.fillRandom(1, 10);

    cout << "Matrix 1:" << endl;
    m1.display();
    cout << endl;

    cout << "Matrix 2:" << endl;
    m2.display();
    cout << endl;

    result = m1 + m2;
    cout << "Matrix 1 + Matrix 2:" << endl;
    result.display();
    cout << endl;

    result = m1 - m2;
    cout << "Matrix 1 - Matrix 2:" << endl;
    result.display();
    cout << endl;

    result = m1 * m2;
    cout << "Matrix 1 * Matrix 2:" << endl;
    result.display();
    cout << endl;

    if (m1 == m2)
        cout << "Matrix 1 is equal to Matrix 2" << endl;
    else
        cout << "Matrix 1 is not equal to Matrix 2" << endl;

    return 0;
}

