#ifndef CUSTOMER_PORTAL_H
#define CUSTOMER_PORTAL_H

#include "CustomerManager.h"

class CustomerPortal {
private:
    CustomerManager& manager;

public:
    CustomerPortal(CustomerManager& manager);
    void showMenu();
    void createNewAccount();
    void login();
};

#endif
