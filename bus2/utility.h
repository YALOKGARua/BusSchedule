#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Bus2.h"

void inputSchedule(std::ofstream& file, int n);
void printSchedule(std::ifstream& file);
void findBusesToDestination(std::ifstream& file, const std::string& destination);
void findBusesInTimePeriod(std::ifstream& file, int startHour, int startMinute, int endHour, int endMinute);

#endif // UTILITY_H
