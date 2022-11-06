/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 4B
The purpose of this program is to print a checkerboardwith the height and width the user enters.
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
		if(i % 2 == 0) {
			for(int j = 0; j < width; j++) {
				if(j % 2 == 0) {
					std::cout << "*";
				}
				else {
					std::cout << " ";
				}
			}
		}
		else {
			for(int j = 0; j < width; j++) {
				if(j % 2 == 0) {
					std::cout << " ";
				}
				else {
					std::cout << "*";
				}
			}
		}
		std::cout<<std::endl;
	}
	return 0;
}
