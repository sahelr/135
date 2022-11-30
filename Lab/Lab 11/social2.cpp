/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 11B
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
  int findID (std::string usrn);
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
};
int main() {
  Network nw;
  cout << nw.addUser("mario", "Mario") << endl;     // true (1)
  cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

  cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
  cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
  cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

  for(int i = 2; i < 20; i++)
      cout << nw.addUser("mario" + to_string(i), 
                 "Mario" + to_string(i)) << endl;   // true (1)

  cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
}
