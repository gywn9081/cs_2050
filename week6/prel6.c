#include <stdio.h>
#include "prel6.h"



GroceryList GroceryListInit(int maxLength, int *errorCode) {
	*errorCode = 0;
	GroceryList glist;
	glist.listArray = malloc(sizeof(char*) * maxLength);
	if (glist.listArray == NULL) {
		*errorCode = 1;
	}
	for (int i = 0; i < maxLength; i++) {
		glist.listArray[i] = NULL;
	}
	glist.size = maxLength;
	glist.lelm = -1;

	return glist;
}

/*
Store pointer to malloc array
	listArray
Store size
	size
Store index of last element
	lelm

!Must be a 2D array first layer must be char pointers
important for free
*/

/*

	class notes
		ADT:
		Bag type just looks like a set no defined order can have dups


	Big O
	look at vector allocating double size when array must grow vs linked list


*/


/*
	error codes:
		0 Succesfull execution
		1 List full
		2 Item not created
*/
GroceryList GroceryListAppend(GroceryList glist, char * itemName, int * errorCode) {
	if ((glist.lelm + 1) >= glist.size) {
		*errorCode = 1;
		return glist;
	}

	glist.listArray[++glist.lelm] = itemName;
	*errorCode = 0;
	return glist;
}

/*
	error codes:
		0 Succesfull execution
		1 Supplied index OOB
		-1 Index valid but empty
*/
char * GroceryListGetItem(GroceryList glist, int k, int *errorCode) {
	if (k < 0 || k >= glist.size) {
		*errorCode = 1;
		return "FAILED";
	} else if (k > glist.lelm) {
		*errorCode = -1;
		return "";
	}
	*errorCode = 0;
	return glist.listArray[k];
}

int GroceryCount(GroceryList glist) {
	return (glist.lelm + 1);
}

void GroceryListPrint(GroceryList glist) {
	for (int i = 0; i <= glist.lelm; i++) {
		printf("item %d %s\n", (i + 1), glist.listArray[i]);
	}
}

void GroceryListDelete(GroceryList glist) {
	// May not work because char pointers may not be ours to free.
	/*
	for (int i = 0; i <= glist.lelm; i++){
		free(glist.listArray[i]);
		glist.listArray[i] = NULL;
	}
	*/
	free(glist.listArray);
	glist.listArray = NULL;
}
