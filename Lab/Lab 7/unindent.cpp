/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 7A
The purpose of this program is to unindent a file.
*/
#include <iostream>
#include <string>
#include <cctype>
std::string removeLeadingSpaces(std::string line) {
	std::string result;
	bool first = false;
	for(int i = 0; i < line.length(); i++) {
		if(!isspace(line[i])) {
			first = true;
		}
		if(first) {
			result += line[i];
		}
	}
	return result;
}
int main() {
	std::string input;
	while (std::getline(std::cin, input)){
        	std::cout << removeLeadingSpaces(input) << std::endl;
    	}
    	return 0;
}


