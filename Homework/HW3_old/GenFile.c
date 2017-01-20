#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 int main(int argc, char * argv[])
 {
   const char * filename="test.txt";
   FILE * ft= fopen(filename, "wb") ;
   if (ft) {
     int i;
     for(i = 0; i < atoi(argv[1]); i++){
        int randomnum = rand() % 1000000;
        fwrite(&randomnum,sizeof(int),1,ft);
     }
     fclose( ft ) ;
   }
   return 0;
 }
