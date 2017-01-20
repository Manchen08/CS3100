/*
 * =====================================================================================
 *
 *       Filename:  cscan.c iiii
 *       	Usage:  ./cscan.c
 *    Description:  is a variant of SCAN designed to provide a more
 *    				uniform wait time. Like SCAN, C-SCAN moves the head from
 *    				one end of the disk to the other, servicing requests 
 *    				along the way. When the head reaches the other end, 
 *    				however, it immediately returns to the beginning of
 *    				the disk without servicing any request on the return
 *    				trip. 
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include "disk.h"
/* Function Defenitions */
void Cscan(int position, int array[])
{
	printf("Starting CSCAN Algorithm\n");
	printf("\tInitial Position %d\n", position);
	
	int i = 0,pos,count=0,move=0,step=900,mark,min=500,max=-1,b[CYL];
	int empty = 0;

	for(int k = 0; k < CYL; k++)
	{		
		b[k] = array[k];
		//printf("%d ",b[k]);	
	}

	while(empty == 0)
	{
		step = 900;
		empty = 1;

		for(i = 0; i < CYL; i++)
		{
			if(b[i] == NULL)
			{
				continue;
			}
		 	if(b[i] < b[min])
			{
				min = i;
			}
			if(b[i] > max)
			{
				max = b[i];
			}
			if(b[i] > position && b[i] != NULL)
			{
				empty = 0;
				if((abs(position - b[i])) < step)
				{
					step = abs(position - b[i]);
					mark = i;
					
				}								
			}
		}
		
		position = b[mark];
		b[mark] = NULL;
		
		//Service request	
		if(position != NULL)
		{
			move = move + step;
			printf("\tServicing %d movement: %d\n", position, move);
			count++;
		}
		
		//Wrap around
		if(position == max)
		{
			position = b[min];
			move = move + (200 - max) + 199 + b[min];
		}
		i = 0;
	}
	printf("\tCSCAN = %d movements\n\n",move);
	return;
}


