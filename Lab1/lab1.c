#include <stdio.h>


/*
	Swaps the values that are pointed to.
	!Important does not swap which values are being pointed to
*/
void swap(int *a, int *b) {
	//printf("%d %d", *a, *b);
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*
	Takes parameters array and size
		array : an int array of size "size"
		size : the size of "array"
	Calls swap to swap the max and min values
	If only one value is present then function returns zero
		Note : This apllies in two cases
			Only one value given
			Only one value given but multiple instances of the value in array 
*/
int swapMaxMin ( int array[] , int size ) {
	int *min = array;
	int *max = array;

	for (int i = 1; i < size; i++) {
		if (array[i] >= *max) {
			max = &array[i];
		}
		if (array[i] <= *min) {
			min = &array[i];
		}
	}

	if (max == min) {
		return 1;
	}
	swap(min, max);
	return 0;
}

/*
	charAt paramters str index result
		str is null terminated string
		index is index of character
		result is pointer of character that result is stored in
		returns 0 if index is valid
		returns 1 if not
*/
int charAt (char str[], int index, char *result) {
	if (index < 0) {
		return 1;
	}
	for (int i = 0; i <= index; i++) {
		if (str[i] == '\0') {
			printf("Null detected");
			return 1;
		}
	}
	//printf("Sucses/n");
	*result = str[index];
	return 0;
}
