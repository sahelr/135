/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 6D
The purpose of this program is to encrypt and decrypt using caesar and vigenere ciphers.
*/
#include <iostream>
#include <string>
#include <cctype>
const int low = (int)'a';
const int upp = (int)'A';
char shiftChar(char c, int rshift) {
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
std::string encryptVigenere(std::string plaintext, std::string keyword) { //Encrypts using Vigenere shift
	int current = 0;
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
std::string decryptCaesar(std::string ciphertext, int rshift) { //Decrypts the Caesar shift
	std::string result = "";
	for(int i = 0; i < ciphertext.length(); i++) {
		if(isupper(ciphertext[i])) {
			result += char((ciphertext[i] + 26 - rshift - upp) % 26 + upp);
		}
		else if(islower(ciphertext[i])){
			result += char((ciphertext[i] + 26 - rshift - low) % 26 + low);
		}
		else {
			result += ciphertext[i];
		}
	}
	return result;
}
std::string decryptVigenere(std::string ciphertext, std::string keyword) { //Decrypts the Vigenere shift
	std::string decrypt = "";
	int current = 0;
	int shift;
	for(int i = 0; i < ciphertext.length(); i++) {
		if(current == keyword.length()) {
			current = 0;
		}
		shift = (int)keyword[current] - low;
		if(isupper(ciphertext[i])) {
			decrypt+= char((ciphertext[i] + 26 - shift - upp) % 26 + upp);
			current++;
		}
		else if(islower(ciphertext[i])){
			decrypt += char((ciphertext[i] + 26 - shift - low) % 26 + low);
			current++;
		}
		else {
			decrypt += ciphertext[i];
		}
	}
	return decrypt;
}
int main() {
	std::string plaintext;
	std::string ciphertext;
	int rshift;
	std::string key;
	std::cout << "Enter plaintext: " << std::endl;
	std::getline(std::cin, plaintext); // Extracts every line the user  enters.
	std::cout <<  "= Caesar =" << std::endl;
	std::cout << "Enter shift: " << std::endl;
	std::cin >> rshift;
	std::cout << "Ciphertext: " << encryptCaesar(plaintext, rshift) << std::endl;
	ciphertext = encryptCaesar(plaintext, rshift);
	std::cout << "Decrypted: " << decryptCaesar(ciphertext, rshift) << std::endl;
	std::cout << std::endl;
	std::cout <<  "= Vigenere =" << std::endl;
	std::cout << "Enter keyword: " << std::endl;
	std::cin >> key;
	std::cout << "Ciphertext: " << encryptVigenere(plaintext, key) << std::endl;
	ciphertext = encryptVigenere(plaintext, key);
	std::cout << "Decrypted: " << decryptVigenere(ciphertext, key) << std::endl;
}

	
