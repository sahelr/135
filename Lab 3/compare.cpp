/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab3C
The purpose of this program is to state whether East or West elevation is greater for the interval the user enters.
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
    std::cout <<"Enter starting date: "<< std::endl;
    std::string start;
    std::cin >> start;
    std::cout << "Enter ending date: " << std::endl;
    std::string end;
    std::cin >> end;
    double eastSt;
    double eastEl;
    double westSt;
    double westEl;
    double min = INT_MAX;
    double max = INT_MIN;
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { // checks every line in the file with these headers
    	fin.ignore(INT_MAX, '\n'); // skips the end of line and remaining collumns 
    	if((date >= start) && (date <= end)) { // ensures that the program is only checking the interval the user entered
    		if(eastEl < westEl) {
    			 std::cout << date << " West" << std::endl;
    		}
    		else if(eastEl > westEl) {
    			std::cout << date << " East" << std::endl;
    		}
        	else {
        		std::cout << date << " Equal" << std::endl;
        	}
        }
    }
    fin.close();
    return 0;
}
