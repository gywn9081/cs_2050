#include "lab11.h"

// -------- HELPER FUNCTIONS --------

void swap(Car *a, Car *b) {
    if(a == b) {
        return;
    }

    Car temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(Car *array, int size, int (*cmp)(Car *, Car *)) {
    Car *min;

    for(int i = 0; i < size; ++i) {
        min = array + i;
        for(int j = i; j < size; ++j) {
            if(cmp(min, array + j) > 0) {
                min = array + j;
            }
        }
        swap(array + i, min);
    }
}

void bubbleStort(Car *array, int size, int (*cmp)(Car *, Car *)) {
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < (size - i - 1); ++j) {
            if(cmp(array + j, array + j + 1) > 0) {
                swap(array + j, array + j + 1);
            }
        }
    }
}

int recursiveAscendingBinarySearch(Car *array, Car *target, int min, int max, int (*cmp)(Car *, Car *)) {
	if(max < min) {
		return -1;
	}

	int median = min + (max - min) / 2;

	if(cmp(array + median, target) == 0) {
		return median;
	} else if(cmp(array + median, target) > 0) {
		max = median - 1;
	} else {
		min = median + 1;
	}

	return recursiveAscendingBinarySearch(array, target, min, max, cmp);
}

int compareBySKU(Car *a, Car *b) {
    if(a->SKU > b->SKU) {
        return 1;
    } else if(b->SKU == a->SKU) {
        return 0;
    }
    return -1;
}

int compareByPrice(Car *a, Car *b) {
    if(a->price > b->price) {
        return 1;
    } else if(a->price < b->price) {
        return -1;
    }
    return 0;
}

// -------- STRUCT DEFINITIONS --------

struct Database_t {
    Car *SKU;
    Car *price;
    int size;
};

// -------- REQUIRED FUNCTIONS --------

/* makeDatabase
    This function takes an array of Car structs,
    as well as the size of the array. It creates a
    two-to-one mapped database with elements sorted
    by both SKU and price. It assumes that no duplicates
    exist in the data. It returns a pointer to the
    database on success, or NULL on failure.
*/
Database * makeDatabase(Car *cars, int size) {
    Database *db = malloc(sizeof(Database) + sizeof(Car) * size * 2);

    if(!db) {
        return NULL;
    }

    db->price = (Car *)(db + 1);
    db->SKU = db->price + size;
    db->size = size;

    for(int i = 0; i < size; ++i) {
        db->price[i] = db->SKU[i] = cars[i];
    }

    selectionSort(db->SKU, size, compareBySKU);
    bubbleStort(db->price, size, compareByPrice);
    return db;
}

/* printSKU_Sorted
    This function takes a Database, and
    prints out the elements in SKU-order
*/
void printSKU_Sorted(Database *db) {
    int size = db->size;

    printf("SKUs: ");

    for(int i = 0; i < size; ++i) {
        printf("%d%s", db->SKU[i].SKU,
            (i + 1 == size ? "\n" : ", "));
    }
}

/* printSKU_Sorted
    This function takes a Database, and
    prints out the elements in price-order
*/
void printPriceSorted(Database *db) {
    int size = db->size;

    printf("prices: ");

    for(int i = 0; i < size; ++i) {
        printf("$%.2lf%s", db->price[i].price,
            (i + 1 == size ? "\n" : ", "));
    }
}

/* getPN_FromSKU
    This function takes a Databse, and performs a
    logarithmic lookup on the given SKU. If found,
    it returns the OEM_PN associated with that SKU,
    otherwise it returns ULLONG_MAX
*/
unsigned long long getPN_FromSKU(Database *db, int SKU) {
    Car temp = {SKU, 0, 0};
    int index = recursiveAscendingBinarySearch(db->SKU, &temp, 0, db->size - 1, compareBySKU);

    if(index == -1) {
        return -1;
    }

    return db->SKU[index].OEM_PN;
}

/* getSKU_FromPrice
    This function takes a Databse, and performs a
    logarithmic lookup on the given price. If found,
    it returns the SKU associated with that price,
    otherwise it returns -1
*/
int getSKU_FromPrice(Database *db, double price) {
    Car temp = {0, price, 0};
    int index = recursiveAscendingBinarySearch(db->price, &temp, 0, db->size - 1, compareByPrice);

    if(index == -1) {
        return -1;
    }

    return db->price[index].SKU;
}

/* destroy
    This function takes a databse, and drops it
*/
void destroy(Database *db) {
    free(db);
}

