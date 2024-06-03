#include <iostream>
#include <fstream>

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

void processWords(const char* filename, const char* searchWord) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Failed to open the file." << endl;
        return;
    }

    int count = 0; 
    char** words = 0; 
    int wordsCount = 0; 

    char word[100]; 

    while (inputFile >> word) {
        int len = stringLength(word);
        if (len == 3) {
            char** temp = new char*[wordsCount + 1];
            for (int i = 0; i < wordsCount; ++i) {
                temp[i] = words[i];
            }
            temp[wordsCount] = new char[len + 1];
            for (int i = 0; i <= len; ++i) {
                temp[wordsCount][i] = word[i];
            }
            delete[] words;
            words = temp;
            ++wordsCount;
        }
        if (isEqualIgnoreCase(word, searchWord)) {
            ++count;
        }
    }
    inputFile.close();

    cout << "Words with 3 letters:" << endl;
    for (int i = 0; i < wordsCount; ++i) {
        cout << words[i] << " ";
        delete[] words[i];
    }
    delete[] words;

    cout << "\nNumber of occurrences of \"" << searchWord << "\": " << count << endl;
}

int main() {
    const char* filename = "text.txt";
    const char* searchWord = "travelling";

    processWords(filename, searchWord);

    return 0;
}

