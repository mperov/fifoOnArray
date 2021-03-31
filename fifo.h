#ifndef FIFO_H_
#define FIFO_H

#include <stdio.h>

//#define DEBUG
#define FIFO_SIZE 10
#define TYPE int

typedef struct {
    TYPE array[FIFO_SIZE];
    unsigned int start;
    unsigned int end;
    unsigned int count;
} FIFO;

void fifo_reset(FIFO *fifo) {
    fifo->start = fifo->end = fifo->count = 0;
}

int fifo_push(FIFO *fifo, TYPE element) {
    if (fifo->count < FIFO_SIZE) {
        fifo->array[fifo->end++] = element;
        fifo->count++;
        if (fifo->end == FIFO_SIZE)
            fifo->end = 0;
#ifdef DEBUG
        printf("push: end is %i\n", fifo->end);
#endif // DEBUG
        return 0;
    } else
        return -1;
}

int fifo_pop(FIFO *fifo, TYPE *element) {
    if (fifo->count != 0) {
        *element = fifo->array[fifo->start++];
        fifo->count--;
        if (fifo->start == FIFO_SIZE)
            fifo->start = 0;
#ifdef DEBUG
        printf("pop: start is %i\n", fifo->start);
#endif // DEBUG
        if (fifo->count == 0)
            fifo->start = fifo->end = 0;
        return 0;
    } else
        return -1;
}

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

#endif // FIFO_H_
