#include "searching.h"

#include <inttypes.h>

int binarySearch(void *array, int length, size_t elemSize, void *target, int(*cmp)(void *, void *)) {
    uint8_t *bytes = array;

    int min = 0, max = length - 1;

    while(min <= max) {
        size_t median = min + (max - min) / 2;

        if(cmp(bytes + median * elemSize, target) == 0) {
            return median;
        } else if(cmp(bytes + median * elemSize, target) > 0) {
            max = median - 1;
        } else {
            min = median + 1;
        }
    }

    return -1;
}

int linearSearch(void *array, int length, size_t elemSize, void *target, int(*cmp)(void *, void *)) {
    uint8_t *bytes = array;
    size_t numBytes = length * elemSize;

    for(int i = 0; i < numBytes; i += elemSize) {
        if(cmp(bytes + i, target) == 0) {
            return i / elemSize;
        }
    }

    return -1;
}
