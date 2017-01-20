/*
 * =====================================================================================
 *
 *       Filename:  sstf.c
 *       	Usage:  ./sstf.c
 *    Description: Shortest-seek-time-first 
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include "disk.h"

/* Function Defenitions */
void Sstf(int position, int array[])
{
	printf("Starting SSTF Algorithm\n");
	printf("\tInitial Position %d\n", position);
	int count = 0,step,mark,jpos =0,b[CYL];
	int last = position;

	for(int k = 0; k < CYL; k++)
	{		
		b[k] = array[k];	
	}

	for(int i = 0; i < CYL; i++)
	{
		//Print out array by step for testing
		//for(int k = 0; k < CYL; k++)
		//{				
		//	printf("%d ",b[k]);
		//}
		//printf("\n");

		step = 900;

		for(int j = i; j < CYL; j++)
		{
			
			if((abs(position - b[j])) < step)
			{
				//Save the step distance, the value and the position of current best step
				step = abs(position - b[j]);			
				mark = b[j];
				jpos = j;
			}						
			
		}
		
		//If there is a best step, swap positions in the array		
		if(step < 900)
		{			
			position = b[jpos];
			int temp = b[i];
			b[i] = mark;
			b[jpos] = temp;			
		}
	
		
	}
	
	//Run jobs
	for(int i = 0; i < CYL; i++)
	{
		count += abs(last - b[i]);
		printf("\tServicing %d movement: %d\n", b[i], count);
		last = b[i];
	}

	printf("\tSSTF = %d movements\n\n",count);


	return;
}



