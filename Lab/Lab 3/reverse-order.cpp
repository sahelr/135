/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab3D
The purpose of this program is to state the West Elevation of the interval the user enters in reverse order.
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include <vector>
int main() {
   std::ifstream fin("Current_Reservoir_Levels.tsv");
   std::string junk;   
   getline(fin, junk);
   if (fin.fail()) {
   	std::cerr << "File cannot be opened for reading." << std::endl;
   	exit(1); // exit if failed to open the file
    }
    std::string date;
    std::cout <<"Enter earlier date: "<< std::endl;
    std::string earlier;
    std::cin >> earlier;
    std::cout << "Enter later date: " << std::endl;
    std::string later;
    std::cin >> later;
    double eastSt;
    double eastEl;
    double westSt;
    double westEl;
    std::vector<std::string> dates;
    std::vector<double> elevs;
   while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { // checks every line in the file with these headers
    	fin.ignore(INT_MAX, '\n'); // skips the end of line and remaining collumns
    	if((date >= earlier) && (date <= later)) { // ensures that the program is only checking the interval the user entered
    		dates.push_back(date);
    		elevs.push_back(westEl);
    	}
   }
   for(int i = elevs.size()-1; i >= 0; i--) {
   	std::cout << dates[i] << " " << elevs[i] << std::endl;
   }
    fin.close();
    return 0;
}

