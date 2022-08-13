#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "relayer.h"

 #include <sys/types.h>
 #include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char** argv )
 {
    int job_id,ret,fd1,fd2;
    mod_init();

    fd2 =open("/dev/tty12",O_RDWR|O_NONBLOCK);
    if(fd2<0){
        perror("fd2_open:");
        exit(1);
    }
     fd1=open("/dev/tty11",O_RDWR|O_NONBLOCK);
    if(fd1<0){
        perror("fd1_open:");
        exit(1);
    }

    ret= job_add(fd1,fd2,&job_id);
        if(ret<0){
        printf("%d\n",ret);
    }
   ret= job_add(fd2,fd1,&job_id);
    if(ret<0){
        printf("%d\n",ret);
    } 

    pause();

    mod_rmove();
}
