#include "admin.h"

void Admin::adminPage(std::vector<Bus>& buses) {
    std::string Username, Password;
    while(true){ // Loop until the correct username and password are entered
    std::cout << "\nWelcome "<<savedAdminUsername<<" to Admin Login:\n";
    std::cout << "Enter your Username: ";
    std::cin >> Username;
    std::cout << "Enter your Password: ";
    std::cin >> Password;

    if (Username == savedAdminUsername && Password == savedAdminPassword) { // Check if the entered username and password are correct
        std::cout << "\nLogin successful!\n";
        manageBusDetails(buses);  // Call the existing admin menu function
        break;
    } 
    else {
        std::cout << "\nAccess not granted. Enter a valid username or password.\n";
    }
    }
}

void Admin::manageBusDetails(std::vector<Bus>& buses) { // Manage bus details
    int choice;

    do {  // Loop until the user chooses to exit
        std::cout << "\nBuses Information:\n";
        std::cout << "Press 1 to check all the buses\n";
        std::cout << "Press 2 to Delete the bus information\n";
        std::cout << "Press 3 to add a new bus\n";
        std::cout << "Press 4 to Terminate\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {    // Switch case for different choices
            case 1:
                displayAllBuses(buses);
                break;
            case 2:
                deleteBus(buses);
                break;
            case 3:
                addBus(buses);
                break;
            case 4:
                return; // Exit manage bus details menu
            default:
                std::cout << "\nInvalid choice. Try again.\n";
        }
    } while (choice != 5);
}

void Admin::addBus(std::vector<Bus>& buses) {   // Add a new bus
    int totalSeats;
    double distance, estimatedTravelTime;
    std::string busName, route;
    std::cout << "\nEnter Bus Details:\n";
    std::cout << "Enter Bus Name: ";
    std::getline(std::cin >> std::ws, busName);
    std::cout << "Enter Total Seats: ";
    std::cin >> totalSeats;
    std::cout << "Enter Route: ";
    std::cin >> route;
    

    buses.push_back(Bus(busName, totalSeats, route));  // Add the bus to the vector
    std::cout << "\nBus added successfully!\n";
}

void Admin::deleteBus(std::vector<Bus>& buses) {  // Delete bus information
    int busIndex;

    std::cout << "\nEnter the bus number which you to delete: ";
    std::cin >> busIndex;

    if (busIndex >= 1 && busIndex <= buses.size()) { // Check if the entered bus number is valid
        // Erase the bus at the specified index
        buses.erase(buses.begin() + busIndex - 1);
        std::cout << "\nBus information removed.\n";
    } else {
        std::cout << "\nThere is no such bus with the entered bus number. Please enter a valid bus number.\n";
    }
}

void Admin::displayAllBuses(const std::vector<Bus>& buses) {
    std::cout << "\nAll Buses:\n";
    for (size_t i = 0; i < buses.size(); ++i) {  // Loop through all the buses
        const Bus& currentBus = buses[i];
        std::cout << "Bus " << i + 1 << " - " << currentBus.getBusName() << "\n";
        std::cout << "   Route: " << currentBus.getRoute() << "\n";
        std::cout << "   Total Seats: " << currentBus.getTotalSeats() << "\n";
        std::cout << "   Occupancy: " << currentBus.getpresentOccupants() << "\n";
        std::cout << "   Available Seats: " << currentBus.getTotalSeats() - currentBus.getpresentOccupants() << "\n";
        std::cout << "\n";
    }
}
