#include "lab11.h"


int main() {

    Car* cars = malloc(sizeof(Car) * 10);
    for (int i = 0; i < 10; i++) {
        cars[i].OEM_PN = i * 10;
        cars[i].price = i * 20.2;
        cars[i].SKU = 9 - i + 10;
    }

    Database* db = makeDatabase(cars, 10);
    if (db == NULL) {
        printf("bad");
        return 0;
    }

    printSKU_Sorted(db);
    printPriceSorted(db);
    getPN_FromSKU(db, 4);
    getSKU_FromPrice(db, 20.2);
    // printf("hello");
    getPN_FromSKU(db, 1);
    getSKU_FromPrice(db, 21110.2);

    destroy(db);
    free(cars);
    return 0;
}