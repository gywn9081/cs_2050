#include "lab5.h"



/*
	Parameters
		mSize int max size
		expensive int number of expensive items
		SIArray array of stock objects
*/
/*struct VendingMachine_t {
    // Your implementation goes here
	int mSize;
	int expensive;
	StockItem* SIArray;
};
*/
/*
	Creates a new vending machine and inits all fields needed
	Returns Vendingmachine pointer or NULL on fail
	Parameters
		numSlots int max number of StockItems
*/
VendingMachine* newMachine (int numSlots) {
	VendingMachine* vm = malloc(sizeof(VendingMachine));
	if (vm == NULL) {
		return NULL;
	}
	vm->expensive = 0;
	vm->mSize = numSlots;


	StockItem* array = malloc(sizeof(StockItem) * numSlots);
	vm->SIArray = array;
	if (array == NULL) {
		return NULL;
	}
	for (int i = 0; i < vm->mSize; i++) {
		vm->SIArray[i].ID = 0;
	}

	return vm;
}


/*
	Adds a StockItem if there is room in given VM(VendingMachine)
	Parameters
		vm VM pointer
		item SI(StockItem)
	returns
		0 for any error
		1 Succesfull adition
*/
int addStockItem (VendingMachine* vm, StockItem item) {
	if (vm == NULL || (item.ID == 0) ||(item.maxStock < item.stock)) {
		return 0;
	}
	for (int i = 0; i < vm->mSize; i++) {
		if(vm->SIArray[i].ID == 0) {
			vm->SIArray[i].ID = item.ID;
			vm->SIArray[i].price = item.price;
			vm->SIArray[i].maxStock = item.maxStock;
			vm->SIArray[i].stock = item.stock;
			if(item.price >= 3) {
				vm->expensive++;
			}
		return 1;
		}
	}
	return 0;
}


/*
	returns
		int number of SI's that are expensive
	Parameters
		vm VM pointer
*/
int countExpensive (VendingMachine* vm) {
	return vm->expensive;
}


/*
		Removes a SI from VM and sets result to removed item
		Parameters
			vm VM pointer
			ID int
			result SI pointer
		Returns
			-1 Vending machine pointer NULL
			0 Item not found
			1 Item found and removed
*/
int removeStockItem (VendingMachine* vm, int ID, StockItem* result) {
	if (vm == NULL || ID == 0) {
		return -1;
	}
	for (int i = 0; i < vm->mSize; i++) {
		if (vm->SIArray[i].ID == ID) {
			if (vm->SIArray[i].price >= 3) {
				vm->expensive = vm->expensive - 1;
			}
			// Add protection
			*result = vm->SIArray[i];
			vm->SIArray[i].ID = 0;
			return 1;
		}
	}
	return 0;
}



/*
	frees memory allocated
	Returns void
	Parameters
		vm VM pointer
*/
void freeVendingMachine (VendingMachine *vm) {
	free(vm->SIArray);
	vm->SIArray = NULL;
	free(vm);
	vm = NULL;
}

