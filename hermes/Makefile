CC=gcc

agent: main.o actions.o c2_prot.o
	$(CC) -o agent main.o actions.o c2_prot.o

clean:
	rm -f agent *.o