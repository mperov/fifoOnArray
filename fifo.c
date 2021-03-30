#include <stdio.h>

#define FIFO_SIZE 10
#define TYPE int

typedef struct {
    TYPE array[FIFO_SIZE];
    unsigned int start;
    unsigned int end;
} FIFO;

void fifo_print(FIFO *fifo) {
    if ( (fifo->start != fifo->end) && (fifo->start < FIFO_SIZE) && (fifo->end < FIFO_SIZE) ) {
        printf("all elements of FIFO: ");
        int i;
        for (i = fifo->start; i < fifo->end; i++)
            printf("%i", fifo->array[i]);
        printf("\n");
    } else
        printf("FIFO is empty!\n");
}

void fifo_init(FIFO *fifo) {
   fifo->start = fifo->end = 0;
}

void main() {
    FIFO fifo;
    fifo_init(&fifo);
    fifo_print(&fifo);
    return;
}
