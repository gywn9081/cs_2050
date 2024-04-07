#include "lab8.h"


typedef struct node_t {
    StockItem item;
    struct node_t* next;
} node;



typedef struct VendingMachine_t {
    node* head;
} VendingMachine;


/*
    newMachine()
        Returns
            VendingMachine* pointer to vending machine
        Parameters
            None
        Use
            Create and init empty vending machine
*/
VendingMachine* newMachine() {
    VendingMachine *vm = malloc(sizeof(VendingMachine));
    if (vm == NULL) {
        return NULL;
    }
    vm->head = NULL;

    return vm;
}

/*
    Template for utils DO NOT USE
*/
void freeNode(node* unode);

/*
    addStockItem(VendingMachine*, StockItem)
        Returns
            int errorcode
                0 bad
                1 good
        Parameters
            VendingMachine* vm: pointer to vending machine
            StockItem item: item to be added
            Int afterID
        Use
            Add an item to vending machine
*/
int addStockItem(VendingMachine* vm, StockItem item, int afterID) {
    //node *aft_add = vm->head;
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        return 0;
    }
    new_node->item = item;

    if (afterID <= 0) {
        new_node->next = vm->head;
        vm->head = new_node;
        return 1;
    }

    node *item_pt = vm->head;
    if (item_pt == NULL) {
        new_node->next = NULL;
        vm->head = new_node;
        return 1;
    }
    while ((item_pt->next != NULL) && (item_pt->next->item.ID != afterID)) {
        item_pt = item_pt->next;
    }
    if (item_pt->next == NULL) {
        new_node->next = NULL;
        item_pt->next = new_node;
        return 1;
    }
    new_node->next = item_pt->next->next;
    item_pt->next->next = new_node;
    
    return 1;
}


/*
    removeStockItem(VendingMachine*, int, StockItem*)
        Returns
            int error code
                1 = good
                0 = bad
        Parameters
            VendingMachine* vm: pointer to vending machine
            int ID: ID of target
            StockItem* result: pointer to place item if match found
        Notes
            Assuming this does not need to remove but just needed to access
        Use
            Get a StockItem of given ID
*/
int removeStockItem(VendingMachine* vm, int ID, StockItem* result) {
    node *item_pt = vm->head;
    if (item_pt == NULL) {
        return 0;
    }
    while ((item_pt->next != NULL) && (item_pt->next->item.ID != ID)) {
        item_pt = item_pt->next;
    }
    if (item_pt->next == NULL) {
        return 0;
    }
    *result = item_pt->next->item;
    node* placepoint = item_pt->next->next;
    freeNode(item_pt->next);
    item_pt->next = placepoint;

    return 1;
}


/*
    printIDS(VendingMachine*)
        Parameters
            vm vendingmachine pointer
        Use
            Prints IDS on a single line seperated by commas
*/
void printIDS(VendingMachine* vm) {
    node *item_pt = vm->head;
    while (1 == 1) {
        if (item_pt == NULL) {
            printf("\n");
            break;
        }
        printf("%d,\t", item_pt->item.ID);
        item_pt = item_pt->next;
    }
}


/*
    purchaseItem(VendingMachine, int)
        Parameter
            vm pointer to vending machine
            ID int item id to find
        Returns
            0 if item not found or out of stock
            1 if item found and purchased
        Uses
            Purchases and item if in stock and removes one stock from it
*/
int purchaseItem ( VendingMachine * vm , int ID ) {
    node *item_pt = vm->head;
    while ((item_pt != NULL) && (item_pt->item.ID != ID)) {
        item_pt = item_pt->next;
    }
    if ((item_pt == NULL) || (item_pt->item.stock == 0)) {
        return 0;
    }
    item_pt->item.stock--;
    return 1;
}

/*
    Util function not to be used
    Frees node give to it
*/
void freeNode(node* unode) {
    free(unode);
    unode = NULL;
}

/*
    freeVendingMachine(VendingMachine*)
        Parameters
            VendingMachine* vm: pointer to vending machine
        Use
            Frees allocated mem
*/
void freeVendingMachine(VendingMachine* vm) {
    node *node_pt = vm->head;
    node *next_node = NULL;
    while((node_pt != NULL)) {
        next_node = node_pt->next;
        free(node_pt);
        node_pt = next_node;
    }
    free(vm);
    vm = NULL;
}


