obj-m += chardev2.o
startstop-objs := start.o stop.o

PWD := $(CURDIR) 

all: 
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean: 
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
