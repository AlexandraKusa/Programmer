#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

class Employee {
private:
    string surname;
    double salary;
    int startYear;

public:
    Employee(string s, double sal, int year) : surname(s), salary(sal), startYear(year) {}
    double nadbavka() const {
        return salary * 0.3;
    }
    int stash(int currentYear) const {
        return currentYear - startYear;
    }
    double totalSalary() const {
        return salary + nadbavka();
    }
    string getSurname() const {
        return surname;
    }
};

int main() {
    const int numEmployees = 3;
    Employee employees[numEmployees] = {
        Employee("Rid", 3200, 2012),
        Employee("Oyvel", 2100, 2018),
        Employee("Marcher", 2900, 2014)
    };

    int currentYear = 2024;
    double totalStash = 0;
    for (int i = 0; i < numEmployees; ++i) {
        totalStash += employees[i].stash(currentYear);
    }
    double avgStash = totalStash / numEmployees;

    ofstream outFile("employees.txt");
    if (outFile.is_open()) {
        for (int i = 0; i < numEmployees; ++i) {
            outFile << employees[i].getSurname() << "; " << employees[i].totalSalary() << endl;
        }
        outFile << "Average stash: " << avgStash << endl;
        outFile.close();
    } else {
        cerr << "Unable to open file!" << endl;
        return 1;
    }
    cout << "Data has been written to employees.txt" << endl;

    return 0;
}

