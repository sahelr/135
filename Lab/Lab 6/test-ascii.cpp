/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 6A
The purpose of this program is to find the ascii codes of every character in the string the user enters.
*/
#include <iostream>
#include <string>
int main() {
	std::string input;
	std::cout << "Input:" << std::endl;
	std::getline(std::cin, input); // Extracts every line the user  enters.
	for(int i = 0; i < input.length(); i++) {
		std::cout << input[i] << " " << (int)input[i] << std::endl; // Gets the character and corresponding ascii value.
	}
	return 0;
}
