#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Worker {
private:
    string surname;
protected:
    int age;
    int drivingExperience;
public:
    Worker(string s, int a, int d) : surname(s), age(a), drivingExperience(d) {}

    void setWorkerData(string s, int a, int d) {
        surname = s;
        age = a;
        drivingExperience = d;
    }

    void displayWorkerData() const {
        cout << "Surname: " << surname << endl;
        cout << "Age: " << age << endl;
        cout << "Driving Experience: " << drivingExperience << " years" << endl;
    }

    int getDrivingStartYear() const {
        time_t t = time(0);
        tm* now = localtime(&t);
        int currentYear = now->tm_year + 1900;
        return currentYear - drivingExperience;
    }
};

class Car {
private:
    string registrationNumber;
    string brand;
protected:
    int yearOfManufacture;
private:
    int mileage;
public:
    Car() : registrationNumber(""), brand(""), yearOfManufacture(0), mileage(0) {}

    Car(string rn, string b, int yom, int m) : registrationNumber(rn), brand(b), yearOfManufacture(yom), mileage(m) {}

    void setCarData(string rn, string b, int yom, int m) {
        registrationNumber = rn;
        brand = b;
        yearOfManufacture = yom;
        mileage = m;
    }

    void displayCarData() const {
        cout << "Registration Number: " << registrationNumber << endl;
        cout << "Brand: " << brand << endl;
        cout << "Year of Manufacture: " << yearOfManufacture << endl;
        cout << "Mileage: " << mileage << " km" << endl;
    }

    double getAverageAnnualMileage() const {
        time_t t = time(0);
        tm* now = localtime(&t);
        int currentYear = now->tm_year + 1900;
        int yearsInUse = currentYear - yearOfManufacture;
        return yearsInUse > 0 ? double(mileage) / yearsInUse : mileage;
    }
};

class Driver : public Worker, public Car {
private:
    int yearOfStartUsingCar;
    bool hasFines;
public:
    Driver(string s, int a, int d, string rn, string b, int yom, int m, int yosu, bool hf)
        : Worker(s, a, d), Car(rn, b, yom, m), yearOfStartUsingCar(yosu), hasFines(hf) {}

    void setDriverData(string s, int a, int d, string rn, string b, int yom, int m, int yosu, bool hf) {
        setWorkerData(s, a, d);
        setCarData(rn, b, yom, m);
        yearOfStartUsingCar = yosu;
        hasFines = hf;
    }

    void displayDriverData() const {
        displayWorkerData();
        displayCarData();
        cout << "Year of Start Using Car: " << yearOfStartUsingCar << endl;
        cout << "Has Fines: " << (hasFines ? "Yes" : "No") << endl;
    }

    void compareCarAgeAndDrivingExperience() const {
        time_t t = time(0);
        tm* now = localtime(&t);
        int currentYear = now->tm_year + 1900;
        int carAge = currentYear - yearOfManufacture;
        cout << "Car Age: " << carAge << " years" << endl;
        cout << "Driving Experience: " << drivingExperience << " years" << endl;

        if (carAge > drivingExperience)
            cout << "The car is older than the driver's driving experience." << endl;
        else if (carAge < drivingExperience)
            cout << "The driver's driving experience is longer than the car's age." << endl;
        else
            cout << "The car's age and the driver's driving experience are the same." << endl;
    }
};

int main() 
{
    Worker worker("Ridl", 36, 10);
    Car car("KA76590", "Audi", 2018, 280000);
    Driver driver("Smith", 30, 10, "AB1234CD", "Toyota", 2010, 150000, 2012, true);
    cout << "Worker Data:" << endl;
    worker.displayWorkerData();
    cout << "Driving Start Year: " << worker.getDrivingStartYear() << endl << endl;
    cout << "Car Data:" << endl;
    car.displayCarData();
    cout << "Average Annual Mileage: " << car.getAverageAnnualMileage() << " km/year" << endl << endl;
    cout << "Driver Data:" << endl;
    driver.displayDriverData();
    driver.compareCarAgeAndDrivingExperience();
    return 0;
}

