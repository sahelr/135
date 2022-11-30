/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 12B
The purpose of this program is to return a vector with only the positive elements.
*/
#include <iostream>
#include <string>
#include <vector>
std::vector<int> goodVibes(const std::vector<int> v) {
    std::vector<int> good;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] > 0) {
            good.push_back(v[i]);
        }
    }
    return good;
}