/*
Author: Sahel Reja
Course: CSCI-136
Instructor: Genady Maryash
Assignment: Lab2A
The purpose of this program is to find the square of an integer the user enters. The bounds of the input must be greather than 0 and less than 100.
*/
#include <iostream>
using namespace std;
int main() {
	int inp = 0;
	int retry = 0;
	do{ 
		if (retry == 0) {
			cout << "Enter an integer:" << endl;
			cin >> inp;
			retry++;
		}
		else {
			cout << "Please re-enter an integer:" << endl;
			cin >> inp;
			retry++;
		}
	} while (inp <= 0 || inp >= 100);
	inp = inp*inp;
	cout << "Number squared is " << inp << "." << endl;
	return 0;
}
