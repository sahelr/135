/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab Quiz #13
The purpose of this program is to return a vector.
*/
#include <iostream>
#include <vector>
std::vector<int> makeVector(int n) {
    std::vector<int> result;
    if(n == 0) {
        return
    }
    for(int i = n; i >= 0; i--) {
        result.push_back(i);
    }
    return result;
}