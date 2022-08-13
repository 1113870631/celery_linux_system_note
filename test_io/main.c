#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024
char buffer[BUFFER_SIZE];

int main(void)
{	
    int fd;
    int ret;

    fd=open("/dev/tty11",O_RDWR|O_NONBLOCK);
    if(fd<0)
    {
        perror("open");
    }
    while(1)
    {
        read(fd,buffer,BUFFER_SIZE);
        write(fd,buffer,BUFFER_SIZE);
        memset(buffer, '\0', BUFFER_SIZE);
    }


}










