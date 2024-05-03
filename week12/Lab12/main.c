#include <stdlib.h>
#include <stdio.h>
#include "sorting.h"
#include "searching.h"

int compareInts(void *a, void *b) {
    return *(int *)a - *(int *)b;
}

void print_int_array(int *array, int size) {
    printf("int[%d] = \n", size);
    for(int i = 0; i < size; ++i) {
        printf("%d%s", array[i],
            (i == (size - 1) ? "\n" : ", "));
    }
}

int main() {
    int size = 1000000;
    int num_runs = 6;
    int *array = malloc((sizeof(int) * size) * num_runs);
    int **arrayed_array = malloc(sizeof(int*) * num_runs);
    if(!arrayed_array) {
        fputs("Failed to allocated secondary array!", stderr);
        return EXIT_FAILURE;
    }
    if(!array) {
        fputs("Failed to allocated primary array!", stderr);
        return EXIT_FAILURE;
    }
    for (int i = 0; i < num_runs; i++) {
        arrayed_array[i] = (array + (size * i));
    }
    // int *array = malloc(sizeof(int) * size);
    int maxRandom = 10000;

    srand(255);


    int rand_number = rand() % (maxRandom + 1);
    for(int i = 0; i < size; ++i) {
        for (int w = 0; w < num_runs; w++) {
            arrayed_array[w][i] = rand_number;
        }
        rand_number = rand() % (maxRandom + 1);
    }

    // for (int i = 0; i < num_runs; i++) {
    //     printf("%d ", arrayed_array[i][0]);
    // }
    // printf("\n");

    // print_int_array(array, size);

    selectionSort(arrayed_array[0], size, sizeof(int), compareInts);
    mergeSort(arrayed_array[1], size, sizeof(int), compareInts);
    bubbleSort(arrayed_array[2], size, sizeof(int), compareInts);
    quickSort(arrayed_array[3], size, sizeof(int), compareInts);

    int search_places[4] = {(int)(size * 0.33), (int)(size * 0.49), (int)(size / 2), (int)(size * 0.79)};

    for (int i = 0; i < 4; i++) {
        binarySearch(arrayed_array[4], size, sizeof(int), &(search_places[i]), compareInts);
        linearSearch(arrayed_array[5], size, sizeof(int), &(search_places[i]), compareInts);
    }

    // print_int_array(array, size);

    // int test = array[(int)(size * 0.79)];

    // int result = linearSearch(array, size, sizeof(int), &test, compareInts);

    // printf("found %d at index [%d]\n", test, result);

    free(array);
    free(arrayed_array);
}
