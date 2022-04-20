CC=gcc

agent: main.o actions.o cnc_prot.o
	$(CC) -o agent main.o actions.o cnc_prot.o

clean:
	rm -f agent *.o