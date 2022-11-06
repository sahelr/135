/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 4F
The purpose of this program is to print a upside down trapezoid with the width and length the user enters.
*/
#include <iostream>
int main() {
	std::cout << "Input width: " << std::endl;
	int width;
	std::cin >> width;
	std::cout << "Input height: " << std::endl;
	int height;
	std::cin >> height;
	if(height > (width + 1)/2) {
		std::cout << "Impossible shape!" << std::endl;
	}
	else {
		 for (int i = 0; i < height; i++){
        		for (int j = 0; j < width - i; j++){
           			 if (j < i){
               				 std::cout << " ";
            			} 
            			else {
                			std::cout << "*";
            			}
        		}
        		std::cout << std::endl;
    		}
    	}
    	return 0;
}
