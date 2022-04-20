CC=gcc

agent: main.o commands.o c2_prot.o
	$(CC) -o agent main.o commands.o c2_prot.o

clean:
	rm -f agent *.o