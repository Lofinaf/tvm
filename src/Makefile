CC=g++

CFLAGS=-w -O2 -c

all: build

build: run.o vm.o vm_tools.o
	$(CC) run.o vm.o vm_tools.o -o build
	
run.o: run.cpp
	$(CC) $(CFLAGS) run.cpp
	
vm.o: vm.cpp
	$(CC) $(CFLAGS) vm.cpp
	
vm_tools.o: vm_tools.c
	$(CC) $(CFLAGS) -x c vm_tools.c