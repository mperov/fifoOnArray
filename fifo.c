#include <stdio.h>

#include "fifo.h"

void fifo_print(FIFO *fifo) {
    if (fifo->count != 0) {
        printf("all elements of FIFO: ");
        int i;
        int j = fifo->start;
        for (i = 0; i < fifo->count; i++) {
            printf("%i ", fifo->array[j]);
            j++;
            if (j == FIFO_SIZE)
                j = 0;
        }
        printf("\n");
    } else
        printf("FIFO is empty!\n");
}

void fifo_init(FIFO *fifo) {
    int i;
    int error;
    fifo->start = fifo->end = fifo->count = 0;
    for(i = 0; i < FIFO_SIZE; i++) {
        error = fifo_push(fifo, i);
        if (error)
            printf("push error, line is %i\n", __LINE__);
   }
}

void main() {
    FIFO fifo;
    int i;
    int error;
    printf("---------------- First test ----------------\n");
    fifo_init(&fifo);
    fifo_print(&fifo);
    for (i = 0; i < FIFO_SIZE; i++) {
        TYPE element;
        error = fifo_pop(&fifo, &element);
        if (!error)
            printf("element from FIFO: %i\n", element);
        else
            printf("pop error, line is %i\n", __LINE__);
        fifo_print(&fifo);
    }
    printf("================ First test ================\n");
    printf("---------------- Second test ----------------\n");
    fifo_init(&fifo);
    fifo_print(&fifo);
    for (i = 0; i < FIFO_SIZE + 5; i++) {
        TYPE element;
        error = fifo_pop(&fifo, &element);
        if (!error)
            printf("element from FIFO: %i\n", element);
        else
            printf("pop error, line is %i\n", __LINE__);
        fifo_print(&fifo);
    }
    printf("================ Second test ================\n");
    return;
}
