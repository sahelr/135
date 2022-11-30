/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 12D
The purpose of this program is to return a vector where the each element is the sum of the pairs of the 2 vectors.
*/
#include <iostream>
#include <string>
#include <vector>
std::vector<int> sumPairWise(std::vector<int> &v1, std::vector<int> &v2) {
    int pairs;
    std::vector<int> paired;
    if(v1.size() == 0) {
        paired = v2;
    }
    else if(v2.size() == 0) {
        paired = v1;
    }
    else if(v1.size() > v2.size()) {
        pairs = v2.size();
        for(int i = 0; i < pairs; i++) {
            paired.push_back(v1[i]+ v2[i]);
        }
        for(int j = pairs; j < v1.size(); j++) {
            paired.push_back(v1[j]);
        }
    }
    else {
        pairs = v1.size();
        for(int k = 0; k < pairs; k++) {
            paired.push_back(v1[k]+ v2[k]);
        }
        for(int l = pairs; l < v1.size(); l++) {
            paired.push_back(v2[l]);
        }
    }
    return paired;
}