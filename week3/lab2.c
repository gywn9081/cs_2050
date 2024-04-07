#include <stdio.h>
#include <stdlib.h>


/*
	int* makeArray (int size)
		Parameters
			size is a int giving size of desired int array
		Returns
			Pointer to created array
*/
int* makeArray (int size) {
	int *array;
	array = malloc(size * sizeof(int));
	if (array == NULL) {
		return array;
	}
	for (int i = 0; i < size; i++) {
		array[i] = 0;
	//	printf("changing %d\n", i);
	}
	return array;
}


/*
	void freeArray(int** array)
		Parameters
			array a pointer to an integer array
		Returns
			Nothing
		Result
			Frees memory being pointed to and sets pointer to NULL
*/
void freeArray (int **array) {
	free(*array);
	*array = NULL;
	//printf("%p", (void*)(*array));

}


/*
	int indexOf (int* array, int size, int element)
		Parameter
			array take an integer array of size "size"
			size gives size of "array"
			element gives integer target value
		Returns
			Index of found element if in list if not present: -1
*/
int indexOf (int* array, int size, int element) {
	for (int i = 0; i < size; i++) {
		if (array[i] == element) {
			return i;
		}
	}
	return -1;
}


/*
	int sliceArray(int* array, int size, int begin, int end, int** result)
		Parameters
			array integer array of "size"
			size integer size of "array"
			begin integer of begining section of target slice
			end intger of end section of target slice
			result int pointer to be set to new start of array
		Returns
			New length of sliced array
*/
int sliceArray (int* array, int size, int begin, int end, int** result) {
	int indexb = indexOf(array, size, begin);
	int indexe = indexOf(array, size, end);
	if (indexb == -1 || indexe == -1) {
		return -1;
	}

	int length = ((indexe + 1) - indexb);
	for (int i = 0; i < length; i++) {
		array[i] = array[indexb + i];
		printf("element %d\n", (indexb + i));
	}
	*result = array;
	return length;
}
