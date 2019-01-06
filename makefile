

FLAG= -Wall -ansi -pedantic -g
all: vm

vm: vm.o vm_options.o vm_utility.o	
	gcc -o vm vm.o vm_options.o vm_utility.o $(FLAG) -lm
	
vm.o: vm.c
	gcc -c vm.c $(FLAG)
	
vm_options.o: vm_options.c
	gcc -c vm_options.c $(FLAG)
	
vm_utility.o: vm_utility.c
	gcc -c vm_utility.c $(FLAG)

clean:
	-rm *.o
	-rm vm

archive:
	zip $(USER)-a2.zip coins.csv makefile stock.csv vm.c vm.h vm_options.c vm_options.h vm_readme.txt vm_utility.c vm_utility.h
