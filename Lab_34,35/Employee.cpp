#include "Employee.h"

Employee::Employee() : surname(""), department(""), yearOfEmployment(0), salary(0.0), bonus(0.0) {}

Employee::Employee(const string& surname, const string& department, int yearOfEmployment, double salary)
    : surname(surname), department(department), yearOfEmployment(yearOfEmployment), salary(salary), bonus(0.0) {}

string Employee::getSurname() const {
    return surname;
}

string Employee::getDepartment() const {
    return department;
}

int Employee::getYearOfEmployment() const {
    return yearOfEmployment;
}

double Employee::getSalary() const {
    return salary;
}

double Employee::getBonus() const {
    return bonus;
}

void Employee::setSurname(const string& surname) {
    this->surname = surname;
}

void Employee::setDepartment(const string& department) {
    this->department = department;
}

void Employee::setYearOfEmployment(int yearOfEmployment) {
    this->yearOfEmployment = yearOfEmployment;
}

void Employee::setSalary(double salary) {
    this->salary = salary;
}

void Employee::setBonus(double bonus) {
    this->bonus = bonus;
}

double Employee::computeBonus(int currentYear) const {
    int experience = currentYear - yearOfEmployment;
    if (experience < 10) {
        return salary * 0.1;
    } else if (experience <= 20) {
        return salary * 0.25;
    } else {
        return salary * 0.4;
    }
}

int Employee::computeExperience(int currentYear) const {
    return currentYear - yearOfEmployment;
}

double calculateAverageExperience(Employee employees[], int size) {
    int totalExperience = 0;
    for (int i = 0; i < size; ++i) {
        totalExperience += employees[i].computeExperience(2024);
    }
    return static_cast<double>(totalExperience) / size;
}

void sortEmployeesByWorkExperience(Employee employees[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (employees[j].computeExperience(2024) > employees[j + 1].computeExperience(2024)) {
                swap(employees[j], employees[j + 1]);
            }
        }
    }
}

