//============================================================================
// Name        : Practice.cpp
// Author      : HMS
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int summation(int);
void display_input_output();
void test_overflow();
void test_constant_variable();
void test_array_size();
void test_vector();
string split_string(string);
string abbrev_name(string);
bool consecutiveDucks (unsigned int);

int main() {

//	display_input_output();
//	test_overflow();
//	test_constant_variable();
//	test_array_size();
//	test_vector();
//	cout << split_string("sam harris") << endl;
//	cout << abbrev_name("Noah Centineo") << endl;
	cout << consecutiveDucks (64) << endl;;
//	cout << "Result: " << summation(8) << endl;
	return 0;
}

int summation(int num){
// Code Here
	int value;
	int result = 0;
	for(int i = 0; i <num; i++)
	{
	   value = i + 1;
	   result = result + value;
	   cout << "value = " << value << endl;
	   cout << "result = " << result << endl;
	}
	   return num*(num+1)/2;
//	  return result;

}

void display_input_output(){
	int number;
	cout << "Enter your favorite number between 1 and 100: ";
	cin >> number;
	cout << "Amazing!! That's my favorite number too!" << endl;
	cout << "No really!!, " << number << " is my favorite number!" << endl;
}

void test_overflow(){
	long long num_of_ppl {7600000000};
	cout << "There are about " << num_of_ppl << " people on earth." << endl;
}

void test_constant_variable(){

	cout << "Estimate for carpet cleaning service" << endl;

	cout << "\nNumber of small rooms: ";
	int small_rooms {0};
	cin >> small_rooms;

	cout << "Number of large rooms: ";
	int large_rooms {0};
	cin >> large_rooms;

	const double small_room_price {25.0};
	const double large_room_price {35.0};
	const double tax_rate {0.06};
	const int valid_days {30}; //estimate validation

	cout << "Price per small rooms: $" << small_rooms * small_room_price << endl;
	cout << "Price per large rooms: $" << large_rooms * large_room_price << endl;
	cout << "Cost: $" << (small_rooms * small_room_price) + (large_rooms * large_room_price) << endl;
	cout << "Tax: $" << ((small_rooms * small_room_price) + (large_rooms * large_room_price))*tax_rate << endl;
	cout << "===============================================" << endl;
	cout << "Total estimate: $" << ((small_rooms * small_room_price) + (large_rooms * large_room_price)) +
			(((small_rooms * small_room_price) + (large_rooms * large_room_price))*tax_rate) << endl;
	cout << "This estimate is valid for " << valid_days << " days" <<endl;
}

void test_array_size(){

	int numbers[]{1,2,3,4};
	cout << "Input another number: ";
	cin >> numbers[4];
	cout << numbers[0] << "," << numbers[1] << "," << numbers[2] << "," << numbers[3] << "," << numbers[4];
}

void test_vector(){

	vector <int> vector1;
	vector <int> vector2;

	vector1.push_back(10);
	vector1.push_back(20);

	cout << vector1.at(0) << endl;
	cout << vector1.at(1) << endl;
	cout << "vector1 has " << vector1.size() << " element(s).\n"<< endl;

	vector2.push_back(100);
	vector2.push_back(200);

	cout << vector2.at(0) << endl;
	cout << vector2.at(1) << endl;
	cout << "vector2 has " << vector2.size() << " element(s).\n"<< endl;

	vector <vector<int>> vector_2d;

	vector_2d.push_back(vector1);
	vector_2d.push_back(vector2);

	cout << "2D Vector...\n" << vector_2d.at(0).at(0);
	cout << " " << vector_2d.at(0).at(1) << endl;
	cout << vector_2d.at(1).at(0) ;
	cout << " " << vector_2d.at(1).at(1) << endl;

	vector1.at(0) = 1000;

	cout << "\nAfter vector1 changed... \n" << vector_2d.at(0).at(0);
	cout << " " << vector_2d.at(0).at(1) << endl;
	cout << vector_2d.at(1).at(0) ;
	cout << " " << vector_2d.at(1).at(1) << endl;

	cout << "\nVector1...\n" << vector1.at(0) << endl;
	cout << vector1.at(1) << endl;

}

string split_string(string str){

	vector <string> result;
	istringstream ss(str);

	//split string by space
	for(string s; ss >> s; ){
		result.push_back(s);
	}

	stringstream combine_text;
	//get the first character of an array
	string first = result.at(0);
	string second = result.at(1);
	//assign upper case to first index of character
	first[0] = toupper(first[0]);
	second[0] = toupper(second[0]);
	//concatenate string
	combine_text << first.at(0) << "." << second.at(0);
	string shortened = combine_text.str();

	return shortened;

}

string abbrev_name(string name){
/*
 * to return only the abbreviation of a name
 * e.g. Michael Jordan = M.J
 *
 * */
	string abbrev {""};
	abbrev = toupper(name.at(0));
	abbrev += ".";
	abbrev += toupper(name.at(name.find(" ")+1));

	return abbrev;
}

bool consecutiveDucks (unsigned int num){
/*
 * to check if given number is a sum of two or more consecutive positive numbers
 * e.g. 24 = 9+8+7
 *
 * */

	bool check {1};
	unsigned int count = 0;
	for(unsigned int L = 1; L * (L+1) < 2*num; L++){
		double a = (1.0* num-(L*(L+1))/2)/(L+1);
		if(a - (int)a == 0.0){
			count++;
		}
	}

	if(count > 0){
		return check;
	}

	return !check;
}
