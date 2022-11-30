/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 11C
The purpose of this program is to create the Network class.
*/
// #include "social2.hpp"
#include <string>
#include <iostream>
#include <cctype>
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
class Network {
private:
  static const int MAX_USERS = 20; // max number of user profiles
  int numUsers;                    // number of registered users
  Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile

  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
  int findID (std::string usrn) {
    for (int i = 0; i < MAX_USERS; i++){
        if (profiles[i].getUsername() == usrn) {
             return i;
        }
    }
    return -1;
  }
  bool following[MAX_USERS][MAX_USERS];
public:
  // Constructor, makes an empty network (numUsers = 0)
  Network():numUsers(0){}
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
  bool addUser(std::string usrn, std::string dspn) {
    if(numUsers == MAX_USERS) {
        return false;
    }
    if(usrn == "") {
        return false;
    }
    for(int i = 0; i < usrn.length(); i++) {
        if(!isalnum(usrn[i])) {
            return false;
        }
    }
    for(int j = 0; j < MAX_USERS; j++) {
        if(profiles[j].getUsername() == usrn) {
            return false;
        }
    }
    Profile user(usrn,dspn);
    profiles[numUsers] = user;
    numUsers++;
    return true;
  }
  bool follow(string usrn1, string usrn2) {
    int u1,u2;
    u1 = findID(usrn1);
    u2 = findID(usrn2);
    if(u1 == -1 || u2 == -1) {
        return false;
    }
    following[u1][u2] = true;
    return true;
  }
  void printDot() {
    std::cout << "digraph {" << std::endl;
    for(int i = 0; i < numUsers; i++) {
        std::cout << "  \"@" + profiles[i].getUsername() + "\"" << std::endl;
    }
    std::cout << std::endl;
    for(int follower = 0; follower < numUsers; follower++) {
        for(int follow = 0; follow < numUsers; follow++) {
            if(following[follower][follow]) {
                std::cout << "  \"@" + profiles[follower].getUsername() + "\"" << " -> " << "\"@" + profiles[follow].getUsername() + "\"" << std::endl;
            }
        }
    }
    std::cout << "}";
  }
};
int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}