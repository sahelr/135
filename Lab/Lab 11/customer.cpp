/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab Quiz #12
The purpose of this program is to create the Customer Class.
*/
#include <iostream>
#include <string>
class Customer {
    private:
        std::string name;
        std::string unique_id;
    public:
    Customer():name(""),unique_id("") {}
    Customer(std::string name, std::string unique_id) {
        this->name = name;
        this->unique_id = unique_id;
    }
    std::string get_name() {return name;}
    std::string get_unique_id() {return unique_id;}
    void set_name(std::string name) {this->name = name;}
    void set_unique_id(std::string unique_id) {this->unique_id = unique_id;}
};