#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

void setRedColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
}

void setBlueColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
}

int main() {
    cout << setw(15) << setfill('-') << "Student" << setw(15) << "Grade" << endl;
    cout << setw(30) << setfill('-') << "" << endl;

    cout << setw(15) << setfill('.') << "Emma" << setw(15);
    setRedColor(); 
    cout << "A+" << endl;
    setBlueColor();
    cout << setw(15) << setfill('.') << "Jack" << setw(15) << "B-" << endl;
    cout << setw(15) << setfill('.') << "Sophia" << setw(15);
    setRedColor(); 
    cout << "A" << endl;
    setBlueColor(); 
    cout << setw(15) << setfill('.') << "William" << setw(15) << "C" << endl;

    return 0;
}

