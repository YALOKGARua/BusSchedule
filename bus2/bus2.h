#ifndef BUS_H
#define BUS_H

#include <iostream>
#include <string>

class Bus {
public:
    int NUM;
    std::string CITY;
    int TIME[2];

    void input();
    void print() const;
    bool matchDestination(const std::string& destination) const;
    bool inTimePeriod(int startHour, int startMinute, int endHour, int endMinute) const;
};

#endif 
