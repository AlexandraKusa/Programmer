#include <iostream>
#include <string>

using namespace std;

class Flat {
private:
    string address;
    int floor;
    int rooms;
    double area;

public:
    Flat() : address(""), floor(0), rooms(2), area(55.0) {}

    Flat(string addr, int fl) : address(addr), floor(fl), rooms(2), area(55.0) {}

    void input() {
        cout << "Enter address: ";
        cin >> address;
        cout << "Enter floor: ";
        cin >> floor;
        cout << "Enter number of rooms: ";
        cin >> rooms;
        cout << "Enter area: ";
        cin >> area;
    }

    void output() const {
        cout << "Address: " << address << ", Floor: " << floor
             << ", Number of rooms: " << rooms << ", Area: " << area << " sqm" << endl;
    }

    int getRooms() const {
        return rooms;
    }

    double getArea() const {
        return area;
    }

    int getFloor() const {
        return floor;
    }
};

void printFlatsByRooms(const Flat flats[], int size, int rooms) {
    cout << "Flats with " << rooms << " rooms:" << endl;
    for (int i = 0; i < size; ++i) {
        if (flats[i].getRooms() == rooms) {
            flats[i].output();
        }
    }
}

void printFlatsByAreaAndFloor(const Flat flats[], int size, double maxArea, int minFloor, int maxFloor) {
    cout << "Flats with area up to " << maxArea << " sqm and located between floors " << minFloor << " and " << maxFloor << ":" << endl;
    for (int i = 0; i < size; ++i) {
        if (flats[i].getArea() <= maxArea && flats[i].getFloor() >= minFloor && flats[i].getFloor() <= maxFloor) {
            flats[i].output();
        }
    }
}

int main() {
    const int numberOfFlats = 4; 
    Flat flats[numberOfFlats] = {
        Flat("Storozynet", 5),
        Flat("Smotryrska", 1),
        Flat("Parkova", 2),
        Flat() 
    };

    for (int i = 0; i < numberOfFlats - 1; ++i) {
        flats[i].output();
    }

    flats[numberOfFlats - 1].input();

    printFlatsByRooms(flats, numberOfFlats, 2);

    printFlatsByAreaAndFloor(flats, numberOfFlats, 40.0, 1, 4);

    return 0;
}

