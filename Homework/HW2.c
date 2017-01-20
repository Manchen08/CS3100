#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"

int stdout = 1;

int main(int argc, char *argv[])
{
	printf(stdout, "Jon Wheeler\n");
	fd = open("tom.txt", 0_CREATER|0_RDWR);
	if(fd >= 0){
		printf(stdout, "Create successful\n");
		if(write(fd, "1 2 3 4", 7) != 7){
			printf(stdout, "Write failed\n");
			exit();
		}
	} else {
		printf(stdout, "Create failed\n");
	}
	close(fd);

}
