#include "lab7.h"

int main() {
    printf("hello\n");

    VendingMachine* vm = newMachine();

    StockItem item;
    StockItem item2;
    item.ID = 100;
    item.stock = 100;
    item.maxStock = 100;
    item.price = 10.0;
    for (int x = 0; x < 1000; x++) {
    if (addStockItem(vm, item) == 1) {
        getStockItem(vm, 100, &item2);
    }
    }
    printf("%d\n", countItems(vm));
    printf("%d\n", countFull(vm));

    printf("item2 id: %d\n", item2.ID);







    freeVendingMachine(vm);

}
