# Bank Management System

## Creator

**Name**: Pavle Vujicic

## Overview
The **Bank Management System** is a hybrid solution that provides separate 
portals for **customers** and **employees**, ensuring efficient and secure 
handling of banking operations. This system is designed with a focus on simplicity, 
role-based access, and transaction integrity.

---

## Features

### **Customer Portal**
- **Create New Account**: Customers can create accounts by providing:
  - **Account Number**
  - **Holder Name**
  - **Initial Balance**
  - **4-Digit PIN** for future authentication
  - **Account Type**: Savings or Checking
- **Login to Account**: Customers must log in using their **Account Number** and **PIN**.
- **Account Management**:
  - View account balance
  - Deposit money
  - Withdraw money

### **Employee Portal**
- **Secured Access**: Employees must enter the **access code (1234)** to access the portal.
- **View All Accounts**: Displays all customer accounts with detailed information.
- **Close Accounts**: Allows employees to close a customer’s account.
- **Generate Reports**: Summarizes all accounts in the system.

---

## Program Flow

### **Main Menu**:
- Choose either **Customer Portal** or **Employee Portal**.

### **Customer Portal**:
1. **Create a New Account**:
   - Enter the required account details.
   - Set a **4-digit PIN** for future logins.
2. **Log In Using Account Number and PIN**:
   - If the login is successful, access the account.
3. **Perform Transactions**:
   - **Deposit** money into the account.
   - **Withdraw** money from the account.

### **Employee Portal**:
1. **Enter the Access Code**:
   - Input the **access code (1234)** to enter the portal.
2. **Manage Customer Accounts**:
   - View all customer accounts.
   - **Close accounts** if needed.
3. **Generate Reports**:
   - Get a detailed report of all accounts.

---

## Code Structure

### **Account Class**
The `Account` class manages individual customer accounts. It provides methods for:
- **Deposits, Withdrawals, and Transfers**
- **PIN validation** during login
- **Displaying account information**

### **CustomerManager Class**
The `CustomerManager` class acts as a bridge between the portals and the customer accounts. It manages:
- **Adding new accounts**
- **Retrieving and closing accounts**
- **Displaying all accounts**

### **Customer Portal**
- Customers can **create accounts**, **log in**, and **perform transactions**.
- The **4-digit PIN** is mandatory for authentication during login.

### **Employee Portal**
- The **access code (1234)** is required to access the Employee Portal.
- Employees can **view all accounts, close accounts, and generate reports**.

---

## How to Use

### **Compilation And Execution Instructions**

1. Make sure you in the project directory inside the terminal
2. Write in the command line to clean any object files just in case: make clean
3. Write in the command line to compile: make all
4. Write in the command line to execute program: ./BankSystem
