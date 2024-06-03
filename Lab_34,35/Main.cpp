#include <iostream>
#include "Employee.h"

using namespace std;

int main() 
{
    Employee employee1;

    Employee employee2("Brown", "Sales", 2010, 4500.0);

    cout << "Employee 1 Info: " << employee1.getSurname() << ", " << employee1.getDepartment() << ", " 
         << employee1.getYearOfEmployment() << ", " << employee1.getSalary() << ", " << employee1.getBonus() << endl;

    cout << "Employee 2 Info: " << employee2.getSurname() << ", " << employee2.getDepartment() << ", " 
         << employee2.getYearOfEmployment() << ", " << employee2.getSalary() << ", " << employee2.computeBonus(2024) << endl;

    const int numEmployees = 3;
    Employee employees[numEmployees];

    for (int i = 0; i < numEmployees; ++i) {
        string surname, department;
        int yearOfEmployment;
        double salary;

        cout << "Enter details for employee " << i + 1 << ":" << endl;
        cout << "Surname: ";
        cin >> surname;
        cout << "Department: ";
        cin >> department;
        cout << "Year of Employment: ";
        cin >> yearOfEmployment;
        cout << "Salary: ";
        cin >> salary;

        employees[i] = Employee(surname, department, yearOfEmployment, salary);
    }

    for (int i = 0; i < numEmployees; ++i) {
        cout << "Employee " << i + 1 << " Details: " << employees[i].getSurname() << ", " 
             << employees[i].getDepartment() << ", " << employees[i].getYearOfEmployment() 
             << ", " << employees[i].getSalary() << ", " << employees[i].computeBonus(2024) << endl;
    }

    double averageExperience = calculateAverageExperience(employees, numEmployees);
    cout << "Average work experience: " << averageExperience << " years" << endl;

    sortEmployeesByWorkExperience(employees, numEmployees);

    cout << "Employees sorted by work experience:" << endl;
    for (int i = 0; i < numEmployees; ++i) {
        cout << "Employee " << i + 1 << ": " << employees[i].getSurname() << ", " 
             << employees[i].getDepartment() << ", " << employees[i].getYearOfEmployment() 
             << ", " << employees[i].getSalary() << ", " << employees[i].computeBonus(2024) << endl;
    }

    return 0;
}

