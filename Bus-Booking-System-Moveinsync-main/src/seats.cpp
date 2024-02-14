#include "seats.h"

Seat::Seat(int number) : seatNumber(number), isBooked(false) {}  // Constructor

int Seat::getSeatNumber() const {
    return seatNumber;  // Get the seat number
}

bool Seat::isSeatBooked() const {    // Check if the seat is booked
    return isBooked;
}

void Seat::bookSeat() {    // Book a seat
    isBooked = true;
}

