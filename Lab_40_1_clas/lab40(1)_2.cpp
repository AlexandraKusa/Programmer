#include <iostream>
#include <string>
#include <vector>

using namespace std;

class People {
private:
    string surname;
    string country;
    string gender;
    string education;
    int birthYear;
    int age;

public:
    People() : surname(""), country("Ukraine"), gender("Unknown"), education("None"), birthYear(2006), age(2024 - 2006) {}

    People(string sname, string gen, string edu, int bYear) 
        : surname(sname), country("Ukraine"), gender(gen), education(edu), birthYear(bYear), age(2024 - bYear) {}

    People(const People &p) 
        : surname(p.surname), country(p.country), gender(p.gender), education(p.education), birthYear(p.birthYear), age(p.age) {}

    void input() {
        cout << "Enter surname: ";
        cin >> surname;
        cout << "Enter country: ";
        cin >> country;
        cout << "Enter gender: ";
        cin >> gender;
        cout << "Enter education: ";
        cin >> education;
        cout << "Enter birth year: ";
        cin >> birthYear;
        age = 2024 - birthYear;
    }

    void output() const {
        cout << "Surname: " << surname << ", Country: " << country
             << ", Gender: " << gender << ", Education: " << education
             << ", Birth Year: " << birthYear << ", Age: " << age << endl;
    }

    string getEducation() const {
        return education;
    }

    int getAge() const {
        return age;
    }

    string getGender() const {
        return gender;
    }

    ~People() {
        cout << "Destructor called for " << surname << endl;
    }
};

void printCitizensWithHigherEducationAndAge(const People people[], int size, int minAge) {
    cout << "Citizens with higher education and age greater than " << minAge << ":" << endl;
    for (int i = 0; i < size; ++i) {
        if (people[i].getEducation() == "Higher" && people[i].getAge() > minAge) {
            people[i].output();
        }
    }
}

void removePeopleByGender(People people[], int &size, const string &targetGender) {
    int newSize = 0;
    for (int i = 0; i < size; ++i) {
        if (people[i].getGender() != targetGender) {
            people[newSize++] = people[i];
        }
    }
    size = newSize;
}

int main() {
    const int numberOfPeople = 5; 
    People people[numberOfPeople] = {
        People("Doe", "Male", "Higher", 1990),
        People("Smith", "Female", "Higher", 1985),
        People("Brown", "Male", "Higher", 1995),
        People("Marks", "Female", "Secondary", 1992),
        People()
    };

    for (int i = 0; i < numberOfPeople - 1; ++i) {
        people[i].output();
    }

    people[numberOfPeople - 1].input();

    printCitizensWithHigherEducationAndAge(people, numberOfPeople, 30);

    string targetGender;
    cout << "Enter gender to remove: ";
    cin >> targetGender;
    int size = numberOfPeople;
    removePeopleByGender(people, size, targetGender);

    cout << "Remaining citizens after removal:" << endl;
    for (int i = 0; i < size; ++i) {
        people[i].output();
    }

    People copiedPerson = people[0];
    for (int i = size; i > 0; --i) {
        people[i] = people[i - 1];
    }
    people[0] = copiedPerson;
    ++size;

    cout << "Array after inserting copied person at the beginning:" << endl;
    for (int i = 0; i < size; ++i) {
        people[i].output();
    }

    return 0;
}

