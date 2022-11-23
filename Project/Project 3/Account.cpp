/* 
Author: Sahel Reja
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 3A
The purpose of this program is to define the functions of the class in the header file.
*/
#include <iostream>
#include <string>
#include <cmath>
#include "Account.hpp"
std::string Account::generateAccountNumber(){
    std::string an_str = "";
    for(int i{0}; i < 8; i++ ){
        int temp = rand() % 10;
        an_str += std::to_string(temp);
    }
    return an_str;
}
Account::Account() {
    firstName = "anonymous";
    lastName = "anonymous";
    pin = "0000";
    accountNumber = generateAccountNumber();
    accountBalance = 0;
}
void Account::setFirstName(std::string first) {
    firstName = first;
}
void Account::setLastName(std::string last) {
    lastName = last;
}
bool Account::setPin(std::string p) {
    if(p.length() != 4) {
        return false;
    }
    for(int i = 0; i < p.length(); i++) {
        if(!isdigit(p[i])) {
            return false;
        }
    }
    pin = p;
    return true;
}
Account::Account(std::string first, std::string last, std::string p) {
    setFirstName(first);
    setLastName(last);
    if(!setPin(p)) {
        pin = "0000";
    }
    accountNumber = generateAccountNumber();
    accountBalance = 0;
}
std::string Account::getFirstName() const {
    return firstName;
}
std::string Account::getLastName() const {
     return lastName;
}
std::string Account::getAccountNumber() const {
    return accountNumber;
}
std::string Account::getPin() const {
    return pin;
}
int Account::getBalance() const {
    return accountBalance;
}
bool Account::transaction(int deposit){
    if(accountBalance + deposit < 0) {
        return false;
    }
    accountBalance += deposit;
    return true;
}