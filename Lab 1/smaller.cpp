/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Lab1A
The purpose of this program is trying to find the minimum of two integers that the user enters. Aftering entering the two integers, the program compares the two integers and figures out which one is smaller.
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
	if(first > second) {
		cout << "The smaller of the two is " << second << "."<< endl;
	}
	else {
		cout << "The smaller of the two is " << first << "." << endl;
	}
	return 0;
}
