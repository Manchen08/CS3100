#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("argc = %d\n",argc);
	printf("argv[0] = %s\n",argv[0]); 
	if (argc != 2)
	{
		printf("Incorrect number of arguments, you must pass in a number and filename.\n");
		return -1;
	}
	else
	{
		printf("%s\n",argv[0]);
		printf("%s\n",argv[1]);
		const char * filename="test.txt";
		FILE * ft= fopen(filename, "rb") ;

   		if (ft) 
		{
			int pid = getpid();
			fseek (ft,0,SEEK_END); //go to end of file
			long size = ftell(ft); //what byte in file am I at?
			fseek (ft,0,SEEK_SET); //go to beginning of file
			int num = (int)size / (int)sizeof(int);
			printf("size of the file: %li ,sizeof(int) = %i\n, the number of numbers = %i\n\n", size, (int) sizeof(int), num);
			int i;
			for(i = 0; i < num; i++)
			{
				int temp = 0;
				fread(&temp,sizeof(int),1,ft);
        			printf("%i: %i\t",pid,temp);
			        usleep(50);
			}

			fclose( ft ) ;
		}
	}

	printf("\n");
	return 0;
}
