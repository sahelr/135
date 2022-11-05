/*
Author: Sahel Reja
Course: CSCI-136
Instructor: Genady Maryash
Assignment: Lab3A
The purpose of this program is to find the East basin storage of the date the user enters.
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
int main() {
	std::ifstream fin("Current_Reservoir_Levels.tsv");
	std::string junk;   
	getline(fin, junk);
	if (fin.fail()) {
    		std::cerr << "File cannot be opened for reading." << std::endl;
    		exit(1); // exit if failed to open the file
	}
	std::string date;
	double eastSt = 0.0;
	std::string target_date;
	std::cout<<"Enter date:"<<std::endl;
	std::cin >> target_date;
	bool found = false;
	while(fin >> date) {
		if(target_date == date) {
			found = true;
			break;
		}
	}
	fin >> eastSt;
	if(found) {
		std::cout << "East basin storage: " << eastSt << " billion gallons." << std::endl;
	}
	fin.close();
	return 0;
}
	
