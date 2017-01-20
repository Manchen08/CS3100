Altered files:
usys.S
	Added syscalls to list

defs.h
	Added syscalls to //proc.c section

proc.h
	Added int priority to proc struct

proc.c
	Added p->priority = 0; set priority to 0 upon init
	Added nice function
	Added setpriority function
	Added getpriority function
	Fork edit so np inherits parants priority
	Edited scheduler to impliment priority queue

sysproc.c
	Added nice syscall

syscall.h
	Added nice, getpriority, setpriority to list

syscall.c
	Added nice, getpriority, setpriority to listed syscalls

user.h
	Added nice, getpriority, setpriority to list
