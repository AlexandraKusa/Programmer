#include <iostream>
#include <stdlib.h>

using namespace std;

void printReversed(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    for (int i = length - 1; i >= 0; i--) {
        cout << str[i];
    }
}

int main() {
    printReversed("1 2 3 4");

    return 0;
}

