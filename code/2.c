#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
 #include <stdio.h>


    int main(int argc ,char** argv){

        struct stat statbuf;
        fstat(0, &statbuf);
        char tmp;
       sprintf(tmp,"%c\n",statbuf.st_uid);
       // write(0,tmp,sizeof(tmp));
      //printf("%d\n",statbuf.st_uid);
        return 0;
    }
   
