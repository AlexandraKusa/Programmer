#include <iostream>
#include <stdlib.h>

using namespace std;

void combineAndPrint(const char* str, char ch1, char ch2, char ch3, char ch4, char ch5, char ch6) {
    cout << str << ch1 << ch2 << ch3 << ch4 << ch5 << ch6;
}

int main() {
    combineAndPrint("Hello", ' ', 'w', 'o', 'r', 'l', 'd');

    return 0;
}

