#include <stdio.h>

//#define DEBUG
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

void fifo_init(FIFO *fifo) {
    int i;
    int error;
    for(i = 0; i < FIFO_SIZE; i++) {
        error = fifo_push(fifo, i);
        if (error)
            printf("push error, line is %i\n", __LINE__);
   }
}

void main() {
    FIFO fifo;
    fifo.start = fifo.end = 0;
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
