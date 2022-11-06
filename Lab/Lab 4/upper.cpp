/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 4E
The purpose of this program is to print a upper triangle with the length the user enters.
*/
#include <iostream>
int main() {
	std::cout << "Input side length: " << std::endl;
	int length;
	std::cin >> length;
	for(int i = 0; i < length; i++) {
		for(int j = 0; j < length; j++) {
			if(j >= i) {
				std::cout << "*";
			}
			else {
				std::cout << " ";
			}
		}
		std::cout<<std::endl;
	}
	return 0;
}
