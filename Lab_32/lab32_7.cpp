#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <cstdlib>

int main() {
    auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    struct tm* localTime = localtime(&now);
    cout << put_time(localTime, "%d-%m-%Y %H:%M:%S") << endl;
    return EXIT_SUCCESS;
}

