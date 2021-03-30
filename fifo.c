#include <stdio.h>

#define FIFO_SIZE 10
#define TYPE int

TYPE fifo_array[FIFO_SIZE] = {0x0};
unsigned int fifo_start = 0x0;
unsigned int fifo_end = 0x0;

void fifo_print(TYPE *fifo) {
    if ( (fifo_start != fifo_end) && (fifo_start < FIFO_SIZE) && (fifo_end < FIFO_SIZE) ) {
        printf("all elements of FIFO: ");
        int i;
        for (i = fifo_start; i < fifo_end; i++)
            printf("%i", *(fifo + i));
        printf("\n");
    } else
        printf("FIFO is empty!\n");
}

void main() {
    fifo_print(fifo_array);
    return;
}
