#pragma once
#include <iostream>
#include <string>
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