#include <iostream>
#include <iomanip>

using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    void setTime(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    void getTime() const {
        cout << setfill('0') << setw(2) << hours << ":" << setw(2) << minutes << ":" << setw(2) << seconds << endl;
    }

    Time operator+(const Time& t) const {
        int h = hours + t.hours;
        int m = minutes + t.minutes;
        int s = seconds + t.seconds;

        if (s >= 60) {
            m += s / 60;
            s %= 60;
        }
        if (m >= 60) {
            h += m / 60;
            m %= 60;
        }

        return Time(h, m, s);
    }

    Time operator-(const Time& t) const {
        int h = hours - t.hours;
        int m = minutes - t.minutes;
        int s = seconds - t.seconds;

        if (s < 0) {
            --m;
            s += 60;
        }
        if (m < 0) {
            --h;
            m += 60;
        }

        return Time(h, m, s);
    }

    bool operator>(const Time& t) const {
        if (hours > t.hours)
            return true;
        else if (hours == t.hours && minutes > t.minutes)
            return true;
        else if (hours == t.hours && minutes == t.minutes && seconds > t.seconds)
            return true;
        else
            return false;
    }

    bool operator<(const Time& t) const {
        return !(*this > t) && !(*this == t);
    }

    bool operator==(const Time& t) const {
        return hours == t.hours && minutes == t.minutes && seconds == t.seconds;
    }

    ~Time() {
        cout << "Destructor called" << endl;
    }
};

int main() {
    Time time1, time2, result;

    cout << "Enter time for first object (HH:MM:SS): ";
    int h, m, s;
    char colon;
    cin >> h >> colon >> m >> colon >> s;
    time1.setTime(h, m, s);

    cout << "Enter time for second object (HH:MM:SS): ";
    cin >> h >> colon >> m >> colon >> s;
    time2.setTime(h, m, s);

    cout << "Time for first object: ";
    time1.getTime();
    cout << "Time for second object: ";
    time2.getTime();

    result = time1 + time2;
    cout << "Addition: ";
    result.getTime();

    result = time1 - time2;
    cout << "Subtraction: ";
    result.getTime();

    if (time1 > time2)
        cout << "First object is greater than second object" << endl;
    else if (time1 < time2)
        cout << "First object is less than second object" << endl;
    else
        cout << "Both objects are equal" << endl;

    return 0;
}

