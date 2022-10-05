/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Lab1D
The prupose of this program is to find the amount of days in the given month. This accounts for leap years hence why the user enters the year.
*/
#include <iostream>
using namespace std;
bool is_leap( int year) {
	if (year % 4 != 0) {
		return false;
	}
	else if (year % 100 != 0) {
		return true;
	}
	else if (year % 400 != 0) {
		return false; 
	}
	else {
		return true;
	}
}
int main() {
	cout << "Enter in a year:" << endl;
	int year = 0;
	cin >> year;
	cout << "Enter in a month (in numerical form):" << endl;
	int month = 0;
	cin >> month;
	if(month < 8 && month % 2 != 0) {
		cout << "There are 31 days." << endl;
	}
	else if (month == 2) {
		if (is_leap(year) == true) {
			cout << "There are 29 days." << endl;
		}
		else {
			cout << "there are 28 days." << endl;
		}
	}
	else if (month < 8 && month % 2 == 0) {
		cout << "There are 30 days." << endl;
	}
	else if (month >= 8 && month % 2 == 0) {
		cout << "There are 31 days." << endl;
	}
	else {
		cout << "There are 30 days." << endl;
	}
	return 0;
}
