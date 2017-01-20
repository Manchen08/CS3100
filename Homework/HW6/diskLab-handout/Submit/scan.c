/*
 * =====================================================================================
 *
 *       Filename:  scan.c 
 *       	Usage:  ./scan.c
 *    Description: Disk arm starts at one end of the disk and moves
 *    				toward the other end, servicing request as it
 *    				reaches each cylinder, until it gets to the 
 *    				other end of the disk
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include "disk.h"

/* Function Defenitions */
void Scan(int position, int array[])
{
	printf("Starting SCAN Algorithm\n");
	printf("\tInitial Position %d\n", position);

	int i = 0,move=0,step,mark,min=500,max=-1,nextstep,next = 0,b[CYL];
	int empty = 0;
	int dir = 0;
	int orig = position;

	for(int k = 0; k < CYL; k++)
	{		
		b[k] = array[k];
		//printf("%d ",b[k]);	
	}

	while(empty == 0)
	{
		step = 900;
		empty = 1;
		nextstep = 900;

		for(i = 0; i < CYL; i++)
		{
			if(b[i] == NULL)
			{
				continue;
			}
		 	if(b[i] < min)
			{
				min = b[i];
			}
			if(b[i] > b[max])
			{
				max = i;
			}
			
			//If we're currently going left.
			if(dir == 0)
			{
				if(b[i] < position && b[i] != NULL)
				{
					empty = 0;
					if((abs(position - b[i])) < step)
					{
						step = abs(position - b[i]);
						mark = i;
					
					}								
				}

				//Keep an eye out for what should come after going left
				if(b[i] > orig && b[i] != NULL)
				{
					if((abs(position - b[i])) < nextstep)
					{
						nextstep = abs(position - b[i]);
						next = i;
					}
				}
			}
			
			
						

			if(b[i] > position && b[i] != NULL)
			{
				empty = 0;				

				if((abs(position - b[i])) < step)
				{
					
					//If we're currently going right.
					if(dir == 1)
					{
						step = abs(position - b[i]);
						mark = i;
					}
					
				
				}								
			}
			


		}
		
		position = b[mark];

		
		if(position != NULL)
		{
			move = move + step;				
			printf("\tServicing %d movement: %d\n", position, move);
			b[mark] = NULL;
		}

		if(position == min)
		{
			move = move + min + b[next];
			dir = 1;
			position = b[next];			
			printf("\tServicing %d movement: %d Moving Right\n", position, move);
			b[next] = NULL;
			
		}		
		
		i = 0;
	}

	printf("\tSCAN = %d movements\n\n",move);

	return;
}


