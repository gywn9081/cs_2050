#include "lab10.h"
#include <stdio.h>


int main() {
    int data = 5;


    // printf("hello?\n");
    Queue* queue = newQueue();

    printf("%d size result\n", getSize(queue));
    printf("%p peek result\n", peek(queue));
    printf("%p dequeu result\n", deQueue(queue));
    for (int i = 0; i < 1000; i++) {
        printf("%d enqueu result\n", enQueue(queue, &data));
    }

    printf("%d size result\n", getSize(queue));
    printf("%p peek result\n", peek(queue));
    printf("%p dequeu result\n", deQueue(queue));

    printf("%d size result\n", getSize(queue));
    printf("%p peek result\n", peek(queue));






    destroy(queue);
}