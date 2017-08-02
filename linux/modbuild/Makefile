#only one file
#obj-m += my_module.o

obj-m += my_mod.o
my_mod-objs = my_module.o my_module2.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
