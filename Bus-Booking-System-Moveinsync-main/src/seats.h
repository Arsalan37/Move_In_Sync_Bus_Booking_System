#ifndef SEATS_H
#define SEATS_H

class Seat {
private:
    int seatNumber;  // Seat number
    bool isBooked;   // Check if the seat is booked

public:
    Seat(int number);
    int getSeatNumber() const;   // Get the seat number
    bool isSeatBooked() const;   // Check if the seat is booked
    void bookSeat();             // Book a seat
};

#endif // SEAT_H
