CC=gcc -g -ggdb

agent:
	$(CC) -c -o main.o main.c
	$(CC) -c -o commands.o commands.c
	$(CC) -c -o c2_prot.o c2_prot.c
	$(CC) -o agent main.o commands.o c2_prot.o

clean:
	rm -f agent *.o