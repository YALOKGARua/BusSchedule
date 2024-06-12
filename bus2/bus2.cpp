#include "Bus2.h"

void Bus::input() {
    std::cout << "Enter bus number: ";
    std::cin >> NUM;
    std::cout << "Enter destination: ";
    std::cin >> CITY;
    std::cout << "Enter departure time (hours and minutes): ";
    std::cin >> TIME[0] >> TIME[1];
}

void Bus::print() const {
    std::cout << NUM << " " << CITY << " " << TIME[0] << ":" << TIME[1] << std::endl;
}

bool Bus::matchDestination(const std::string& destination) const {
    return CITY == destination;
}

bool Bus::inTimePeriod(int startHour, int startMinute, int endHour, int endMinute) const {
    int busTimeInMinutes = TIME[0] * 60 + TIME[1];
    int startTimeInMinutes = startHour * 60 + startMinute;
    int endTimeInMinutes = endHour * 60 + endMinute;
    return (busTimeInMinutes >= startTimeInMinutes && busTimeInMinutes <= endTimeInMinutes);
}
