#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"


int
main(int argc, char *argv[])
{
int magic = getMagic();
printf(1, "current magic number is the following: %d\n",magic);

incrementMagic(3);

magic = getMagic();
printf(1, "current magic number is the following: %d\n",magic);

getCurrentProcessName();
printf(1, "current process name = %s \n", name);

//modifyCurrentProcessName("newName");

//getCurrentProcessName();

magic = getMagic();
printf(1, "current magic number is the following: %d\n",magic);

incrementMagic(3);

magic = getMagic();
printf(1, "current magic number is the following: %d\n",magic);

exit();
}
