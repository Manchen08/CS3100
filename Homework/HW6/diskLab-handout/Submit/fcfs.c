/*
 * =====================================================================================
 *
 *       Filename:  fcfs.c
 *       	Usage:  ./fcfs.c
 *    Description:  First Come, First Serve
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include "disk.h"
/* Function Defenitions */
void Fcfs(int position, int array[])
{

	printf("Starting FCFS algorithm\n");
	printf("\tInitial position %d\n", position);

	int count = 0;
	int last = position;
	for(int i = 0; i < CYL; i++)
	{
		count += abs(last - array[i]);
		printf("\tServicing %d movement: %d\n", array[i], count);
		last = array[i];
	}
	
	printf("\tFCFS = %d movements\n\n",count);
	return;
}
