#include "lab7.h"


typedef struct node_t {
    StockItem item;
    struct node_t* next;
} node;



typedef struct VendingMachine_t {
    int list_size;
    int full_items;
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
    
    vm->list_size = 0;
    vm->full_items = 0;
    vm->head = NULL;

    return vm;
}


/*
    addStockItem(VendingMachine*, StockItem)
        Returns
            int errorcode
                0 bad
                1 good
        Parameters
            VendingMachine* vm: pointer to vending machine
            StockItem item: item to be added
        Use
            Add an item to vending machine
*/
int addStockItem(VendingMachine* vm, StockItem item) {
    node *aft_add = vm->head;
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        return 0;
    }
    new_node->item = item;
    new_node->next = aft_add;
    vm->head = new_node;

    vm->list_size++;
    if (item.stock == item.maxStock) {
        vm->full_items++;
    }
    
    return 1;
}


/*
    countItems(VendingMachine *)
        Returns
            int size of list
        Parameters
            VendingMachine* vm
        Notes
            Need to make sure if deletion is added in future that those functions will change size accordingly
        Use
            Get amount of items in vending machine regardless of status
*/
int countItems(VendingMachine* vm) {
    return vm->list_size;
}


/*
    countFull(VendingMachine *)
        Returns
            int number of full items
        Parameters
            VendingMachine* vm
        Notes
            Need to make sure if deletion is added in future that those functions will change full items accordingly
        Use
            Get amount of items fully stocked
*/
int countFull(VendingMachine* vm) {
    return vm->full_items;
}


/*
    getStockItem(VendingMachine*, int, StockItem*)
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
int getStockItem(VendingMachine* vm, int ID, StockItem* result) {
    node *item_pt = vm->head;
    while ((item_pt != NULL) && (item_pt->item.ID != ID)) {
        item_pt = item_pt->next;
    }
    if (item_pt == NULL) {
        return 0;
    }
    *result = item_pt->item;
    return 1;
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