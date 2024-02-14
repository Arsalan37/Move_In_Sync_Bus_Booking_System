#include "bus.h"

Bus::Bus(const std::string& name, int seats, const std::string& route)
    : busName(name), totalSeats(seats), presentOccupants(0), route(route) {
    // Initialize seats
    for (int i = 1; i <= totalSeats; ++i) {
        Seat seat(i);
        this->seats.push_back(seat);
    }
}
bool Bus::bookSeat(int seatNumber) {  // Book a seat
    if (seatNumber >= 1 && seatNumber <= totalSeats) {  // Check if the seat number is valid
        if (!seats[seatNumber - 1].isSeatBooked()) {  // Check if the seat is not already booked
            seats[seatNumber - 1].bookSeat();
            presentOccupants++;
            return true;
        } else {
            return false; // Seat is already booked
        }
    } else {
        return false; // Invalid seat number
    }
}

const std::string& Bus::getBusName() const {  // Get the name of the bus
    return busName;
}

int Bus::getTotalSeats() const {  // Get the total number of seats
    return totalSeats;
}

int Bus::getpresentOccupants() const {  // Get the number of present occupants
    return presentOccupants;
}  

const std::string& Bus::getRoute() const {  // Get the route of the bus
    return route;
}

const std::vector<Seat>& Bus::getSeats() const {  // Get the vector of seats
    return seats;
}


