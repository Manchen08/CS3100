#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	//printf("argc = %d\n",argc);
	//printf("argv[0] = %s\n",argv[0]); 
	//printf("argv[1] = %s\n",argv[1]);
	//printf("argv[2] = %s\n",argv[2]);

	const char * filename=argv[2];
	FILE * ft= fopen(filename, "rb") ;

	fseek (ft,0,SEEK_END); //go to end of file
	long size = ftell(ft); //what byte in file am I at?
	fseek (ft,0,SEEK_SET); //go to beginning of file
	int num = (int)size / (int)sizeof(int);
	int min = 2147483640;
	int max = 1;	

	//One call, read the whole file.
	if (strcmp(argv[1], "0") == 0)
	{
		//printf("size of the file: %li ,sizeof(int) = %i\n, the number of numbers = %i\n\n", size, (int) sizeof(int), num);
		if (ft) 
		{
			int pid = getpid();

			int i;
			for(i = 0; i < num; i++)
			{
				int temp = 0;
				fread(&temp,sizeof(int),1,ft);
				if(temp < min)
				{
					min = temp;
				}

				if(temp > max)
				{
					max = temp;
				}

			}
			//write(1,&min, sizeof(int));
			//write(1,&max, 1);
			fwrite(&min,sizeof(int),1,stdout);
			fwrite(&max,sizeof(int),1,stdout);
			//printf("%i,%i,",min,max);
		}
		
	}

	//Begin forking options
	if (strcmp(argv[1], "1") == 0)
	{		

		if (ft) 
		{
			int pid = getpid();
			
			int i;
			for(i = 0; i < num/ (int)sizeof(int); i++)
			{
				int temp = 0;
				fread(&temp,sizeof(int),1,ft);
				if(temp < min)
				{
					min = temp;
				}

				if(temp > max)
				{
					max = temp;
				}

			}
			fwrite(&min,sizeof(int),1,stdout);
			fwrite(&max,sizeof(int),1,stdout);
			//printf("%i,%i,",min,max);
		}
	}

	if (strcmp(argv[1], "2") == 0)
	{

		if (ft) 
		{
			int pid = getpid();
			int pos = num * atoi(argv[1]) - num;
			fseek(ft, pos, SEEK_SET);

			//printf("Second Section\n");
			int i;
			for(i = 0; i < num/ (int)sizeof(int); i++)
			{
				int temp = 0;
				fread(&temp,sizeof(int),1,ft);
				if(temp < min)
				{
					min = temp;
				}

				if(temp > max)
				{
					max = temp;
				}

			}
			fwrite(&min,sizeof(int),1,stdout);
			fwrite(&max,sizeof(int),1,stdout);
			//printf("%i,%i,",min,max);
		}
	}	

	if (strcmp(argv[1], "3") == 0)
	{

		if (ft) 
		{
			int pid = getpid();
			int pos = num * atoi(argv[1]) - num;
			fseek(ft, pos, SEEK_SET);

			//printf("Third Section\n");
			int i;
			for(i = 0; i < num/ (int)sizeof(int); i++)
			{
				int temp = 0;
				fread(&temp,sizeof(int),1,ft);
				if(temp < min)
				{
					min = temp;
				}

				if(temp > max)
				{
					max = temp;
				}

			}
			//write(1,&min, sizeof(min));
			//write(1,&max, sizeof(max));
			fwrite(&min,sizeof(int),1,stdout);
			fwrite(&max,sizeof(int),1,stdout);
			//printf("%i,%i,",min,max);
		}
	}

	if (strcmp(argv[1], "4") == 0)
	{
		//printf("size of the file: %li ,sizeof(int) = %i\n, the number of numbers = %i\n\n", size, (int) sizeof(int), num);

		if (ft) 
		{
			int pid = getpid();
			int pos = num * atoi(argv[1]) - num;
			fseek(ft, pos, SEEK_SET);

			//printf("Fourth Section\n");
			int i;
			for(i = 0; i < num/ (int)sizeof(int); i++)
			{
				int temp = 0;
				fread(&temp,sizeof(int),1,ft);
				if(temp < min)
				{
					min = temp;
				}

				if(temp > max)
				{
					max = temp;
				}

			}
			//write(1,&min, sizeof(min));
			//write(1,&max, sizeof(max));
			fwrite(&min,sizeof(int),1,stdout);
			fwrite(&max,sizeof(int),1,stdout);
			//printf("%i,%i,",min,max);
		}
	}
	//printf("%i%i", min, max);
	return 0;
}
