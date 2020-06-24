//============================================================================
// Name        : Collection_lists.cpp
// Author      : HMS
// Version     : 1
// Copyright   : Your copyright notice
// Description : using a collection (list) of integers and allowing the user
//    			 to select options from a menu to perform operations on the list.
//============================================================================

#include <iostream>
#include <vector>
#include <ctype.h> //to use toupper function to convert a character to uppercase
#include <algorithm>
#include <iterator>

using namespace std;

int main() {

	char enter_choice{};
	int number{},vec_size{},limit{},sum{},min{},max{},search_num{},count{},duplicate{};
	double total{};
	char quit{};
	vector<int> vec{};

	do{
		// prints menu options
		cout << "======================================" << endl;
		cout << "\nPlease enter the options as below" << endl;
		cout << "P - Print numbers" << endl;
		cout << "A - Add a number" << endl;
		cout << "C - Clear the list" << endl;
		cout << "M - Display mean of the numbers" << endl;
		cout << "S - Display the smallest number" << endl;
		cout << "L - Display the largest number" << endl;
		cout << "N - Search for a number count in the list" << endl;
		cout << "Q - Quit\n" << endl;
		cout << "======================================\n" << endl;

		cout << "Enter your choice: ";
		cin >> enter_choice;

		switch(enter_choice){

			case 'P':
			case 'p':
				if(vec.size()){

					cout << "[";
					for(auto x:vec){
						//to display all integers in vector list
						cout << " " << x << " ";
					}
					cout << "]" << endl;
				}
				else{
					cout << "[] - the list is empty" << endl;
				}
				break;
			case 'A':
			case 'a':
				do{
					cout << "Vector size? ";
					cin >> vec_size;
					while(limit<vec_size){
						cout << "\nPlease enter an integer to add: ";
						cin >> number;
						//loop for vec_size count then ask option to continue to add
						if(vec.size()){
							//check duplicate with number entered
							for(size_t x{0};x<vec.size();++x){
								if(number == vec[x]){
									duplicate++;
								}
							}
							if(duplicate > 0){
								cout << "Duplicate entries are not allowed." << endl;
								duplicate = 0;
							}
							else{
								vec.push_back(number);
								cout << number << " was added." << endl;
							}
						}
						else{
							vec.push_back(number);
							cout << number << " was added." << endl;
						}

						limit++;
					}
					limit = 0;
					cout << "Add another number? Y/N: ";
					cin >> quit;

				}while(quit!='N' && quit != 'n');

				break;
			case 'M':
			case 'm':
				if(vec.size()){
					for(auto x:vec){
						sum += x;
					}
					//calculate average
					total = sum/vec.size();
					cout << "Mean or Average of the elements in the list is: "
							<< total << endl;
				}
				else{
					cout << "Unable to calculate the mean - no data" << endl;
				}
				break;
			case 'S':
			case 's':
				if(vec.size()){
					//find smallest number in the list
					min = vec[0];
					for(size_t x{0};x<vec.size();x++){
						if(vec[x] < min){
							min = vec[x];
						}
					}
					cout << "The smallest number is " << min << endl;
				}
				else{
					cout << "Unable to determine the smallest number - list is empty" << endl;
				}
				break;
			case 'L':
			case 'l':
				if(vec.size()){
					//find largest number in the list
					max = vec[0];
					for(size_t x{0};x<vec.size();x++){
						if(vec[x] > max){
							max = vec[x];
						}
					}
					cout << "The largest number is " << max << endl;
				}
				else{
					cout << "Unable to determine the largest number - list is empty" << endl;
				}
				break;
			case 'N':
			case 'n':
				if(vec.size()){
					cout << "Search for a number in the list: ";
					cin >> search_num;
					for(size_t x{0}; x<vec.size();x++){
						if(search_num == vec[x]){
							count++;
						}
					}
					cout << "Number of times occur in the list: " << count << endl;
					count = 0;
				}
				else{
					cout << "Unable to count number of times occur - list is empty" << endl;
				}
				break;
			case 'C':
			case 'c':
				if(vec.size()){
					//clear value in the list
					vec.clear();
					cout << "All the elements of the list are cleared." << endl;
				}
				else{
					cout << "Nothing to clear - list is empty" << endl;
				}
				break;
			case 'Q':
			case 'q':
				cout << "Goodbye!" << endl;
				break;
			default:
				cout << "Unknown selection, please try again." << endl;
		}

	}while(enter_choice !='q' && enter_choice !='Q');

	return 0;
}
