#ifndef _SORTING_H
#define _SORTING_H

#include <stdlib.h>

void selectionSort(void *array, int length, size_t elemSize, int(*cmp)(void *, void *));

void bubbleSort(void *array, int length, size_t elemSize, int(*cmp)(void *, void *));

void mergeSort(void *array, int length, size_t elemSize, int(*cmp)(void *, void *));

void quickSort(void *array, int length, size_t elemSize, int(*cmp)(void *, void *));

#endif