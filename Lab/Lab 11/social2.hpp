#ifndef SOCIAL2_HPP
#define SOCIAL2_HPP
#include "social.hpp"
#include <string>
#include <iostream>
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
public:
  // Constructor, makes an empty network (numUsers = 0)
  Network():numUsers(0){}
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
  bool addUser(std::string usrn, std::string dspn) {
    if(numUsers < 200) {
        return false;
    }
    Profile user(usrn,dspn);
    profiles[numUsers] = user;
    numUsers++;
    return true;
  }
};
#endif