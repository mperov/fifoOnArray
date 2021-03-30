all: fifo

fifo: fifo.o
	gcc fifo.o -o fifo

fifo.o: fifo.c
	gcc -c fifo.c -o fifo.o

clean:
	rm -rf fifo.o fifo
