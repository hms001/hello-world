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

using namespace std;

bool isDivisible(int n, int x, int y);
int nbDig(int n, int d);

int main() {
//	cout << isDivisible(3, 3, 4) << endl;
	cout << nbDig(5750, 0) << endl;
	return 0;
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
