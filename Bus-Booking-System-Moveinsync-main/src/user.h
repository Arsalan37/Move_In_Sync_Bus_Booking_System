#ifndef USER_H    // USER_H
#define USER_H  // USER_H

#include <iostream>
#include <vector>
#include <string>
#include "bus.h"

class User {
private:
    std::string username;
    std::string password;
    std::vector<int> bookedSeats;

public:
    User();
    User(const std::string& usrnm, const std::string& pswrd);

    const std::string& getUsername() const;
    const std::string& getPassword() const;

    bool authenticate(const std::string& enteredUsername, const std::string& enteredPassword) const; // Authenticate the user

    void checkAvailableBuses(const std::vector<Bus>& buses, const std::string& source, const std::string& destination);
    bool bookSeat(Bus& bus, int seatNumber);
};

#endif // USER_H
