//============================================================================
// Name        : Collection_Lists_in_function.cpp
// Author      : HMS
// Version     : 1
// Copyright   : Your copyright notice
// Description : Display a collection of vector list using functions
//============================================================================

#include <iostream>
#include <vector>
#include <ctype.h> //to use toupper function to convert a character to uppercase
#include <algorithm>
#include <iterator>

using namespace std;

char enter_choice();
void display_menu();
void print_number(vector<int> &vec);
void add_number(vector<int> &vec);
void clear_list(vector<int> &vec);
void display_mean(vector<int> &vec);
void display_smallest_num(vector<int> &vec);
void display_largest_num(vector<int> &vec);
void search_num_count(vector<int> &vec);

char choice{};

int main(){

	vector<int> vec{};
	char selected{};

	do{

		display_menu();
		selected = enter_choice();
		if(selected =='P'){
			print_number(vec);
		}
		else if(selected == 'A'){
			add_number(vec);
		}
		else if(selected == 'C'){
			clear_list(vec);
		}
		else if(selected == 'M'){
			display_mean(vec);
		}
		else if(selected == 'S'){
			display_smallest_num(vec);
		}
		else if(selected == 'L'){
			display_largest_num(vec);
		}
		else if(selected == 'N'){
			search_num_count(vec);
		}
		else if(selected =='Q'){
			cout << "Goodbye!" << endl;

		}
		else{
			cout << "Unknown selection, please try again." << endl;
		}

	}while(selected !='Q');


}

void display_menu(){

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

}

char enter_choice(){
/*
 * to accept user entry
 */

	cout << "Enter your choice: ";
	cin >> choice;
	return toupper(choice);

}

void print_number(vector<int> &vec){
/*
 * to display a list of data in vector
 */

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
}

void add_number(vector<int> &vec){
/*
 * to add a new data to vector
 */

	int vec_size{},limit{},number{},duplicate{};
	char quit{},option{};

	do{
		//check how big the vector size should be
		cout << "Vector size? ";
		cin >> vec_size;
		//while num of data adding is within vector size
		while(limit<vec_size){

			limit++;
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
					duplicate = 0; //reset value to 0
					limit--; //minus 1 from vector size as it is duplicate
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

		}
		limit = 0; //reset to 0 as to prepare if want to add new vector size

		do{
			//if still want to add another set of vector
			cout << "\nAdd another number? Y/N: ";
			cin >> quit;
			option = toupper(quit);
			//to only accept Y and N
			if(option != 'Y' && option != 'N'){
				cout << "Incorrect option. Please enter again!" << endl;
			}

		}while(option != 'Y' && option != 'N');

	}while(option !='N');
}

void clear_list(vector<int> &vec){
/*
 * clear data in vector list
 */

	if(vec.size()){
		//clear value in the list
		vec.clear();
		cout << "All the elements of the list are cleared." << endl;
	}
	else{
		cout << "Nothing to clear - list is empty" << endl;
	}
}

void display_mean(vector<int> &vec){
/*
 * to display average number of the whole vector list
 */

	int sum{};
	double total{};

	if(vec.size()){
		for(auto x:vec){
			sum += x;
		}
		//calculate average
		total = static_cast<double>(sum)/vec.size();
		cout << "Mean or Average of the elements in the list is: "
				<< total << endl;
	}
	else{
		cout << "Unable to calculate the mean - no data" << endl;
	}
}

void display_smallest_num(vector<int> &vec){
/*
 * display smallest data in vector list
 */

	int min{};

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
}

void display_largest_num(vector<int> &vec){
/*
 * display largest data in vector list
 */

	int max{};

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
}


void search_num_count(vector<int> &vec){
/*
 * search a selected number in vector list
 */

	int search_num{},count{};

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
}
