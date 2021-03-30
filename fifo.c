#include <stdio.h>

#define FIFO_SIZE 10
#define TYPE int

typedef struct {
    TYPE array[FIFO_SIZE];
    unsigned int start;
    unsigned int end;
} FIFO;

void fifo_print(FIFO *fifo) {
    if (fifo->start != fifo->end) {
        printf("all elements of FIFO: ");
        int i;
        for (i = fifo->start; i < fifo->end; i++)
            printf("%i ", fifo->array[i]);
        printf("\n");
    } else
        printf("FIFO is empty!\n");
}

void fifo_push(FIFO *fifo, TYPE element) {
    fifo->array[fifo->end++] = element;
}

void fifo_init(FIFO *fifo) {
   fifo->start = fifo->end = 0;
   int i;
   for(i = 0; i < FIFO_SIZE; i++) {
       fifo_push(fifo, i);
   }
}

void main() {
    FIFO fifo;
    fifo_init(&fifo);
    fifo_print(&fifo);
    return;
}
