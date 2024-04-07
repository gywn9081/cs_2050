#include <stdio.h>
#include "prel6.h"

int main() {

	int errorCode;

	GroceryList list;
	list = GroceryListInit(100, &errorCode);
	printf("%d\n", errorCode);
	list = GroceryListAppend(list, "Lettuce", &errorCode);
	printf("%d\n", errorCode);
	GroceryListPrint(list);

	GroceryListDelete(list);


	return 0;
}
