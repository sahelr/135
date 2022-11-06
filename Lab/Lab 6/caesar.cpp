/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 6B
The purpose of this program is to use a right shift to perform a caesar cipher.
*/
#include <iostream>
#include <string>
#include <cctype>
char shiftChar(char c, int rshift) {
	int low = (int)'a';
	int upp = (int)'A';
	if(isupper(c)) {
		return char((c + rshift - upp) % 26 + upp);
	}
	else if(islower(c)){
		return char((c + rshift - low) % 26 + low);
	}
	else {
		return c;
	}
}
std::string encryptCaesar(std::string plaintext, int rshift) {
	std::string encrypt = "";
	for(int i = 0; i < plaintext.length(); i++) {
		encrypt += shiftChar(plaintext[i], rshift); // Shifting the char.
	}
	return encrypt;
}
int main() {
	std::string input;
	int r;
	std::cout << "Enter plaintext: " << std::endl;
	std::getline(std::cin, input); // Extracts every line the user  enters.
	std::cout << "Enter shift: " << std::endl;
	std::cin >> r;
	std::cout << "Ciphertext: " << encryptCaesar(input, r) << std::endl;
	return 0;
}
	
	
