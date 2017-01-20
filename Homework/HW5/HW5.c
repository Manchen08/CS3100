#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"

void
exectest(void)
{
  printf(stdout, "exec test\n");
  if(exec("echo", echoargv) < 0){
    printf(stdout, "exec echo failed\n");
    exit();
  }
}

int main(int argc, char *argv[])
{

	if(argc > 1) || (argc = 0){
		printf("Please a positive integer\n");
		return -1;
	}

	if (!isdigit(atoi(argv[1]))){
		printf("Please enter a positive integer\n");
	}

	printf("Jon Wheeler\n");
	if (strcmp(argv[1], "1") == 0)
	{
	}
}
