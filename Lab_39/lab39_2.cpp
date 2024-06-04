#include <iostream>
#include <string>

using namespace std;

class Engine {
private:
    int power;
    string serialNumber;

public:
    Engine(int p = 0, string sn = "") : power(p), serialNumber(sn) {}

    ~Engine() {
        cout << "Destructor for Engine called" << endl;
    }

    void setEngineData(int p, string sn) {
        power = p;
        serialNumber = sn;
    }

    void displayEngineData() const {
        cout << "Power: " << power << " HP" << endl;
        cout << "Serial Number: " << serialNumber << endl;
    }
};

class Car : public Engine {
private:
    string brand;
    double price;

public:
    Car(int p = 0, string sn = "", string b = "", double pr = 0.0) : Engine(p, sn), brand(b), price(pr) {}

    ~Car() {
        cout << "Destructor for Car called" << endl;
    }

    void setCarData(int p, string sn, string b, double pr) {
        setEngineData(p, sn);
        brand = b;
        price = pr;
    }

    void displayCarData() const {
        displayEngineData();
        cout << "Brand: " << brand << endl;
        cout << "Price: $" << price << endl;
    }
};

class Truck : public Car {
private:
    double loadCapacity;

public:
    Truck(int p = 0, string sn = "", string b = "", double pr = 0.0, double lc = 0.0) 
        : Car(p, sn, b, pr), loadCapacity(lc) {}

    ~Truck() {
        cout << "Destructor for Truck called" << endl;
    }

    void setTruckData(int p, string sn, string b, double pr, double lc) {
        setCarData(p, sn, b, pr);
        loadCapacity = lc;
    }

    void displayTruckData() const {
        displayCarData();
        cout << "Load Capacity: " << loadCapacity << " tons" << endl;
    }
};

int main() 
{
    Engine engines[3];
    Car cars[3];
    Truck trucks[3];

    engines[0].setEngineData(150, "CE98231");
    engines[1].setEngineData(200, "CE66120");
    engines[2].setEngineData(250, "KA98712");

    for (int i = 0; i < 3; ++i) {
        cout << "Engine " << i + 1 << ":" << endl;
        engines[i].displayEngineData();
        cout << endl;
    }

    cars[0].setCarData(150, "CE98231", "Audi", 30000);
    cars[1].setCarData(200, "CE66120", "Jeep", 35000);
    cars[2].setCarData(250, "KA98712", "Rover", 42000);

    for (int i = 0; i < 3; ++i) {
        cout << "Car " << i + 1 << ":" << endl;
        cars[i].displayCarData();
        cout << endl;
    }

    trucks[0].setTruckData(300, "AA54381", "Ford", 55000, 10);
    trucks[1].setTruckData(350, "CE36766", "Kia", 68000, 15);
    trucks[2].setTruckData(400, "BA00888", "Seat", 80000, 20);

    for (int i = 0; i < 3; ++i) {
        cout << "Truck " << i + 1 << ":" << endl;
        trucks[i].displayTruckData();
        cout << endl;
    }

    return 0;
}

