/*
Author: Sahel Reja
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 2D
The purpose of this program is to try to figure out all Fibonacci numbers from F[0] to F[59] and print them out.
*/
#include <iostream>
using namespace std;
int main() {
	long fib[60];
	fib[0] = 0;
	fib[1] = 1;
	for(int i = 2; i < 60; i++) {
		if(i == 2) {
			cout << fib[0] << " " << fib[1] << " ";
		}
		fib[i] = fib[i-2] + fib[i-1];
		cout << fib[i] << " ";
	}
	return 0;
}
	
