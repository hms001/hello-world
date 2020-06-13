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
#include <iomanip> //set for precision
#include <limits> //set for numeric limits

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
void data_conversion();
void display_pyramid();
void logical_operators(int age, bool parental_consent, bool ssn, bool accidents);
void convert_cents();
void convert_cents_modulus();
void shipping_cost_calculator();
void conditional_operator();
int count_numbers(const vector<int> &vec);
int calculate_pairs(vector<int> vec);
int points(const std::array<std::string, 10>& games);

int main() {

//	display_input_output();
//	test_overflow();
//	test_constant_variable();
//	test_array_size();
//	test_vector();
//	cout << split_string("sam harris") << endl;
//	cout << abbrev_name("Noah Centineo") << endl;
//	cout << consecutiveDucks (64) << endl;
//	data_conversion();
//	display_pyramid();
//	bool parental_consent{1};
//	bool ssn{1};
//	bool accidents{0};
//	int age = 16;
//	logical_operators(age,parental_consent,ssn,accidents);
//	convert_cents();
//	convert_cents_modulus();
//	shipping_cost_calculator();
//	conditional_operator();
//	vector <int> v {100,101,103,-50,-99,30,70};
//	cout << "Numbers of intergers presence in vector: " << count_numbers(v) << endl;
//	vector<int> vec{2,4,6,8};
//	cout << calculate_pairs(vec) << endl;
	const std::array<std::string, 10>& games{"1:0","2:0","3:0","4:0","2:1","3:1","4:1","3:2","4:2","4:3"};
	cout << "count of points: " << points(games) << endl;
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

void data_conversion(){
	int total{};
	int num1{},num2{},num3{};
	const int count{3};

	cout << "Enter 3 numbers seperated by space: ";
	cin >> num1 >> num2 >> num3;

	total = num1+num2+num3;
	double average{0.0};

	average = total/count;

	cout << "The sum of the numbers is " << total << endl;
	cout << "The average of the numbers is " << average << endl;

	double new_average{0.0};
	new_average = static_cast<double>(total)/count;
	cout << "The exact average of the numbers is " << new_average << endl;

}

void display_pyramid(){
	int i{},j{},k{};

	for(k=1;k<=5;k++){
		for(j=1;j<=5-k;j++){
			cout << " ";
		}
		for(i=1;i<=2*k-1;i++){
			cout << "*";
		}
		cout << endl;
	}
}

void logical_operators(int age, bool parental_consent, bool ssn, bool accidents) {

    if ((age >=18 || (age >= 16 && parental_consent)) && ssn && !accidents)
        cout << "Yes, you can work.";

    return;
}

void convert_cents(){

	cout << "Please enter amount in cents: ";
	unsigned int cents{};

	cin >> cents;

	const int dollar{100},quarter{25},dime{10},
	nickel{5},penny{1};

	unsigned int cents_do{},cents_qu{},cents_di{},
		cents_ni{},cents_pe{};

	unsigned int current_cents{},balance{};

	cents_do = cents/dollar;
	current_cents = dollar * cents_do;
	balance = cents - (dollar * cents_do);

	cents_qu = balance/quarter;
	current_cents = current_cents + (quarter * cents_qu);
	balance -= quarter * cents_qu;

	cents_di = balance/dime;
	current_cents = current_cents + (dime * cents_di);
	balance -= dime * cents_di;

	cents_ni = balance/nickel;
	current_cents = current_cents + (nickel * cents_ni);
	balance -= nickel * cents_ni;

	cents_pe = balance/penny;


	cout << "dollars  : " << cents_do << endl;
	cout << "quarters : " << cents_qu << endl;
	cout << "dimes    : " << cents_di << endl;
	cout << "nickels  : " << cents_ni << endl;
	cout << "pennies  : " << cents_pe << endl;

}

void convert_cents_modulus(){

	cout << "Please enter amount in cents: ";
	int cents{};

	cin >> cents;

	const int dollar{100},quarter{25},dime{10},nickel{5};

	int cents_do{},cents_qu{},cents_di{},
		cents_ni{},cents_pe{};

	int balance{};

	cents_do = cents/dollar;
	balance = cents % dollar;

	cents_qu = balance/quarter;
	balance %= quarter;

	cents_di = balance/dime;
	balance %= dime;

	cents_ni = balance/nickel;
	balance %= nickel;

	cents_pe = balance;

	cout << "dollars  : " << cents_do << endl;
	cout << "quarters : " << cents_qu << endl;
	cout << "dimes    : " << cents_di << endl;
	cout << "nickels  : " << cents_ni << endl;
	cout << "pennies  : " << cents_pe << endl;
}

void shipping_cost_calculator(){

	int length{},width{},height{},pkg_volume{};
	double total_cost{};
	const double base_cost{2.50};
	const double greater_100_surcharge{0.10};
	const double greater_500_surcharge{0.25};

	cout << "Please enter package dimension in inches" << endl;
	cout << "=========================================" << endl;
	cout << "\nlength : ";
	cin >> length;
	cout << "width : ";
	cin >> width;
	cout << "height : ";
	cin >> height;

	if(length <= 10 && width <= 10 && height <= 10){
		pkg_volume = length * width * height;
		if(pkg_volume >= 100 && pkg_volume <= 499){
			total_cost = base_cost + (base_cost*greater_100_surcharge);

		}
		else if(pkg_volume >= 500){
			total_cost = base_cost + (base_cost*greater_500_surcharge);

		}
		else{
			total_cost = base_cost;
		}

		cout << fixed << setprecision(2);
		cout << "Shipping total cost is $" << total_cost << endl;
	}
	else{
		cout << "Dimension is more than 10 inches!" << endl;
		cout << "We cannot ship it." << endl;
	}

}


void conditional_operator(){

	int num1{},num2{};
	cout << "Enter a number: ";
	cin >> num1 >> num2;

	if(num1 != num2){
		cout << ((num1 > num2) ? num1 : num2)  << " is larger." << endl;
		cout << ((num1 < num2) ? num1 : num2)  << " is smaller." << endl;
	}
	else{
		cout << "The values are the same." << endl;
	}
}


int count_numbers(const vector<int> &vec){
/*
*	The type_size size_t is part of the std library. It is the unsigned integer type
*	result of the sizeof operator since C++11 meaning it cannot be zero or  a negative
*	number and <int> is a signed type which can have negative numbers. Using int will
*	work, however will cause warnings with conversions when getting the length of types
*	such as arrays and vectors . Also,  size_t can theoretically store the maximum size
*	of a possible object of any type(including arrays and vectors(array.size(); vector.size();
*	sizeof(vector); sizeof(array);) size_t is commonly used for indexing and loop counting.
*	When indexing containers like string , array, or vector, the typedef size_type provided
*	by the containers is usually defined as a synonym for size_t.
*/
	int count{0};
	size_t index{};

	while(index < vec.size() && vec.at(index)!=-99){
		count++;
		index++;
	}
	return count;
}

int calculate_pairs(vector<int> vec){
/*
 * Given the vector vec to be {1,2,3}, the possible pairs are
 * (1,2),(1,3) and (2,3). So the result would be (1*2)+(1*3)+(2*3)
 * which is 11
 */
	int result{};
	for(size_t x{};x<vec.size();x++){
		for(size_t y{x+1};y<vec.size();y++){
			result += (vec.at(x)*vec.at(y));
		}
	}

	return result;
}

int points(const std::array<std::string, 10>& games){
/*
 * Our football team finished the championship. The result of each match look like "x:y".
 * Results of all matches are recorded in the collection.
 * For example: ["3:1", "2:2", "0:1", ...]
 * Write a function that takes such collection and counts the points of our team in the
 * championship. Rules for counting points for each match:
 * if x>y - 3 points
 * if x<y - 0 point
 * if x=y - 1 point
 * Notes:

 * there are 10 matches in the championship
 * 0 <= x <= 4
 * 0 <= y <= 4
 */
	int count_of_points{};
	string result_of_match{};
	string x{},y{};
	for(auto result:games){
		result_of_match = result;
		x = result_of_match.at(0);
		y = result_of_match.at(2);

//		if(x > y){
//			count_of_points += 3;
//		}
//		else if(x < y){
//			count_of_points += 0;
//		}
//		else if(x == y){
//			count_of_points += 1;
//		}

		count_of_points += (x > y)? 3 : (x < y)? 0 : 1;

	}

	return count_of_points;
}
