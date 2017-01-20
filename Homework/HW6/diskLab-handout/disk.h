/*
 * =====================================================================================
 *       Filename:  disk.h
 * =====================================================================================
 */
#ifndef __disk__
#define __disk__
/* Array Size */
#define CYL 8
#define LC 0
#define UC 199

/* Function Prototypes */
void Fcfs(int position, int array[]);
void Sstf(int position, int array[]);
void Scan(int position, int array[]);
void Cscan(int position, int array[]);

#endif // __disk__
