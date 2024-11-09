#include "EmployeePortal.h"
#include <iostream>

//access code
const int EmployeePortal::ACCESS_CODE = 1234;

EmployeePortal::EmployeePortal(CustomerManager& manager) : manager(manager) {}

bool EmployeePortal::authenticate() {
    
    int code;
    std::cout << "Enter Employee Access Code: ";
    std::cin >> code;

    if (code == ACCESS_CODE) {
        std::cout << "Access granted." << std::endl;
        return true;
    } else {
        std::cout << "Invalid access code. Access denied." << std::endl;
        return false;
    }
}

void EmployeePortal::showMenu() {
    if (!authenticate()) {
        std::cout << "Returning to main menu..." << std::endl;
        return;
    }

    int choice;
    do {
        
        std::cout << "\n--- Employee Portal ---\n";
        std::cout << "1. View All Accounts\n";
        std::cout << "2. Close an Account\n";
        std::cout << "3. Generate Report\n";
        std::cout << "4. Exit\n";

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                
                manager.displayAllAccounts();
                break;
            case 2:
                closeAccount();
                break;
            case 3:
                generateReport();
                break;
            case 4:
                std::cout << "Exiting Employee Portal..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != 4);
}

void EmployeePortal::closeAccount() {
    
    int accNum;
    std::cout << "Enter the Account Number to close: ";
    std::cin >> accNum;

    if (manager.closeAccount(accNum)) {
        std::cout << "Account closed successfully." << std::endl;
    } else {
        std::cout << "Error: Account not found." << std::endl;
    }
}

void EmployeePortal::generateReport() const {
    int accNum;
    std::cout << "--- Bank Report ---" << std::endl;
    manager.displayAllAccounts(); 

    std::cout << "Enter the Account Number for the report: ";
    std::cin >> accNum;

    Account* account = manager.getAccount(accNum);
    if (!account) {
        std::cout << "Error: Account not found." << std::endl;
        return;
    }

    
    std::string currentDesc = account->getDescription();
    if (!currentDesc.empty()) {
        std::cout << "Current Description: " << currentDesc << std::endl;
        std::cout << "Do you want to replace the existing description? (yes/no): ";
        std::string response;
        std::cin >> response;
        if (response != "yes") {
            return;
        }
    }

    
    std::cout << "Enter new description: ";
    std::cin.ignore(); 
    std::getline(std::cin, currentDesc);
    account->setDescription(currentDesc);
    std::cout << "Description updated successfully!" << std::endl;
}
