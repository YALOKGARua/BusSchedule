#include "utility.h"

void inputSchedule(std::ofstream& file, int n) {
    Bus bus;
    for (int i = 0; i < n; i++) {
        bus.input();
        file << bus.NUM << " " << bus.CITY << " " << bus.TIME[0] << " " << bus.TIME[1] << std::endl;
    }
}

void printSchedule(std::ifstream& file) {
    Bus bus;
    std::cout << "\nSchedule:\n";
    while (file >> bus.NUM >> bus.CITY >> bus.TIME[0] >> bus.TIME[1]) {
        bus.print();
    }
}

void findBusesToDestination(std::ifstream& file, const std::string& destination) {
    Bus bus;
    bool found = false;
    std::cout << "\nBuses to destination " << destination << ":\n";
    while (file >> bus.NUM >> bus.CITY >> bus.TIME[0] >> bus.TIME[1]) {
        if (bus.matchDestination(destination)) {
            bus.print();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No buses to destination " << destination << " found.\n";
    }
}

void findBusesInTimePeriod(std::ifstream& file, int startHour, int startMinute, int endHour, int endMinute) {
    Bus bus;
    bool found = false;
    std::cout << "\nBuses from " << startHour << ":" << startMinute << " to " << endHour << ":" << endMinute << ":\n";
    while (file >> bus.NUM >> bus.CITY >> bus.TIME[0] >> bus.TIME[1]) {
        if (bus.inTimePeriod(startHour, startMinute, endHour, endMinute)) {
            bus.print();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No buses found in the specified time period.\n";
    }
}
