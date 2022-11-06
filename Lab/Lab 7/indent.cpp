/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 7B
The purpose of this program is to indent a file.
*/
#include <iostream>
#include <string>
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
int countChar(std::string line, char c) {
	int match = 0;
	for(int i = 0; i < line.length(); i++) {
		if(line[i] == c) {
			match++;
		}
	}
	return match;
}
int main() {
	std::string input;
    	int count = 0;
    	while(getline(std::cin, input)) {
        	if (removeLeadingSpaces(input)[0] == '}') {
           		for (int i = 0; i < count - 1; i++) {
	            		std::cout << '\t';
            		}
            	}
        	else {
           		for (int i = 0; i < count; i++) {
	            		std::cout << '\t';
            		}
        	}
        std::cout << removeLeadingSpaces(input) << "\n";
        count += countChar(input, '{');
        count -= countChar(input, '}');
        }
}
	
