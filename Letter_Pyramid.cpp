//============================================================================
// Name        : Letter_Pyramid.cpp
// Author      : HMS
// Version     :
// Copyright   : Your copyright notice
// Description : program that displays a Letter Pyramid from a user-provided
// std::string. Prompt the user to enter a std::string and then from that string
// display a Letter Pyramid
//============================================================================

#include <iostream>
#include <string>

using namespace std;

int main() {

/*
 * Get the input from the user and store it in a std::string variable
	Loop for each letter in the string entered by the user
	Determine how many blank spaces must be displayed before the current row and display them
	Determine how many letters must be displayed before the current character and display them
	Display the current character
	Display the remaining characters in reverse order
	Complete the row with a new line
 */
	string letter{};

	cout << "Enter a string to display a letter pyramid: ";
	cin >> letter;


	for(size_t i{1}; i <= letter.size(); i++){

		for(size_t j{1}; j <= letter.size()-i; j++){
			cout << " "; //display spaces
		}
		for(size_t k{1}; k <= i; k++){

			cout << letter.at(k-1); //Display center character
		}

		for(size_t d{i-1}; d >= 1; d--){
			cout << letter.at(d-1); // Display in reverse order
		}
		cout << endl; //end line for each row
	}


/*
 * Another way with for-range loop
 *
 */
//	std::string letters{};
//
//	std::cout << "Enter a string of letters so I can create a Letter Pyramid from it: ";
//	getline(std::cin, letters);
//
//	size_t num_letters = letters.length();
//
//	size_t position {0};
//
//	// for each letter in the string
//	for (char c: letters) {
//
//		size_t num_spaces = num_letters - position;
//		while (num_spaces > 0) {
//			std::cout << " ";
//			--num_spaces;
//		}
//
//		// Display in order up to the current character
//		for (size_t j=0; j < position; j++) {
//			std::cout << letters.at(j);
//		}
//
//		// Display the current 'center' character
//		std::cout << c;
//
//		// Display the remaining characters in reverse order
//		for (int j=position-1; j >=0; --j) {
//			// You can use this line to get rid of the size_t vs int warning if you want
//			auto k = static_cast<size_t>(j);
//			std::cout << letters.at(k);
//		}
//
//		std::cout << std::endl; // Don't forget the end line
//		++position;
//	}


/*
 * Another way without getting user input
 *
 */
//	char ch='A';
//	int i, j, k, m;
//	for(i=1;i<=5;i++)
//	{
//		for(j=5;j>=i;j--)
//			cout<<" ";
//		for(k=1;k<=i;k++){
//			cout<<ch++;
//		}
//		ch--;
//		for(m=1;m<i;m++)
//			cout<<--ch;
//		cout<<"\n";
//		ch='A';
//	}

	return 0;
}
