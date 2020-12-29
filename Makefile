obj-m += umbra.o

ifeq ($(KDIR),)
	KDIR := /lib/modules/$(shell uname -r)/build
endif

PWD := $(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
