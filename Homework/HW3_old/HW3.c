#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
//#include "rctimer.h"

 int main(int argc, char * argv[])
 {
   
	printf("argc = %d\n",argc);
	printf("argv[0] = %s\n",argv[0]); 
	printf("argv[1] = %s\n",argv[1]);
	printf("argv[2] = %s\n",argv[2]);

	if (argc != 3)
	{
		printf("Incorrect number of arguments, you must pass in a number and filename.\n");
		return -1;
	}

	int choice = atoi(argv[1]);
	//start_timer();
	if(choice == 1)
	{
		printf("Argv is 1, entering single exec");
		int cp[2];
		if (pipe(cp) < 0)
		{
			printf("didn't work, couldn't not establish pipe.\n");
			return -1;
		}
		close(1); //close stdout
		dup(cp[1]); //move stdout to pipe of cp[1]
		close(0); //close stdin
		close(cp[0]); //close pipe in
		execl("minerMaxer","1", argv[1],(char *) 0);
	}

	if(atoi(argv[1]) == 4)
	{
		printf("This is before the fork.\n");
	    int cp1[2];
	    int cp2[2];
	    int cp3[2];
	    int cp4[2];

	    if (pipe(cp1) < 0)
	    {
		printf("didn't work, couldn't not establish pipe.\n");
		return -1;
	    }
	    if (pipe(cp2) < 0)
	    {
		printf("didn't work, couldn't not establish pipe.\n");
		return -1;
	    }
	    if (pipe(cp3) < 0)
	    {
		printf("didn't work, couldn't not establish pipe.\n");
		return -1;
	    }
	    if (pipe(cp4) < 0)
	    {
		printf("didn't work, couldn't not establish pipe.\n");
		return -1;
	    }
	

	    int cp[2];
	    int pid = fork();
	    if (pid == 0)
	    {
		//printf("this is child.\n");
		//close(1); //close stdout
		//dup(cp[1]); //move stdout to pipe of cp[1]
		//close(0); //close stdin
		//close(cp[0]); //close pipe in
		//execl("minerMaxer","4", "test.txt",(char *) 0);
	    }
	    else
	    {

		close(cp[1]); //if you don't close this part of the pipe then the while loop (three lines down) will never return
		printf("this is the parent. the 'original.'\n");
		char ch;
		while( read(cp[0], &ch, 1) == 1)
		{
		    printf("%c",ch);
		    //write(1, &ch, 1);
		    //outcount++;
		}
		printf("all done.\n");
		//execl("printStuff","printStuff", "10",(char *) 0);
	    }
	    printf("This is after the fork.\n");

	}
	//end_timer();
	//printf("Elapsed time: %s\n", get_elapsed_time());
	printf("Finished");
    return 0;   
 }
