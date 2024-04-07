#include <stdio.h>
#include <stdlib.h>
#include "lab2.h"




int main() {

	int *p;
	int size = 1000;
	p = makeArray(size);

	for (int i = 0; i < size; i++) {
		//printf("%d\n", p[i]);
		p[i] = 10*(i + 1) * i + i/5;
		printf("%d\n", p[i]);
	}
	printf("index: %d\n", indexOf(p, size, 3));

	int newSize = sliceArray(p, size, 0, 9990199, &p);
	printf("new size %d\n", newSize);
	for (int i = 0; i < size; i++) {
		printf("new element %d %d\n", i, p[i]);
	}

	freeArray(&p);
	//for (int i = 0; i < size; i++) {
	//	printf("Free element #%d %d\n", i, p[i]);
	//}
	//printf("\n%p\n", (void*)(p));
	//printf("%d\n", p[1]);
	return 0;
}
