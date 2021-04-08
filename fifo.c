#include <stdio.h>

#include "fifo.h"

#define FIFO_SIZE 10

void fifo_fill(FIFO *fifo) {
    int i;
    int error;
    fifo_reset(fifo);
    for(i = 0; i < fifo->fifo_size; i++) {
        error = fifo_push(fifo, i);
        if (error)
            printf("push error, line is %i\n", __LINE__);
   }
}

#define FIFO_INIT\
        fifo_fill(&fifo);
    
#define POP\
    TYPE __element;\
    error = fifo_pop(&fifo, &__element);\
    if (!error)\
        printf("element from FIFO: %i\n", __element);\
    else\
        printf("pop error, line is %i\n", __LINE__);

#define PRINT\
    fifo_print(&fifo);
    
#define FILL\
    fifo_fill(&fifo);
    
#define PUSH(a)\
    error = fifo_push(&fifo, a);\
    if (!error)\
        printf("element to FIFO: %i\n", a);\
    else\
        printf("pop error, line is %i\n", __LINE__);
        

void main() {
    //debugging = 1; // switch on debug mode
    FIFO fifo;
    int error;
    error = fifo_init(&fifo, FIFO_SIZE);
    if (error) {
        printf("Error in initializing of FIFO!\n");
        exit(-1);
    }
    int i;
    printf("---------------- First test ----------------\n");
    FILL
    PRINT
    for (i = 0; i < fifo.fifo_size; i++) {
        POP
        PRINT
    }
    printf("================ First test ================\n");
    printf("---------------- Second test ----------------\n");
    FILL
    PRINT
    for (i = 0; i < fifo.fifo_size + 5; i++) {
        POP
        PRINT
    }
    printf("================ Second test ================\n");
    printf("---------------- Third test ----------------\n");
    fifo_reset(&fifo);
    PRINT
    for (i = 0; i < fifo.fifo_size + 5; i++) {
        TYPE element = i;
        PUSH(element)
        POP
        PRINT
    }
    printf("================ Third test ================\n");
    fifo_finalize(&fifo);
    return;
}
