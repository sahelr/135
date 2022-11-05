/*
Author: Sahel Reja
Course: CSCI-136
Instructor: Gennadiy Maryash
Assignment: title, Lab1C
The purpose of this program is determine if the year the user entered is a leap or common year. Any year not divisible by 4 is a common, centuries except those divisble by 400 are common years. Everything else is a leap year/
*/
#include <iostream>
using namespace std;
int main() {
	cout << "Enter in a year:" << endl;
	int year = 0;
	cin >> year;
	if (year % 4 != 0) {
		cout << year <<  " is a common year." << endl;
	}
	else if (year % 100 != 0) {
		cout << year << " is a leap year." << endl;
	}
	else if (year % 400 != 0) {
		cout << year << " is a common year." << endl;
	}
	else {
		cout << year << " is a leap year." << endl;
	}
	return 0;
}
