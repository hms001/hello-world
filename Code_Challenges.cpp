//============================================================================
// Name        : Code_Challenges.cpp
// Author      : HMS
// Version     :
// Copyright   : Your copyright notice
// Description : Compilations of coding challenges from different sources
//============================================================================

#include <iostream>
#include <cmath>
#include <string>
#include <ctype.h>

using namespace std;

int remove_duplicate(int *A,size_t N);
bool isDivisible(int n, int x, int y);
int nbDig(int n, int d);
string fakeBin(std::string str);
std::string solve(const std::string& str);

int main() {
//	cout << isDivisible(3, 3, 4) << endl;
//	cout << nbDig(5750, 0) << endl;
	int A[] {2,4,2,6,7};
	const size_t array1_size {5};
	cout << "Size of current array: " << remove_duplicate(A,array1_size) << endl;
//	return 0;
//	cout << fakeBin("45385593107843568") << endl;
	string str{"CODe"};
	cout << solve(str) << endl;
}

bool isDivisible(int n, int x, int y) {
/*
 * integer n to be able to divided by x and y
 */
	bool check{};
	cout << std::boolalpha; //to print literal true/false value
	check = ((n%x == 0) && (n%y == 0)) ? true: false;
	return check;

}

int nbDig(int n, int d){
/*
 * Take an integer n (n >= 0) and a digit d (0 <= d <= 9) as an integer.
 * Square all numbers k (0 <= k <= n) between 0 and n. Count the numbers
 * of digits d used in the writing of all the k**2. Call nb_dig (or nbDig or ...)
 * the function taking n and d as parameters and returning this count.
 * E.g. n = 10, d = 1, the k*k are 0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100
 * We are using the digit 1 in 1, 16, 81, 100. The total count is then 4.
 */
	int k{};
	int count{0};

	for(int num{0}; num <= n; num++){

		k = num * num;

		do{

			if(k%10 == d){
				count++;
			}
			k = k/10;
		}while(k > 0);

	}

	return count;
}


string fakeBin(std::string str){
/*
 * Given a string of digits, replace any digit below 5 with '0' and any digit 5
 *and above with '1'. Return the resulting string.
**/
	 std::string word{};
	 char d{};
//	 int num = std::stoi(str);
	 for(size_t digit{0}; digit < str.length(); digit++){
		 cout << str.at(digit) << endl;
		 char i= str.at(digit);
		 cout << "i = " << i << endl;
		 /****************************************************************************
		  * The digit characters are in the ASCII table at codes:
		  *	'0' : 48
		  *	'1' : 49
		  *	'2' : 50
		  *	'3' : 51
		  *	etc.
		  *	So, we need to convert the digit character to it's integer representation.
		  *	So, if we have '3' then
		  *	'3' - '0' is 51 - 48 which give the integer 3.
		  *****************************************************************************/
		if((str.at(digit)-'0') < 5){
			cout << "less than 5 " << endl;
		  d = '0';
		  word += d;
		}
		else{
			cout << "more than 5 " << endl;
		  d = '1';
		  word += d;
		}
	  }
	  return word;

}

std::string solve(const std::string& str){
/*
 * a string that may have mixed uppercase and lowercase letters and your task is to
 * convert that string to either lowercase only or uppercase only based on:
 *	-make as few changes as possible.
 *	-if the string contains equal number of uppercase and lowercase letters,
 *	convert the string to lowercase.
 * E.g.
 * solve("coDe") = "code". Lowercase characters > uppercase. Change only the "D" to lowercase.
 * solve("CODe") = "CODE". Uppercase characters > lowecase. Change only the "e" to uppercase.
 * solve("coDE") = "code". Upper == lowercase. Change all to lowercase.
 */
	string letter{str};
	int count_upper{0},count_lower{0};

	for(size_t n{0}; n<letter.length();n++){
		if(isupper(letter[n])){
			count_upper++;
		}
		else{
			count_lower++;
		}
	}

	if(count_upper > count_lower){
		for(size_t n{0}; n<letter.length();n++){
			int c = letter[n];
			letter[n] = toupper(c);
		}
	}
	else if(count_upper < count_lower){
		for(size_t n{0}; n<letter.length();n++){
			int c = letter[n];
			letter[n] = tolower(c);
		}
	}
	else if(count_upper == count_lower){
		for(size_t n{0}; n<letter.length();n++){
			int c = letter[n];
			letter[n] = tolower(c);
		}
	}

	return letter;
}

int remove_duplicate(int *A,size_t N){
/*
 * find any duplicate num inside array and remove if found
 * note: only after array position can check now need to improve to check
 * both before and after array positions
 */

	cout << "[ " ;
	for(size_t i{0}; i < N; i++){

		cout << A[i] << " ";
	}
	cout << "]" << endl;

	size_t y{};
	int a{};
	for(size_t x{0};x<N;x++){
		a++;
		cout << "a = " << a << endl;
		for(y=a;y<N;y++){
			cout << "N = " << N << endl;
			cout << "A[x] first : " << A[x] <<endl;
			cout << "A[y] first : " << A[y] <<endl;
			if(A[x] == A[y]){
				cout << "Meet condition" << endl;
				A[y] = A[y+1];
				A[y+1] = A[y+2];
				N--;
				cout << "A[x] after : " << A[x] <<endl;
				cout << "A[y] after : " << A[y] <<endl;

			}
			cout << "Changed [ " ;
			for(size_t i{0}; i < N; i++){

				cout << A[i] << " ";
			}
			cout << "]" << endl;
		}


	}
	cout << "[ " ;
	for(size_t i{0}; i < N; i++){

		cout << A[i] << " ";
	}
	cout << "]" << endl;


	return N;
}

