#ifndef BUS_H
#define BUS_H

#include <iostream>
#include <vector>
#include <string>
#include "seats.h"

class Bus {
private:
    std::string busName; // Name of the bus
    int totalSeats; // Total number of seats in the bus
    int presentOccupants; // Number of present occupants
    std::vector<Seat> seats; // Vector to store the seats
    std::string route; // Route of the bus

public:
    Bus(const std::string& name, int seats, const std::string& route); // Constructor
    
    bool bookSeat(int seatNumber); // Book a seat
    const std::string& getBusName() const; // Get the name of the bus 
    int getTotalSeats() const;   // Get the total number of seats
    int getpresentOccupants() const;   // Get the number of present occupants
    const std::string& getRoute() const;   // Get the route of the bus
    const std::vector<Seat>& getSeats() const;  // Get the vector of seats
};

#endif // BUS_H
