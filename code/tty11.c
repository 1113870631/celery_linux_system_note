#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char buffer[1024];


int main(int srgc, char* argv){
    int fd;
    size_t ret;
    fd =open("/dev/tty11",O_RDWR|O_NONBLOCK);
    if(fd<0){
        perror("fd_open:");
        exit(1);
    }

    while(1)
      {
	 ret=read(fd,buffer,1024);

	 if(ret<0)
	 {
		 puts("read fali!");
		 exit(0);
	 }
	 write(fd,buffer,ret);
      }
    return 0;
}


