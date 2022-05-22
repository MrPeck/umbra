CC := gcc
CFLAGS += -g -ggdb

objects := main.o commands.o c2_prot.o

all: $(objects)
	$(CC) $(CFLAGS) -o agent $(objects)

clean:
	rm -f agent *.o