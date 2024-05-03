#ifndef _SEARCHING_H
#define _SEARCHING_H

#include <stdlib.h>

int binarySearch(void *array, int length, size_t elemSize, void *target, int(*cmp)(void *, void *));

int linearSearch(void *array, int length, size_t elemSize, void *target, int(*cmp)(void *, void *));

#endif
