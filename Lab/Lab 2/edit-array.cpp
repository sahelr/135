/*
Author: Sahel Reja
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 2C
The purpose of this program is to create a 10 element integer array that are all 1. Then we manipulate that array at the index the user enters with the value the user enters. This will go on until the user enters an invalid index.
*/
#include <iostream> 
using namespace std;
int main() {
	int myData[10] = {1,1,1,1,1,1,1,1,1,1};
	int inp = 0;
	int val = 0;
	do {
		for(int i = 0; i < 10; i++) {
			cout << myData[i] << " ";
			if (i == 9) {
				cout << endl;
			}
		}
		cout << "Index input:" << endl;
		cin >> inp;
		cout << "Index value:" << endl;
		cin >> val;
		if( inp >= 0 && inp < 10) {
			myData[inp] = val;
		}
	} while(inp >= 0 && inp < 10);
	cout << "Index out of range. Exit." << endl;
	return 0;
}
