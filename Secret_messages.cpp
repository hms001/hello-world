//============================================================================
// Name        : Secret_messages.cpp
// Author      : HMS
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	std::string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	std::string key  {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
	std::string secret_msg{};

	cout << "Enter your secret message: ";
	getline(cin,secret_msg);

	cout << "\nEncrypting message...\n" << endl;

/*
 * Use by string::npos to find the char
 *
 */
	std::string encrypted_msg{};

	for(auto a: secret_msg){
		char text{};
		if( alphabet.find(a) != string::npos){
			text = key.at(alphabet.find(a));
			encrypted_msg += text;
		}
		else{
			encrypted_msg += a;
		}
	}

	cout << "Encrypted message: " << encrypted_msg << endl;

	std::string decrypted_msg{};

	cout << "\nDecrypting message...\n" << endl;

	for(auto k: encrypted_msg){
		char text{};
		if( key.find(k) != string::npos){
			text = alphabet.at(key.find(k));
			decrypted_msg += text;
		}
		else{
			decrypted_msg += k;
		}
	}

	cout << "Decrypted message: " << decrypted_msg << endl;

/*
 * Another way of doing by looping the whole string
 *
 */
//	for(size_t x{0};x < secret_msg.length();x++){
//		size_t text;
//		for(text = 0;text < alphabet.length(); text++){
//			if(secret_msg[x] == alphabet[text]){
//				break;
//			}
//
//		}
//		if(text == alphabet.length()){
//			continue;
//		}
//		else{
//			secret_msg[x] = key[text];
//		}
//	}
//
//	cout << "Encrypted message: " << secret_msg << endl;
//
//	cout << "\nDecrypting message...\n" << endl;
//
//	for(size_t x{0};x < secret_msg.length();x++){
//			size_t text;
//			for(text = 0;text < key.length(); text++){
//				if(secret_msg[x] == key[text]){
//					break;
//				}
//
//			}
//			if(text == key.length()){
//				continue;
//			}
//			else{
//				secret_msg[x] = alphabet[text];
//			}
//	}
//
//	cout << "Decrypted message: " << secret_msg << endl;

	return 0;
}
