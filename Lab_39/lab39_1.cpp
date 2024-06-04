#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Person {
protected:
    string name;
    int birthYear;
    char gender;

public:
    Person(string n = "", int by = 2000, char g = 'M') 
        : name(n), birthYear(by), gender(g) {}

    int calculateAge() const {
        time_t t = time(0); 
        tm* now = localtime(&t);
        int currentYear = now->tm_year + 1900;
        return currentYear - birthYear;
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Birth Year: " << birthYear << endl;
        cout << "Gender: " << gender << endl;
        cout << "Age: " << calculateAge() << endl;
    }
};

class Worker : public Person {
private:
    double salary;
    string workplace;

public:
    Worker(string n, int by, char g, double s, string wp) 
        : Person(n, by, g), salary(s), workplace(wp) {}

    void display() const {
        Person::display();
        cout << "Salary: " << salary << endl;
        cout << "Workplace: " << workplace << endl;
    }
};

int main() {
    Person student("Ann Green", 2006, 'M');
    cout << "Student Details:" << endl;
    student.display();
    cout << endl;

    Worker worker("Tom Red", 1996, 'F', 45000, "Tech Corp");
    cout << "Worker Details:" << endl;
    worker.display();

    return 0;
}

