#include "user.h"
#include <algorithm>
User::User(const std::string& usrnm, const std::string& pswrd) : username(usrnm), password(pswrd) {}  // Parameterized constructor
User::User() : username(""), password("") {}   // Default constructor


bool User::authenticate(const std::string& enteredUsername, const std::string& enteredPassword) const {  // Authenticate the user
    return (username == enteredUsername && password == enteredPassword);
}

const std::string& User::getUsername() const {  // Get the username
    return username;
}

const std::string& User::getPassword() const {  // Get the password
    return password;
}

const std::vector<int>& User::getBookedSeats() const {  // Get the booked seats
    return bookedSeats;
}

void User::checkAvailableBuses(const std::vector<Bus>& buses, const std::string& source, const std::string& destination) {
    bool flag=false;                            // Check if the bus follows the specified route
    for (size_t i = 0; i < buses.size(); ++i) {
        const Bus& currentBus = buses[i];

        int percentOccupancy = (currentBus.getpresentOccupants() * 100 / currentBus.getTotalSeats()); // Calculate the occupancy percentage

        if (percentOccupancy < 60) {
            std::cout << "\033[32m";  // Set text color to green
        } else if (percentOccupancy < 90) {
            std::cout << "\033[33m";  // Set text color to yellow
        } else {
            std::cout << "\033[31m";  // Set text color to red
        }
        // Check if the bus follows the specified route
        if (currentBus.getRoute() == source + "-" + destination) {
            flag=true;
            std::cout << "\nBuses that are available from " << source << " to " << destination << " are:\n";
            std::cout << "Bus " << i + 1 << " - " << currentBus.getBusName() << "\n";
            std::cout << "   Total Seats: " << currentBus.getTotalSeats() << "\n";
            std::cout << "   Occupancy: " << currentBus.getpresentOccupants() << "\n";
            std::cout << "   Available Seats: " << currentBus.getTotalSeats() - currentBus.getpresentOccupants()<< "\n";
            std::cout << "   Route: " << currentBus.getRoute() << "\n";
            std::cout << "\n";
        }
        std::cout << "\033[0m";  // Reset text color
    }
    if(flag==false)
        {
            std::cout << "\nNo buses are available from " << source << " to " << destination << "\n";  // No buses available
        }
}

void User::checkSeatAvailability(const Bus& bus) {
    std::cout << "\nSeat Availability for " << bus.getBusName() << ":\n";

    const std::vector<Seat>& seats = bus.getSeats();
    for (const Seat& seat : seats) {     // Loop through all the seats
        if (seat.isSeatBooked()) {
            std::cout << "\033[31m";
            std::cout << "Seat " << seat.getSeatNumber() << ": ";
            std::cout << "Booked\n";
            std::cout << "\033[0m";
        } else {                             // Check if the seat is booked
            std::cout << "\033[32m";
            std::cout << "Seat " << seat.getSeatNumber() << ": ";
            std::cout << "Available\n";
            std::cout << "\033[0m";
        }
    }
}

bool User::bookSeat(Bus& bus, int seatNumber) {            // Book a seat
    if (seatNumber >= 1 && seatNumber <= bus.getTotalSeats()) {
        if (!bus.getSeats()[seatNumber - 1].isSeatBooked()) {
            bus.bookSeat(seatNumber);
            bookedSeats.push_back(seatNumber);  // Associate the booked seat with the user
            std::cout << "\nPreferred seat " << seatNumber << " has been booked successfully!\n";
            return true;
        } else {
            std::cout << "\nThe particular seat " << seatNumber << " is already booked. Please Choose another seat.\n";
        }
    } else {
        std::cout << "\nPlease enter a valid seat number.\n";
    }
    return false;
}

