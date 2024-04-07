#include "lab0.h"

/* REQUIRED CODE GOES HERE */
/*          Thanks!        */
/*
	Function: countOccurrences

	Paramaters: size, array, query
		size(int) - The size of array being passed
		array(int []) - An array of size size being passed for lookup
		query(int) - The target value for lookup in the array

	Return: counter
		counter(int) - The number of times query was found in the array

	Error-Codes: N/A
		There are no error codes
*/

int countOccurrences ( int size , int array [] , int query ) {
	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (array[i] == query) {
			counter++;
		}
	}
	return counter;
}
