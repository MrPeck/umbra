CC := gcc
CFLAGS += -g -ggdb

objects := main.o commands.o c2_prot.o

all: $(objects)
	$(MAKE) -C protocol
	$(CC) $(CFLAGS) -o agent $(objects) protocol/*.o

clean:
	rm -f agent *.o