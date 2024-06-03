#include <iostream>
#include <stdlib.h>

using namespace std;

class Ticket {
private:
    char destination[50];
    int trainNumber;
    char departureTime[10];
    int coupeSeats;
    int reservedSeats;

public:
    Ticket() {
        trainNumber = 0;
        coupeSeats = 0;
        reservedSeats = 0;
    }
    Ticket(const char* dest, int number, const char* time, int coupe, int reserved) {
        int i = 0;
        while (*(dest + i) != '\0' && i < 49) {
            destination[i] = *(dest + i);
            i++;
        }
        destination[i] = '\0';
        trainNumber = number;
        i = 0;
        while (*(time + i) != '\0' && i < 9) {
            departureTime[i] = *(time + i);
            i++;
        }
        departureTime[i] = '\0';
        coupeSeats = coupe;
        reservedSeats = reserved;
    }

    int sum() {
        return coupeSeats + reservedSeats;
    }

    float percent() {
        if (sum() == 0) return 0;
        return static_cast<float>(reservedSeats) / sum() * 100;
    }
};

int main() {
    Ticket defaultTicket;
    Ticket myTicket("Kyiv", 165, "16:30", 70, 130);
    cout << "Total seats: " << myTicket.sum() << endl;
    cout << "Percentage of reserved seats: " << myTicket.percent() << "%" << endl;
    return EXIT_SUCCESS;
}

