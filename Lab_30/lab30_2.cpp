#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int stringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        ++length;
    }
    return length;
}

bool isEqualIgnoreCase(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        char c1 = str1[i];
        char c2 = str2[i];
        if (c1 >= 'A' && c1 <= 'Z') {
            c1 += 32;
        }
        if (c2 >= 'A' && c2 <= 'Z') {
            c2 += 32;
        }
        if (c1 != c2) {
            return false;
        }
        ++i;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}

bool wordInRow(const char* word, char** matrix, int row, int n) {
    for (int j = 0; j <= n - stringLength(word); ++j) {
        bool found = true;
        for (int k = 0; word[k] != '\0'; ++k) {
            if (matrix[row][j + k] != word[k]) {
                found = false;
                break;
            }
        }
        if (found) {
            cout << "Word found in row. Coordinates: (" << row << "," << j + 1 << ") - (" << row << "," << j + stringLength(word) << ")" << endl;
            return true;
        }
    }
    return false;
}

bool wordInColumn(const char* word, char** matrix, int col, int n) {
    for (int i = 0; i <= n - stringLength(word); ++i) {
        bool found = true;
        for (int k = 0; word[k] != '\0'; ++k) {
            if (matrix[i + k][col] != word[k]) {
                found = false;
                break;
            }
        }
        if (found) {
            cout << "Word found in column. Coordinates: (" << i + 1 << "," << col << ") - (" << i + stringLength(word) << "," << col << ")" << endl;
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Dimension = ";
    cin >> n;

    char** matrix = new char*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new char[n];
    }

    srand(time(0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j || i + j == n - 1) { 
                do {
                    matrix[i][j] = rand() % 26 + 'a'; 
                } while (!(matrix[i][j] == 'a' || matrix[i][j] == 'e' || matrix[i][j] == 'i' || matrix[i][j] == 'o' || matrix[i][j] == 'u' ||
                           matrix[i][j] == 'A' || matrix[i][j] == 'E' || matrix[i][j] == 'I' || matrix[i][j] == 'O' || matrix[i][j] == 'U'));
            } else {
                do {
                    matrix[i][j] = rand() % 26 + 'a'; 
                } while (matrix[i][j] == 'a' || matrix[i][j] == 'e' || matrix[i][j] == 'i' || matrix[i][j] == 'o' || matrix[i][j] == 'u' ||
                         matrix[i][j] == 'A' || matrix[i][j] == 'E' || matrix[i][j] == 'I' || matrix[i][j] == 'O' || matrix[i][j] == 'U');
            }
        }
    }

    cout << "Matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    string word;
    cout << "Enter a word to search: ";
    cin >> word;

    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (wordInRow(word.c_str(), matrix, i, n)) {
            found = true;
        }
        if (wordInColumn(word.c_str(), matrix, i, n)) {
            found = true;
        }
    }
    if (!found) {
        cout << "Word not found." << endl;
    }

    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

