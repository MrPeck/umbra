CC = gcc
CFLAGS = -g -ggdb

agent: main.o commands.o c2_prot.o
	$(CC) $(CFLAGS) -o agent main.o commands.o c2_prot.o

clean:
	rm -f agent *.o