
/*
Author: Sahel Reja
Course: CSCI-136
Instructor: Genady Maryash
Assignment: Lab3B
The purpose of this program is to find the minimum and maxium East basin storage.
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
    double eastSt;
    double min = INT_MAX;
    double max = INT_MIN;
	while(fin >> date >> eastSt) {
        fin.ignore(INT_MAX, '\n'); // skips the end of line and remaining collumns 
        if(min > eastSt) {
            min = eastSt;
        }
		if(max < eastSt) {
			max = eastSt;
		}
	}
	std::cout << "minimum storage in East basin: " << min << " billion gallons." << std::endl;
	std::cout << "maximum storage in East basin: " << max << " billion gallons." << std::endl;
	fin.close();
	return 0;
}
