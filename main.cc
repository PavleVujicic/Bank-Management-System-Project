#include "CustomerPortal.h"
#include "EmployeePortal.h"
#include "CustomerManager.h"
#include <iostream>

int main() {
    CustomerManager manager;
    CustomerPortal customerPortal(manager);
    EmployeePortal employeePortal(manager);

    int choice;

    do {

        std::cout << "\n--- Bank Management System ---\n";
        std::cout << "1. Customer Portal\n";
        std::cout << "2. Employee Portal\n";
        std::cout << "3. Exit\n";

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                customerPortal.showMenu();
                break;
            case 2:
                if (employeePortal.authenticate()) {
                    employeePortal.showMenu();
                } else {
                    std::cout << "Returning to the main menu..." << std::endl;
                }
                break;
            case 3:
                std::cout << "Exiting the system..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 3);

    return 0;
}
