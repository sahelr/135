
/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 4G
The purpose of this program is to print a 3x3 checkerboard with the width and height the user enters.
*/
#include <iostream>
#include <string>
int main() {
	std::cout << "Input width: " << std::endl;
	int width;
	std::cin >> width;
	std::cout << "Input height: " << std::endl;
	int height;
	std::string board;
	std::cin >> height;
	for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {      
            if ((j / 3) % 2 == ((i / 3) % 2)) {
	            board += "*";
            } else {
	            board += " ";
            }
        }
        board += "\n";
    }
    std::cout << board;
}
