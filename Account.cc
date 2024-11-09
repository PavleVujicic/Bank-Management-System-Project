#include <iostream>
#include <string>
#include "Account.h"

Account::Account(int accNum, const std::string& name, double initialBalance, int pin, AccountType type)
    : accountNumber(accNum), pin(pin), type(type) {
    holderName = new std::string(name);
    balance = new double(initialBalance);
    description = new std::string();
}

Account::~Account() {
    delete holderName;
    delete balance;
    delete description;
}

bool Account::validatePIN(int enteredPIN) const {
    return pin == enteredPIN;
}

void Account::deposit(double amount) {
    if (amount > 0) {
        *balance += amount;
        std::cout << "Deposit successful." << std::endl;
        std::cout << "New Balance: $" << *balance << std::endl;
    } else {
        std::cout << "Invalid deposit amount." << std::endl;
    }
}

bool Account::withdraw(double amount) {
    if (amount <= *balance) {
        *balance -= amount;
        std::cout << "Withdrawal successful." << std::endl;
        std::cout << "New Balance: $" << *balance << std::endl;
        return true;
    } else {
        std::cout << "Insufficient balance." << std::endl;
        return false;
    }
}

bool Account::transfer(Account& toAccount, double amount) {
    if (withdraw(amount)) {
        toAccount.deposit(amount);
        std::cout << "Transfer successful." << std::endl;
        return true;
    } else {
        std::cout << "Transfer failed." << std::endl;
        return false;
    }
}

double Account::getBalance() const {
    return *balance;
}

void Account::displayAccountInfo() const {
    std::cout << "----Account Information----" << std::endl;
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Holder Name: " << *holderName << std::endl;
    std::cout << "Account Type: " << getAccountType() << std::endl;
    std::cout << "Balance: $" << *balance << std::endl;
    if (!description->empty()) {
        std::cout << "Description: " << *description << std::endl;
    }
}

void Account::setHolderName(const std::string& name) {
    *holderName = name;
}

std::string Account::getHolderName() const {
    return *holderName;
}

std::string Account::getAccountType() const {
    return (type == AccountType::Savings) ? "Savings" : "Checking";
}

void Account::setDescription(const std::string& desc) {
    *description = desc;
}

std::string Account::getDescription() const {
    return *description;
}

int Account::getAccountNumber() const { 
    return accountNumber; 
}
