/* 
Author: Sahel Reja
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 3B
The purpose of this program is to define the functions of the class in the header file.
*/
#include "Bank.hpp"
Bank::Bank() {
    accountTotal = 0;
}
std::string Bank::createAccount(std::string first, std::string last, std::string p) {
    Account a(first,last,p);
    if(accountTotal < 200) {
        accounts[accountTotal] = a;
        accountTotal++;
    }
    else {
        return "-1";
    }
    return a.getAccountNumber();
}
bool Bank::removeAccount(std::string accountNum) {
    Account empty;
    for(int i = 0; i < 200; i++) {
        if(accounts[i].getAccountNumber() == accountNum) {
            accounts[i] = empty;
            accountTotal--;
            return true;
        }
    }
    return false;
}
bool Bank::withdraw(int amount, std::string accountNum, std::string p) {
    for(int i = 0; i < 200; i++) {
        if(accounts[i].getAccountNumber() == accountNum) {
            if(accounts[i].getPin() == p) {
                if(accounts[i].transaction(-1* amount)) {
                    return true;
                }
            }
        }
    }
    return false;
}
bool Bank::deposit(int amount, std::string accountNum, std::string p) {
    for(int i = 0; i < 200; i++) {
        if(accounts[i].getAccountNumber() == accountNum) {
            if(accounts[i].getPin() == p) {
                if(accounts[i].transaction(amount)) {
                    return true;
                }
            }
        }
    }
    return false;
}
int Bank::getAccountBalance(std::string accountNum, std::string p) {
    for(int i = 0; i < 200; i++) {
        if(accounts[i].getAccountNumber() == accountNum) {
            if(accounts[i].getPin() == p) {
                return accounts[i].getBalance();
            }
        }
    }
    return -1;
}