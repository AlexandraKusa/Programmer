#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

using namespace std;

class Employee {
private:
    string surname;
    string department;
    int yearOfEmployment;
    double salary;
    double bonus;

public:
    Employee();
    Employee(const string& surname, const string& department, int yearOfEmployment, double salary);

    string getSurname() const;
    string getDepartment() const;
    int getYearOfEmployment() const;
    double getSalary() const;
    double getBonus() const;

    void setSurname(const string& surname);
    void setDepartment(const string& department);
    void setYearOfEmployment(int yearOfEmployment);
    void setSalary(double salary);
    void setBonus(double bonus);

    double computeBonus(int currentYear) const;
    int computeExperience(int currentYear) const;
};

double calculateAverageExperience(Employee employees[], int size);
void sortEmployeesByWorkExperience(Employee employees[], int size);

#endif 

