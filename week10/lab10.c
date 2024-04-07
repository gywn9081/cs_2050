#include "lab10.h"
#include <stdio.h>


// Struct defs
typedef struct Node_t {
    void* data;
    struct Node_t* next;
    struct Node_t* back;
} Node;

typedef struct Queue_t {
    int size;
    Node* head;
    Node* tail;
} Queue;

// Helper Functions
void freeNode(Node* unode);

// Free Node and do what ever else is needed
void freeNode(Node* unode) {
    free(unode);
}


/*
    newQueue(void)
        Parameters
            void
        Returns
            * Queue : queue type
        Notes
            Run time : O(1)
        Use
            Construct a time-priority queue to hold data
*/
Queue * newQueue(void) {
    Queue* uQueue = malloc(sizeof(Queue));
    if (uQueue == NULL) {
        return NULL;
    }
    uQueue->size = 0;

    uQueue->head = malloc(sizeof(Node));
    if (uQueue->head == NULL) {
        free(uQueue);
        return NULL;
    }
    uQueue->tail = malloc(sizeof(Node));
    if (uQueue->tail == NULL) {
        free(uQueue->head);
        free(uQueue);
        return NULL;
    }

    uQueue->head->next = NULL;
    uQueue->head->back = uQueue->tail;
    uQueue->head->data = NULL;
    uQueue->tail->back = NULL;
    uQueue->tail->next = uQueue->head;
    uQueue->tail->data = NULL;

    return uQueue;
}


/*
    getSize(Queue *q)
        Parameters
            * Queue : queue type
        Returns
            int : size
        Notes
            Run time : O(1)
        Use
            Get amount of items in queue
*/
int getSize(Queue *q) {
    return q->size;
}


/*
    enQueue(Queue *q, void *data)
        Parameters
            * Queue : queue type
            * void : User data
        Returns
            int : error code
                0 Bad
                1 Good
        Notes
            Run time : O(1)
        Use
            Adds object to back of supplied queue
*/
int enQueue(Queue *q, void *data) {
    Node* uNode = malloc(sizeof(Node));
    if (uNode == NULL) {
        return 0;
    }
    q->size++;
    uNode->data = data;

    uNode->next = q->tail->next;
    uNode->back = q->tail;
    
    q->tail->next->back = uNode;
    q->tail->next = uNode;
    return 1;
}


/*
    peek(Queue *q)
        Parameters
            * Queue : queue type
        Returns
            * void : uData
        Notes
            Run time : O(1)
        Use
            See upcoming data without removing it from the queue
*/
void* peek(Queue *q) {
    return q->head->back->data;
}


/*
    deQueue(Queue *q)
        Parameters
            * Queue : queue type
        Returns
            *void : User data
        Notes
            Run time: O(1)
        Use
            Remove oldest object in queue and get data
*/
void* deQueue(Queue *q) {
    if (q->size == 0) {
        return q->head->data;
    }
    q->size--;
    void* uData = q->head->back->data;
    Node* rNode = q->head->back;

    q->head->back = q->head->back->back;
    q->head->back->next = q->head;

    freeNode(rNode);
    return(uData);
}


/*
    destroy(Queue *q)
        Parameters
            *Queue q : queue type
        Returns
            void
        Notes
            Run time: O(n)
        Use
            free all memory associated with given queue
*/
void destroy(Queue *q) {
    Node* cNode = q->tail;
    Node* nNode = cNode->next;
    while (nNode != NULL) {
        freeNode(cNode);
        cNode = nNode;
        nNode = cNode->next;
    }
    freeNode(cNode);
    free(q);
}