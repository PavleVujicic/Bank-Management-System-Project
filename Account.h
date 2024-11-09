#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>

enum class AccountType { Savings, Checking };

class Account {
private:
    int accountNumber;
    std::string* holderName;       
    double* balance;               
    int pin;
    AccountType type;
    std::string* description;

public:
    Account(int accNum, const std::string& name, double initialBalance, int pin, AccountType type);
    ~Account();
    bool validatePIN(int enteredPIN) const;
    void deposit(double amount);
    bool withdraw(double amount);
    bool transfer(Account& toAccount, double amount);
    double getBalance() const;
    void displayAccountInfo() const;
    void setHolderName(const std::string& name);
    std::string getHolderName() const;
    std::string getAccountType() const;
    void setDescription(const std::string& desc);
    std::string getDescription() const;
    int getAccountNumber() const;
};

#endif
