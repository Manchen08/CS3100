#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "rctimer.h"

int main(int argc, char *argv[])
{
	start_timer();

	//RUN ALL THE WAY THROUGH
	if (strcmp(argv[1], "1") == 0)
	{
		printf("This is before the fork.\n");
		int cp[2];

		if (pipe(cp) < 0)
		{
			printf("didn't work, couldn't not establish pipe.\n");
			return -1;
		}

		int pid = fork();
		if (pid == 0)
		{
			printf("this is the child. not the original\n");
			close(1); //close stdout
			dup(cp[1]); //move stdout to pipe of cp[1]
			close(0); //close stdin
			close(cp[0]); //close pipe in 
			execl("printStuff","printStuff","0", argv[2],(char *) 0);
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
		
		}
		printf("This is after the fork.\n");
	}



	

	if (strcmp(argv[1], "4") == 0)
	{	

		int cp[2];

		if (pipe(cp) < 0)
		{
			printf("didn't work, couldn't not establish pipe.\n");
			return -1;
		}

		int pid = fork();
		if (pid != 0)
		{
			int cp2[2];
				if (pipe(cp2) < 0)
				{
					printf("didn't work, couldn't not establish pipe.\n");
					return -1;
				}
			int pid = fork();
			if (pid != 0)
			{
				int cp3[2];
				if (pipe(cp3) < 0)
				{
					printf("didn't work, couldn't not establish pipe.\n");
					return -1;
				}

				int pid = fork();
				if (pid != 0)
				{
					int cp4[2];
					if (pipe(cp4) < 0)
					{
						printf("didn't work, couldn't not establish pipe.\n");
						return -1;
					}
					int pid = fork();
					if (pid != 0)
					{
						close(cp4[1]); //if you don't 							//printf("this is the parent.'\n");
						char ch;
						while( read(cp4[0], &ch, sizeof(ch)) == 1)
						{
							printf("%c",ch);

						}
						//printf("4 done.\n");
					}
					else
					{
				
						//printf("this is child 4.\n");
						close(1); //close stdout
						dup(cp4[1]); //move stdout to pipe of cp[1]
						close(0); //close stdin
						close(cp4[0]); //close pipe in 
						execl("printStuff","printStuff","4", "test.txt",(char *) 0);
					}
					close(cp3[1]); //if you don't close this part of the pipe then the while loop (three lines down) will never return
					//printf("this is the parent. the 'original.'\n");
					char ch;
					while( read(cp3[0], &ch, 1) == 1)
					{
						printf("%c",ch);

					}
					//printf("3 done.\n");
				}
				else
				{
				
					//printf("this is child 3.\n");
					close(1); //close stdout
					dup(cp3[1]); //move stdout to pipe of cp[1]
					close(0); //close stdin
					close(cp3[0]); //close pipe in 
					execl("printStuff","printStuff","3", "test.txt",(char *) 0);
				}

				close(cp2[1]); //if you don't close this part of the pipe then the while loop (three lines down) will never return
				//printf("this is the parent. the 'original.'\n");
				char ch;
				while( read(cp2[0], &ch, 1) == 1)
				{
					printf("%c",ch);

				}
				//printf("2 done.\n");
			}
			else
			{
				
				//printf("this is child 2.\n");
				close(1); //close stdout
				dup(cp2[1]); //move stdout to pipe of cp[1]
				close(0); //close stdin
				close(cp2[0]); //close pipe in 
				execl("printStuff","printStuff","2", "test.txt",(char *) 0);
			}

			close(cp[1]); //if you don't close this part of the pipe then the while loop (three lines down) will never return
			//printf("this is the parent. the 'original.'\n");
			char ch;
			while( read(cp[0], &ch, 1) == 1)
			{
				printf("%c",ch);
				//write(1, &ch, 1);
				//outcount++;
			}
			//printf("1 done.\n");
		}
		else
		{
			//printf("this is child 1.\n");
			close(1); //close stdout
			dup(cp[1]); //move stdout to pipe of cp[1]
			close(0); //close stdin
			close(cp[0]); //close pipe in 
			execl("printStuff","printStuff","1", "test.txt",(char *) 0);

			
		
		}
		//printf("This is after the fork.\n");
	}
	end_timer();
	printf("Elapsed time: %s\n", get_elapsed_time());
	return 0;
}
