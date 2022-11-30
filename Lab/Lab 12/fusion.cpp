/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 12C
The purpose of this program is to append all elements of the second vector into the first vector and clear the second vector.
*/
#include <iostream>
#include <string>
#include <vector>
void gogeta(std::vector<int> &goku, std::vector<int> &vegeta) {
    for(int i = 0; i < vegeta.size(); i++) {
        goku.push_back(vegeta[i]);
    }
    vegeta.clear();
}