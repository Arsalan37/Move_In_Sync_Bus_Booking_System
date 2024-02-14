#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <vector>
#include "bus.h"

class Admin {
private:
    const std::string savedAdminUsername = "arsalan";  // Admin username
    const std::string savedAdminPassword = "pass";   // Admin password

public:
    void adminPage(std::vector<Bus>& buses);   // Admin page
    void manageBusDetails(std::vector<Bus>& buses);  // Manage bus details

private:  // Private member functions
    void addBus(std::vector<Bus>& buses);  // Add a new bus
    void deleteBus(std::vector<Bus>& buses);  // Delete a bus
    void displayAllBuses(const std::vector<Bus>& buses);  // Display all the buses
};

#endif // ADMIN_H
