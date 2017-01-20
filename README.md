# CS3100
Robert Ball

Book Information
Required Books

Operating Systems: Three Easy Pieces http://pages.cs.wisc.edu/~remzi/OSTEP/

C Primer Plus (any Edition): ISBN-13: 978-0321928429

The XV6 Book: http://pdos.csail.mit.edu/6.828/2014/xv6/book-rev8.pdf 

 

Suggested Book: 

Advanced Programming in the UNIX Environment, 3rd Edition. 

ISBN-13: 978-0321637734

Debugging Tools:

gdb http://www.gnu.org/software/gdb/

valgrind http://valgrind.org/

objdump http://linux.die.net/man/1/objdump


# qemu and compile in Linux Mint

In order to run XV6, you will need qemu.

From the command line prompt in Linux type the following:

sudo apt-get install qemu-system-x86

 

To compile, you just type "make" However, before you do that you have to download the compiler:

sudo apt-get install g++-4.8

sudo ln -s /usr/bin/gcc-4.8 /usr/bin/gcc

*If you get an error that gcc already exists then type:

sudo rm /usr/bin/gcc  

then type

sudo ln -s /usr/bin/gcc-4.8 /usr/bin/gcc
