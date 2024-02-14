#include "user.cpp"
#include "admin.cpp"
#include "bus.cpp"
#include "seats.cpp"
#include <bits/stdc++.h>
using namespace std;

#define YELLOW  "\033[33m"   // Set text color to yellow
#define RESET   "\033[0m"    // Reset text color
#define RED     "\033[31m"   // Set text color to red
#define GREEN   "\033[32m"   // Set text color to green

void adminMenu(vector<Bus>& buses) {
    Admin admin;
    int choice;
    while(true){    // Loop until the user chooses to exit
        cout << "\nAdmin Page:\n";
        cout << "Press 1 manage bus details\n";
        cout << "Press 2 to go back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1){ 
            admin.adminPage(buses);
            break;
        }
        else if (choice == 2) 
        {
            return;
            }  // Exit admin menu}
        else
        { // Invalid choice
                cout << "Enter a valid choice.\n";
        }
    }
}
void displayMainMenu() { // Display the main menu
    cout<< "\nWelcome to Bus Booking System : Made By Shah Arsalan : 12102195\n";
    cout << "Press 1 to enter into User Mode \n";
    cout << "Press 2 to enter into Admin Mode  \n";
    cout << "Press 3 to Exit\n";
    cout << "Enter your choice: \n";
}

void performUserActions(std::vector<Bus>& buses, User& currentUser) { // Perform user actions
    int choice;

    while(true){
        std::cout << "\nUser Page:\n";
        std::cout << "Press 1 to check the available buses\n";
        std::cout << "Press 2 to book a seat\n";
        std::cout << "Press 3 to Go back\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {  // Check available buses
                std::string source, destination;
                std::cout << "Enter Source: ";
                std::cin >> source;
                std::cout << "Enter destination: ";
                std::cin >> destination;
                currentUser.checkAvailableBuses(buses, source, destination);
            } 
        else if (choice == 2) {
                int busIndex, seatNumber;
                std::cout << "Enter the bus number: ";
                std::cin >> busIndex;
                std::cout << "Enter the seat number: ";
                std::cin >> seatNumber;
                if (currentUser.bookSeat(buses[busIndex - 1], seatNumber)) {
                    std::cout << "\nSeat booked successfully!\n";
                } else {
                    std::cout << "\nCan't perform this operation.\n";
                }
            }   
        else if (choice == 3) {
                break;
                // Exit user menu
            } 
            else {
                std::cout << "\nNot a valid choice. Try again\n";
            }
    }
}

void userMenu(std::vector<Bus>& buses, std::vector<User>& users) {
    std::string Username, Password;
    User currentUser;
    users.push_back(User("arsalan","1"));
    users.push_back(User("void","2"));
    bool foundUser = false;
    do {     // Loop until the user chooses to exit
        std::cout << "\nUser Menu:\n";
        std::cout << "Press 1 to Login\n";
        std::cout << "Press 2 to go back to Main Menu\n";
        std::cout << "Enter your choice: ";
        int userchoice;
        std::cin >> userchoice;
        foundUser = false;
        switch (userchoice) {
            case 1: {
                std::cout << "\nWelcome to Login Page\n";   // Login
                std::cout << "Enter your username: ";
                std::cin >>Username;
                std::cout << "Enter your password: ";
                std::cin >>Password;

                // Find the user in the vector based on entered credentials
                for (User& user : users) {               // Loop through the vector of users
                    if (user.authenticate(Username, Password)) {    // Check if the entered credentials are correct
                        std::cout << "Login successful!\n";
                        currentUser = user;  // Set the current user
                        foundUser = true;     // Set the flag to true
                        performUserActions(buses, currentUser);  // Call the function for user options
                        break;
                    }
                }

                if (!foundUser) {   // If the user is not found
                    std::cout << "Please enter a valid username or password . Try again.\n";
                }
                break;
                
            }
            case 2:
                // Back to Main Menu
                return;  // Exit the userMenu function
            default:
                std::cout << "Enter a valid choice.Try again\n";
        }
    } while (true);
}



int main() {
    std::vector<Bus> buses;   // Vector of buses
    std::vector<User> users; // Vector of users

    buses.push_back(Bus("moveinsync bus1", 5, "jammu-kashmir"));
    buses.push_back(Bus("moveinsync bus2", 30, "punjab-amritsar"));

    int choice;

    do {                                    // Loop until the user chooses to exit
        displayMainMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                userMenu(buses, users);
                break;
            case 2:
                adminMenu(buses);
                break;
            case 3:
                std::cout << "Terminating the execution.\n";
                break;
            default:
                std::cout << "Enter a valid choice. Try again.\n";
                break;
        }
    } while (choice != 3);

    return 0;
}