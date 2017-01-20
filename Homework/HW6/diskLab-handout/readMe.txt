The program, "main" is what will be used for the passoff. This executable will use the library, "libdisk.so" that you will create.

The main.c file is a skeleton of a test file that you can create to test for yourself. You do not have to implement it.

The Makefile included in this library will only create the shared library "libdisk.so" if you type "make". If you want to compile main.c for your own testing purposes then you will have to type "make main".

Note that you have to set your environement variable "LD_LIBRARY_PATH" for the executable to find your shared library. There are several ways to do it, but the easiest way is the following, "LD_LIBRARY_PATH=.; export LD_LIBRARY_PATH"
