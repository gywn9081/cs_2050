#include "sorting.h"

#include <inttypes.h>
#include <string.h>
#include <stdio.h>

void merge(void *arr, size_t elemSize, int min, int median, int max, int(*cmp)(void *, void *));

void mergeSortRecursive(void *array, int min, int max, size_t elemSize, int(*cmp)(void *, void *));

void quickSortRecursive(void *array, int min, int max, size_t elemSize, int(*cmp)(void *, void *));

int quickSortPartition(void *array, int min, int max, size_t elemSize, int(*cmp)(void *, void *));

// Generic swap function, works with any data
void swap(void *a, void *b, size_t size) {
    // We assume that sizeof(a) is small
    // enough to fit onto the stack
    uint8_t bytes[size];

    memcpy(bytes, a, size);
    memcpy(a, b, size);
    memcpy(b, bytes, size);
}

// -------------------------------- SELECTION_SORT --------------------------------

void selectionSort(void *array, int length, size_t elemSize, int(*cmp)(void *, void *)) {
    void *min;

    uint8_t *bytes = array;
    size_t num_bytes = length * elemSize;

    for(int i = 0; i < num_bytes; i += elemSize) {
        min = bytes + i;
        for(int j = i; j < num_bytes; j += elemSize) {
            if(cmp(min, bytes + j) > 0) {
                min = bytes + j;
            }
        }
        swap(bytes + i, min, elemSize);
    }
}

// -------------------------------- BUBBLE_SORT --------------------------------

void bubbleSort(void *array, int length, size_t elemSize, int(*cmp)(void *, void *)) {
    uint8_t *bytes = array;
    size_t num_bytes = length * elemSize;

    for(int i = 0; i < num_bytes; i += elemSize) {
        for(int j = 0; j < (num_bytes - i - elemSize); j += elemSize) {
            if(cmp(bytes + j, bytes + j + elemSize) > 0) {
                swap(bytes + j, bytes + j + elemSize, elemSize);
            }
        }
    }
}

// -------------------------------- MERGE_SORT --------------------------------

void mergeSort(void *array, int length, size_t elemSize, int(*cmp)(void *, void *)) {
    mergeSortRecursive(array, 0, length - 1, elemSize, cmp);
}

void mergeSortRecursive(void *array, int min, int max, size_t elemSize, int(*cmp)(void *, void *)) {
    if(min >= max) {
        return;
    }

    int median = min + (max - min) / 2;
    mergeSortRecursive(array, min, median, elemSize, cmp);
    mergeSortRecursive(array, median + 1, max, elemSize, cmp);

    merge(array, elemSize, min, median, max, cmp);
}

void merge(void *array, size_t elemSize, int min, int median, int max, int(*cmp)(void *, void *)) {
    int leftSize = median - min + 1;
    int rightSize = max - median;

    uint8_t *bytes = array;
    uint8_t *left = malloc(elemSize * leftSize);
    uint8_t *right = malloc(elemSize * rightSize);

    if(!left || !right) {
        fputs("MEMORY ALLOCATION ERROR in merge: exiting", stderr);
        // We cannot recover from this error,
        // since we have no way to let the caller know that something went wrong
        exit(EXIT_FAILURE);
    }

    memcpy(left, bytes + elemSize * min, elemSize * leftSize);
    memcpy(right, bytes + elemSize * (median + 1), elemSize * rightSize);

    int index = min * elemSize, lindex = 0, rindex = 0;

    while(lindex < (leftSize * elemSize) && rindex < (rightSize * elemSize)) {
        if(cmp(left + lindex, right + rindex) <= 0) {
            memcpy(bytes + index, left + lindex, elemSize);
            lindex += elemSize;
        } else {
            memcpy(bytes + index, right + rindex, elemSize);
            rindex += elemSize;
        }
        index += elemSize;
    }

    if(lindex == (leftSize * elemSize)) {
        int leftovers = rightSize * elemSize - rindex;
        memcpy(bytes + index, right + rindex, leftovers);
    } else {
        int leftovers = leftSize * elemSize - lindex;
        memcpy(bytes + index, left + lindex, leftovers);
    }

    free(left);
    free(right);
}

// -------------------------------- QUICK_SORT --------------------------------

void quickSort(void *array, int length, size_t elemSize, int(*cmp)(void *, void *)) {
    quickSortRecursive(array, 0, length - 1, elemSize, cmp);
}

void quickSortRecursive(void *array, int min, int max, size_t elemSize, int(*cmp)(void *, void *)) {
    if(min >= max) {
        return;
    }
    
    int p = quickSortPartition(array, min, max, elemSize, cmp);
    quickSortRecursive(array, min, p - 1, elemSize, cmp);
    quickSortRecursive(array, p + 1, max, elemSize, cmp);
}

int quickSortPartition(void *array, int min, int max, size_t elemSize, int(*cmp)(void *, void *)) {
    uint8_t *bytes = array;

    uint8_t *pivot = bytes + max * elemSize;
    int index = min - 1;

    for(int i = min; i < max; ++i) {
        if(cmp(bytes + i * elemSize, pivot) <= 0) {
            ++index;
            swap(bytes + index * elemSize, bytes + i * elemSize, elemSize);
        }
    }

    swap(bytes + elemSize * (index + 1), bytes + elemSize * max, elemSize);
    return index + 1;
}
