/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Lab1B
The purpose of this program is trying to find the minimum of three integers that the user enters. Aftering entering the three integers, the program compares the three integers and figures out which one is smaller.
*/
#include <iostream>
#include <cmath>
using namespace std;
bool isInt(float x)
{
  return floor(x) == x;
}
int main() {
	cout << "Enter your first integer:" << endl;
	int first = 0;
	cin >> first;
	cout << "Enter your second integer:" << endl;
	int second = 0;
	cin >> second;
	cout << "Enter your third integer:" << endl;
	int third = 0;
	cin >> third;
	if (second >= first && third >= first) {
		cout << first << " is the smallest integer." << endl;
	}
	else if (first >= second && third >= second) {
		cout << second << " is the smallest integer." << endl;	
	}
	else {
		cout << third << " is the smallest integer." << endl;
	}
	return 0;
}
