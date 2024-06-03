#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int width; 
    int precision; 

    cout << "Enter the desired width of the field: ";
    cin >> width;
    cout << "Enter the desired precision: ";
    cin >> precision;

    double number = 123.456789; 

    cout << setw(width) << setprecision(precision) << number << endl;

    return 0;
}

