//============================================================================
// Name        : Arrays_and_Pointers.cpp
// Author      : HMS
// Version     :
// Copyright   : Your copyright notice
// Description :
/* Write a C++ function named apply_all that expects two arrays of integers and their sizes and
  dynamically allocates a new array of integers whose size is the product of the 2 array sizes

  The function should loop through the second array and multiplies each element across each element of array 1 and store the
  product in the newly created array.

  The function should return a pointer to the newly allocated array.

  You can also write a print function that expects a pointer to an array of integers and its size and display the
  elements in the array.

  For example,

  Below is the output from the following code which would be in main:

    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};

    cout << "Array 1: " ;
    print(array1,5);

    cout << "Array 2: " ;
    print(array2,3);

    int *results = apply_all(array1, 5, array2, 3);
    cout << "Result: " ;
    print(results,15);

   Output
   ---------------------
   Array 1: [ 1 2 3 4 5 ]
   Array 2: [ 10 20 30 ]
   Result: [ 10 20 30 40 50 20 40 60 80 100 30 60 90 120 150 ]
*/
//============================================================================

#include <iostream>

//make const int const * as to prevent any changes to pointer or what it's pointing to so if
//any changes make, the error will bbe caught
int *apply_all(const int const *array1,size_t array1_size,const int const *array2,size_t array2_size);
void print(const int const *array1,size_t array1_size);

using namespace std;

int main() {
    const size_t array1_size {5};
    const size_t array2_size {3};

    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};
    apply_all(array1, array1_size, array2, array2_size);
    cout << "Array 1: " ;
    print(array1,array1_size);

    cout << "Array 2: " ;
    print(array2,array2_size);

    int *results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size {array1_size * array2_size};

    cout << "Result: " ;
    print(results, results_size);

    //delete array pointer
    delete [] results;
    cout << endl;

    return 0;
}

int *apply_all(const int const *array1,size_t array1_size,const int const *array2,size_t array2_size){
/*
 * dynamically allocates a new array then it loops through each element of arr2
 * and multiples it across all the elements of arr1  and each product is stored
 * in the newly created array
 */

	int *result{nullptr};
	auto size_calc{array1_size*array2_size};
	//allocating new int size
	result = new int[size_calc];

	int arr_size{0};
	for(size_t x=0; x < array2_size; x++){

		for(size_t y=0; y < array1_size; y++){
			/*get by dereferencing pointer*/
//			result[arr_size] = (*(array1+y)) * (*(array2+x));
			//use by address value
			result[arr_size] = array1[y] * array2[x];
			arr_size++;
		}

	}

	return result;
}

void print(const int const *array1,size_t array1_size){
/*
 * loops through array and display all the integers
 */

	cout << "[ " ;
	for(size_t i{0}; i < array1_size; i++){
		/*get by dereferencing pointer*/
//		cout << *(array1+i) << " ";
		cout << array1[i] << " ";
	}
	cout << "]" << endl;
}
