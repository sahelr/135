/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 5G
The purpose of this program is to determine if the largest twin prime in the interval.
*/
#include <iostream>
bool isDivisibleBy(int n, int d) {
	if(d == 0) {
		return false;
	}
	else if(n % d == 0) {
		return true;
	}
	else {
		return false;
	}
}
bool isPrime(int n) {
	if(n < 2) {
		return false;
	}
	for(int i = 2; i < n; i++) {
		if(isDivisibleBy(n, i)) { 
			return false;
		}
	}
	return true;
}
int nextPrime(int n) {
	n++;
	while(!isPrime(n)) {
		n++;
	}
	return n;
}
int countPrimes(int a, int b) {
	int count = 0;
	for(int i = a; i <= b; i++) {
		if(isPrime(i)) {
			count++;
		}
	}
	return count;
}
bool isTwinPrime(int n) {
	if(!isPrime(n)) {
		return false;
	}
	else if(isPrime(n+2) || isPrime(n-2)) {
		return true;
	}
	else {
		return false;
	}
}
int nextTwinPrime(int n) {
	n++;
	while(!isTwinPrime(n)) {
		n++;
	}
	return n;
}
int largestTwinPrime(int a, int b) {
	for(int i = b; i >= a; i--) {
		if(isTwinPrime(i)) {
			return i;
		}
	}
	return -1;
}
int main() {
	int num;
	int div;
	std::cout << "Enter your first integer:" << std::endl;
	std::cin >> num;
	std::cout << "Enter your second integer:" << std::endl;
	std::cin >> div;
	/*if(isDivisibleBy(num,div)) {
		std::cout << "Yes" << std::endl;
	}
	else {
		std::cout << "No" << std::endl;
	} */
	/*std::cout << "Enter an integer:" << std::endl;
	std::cin >> num;
	if(isPrime(num)) {
		std::cout << "Yes" << std::endl;
	}
	else {
		std::cout << "No" << std::endl;
	}  */
	//std::cout << nextPrime(num) << std::endl;
	//std::cout << countPrimes(num, div) << std::endl;
	/*if(isTwinPrime(num)) {
		std::cout << "Yes" << std::endl;
	}
	else {
		std::cout << "No" << std::endl;
	}*/
	//std::cout << nextTwinPrime(num) << std::endl;
	std::cout << largestTwinPrime(num, div) << std::endl;
	return 0;
}
