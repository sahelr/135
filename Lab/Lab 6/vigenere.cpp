/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 6C
The purpose of this program is to use a keyword to shift the plaintext.
*/
#include <iostream>
#include <string>
#include <cctype>
std::string encryptVigenere(std::string plaintext, std::string keyword) {
	int current = 0;
	int low = (int)'a';
	int upp = (int)'A';
	int shift;
	std::string encrypt = "";
	for(int i = 0; i < plaintext.length(); i++) {
		if(current == keyword.length()) {
			current = 0;
		}
		shift = (int)keyword[current] - low;
		if(isupper(plaintext[i])) {
			encrypt+= char((plaintext[i] + shift - upp) % 26 + upp);
			current++;
		}
		else if(islower(plaintext[i])){
			encrypt += char((plaintext[i] + shift - low) % 26 + low);
			current++;
		}
		else {
			encrypt += plaintext[i];
		}
	}
	return encrypt;
}
int main() {
	std::string input;
	std::string key;
	std::cout << "Enter plaintext: " << std::endl;
	std::getline(std::cin, input); // Extracts every line the user  enters.
	std::cout << "Enter keyword: " << std::endl;
	std::cin >> key;
	std::cout << "Ciphertext: " << encryptVigenere(input, key) << std::endl;
	return 0;
}
