#include <iostream>
#include <fstream>
#include <string>
#include "utility.h"

int main() {
    std::ofstream outFile("schedule.txt", std::ios::app);
    if (!outFile) {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }

    int n;
    std::cout << "Enter the number of buses: ";
    std::cin >> n;

    inputSchedule(outFile, n);
    outFile.close();

    std::ifstream inFile("schedule.txt");
    if (!inFile) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }

    printSchedule(inFile);
    inFile.close();

    std::string destination;
    std::cout << "\nEnter destination to search for buses: ";
    std::cin >> destination;
    inFile.open("schedule.txt");
    if (!inFile) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }
    findBusesToDestination(inFile, destination);
    inFile.close();

    int startHour, startMinute, endHour, endMinute;
    std::cout << "\nEnter start time (hours and minutes): ";
    std::cin >> startHour >> startMinute;
    std::cout << "Enter end time (hours and minutes): ";
    std::cin >> endHour >> endMinute;
    inFile.open("schedule.txt");
    if (!inFile) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }
    findBusesInTimePeriod(inFile, startHour, startMinute, endHour, endMinute);
    inFile.close();

    return 0;
}
