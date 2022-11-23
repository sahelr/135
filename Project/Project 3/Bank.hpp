/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 3B
The purpose of this program is define a class called Bank with the corresponding members that is a a superset of the Account class.
*/
#include "Account.hpp"
#include <string>
#ifndef BANK_HPP
#define BANK_HPP
class Bank {
    private:
    Account accounts[200];
    int accountTotal;
    public:
    Bank();
    std::string createAccount(std::string first, std::string last, std::string p);
    bool removeAccount(std::string accountNum);
    bool withdraw(int amount, std::string accountNum, std::string p);
    bool deposit(int amount, std::string accountNum, std::string p);
    int getAccountBalance(std::string accountNum, std::string p);
};
#endif