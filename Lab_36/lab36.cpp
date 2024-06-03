#include <iostream>
#include <string>

using namespace std;

const int MAX_EMPLOYEES = 5;

class Employee {
private:
    string name;
    string department;
    double salary;
    int yearsWorked;

public:
    Employee(string n, string dep, double sal, int years) 
        : name(n), department(dep), salary(sal), yearsWorked(years) {}

    string getName() const {
        return name;
    }

    double getSalary() const {
        return salary;
    }

    int getYearsWorked() const {
        return yearsWorked;
    }

    string getDepartment() const {
        return department;
    }

    friend void departmentStats(Employee employees[], int size);
};

void departmentStats(Employee employees[], int size) {
    struct Department {
        string name;
        int employeeCount = 0;
        double totalSalary = 0.0;
    };

    Department departments[MAX_EMPLOYEES];

    for (int i = 0; i < size; ++i) {
        bool found = false;
        for (int j = 0; j < MAX_EMPLOYEES; ++j) {
            if (departments[j].name == employees[i].getDepartment()) {
                departments[j].employeeCount++;
                departments[j].totalSalary += employees[i].getSalary();
                found = true;
                break;
            }
        }
        if (!found) {
            for (int j = 0; j < MAX_EMPLOYEES; ++j) {
                if (departments[j].name.empty()) {
                    departments[j].name = employees[i].getDepartment();
                    departments[j].employeeCount = 1;
                    departments[j].totalSalary = employees[i].getSalary();
                    break;
                }
            }
        }
    }

    for (int i = 0; i < MAX_EMPLOYEES; ++i) {
        if (!departments[i].name.empty()) {
            cout << "Department: " << departments[i].name << ", Employees: " << departments[i].employeeCount
                 << ", Total Salary: " << departments[i].totalSalary << endl;
        }
    }
}

class Vacation {
private:
    Employee employee;
    string startDate;
    int duration;
    string endDate;

public:
    Vacation(const Employee& emp, string start = "01.07.2021")
        : employee(emp), startDate(start) {
        if (emp.getYearsWorked() < 10 && emp.getSalary() < 12000)
            duration = 14;
        else if (emp.getYearsWorked() > 25 && emp.getSalary() > 25000)
            duration = 28;
        else
            duration = 21;

        endDate = "21 days after " + startDate;
    }

    Vacation() : employee("", "", 0, 0), startDate("01.07.2021"), duration(21), endDate("21 days after 01.07.2021") {}

    void display() const {
        cout << "Employee: " << employee.getName() << ", Start Date: " << startDate
             << ", Duration: " << duration << " days, End Date: " << endDate << endl;
    }
};

int main() {
    Employee employees[MAX_EMPLOYEES] = {
        Employee("John Doe", "IT", 15000, 5),
        Employee("Jane Smith", "HR", 20000, 15),
        Employee("Michael Johnson", "Accounting", 25000, 30),
        Employee("Emily Brown", "IT", 10000, 2),
        Employee("William Davis", "HR", 18000, 10)
    };

    departmentStats(employees, MAX_EMPLOYEES);

    Vacation vacations[MAX_EMPLOYEES];
    for (int i = 0; i < MAX_EMPLOYEES; ++i) {
        vacations[i] = Vacation(employees[i]);
    }

    for (int i = 0; i < MAX_EMPLOYEES; ++i) {
        vacations[i].display();
    }

    return 0;
}

