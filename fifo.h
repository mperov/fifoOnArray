#ifndef FIFO_H_
#define FIFO_H

#include <stdlib.h>
#include <stdio.h>

unsigned int debugging = 0;

#define DEBUG
#if defined(DEBUG)
#   define debug_printf(...) (debugging) ? printf(__VA_ARGS__) : printf("")
#else
#   define debug_printf(...)
#endif

#define TYPE int

typedef struct {
    TYPE *array;
    unsigned int start;
    unsigned int end;
    unsigned int count;
    unsigned int fifo_size;
} FIFO;

void fifo_reset(FIFO *fifo) {
    fifo->start = fifo->end = fifo->count = 0;
}

int fifo_init(FIFO *fifo, unsigned int fifo_size) {
    fifo->fifo_size = fifo_size;
    fifo_reset(fifo);
    fifo->array = calloc(fifo_size, sizeof(TYPE));
}

int fifo_push(FIFO *fifo, TYPE element) {
    if (fifo->count < fifo->fifo_size) {
        fifo->array[fifo->end++] = element;
        fifo->count++;
        if (fifo->end == fifo->fifo_size)
            fifo->end = 0;
        debug_printf("push: end is %i\n", fifo->end);
        return 0;
    } else
        return -1;
}

int fifo_pop(FIFO *fifo, TYPE *element) {
    if (fifo->count != 0) {
        *element = fifo->array[fifo->start++];
        fifo->count--;
        if (fifo->start == fifo->fifo_size)
            fifo->start = 0;
        debug_printf("pop: start is %i\n", fifo->start);
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
            if (j == fifo->fifo_size)
                j = 0;
        }
        printf("\n");
    } else
        printf("FIFO is empty!\n");
}

#endif // FIFO_H_
