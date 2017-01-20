# Student makefile for Disk Lab
# Change the USER/TEAM to your First_Last 
#
# Builds the Cache Lab simulators and tools
#
# Set environment variables
#export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
CC = gcc
CFLAGS = -Wall -Werror -std=c99
LIBFLAGS = -shared
LAB = diskLab

all: lib main

lib: fcfs.c sstf.c scan.c cscan.c disk.h
	$(CC) -std=c99 -c -fPIC fcfs.c sstf.c scan.c cscan.c
	$(CC) $(LIBFLAGS) -o libdisk.so fcfs.o sstf.o scan.o cscan.o

main: main.c 
	$(CC) $(CFLAGS) -o main main.c -ldisk  -L.

clean:
	rm -rf *.o *.s *.so
	rm -rf main
