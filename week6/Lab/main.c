#include <stdio.h>
#include "lab5.h"


int main() {

	//VendingMachine vm = NULL;
	VendingMachine* vm = newMachine(100);
	//if (vm == NULL) {
	//	printf("exiting\n");
	//	return 1;
	//}
	int test = 4, scaler = 1;
	//printf("test %d\tscaler%d\n", test, scaler);
	StockItem item;
	int counter = 0;
	//printf("\n\n\n\n test\n\n\n\n\n");
	while (test != 0 && (counter < 2000)) {
		item.ID = scaler;
		item.stock = 1;
		item.maxStock = 5;
		item.price = (2.0 + 0.1 * scaler);
		test = addStockItem(vm, item);
		counter++;
		scaler++;
	}

	//printf("counter: %d\n", counter);
	for (int i = 0; i < 100; i++) {
		printf("ID: %d\tPrice: %lf\n", vm->SIArray[i].ID, vm->SIArray[i].price);
	}
	printf("expensive %d\t%d\n", vm->expensive, countExpensive(vm));
	StockItem item2;
	removeStockItem(vm, 10, &item2);
	printf("price %lf stock %d id %d\n", item2.price, item2.stock, item2.ID);
	printf("expensive %d\t%d\n", vm->expensive, countExpensive(vm));

	freeVendingMachine(vm);

	printf("this is a test");
	return 0;
}
