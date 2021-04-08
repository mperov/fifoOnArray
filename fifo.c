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


#define RESET\
    fifo_reset(&fifo);
        
#define INIT\
    FIFO fifo;\
    int error;\
    error = fifo_init(&fifo, FIFO_SIZE);\
    if (error) {\
        printf("Error in initializing of FIFO!\n");\
        exit(-1);\
    }
    
#define FINALIZE\
    fifo_finalize(&fifo);
    
#define TEST(name, code)\
    printf("==================TEST %s==================\n", #name);\
    code
    
void main() {
    TEST(TESTING_TEST, {printf("Hello, world!\n");})
    TEST(JUST_POP, {
        INIT
        FILL
        PRINT
        int i;
        for (i = 0; i < 11; ++i) {
            POP
            PRINT
        }
        FINALIZE
    })
    TEST(JUST_PUSH, {
        INIT
        PRINT
        int i;
        for (i = 0; i < 11; ++i) {
            PUSH(i * i)
            PRINT
        }
        FINALIZE
    })
    TEST(PING_PONG, {
        INIT
        int i;
        for (i = 0; i < 15; ++i) {
            PUSH (i * i * i)
            PRINT
            POP
            PRINT
        }
        FINALIZE
    })
    TEST(FILL_CLEAR, {
        INIT
        int i;
        for (i = 0; i < 10; ++i) {
            PUSH(i)
            PRINT
        }
        for (i = 0; i < 10; ++i) {
            POP
            PRINT
        }
        FINALIZE
    })
    return;
}
