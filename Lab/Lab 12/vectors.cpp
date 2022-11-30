/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 12A
The purpose of this program is to create a vector of n elements starting with 0 to n-1.
*/
#include <iostream>
#include <string>
#include <vector>
std::vector<int> makeVector(int n) {
    std::vector<int> v;
    for(int i = 0; i < n; i++) {
        v.push_back(i); // Adds element
    }
    return v;
}