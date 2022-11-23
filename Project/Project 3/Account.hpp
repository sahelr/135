
/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 3A
The purpose of this program is define a class called Account with public and private members.
*/
#pragma once
#include <string>
#include <iostream>
class Account {
    private:
    std::string generateAccountNumber();
    std::string firstName;
    std::string lastName;
    std::string accountNumber;
    std::string pin;
    int accountBalance;
    public:
    Account();
    void setFirstName(std::string first);
    void setLastName(std::string last);
    bool setPin(std::string p);
    Account(std::string first, std::string last, std::string p);
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getAccountNumber() const;
    std::string getPin() const;
    int getBalance() const;
    bool transaction(int deposit);
};
