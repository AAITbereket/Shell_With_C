KERNELDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)
build:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c
obj-m :=hello-2.o