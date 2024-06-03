#include <iostream>
#include <stdlib.h>

using namespace std;

int calculateRectangleArea(int width = 1, int height = 1) {
    return width * height;
}

int main() {
    cout << "Default rectangle area: " << calculateRectangleArea() << endl;

    cout << "Rectangle area with width 8 and height 4: " << calculateRectangleArea(8, 4) << endl;

    return 0;
}

