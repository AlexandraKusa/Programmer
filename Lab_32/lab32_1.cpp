#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
    cout << "p with 2 digits after the decimal point: " << fixed << setprecision(2) << M_PI << endl;
    cout << "p with 4 digits after the decimal point: " << fixed << setprecision(4) << M_PI << endl;
    cout << "p with 6 digits after the decimal point: " << fixed << setprecision(6) << M_PI << endl;

    return 0;
}

