#ifndef CUSTOMER_MANAGER_H
#define CUSTOMER_MANAGER_H

#include "Account.h"
#include <vector>

class CustomerManager {
private:
    std::vector<Account*> accounts;

public:
    CustomerManager();
    ~CustomerManager();
    bool addAccount(Account* account);
    Account* getAccount(int accNum);
    void displayAllAccounts() const;
    bool closeAccount(int accNum);
};

#endif
