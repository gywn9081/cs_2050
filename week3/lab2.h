#include <stdlib.h>
#include <stdio.h>


int * makeArray(int size);

int indexOf(int *array, int size, int element);

int sliceArray(int *array, int size, int begin, int end, int **result);

void freeArray(int **array);

