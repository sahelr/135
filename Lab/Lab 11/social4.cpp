#include <string>
#include <iostream>
#include <cctype>
using namespace std;
struct Post{
  std::string username;
  std::string message;
};
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
  static const int MAX_POSTS = 100;
  int numPosts;                    // number of posts
  Post posts[MAX_POSTS];           // array of all posts
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
  // Add a new post
  bool writePost(string usrn, string msg) {
    if(numPosts == MAX_POSTS) {
        return false;
    }
    for(int i = 0; i < numUsers; i++) {
        if(profiles[i].getUsername() == usrn) {
            Post n = {usrn, msg};
            posts[numPosts] = n;
            numPosts++;
            return true;
        }
    }
    return false;
  };
  // Print user's "timeline"
  bool printTimeline(string usrn) {
    int user_id = findID(usrn);
    if(user_id == -1) {
        return false;
    }
    for(int i = numPosts; i >= 0; i--) {
        Post p = posts[i];
        int follower_id = findID(p.username);
        if(p.username == usrn) {
            std::cout << profiles[user_id].getFullName() << ": " << p.message << endl;
        } else if(following[user_id][follower_id]) {
            std::cout << profiles[follower_id].getFullName() << ": " << p.message << endl;
        }
    }
    return true;
  }
};
int main() {
  Network nw;
  // add three users
  nw.addUser("mario", "Mario");
  nw.addUser("luigi", "Luigi");
  nw.addUser("yoshi", "Yoshi");
   
  nw.follow("mario", "luigi");
  nw.follow("luigi", "mario");
  nw.follow("luigi", "yoshi");
  nw.follow("yoshi", "mario");

  // write some posts
  nw.writePost("mario", "It's a-me, Mario!");
  nw.writePost("luigi", "Hey hey!");
  nw.writePost("mario", "Hi Luigi!");
  nw.writePost("yoshi", "Test 1");
  nw.writePost("yoshi", "Test 2");
  nw.writePost("luigi", "I just hope this crazy plan of yours works!");
  nw.writePost("mario", "My crazy plans always work!");
  nw.writePost("yoshi", "Test 3");
  nw.writePost("yoshi", "Test 4");
  nw.writePost("yoshi", "Test 5");

  cout << endl;
  cout << "======= Mario's timeline =======" << endl;
  nw.printTimeline("mario");
  cout << endl;

  cout << "======= Yoshi's timeline =======" << endl;
  nw.printTimeline("yoshi");
  cout << endl;
}