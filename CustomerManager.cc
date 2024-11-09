#include "CustomerManager.h"
#include <iostream>

CustomerManager::CustomerManager(){
    accounts.push_back(new Account(101, "John Doe", 1500.0, 1234, AccountType::Checking));
        accounts.push_back(new Account(102, "Jane Smith", 2500.0, 5678, AccountType::Savings));
        accounts.push_back(new Account(103, "Alice Johnson", 3000.0, 4321, AccountType::Checking));
        accounts.push_back(new Account(104, "Michael Brown", 1800.0, 2345, AccountType::Savings));
        accounts.push_back(new Account(105, "Linda Black", 2400.0, 3456, AccountType::Checking));
        accounts.push_back(new Account(106, "Josh Green", 5000.0, 4567, AccountType::Savings));
        accounts.push_back(new Account(107, "Emily White", 2600.0, 5678, AccountType::Checking));
        accounts.push_back(new Account(108, "James King", 3900.0, 6789, AccountType::Savings));
        accounts.push_back(new Account(109, "Patricia Hall", 4700.0, 7890, AccountType::Checking));
        accounts.push_back(new Account(110, "Robert Lee", 5500.0, 8901, AccountType::Savings));
}

CustomerManager::~CustomerManager() {
    for (auto account : accounts) {
        delete account;
    }
    accounts.clear();
}

bool CustomerManager::addAccount(Account* account) {
    if (getAccount(account->getAccountNumber())) {
        std::cout << "Error: Account with this number already exists." << std::endl;
        return false;
    }
    accounts.push_back(account);
    return true;
}

Account* CustomerManager::getAccount(int accNum) {
    for (auto account : accounts) {
        if (account->getAccountNumber() == accNum) {
            return account;
        }
    }
    return nullptr;
}

void CustomerManager::displayAllAccounts() const {
    if (accounts.empty()) {
        std::cout << "No accounts available." << std::endl;
        return;
    }
    for (const auto& account : accounts) {
        account->displayAccountInfo();  
        std::cout << "-------------------------" << std::endl;
    }
}

bool CustomerManager::closeAccount(int accNum) {
    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if ((*it)->getAccountNumber() == accNum) {
            delete *it;
            accounts.erase(it);
            std::cout << "Account closed successfully." << std::endl;
            return true;
        }
    }
    std::cout << "Error: Account not found." << std::endl;
    return false;
}

