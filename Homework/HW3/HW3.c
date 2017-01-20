#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "rctimer.h"

int main(int argc, char *argv[])
{
	start_timer();
	//char file[] = (char *)argv[2];
	int min = 2147483647;
	int max = 0;	
	//RUN ALL THE WAY THROUGH
	if(argc < 3){
		printf("Please enter 1 or 4 and a file name.\n");
		return -1;
	}
	printf("Jon Wheeler\n");
	if (strcmp(argv[1], "1") == 0)
	{
		int cp[2];

		if (pipe(cp) < 0)
		{
			printf("didn't work, couldn't not establish pipe.\n");
			return -1;
		}

		int pid = fork();
		if (pid == 0)
		{
			//printf("this is the child. not the original\n");
			close(1); //close stdout
			dup(cp[1]); //move stdout to pipe of cp[1]
			close(0); //close stdin
			close(cp[0]); //close pipe in 
			execl("printStuff","printStuff","0", argv[2],(char *) 0);
		}
		else
		{

			close(cp[1]); //if you don't close this part of the pipe then the while loop (three lines down) will never return
			int test;
	 		
//!!!!!!!!read() returns the number of bytes read (when nothing goes wrong).!!!!!!!!!!!!!!!!!!1
			while( read(cp[0], &test, sizeof(int)) == 4)
			{

				//printf("%i",test);
				if(test > max)
				{
					max = test; 
				}
				if(test < min)
				{
					min = test;
				}


			}
		
		}
	}
	

	if (strcmp(argv[1], "4") == 0)
	{	
		int numForks = 4;		
		int cp[2];
		char temp[10];
		
		if(pipe(cp) < 0)
		{
			printf("didn't work, couldn't not establish pipe.\n");
			return -1;
		}

		int i;
		for (i=0; i < numForks; i++)
		{			
			int pid = fork();
			sprintf(temp, "%i",i+1);

			if (pid == 0)
			{
				//printf("Child: %i\n",i);				
				close(1); //close stdout
				dup(cp[1]); //move stdout to pipe of cp[1]
				close(0); //close stdin
				close(cp[0]); //close pipe in 
				execl("printStuff","printStuff", temp, argv[2],(char *) 0);
			}

		}

		close(cp[1]);
		//printf("this is the parent.\n");
		int test;
		while( read(cp[0], &test, sizeof(int)) == 4)
		{
			//printf("%i\n",test);
			if(test > max)
			{
				max = test; 
			}
			if(test < min)
			{
				min = test;
			}

			
		}
		

	}
	end_timer();
	printf("Min: %i, Max: %i\n",min,max);
	printf("\nElapsed time: %s\n", get_elapsed_time());
	return 0;
}
