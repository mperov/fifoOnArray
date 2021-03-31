#include <stdio.h>

#include "fifo.h"

void fifo_fill(FIFO *fifo) {
    int i;
    int error;
    fifo_reset(fifo);
    for(i = 0; i < FIFO_SIZE; i++) {
        error = fifo_push(fifo, i);
        if (error)
            printf("push error, line is %i\n", __LINE__);
   }
}

void main() {
    //debugging = 1; // switch on debug mode
    FIFO fifo;
    int i;
    int error;
    printf("---------------- First test ----------------\n");
    fifo_fill(&fifo);
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
    fifo_fill(&fifo);
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
    printf("---------------- Third test ----------------\n");
    fifo_reset(&fifo);
    fifo_print(&fifo);
    for (i = 0; i < FIFO_SIZE + 5; i++) {
        TYPE element = i;
        error = fifo_push(&fifo, element);
        if (!error)
            printf("element to FIFO: %i\n", element);
        else
            printf("pop error, line is %i\n", __LINE__);
        error = fifo_pop(&fifo, &element);
        if (!error)
            printf("element from FIFO: %i\n", element);
        else
            printf("pop error, line is %i\n", __LINE__);
        fifo_print(&fifo);
    }
    printf("================ Third test ================\n");
    return;
}
