#ifndef FIFO_H_
#define FIFO_H

//#define DEBUG
#define FIFO_SIZE 10
#define TYPE int

#ifdef DEBUG
#   include <stdio.h>
#endif // DEBUG

typedef struct {
    TYPE array[FIFO_SIZE];
    unsigned int start;
    unsigned int end;
} FIFO;

int fifo_push(FIFO *fifo, TYPE element) {
    if (fifo->end < FIFO_SIZE) {
        fifo->array[fifo->end++] = element;
#ifdef DEBUG
        printf("push: end is %i\n", fifo->end);
#endif // DEBUG
        return 0;
    } else
        return -1;
}

int fifo_pop(FIFO *fifo, TYPE *element) {
    if (fifo->start != fifo->end) {
        *element = fifo->array[fifo->start++];
#ifdef DEBUG
        printf("pop: start is %i\n", fifo->start);
#endif // DEBUG
        if (fifo->start == fifo->end)
            fifo->start = fifo->end = 0;
        return 0;
    } else
        return -1;
}

#endif // FIFO_H_
