#include "lab8.h"

int main() {
    printf("hello\n");

    VendingMachine* vm = newMachine();
    StockItem item;
    StockItem *pitem = &item;
    int ids[10] = {1, 2, 3, 4, 4, 6, 7, 8, 9, 9}; 
    int error;

    for (int i = 0; i < 10; i++) {
        StockItem item2;
        item2.stock = 100;
        item2.maxStock = 100;
        item2.price = 10.0;
        item2.ID = i + 1;
        error = addStockItem(vm, item2, ids[i]);
        if (error == 0) {
            printf("error\n");
        }
        if (error == 1) {
            printf("Insert Beging\n");
        }
        if (error == 2) {
            printf("empty list\n");
        }
        if (error == 3) {
            printf("Insert end\n");
        }
        if (error == 4) {
            printf("Found\n");
        }
    }
    printIDS(vm);
    for (int i = 0; i < 14; i = i + 2) {
        if((removeStockItem(vm , i, pitem) == 0) || (purchaseItem(vm, i + 1) == -9999)) {
            printf("NULL\n");
        }
    }
    printIDS(vm);
    // printf("%d\n", addStockItem(vm, item, 0));
    // for (int x = 0; x < 1000; x++) {
    // if (addStockItem(vm, item) == 1) {
    //     getStockItem(vm, 100, &item2);
    // }
    // }
    // printf("%d\n", countItems(vm));
    // printf("%d\n", countFull(vm));

    // printf("item2 id: %d\n", item2.ID);







    freeVendingMachine(vm);

}
