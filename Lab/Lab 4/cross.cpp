/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 4C
The purpose of this program is to print a cross with the size the user enters.
*/
#include <iostream>
int main() {
	std::cout << "Input size: " << std::endl;
	int size;
	std::cin >> size;
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			if((j == 0 + i) || (j == size - 1 - i)) {
				std::cout<<"*";
			}
			else {
				std::cout<<" ";
			}
		}
		std::cout<< std::endl;
	}
	return 0;
}
