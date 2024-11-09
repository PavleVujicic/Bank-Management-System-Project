#include "CustomerPortal.h"
#include <iostream>

CustomerPortal::CustomerPortal(CustomerManager& manager) : manager(manager) {}

void CustomerPortal::showMenu() {
    int choice;
    
    do {
        
        std::cout << "\n--- Customer Portal ---\n";
        std::cout << "1. Create New Account\n";
        std::cout << "2. Login to Your Account\n";
        std::cout << "3. Exit\n";
        
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                createNewAccount();
                break;
            case 2:
                login();
                break;
            case 3:
                
                std::cout << "Exiting Customer Portal..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != 3);
}

void CustomerPortal::createNewAccount() {
    
    int accNum, pin, accountTypeChoice;
    std::string name;
    double initialBalance;

    std::cout << "Enter Account Number: ";
    std::cin >> accNum;
    std::cout << "Enter Holder Name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter Initial Balance: $";
    std::cin >> initialBalance;

    do {
        std::cout << "Enter a 4-digit PIN: ";
        std::cin >> pin;
    } while (pin < 1000 || pin > 9999);

    std::cout << "Choose Account Type:\n";
    std::cout << "1. Savings\n";
    std::cout << "2. Checking\n";
    std::cout << "Option: ";
    std::cin >> accountTypeChoice;

    AccountType type = (accountTypeChoice == 1) ? AccountType::Savings : AccountType::Checking;

    if (manager.addAccount(new Account(accNum, name, initialBalance, pin, type))) {
        std::cout << std::endl;
        std::cout << "Account created successfully!" << std::endl;
    } else {
        std::cout << std::endl;
        std::cout << "Failed to create account. Try again." << std::endl;
    }
}

void CustomerPortal::login() {
    int accNum, enteredPIN;
    std::cout << "Enter Account Number: ";
    std::cin >> accNum;

    Account* account = manager.getAccount(accNum);
    if (!account) {
        std::cout << "Error: Account not found." << std::endl;
        return;
    }

    int attempts = 3;

    while (attempts > 0) {
        std::cout << "Enter 4-digit PIN: ";
        std::cin >> enteredPIN;

        if (account->validatePIN(enteredPIN)) {
            std::cout << std::endl << "Login successful!" << std::endl;
            int subChoice;
            do {
                std::cout << std::endl;
                std::cout << "1. Display Account Info" << std::endl;
                std::cout << "2. Deposit" << std::endl;
                std::cout << "3. Withdraw" << std::endl;
                std::cout << "4. Log out" << std::endl;
                std::cout << "Enter option: ";
                std::cin >> subChoice;

                switch (subChoice) {
                    case 1:
                        account->displayAccountInfo();
                        break;
                    case 2:
                        double depositAmount;
                        std::cout << "Enter deposit amount: $";
                        std::cin >> depositAmount;
                        account->deposit(depositAmount);
                        break;
                    case 3:
                        double withdrawAmount;
                        std::cout << "Enter withdrawal amount: $";
                        std::cin >> withdrawAmount;
                        if (!account->withdraw(withdrawAmount)) {
                            std::cout << "Insufficient funds." << std::endl;
                        }
                        break;
                    case 4:
                        std::cout << "Logging out..." << std::endl;
                        return;
                }
            } while (subChoice != 4);
        } else {
            attempts--;
            std::cout << "Invalid PIN. " << attempts << " attempt(s) remaining." << std::endl;
        }
    }
    std::cout << "Too many failed attempts. Returning to main menu." << std::endl;
}


