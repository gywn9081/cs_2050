#include "lab11.h"


typedef struct Database_t {
    int size;
    Car* bySKU;
    Car* byPrice;
} Database;





// O(n^2)
/*creates databas of cars searchable with sku and price*/
Database* makeDatabase(Car* cars, int size){
    // if (size == 0) {
    //     return NULL;
    // }
    Database* db = malloc(sizeof(Database));
    if (db == NULL) {
        return NULL;
    }
    db->size = size;

    db->bySKU = malloc(sizeof(Car) * db->size);
    if (db->bySKU == NULL) {
        free(db);
        return NULL;
    }
    db->byPrice = malloc(sizeof(Car) * db->size);
    if (db->byPrice == NULL) {
        free(db->bySKU);
        free(db);
        return NULL;
    }
    if (size < 1) {
        return db;
    }
    // printf("test\n");

    Car** cars_SKU = malloc(sizeof(Car*) * (db->size * 2));
    if (cars_SKU == NULL) {
        free(db->bySKU);
        free(db->byPrice);
        free(db);
        return NULL;
    }
    Car** cars_price = cars_SKU + db->size;
    for (int index = 0; index < db->size; index++) {
        cars_SKU[index] = &(cars[index]);
        cars_price[index] = &(cars[index]);
    }

    // printf("test\n");
    // ! Assuming everything went well
    // * Sorting (Insane way to do this)
    int smallest_SKU = 0;
    int smallest_price = 0;
    for (int i = 0; i < db->size; i++) {
        for (int index = 0; index < db->size; index++) {
            // printf("%d\n", index);
            if (cars_price[index] != NULL) {
                if (smallest_price == -1) {
                    smallest_price = index;
                }
                if (cars_price[index]->price < cars_price[smallest_price]->price) {
                    smallest_price = index;
                }
            }
            if (cars_SKU[index] != NULL) {
                if (smallest_SKU == -1) {
                    smallest_SKU = index;
                }
                if (cars_SKU[index]->SKU < cars_SKU[smallest_SKU]->SKU) {
                    smallest_SKU = index;
                }
            }
        }
        cars_price[smallest_price] = NULL;
        cars_SKU[smallest_SKU] = NULL;
        db->byPrice[i] = cars[smallest_price];
        db->bySKU[i] = cars[smallest_SKU];
        smallest_price = -1;
        smallest_SKU = -1;
    }
    free(cars_SKU);
    return db;
}

// O(n)
/*prints sku in ascending sorted order*/
void printSKU_Sorted(Database *db) {
    printf("SKUs : ");
    if (db->size > 0) {
        for (int i = 0; i < (db->size - 1); i++) {
            printf("%d, ", db->bySKU[i].SKU);
        }
        printf("%d", db->bySKU[db->size - 1].SKU);
    }
    printf("\n");
}

// O(n)
/*prints prices in asscending sorted order*/
void printPriceSorted(Database *db) {
    printf("prices : ");
    if (db->size > 0) {
        for (int i = 0; i < (db->size - 1); i++) {
            printf("$%lf, ", db->byPrice[i].price);
        }
        printf("$%lf", db->byPrice[db->size - 1].price);
    }
    printf("\n");

}


// O(log(n))
/*gets OEM number from sku given*/
unsigned long long getPN_FromSKU(Database *db, int SKU) {
    if (db->size < 1) {
        return -1;
    }
    int b_index = 0;
    int e_index = db->size - 1;
    int choice = e_index - ((e_index - b_index) / 2);
    // e_index - ((e_index - b_index) / 2)
    while ((b_index != choice) && (e_index != choice)) {
        // printf("b_index: %d e_index: %d choice: %d\n", b_index, e_index, choice);
        if (db->bySKU[choice].SKU == SKU) {
            return db->bySKU[choice].OEM_PN;
        }
        else if (SKU < db->bySKU[choice].SKU) {
            e_index = choice;
        }
        else if (SKU > db->bySKU[choice].SKU){
            b_index = choice;
        }
        choice = e_index - ((e_index - b_index) / 2);
    }
    if (db->bySKU[choice].SKU == SKU) {
        // printf("Found at end");
        return db->bySKU[choice].OEM_PN;
    }
    return -1;
}

// O(log(n))
/*get sku from price in O(log(n))*/
int getSKU_FromPrice(Database *db, double price) {
    if (db->size < 1) {
        return -1;
    }
    int b_index = 0;
    int e_index = db->size - 1;
    int choice = e_index - ((e_index - b_index) / 2);
    while ((b_index != choice) && (e_index != choice)) {
        // printf("b_index: %d e_index: %d choice: %d\n", b_index, e_index, choice);
        // printf("%d\n", e_index - ((e_index - b_index) / 2));
        if (db->byPrice[choice].price == price) {
            return db->bySKU[choice].SKU;
        }
        else if (price < db->byPrice[choice].price) {
            e_index = choice;
        }
        else if (price > db->byPrice[choice].price){
            b_index = choice;
        }
        // printf("%d\n", e_index - ((e_index - b_index) / 2));
        choice = e_index - ((e_index - b_index) / 2);
    }
    if (db->bySKU[choice].price == price) {
        // printf("Found at end");
        return db->bySKU[choice].price;
    }
    return -1;
}

// O(1)
// This Assumes that the car objects will be freed by the user. I do not belive O(1) would be possible if not
/*Frees all memory used*/
void destroy(Database *db) {
    // free(&(db->size));
    free(db->bySKU);
    free(db->byPrice);
    free(db);
}