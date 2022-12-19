/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab #13
The purpose of print all numbers between left and right.
*/
#include <iostream>
#include <string>
#include <cctype>
void printRange(int left, int right) {
    if(left <= right) { // Base Case
        std::cout << left<< " ";
        printRange(left+1,right); // Recursion
    }
}
int sumRange(int left, int right) { 
    if(left > right) { // Base Case
        return 0; // Indicates end of recursion
    }
    return left + sumRange(left + 1, right);
}
int sumArray(int *arr, int size) {
    if(size == 0) { // Base Case
        return 0; //Indicates end of recursion
    }
    return arr[size-1] + sumArray(arr,size-1); // Recursion
}
bool isAlphanumeric(std::string s) {
   if(s.length()==0) { // Base Case
       return true; 
   }
   else if (!isalnum(s[s.length()-1])) { // Other cases
       return false;
   }
   else {
       return isAlphanumeric(s.substr(0,s.length()-1)); // Recursion
   }
}
bool nestedParens(std::string s) {
    if(s.length() == 0) { // Base Case
        return true;
    }
    else if(s[0] != '(' || s[s.length()-1] != ')') { // Other Cases
        return false;
    }
    else {
        return nestedParens(s.substr(1,s.length()-2)); // Recursion
    }
}