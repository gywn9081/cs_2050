#include <stdio.h>
#include <stdlib.h>

// partial typedef, must complete in implementation file
typedef struct {
    int ID;
    // The amount of this item currently in stock
    int stock;
    // The max amount of this item that can fit in a slot
    int maxStock;
    // The purchase price of 1 of this item
    float price;
} StockItem;

typedef struct VendingMachine_t {
    // Your implementation goes here
        int mSize;
        int expensive;
        StockItem* SIArray;
} VendingMachine;


VendingMachine * newMachine(int numSlots);

int addStockItem(VendingMachine *vm, StockItem item);

int countExpensive(VendingMachine *vm);

int removeStockItem(VendingMachine *vm, int ID, StockItem *result);

void freeVendingMachine(VendingMachine *vm);

