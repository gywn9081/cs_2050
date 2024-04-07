#include <stdio.h>
#include "lab1.h"


int main() {
	//Testing data

	int array0[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//int array0[] = {0, 1, 2, 3, 4, 5, 9, 8, 7, 6, 10};
	//int array0[] = {0, 0, 0, 0, 0};
	//int array0[] = {10};
/*
	int swap0[] = {1, 2, 1};
	int *swapp1 = &swap0[0];
	int *swapp2 = &swap0[2];

	swap(swapp1, swapp2);
*/
	swapMaxMin(array0, 1);

	for (int i = 0; i < 1; i++) {
		printf("%d\n", array0[i]);
	}

	//printf("testing123");

	char stringd[] = {'t','e','\0','s'};
	int index = 0;
	char result = 'p';

	charAt(stringd, index, &result);

	printf("%c", result);











	return 0;
}
