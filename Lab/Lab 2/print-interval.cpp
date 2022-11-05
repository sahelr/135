/*
Author: Sahel Reja
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab2B
The program asks the user for a lower and upper bound then prints all integers between greather to equal to the lower bound and less than the upper bound.
*/
#include <iostream>
using namespace std;
int main() {
	cout << "Please enter L:" << endl;
	int lower = 0;
	cin >> lower;
	cout << "Please enter U:" << endl;
	int upper = 0;
	cin >> upper;
	for(int i = lower; i < upper; i++) {
		cout << i << " ";
	}
	return 0;
}
