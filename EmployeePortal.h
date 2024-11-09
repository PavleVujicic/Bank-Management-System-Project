#ifndef EMPLOYEE_PORTAL_H
#define EMPLOYEE_PORTAL_H

#include "CustomerManager.h"

class EmployeePortal {
private:
    CustomerManager& manager;
    static const int ACCESS_CODE;  // Employee access code

public:
    EmployeePortal(CustomerManager& manager);
    bool authenticate(); 
    void showMenu();  
    void closeAccount();
    void generateReport() const;  
};

#endif
