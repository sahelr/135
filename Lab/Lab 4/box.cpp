/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 4A
The purpose of this program is to print a box with the height and width the user enters.
*/
#include <iostream>
int main() {
	std::cout << "Input width: " << std::endl;
	int width;
	std::cin >> width;
	std::cout << "Input height: " << std::endl;
	int height;
	std::cin >> height;
	std::cout << "Shape:" << std::endl;
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			std::cout<<"*";
		}
		std::cout<<std::endl;
	}
}
