/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 11A
The purpose of this program is to create the Profile class.
*/
// #include "social.hpp"
#include <iostream>
#include <string>
using namespace std;
class Profile {
private:
    std::string username;
    std::string displayname;
public:
    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    Profile(std::string usrn, std::string dspn):username(usrn), displayname(dspn) {}
    // Default Profile constructor (username="", displayname="")
    Profile():username(""), displayname("") {}
    // Return username
    std::string getUsername() const {return username;}
    // Return name in the format: "displayname (@username)"
    std::string getFullName() const {return displayname + " (@" + username + ")";}
    // Change display name
    void setDisplayName(std::string dspn) {displayname = dspn;}
};
int main() {
    Profile p1("marco", "Marco");    
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco (@marco)

    p1.setDisplayName("Marco Rossi"); 
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco Rossi (@marco)
    
    Profile p2("tarma1", "Tarma Roving");    
    cout << p2.getUsername() << endl; // tarma1
    cout << p2.getFullName() << endl; // Tarma Roving (@tarma1)
}
