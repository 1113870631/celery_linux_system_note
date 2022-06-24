#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int srgc, char* argv){
    int oldfd=open("/tmp/test_code",O_RDWR|O_CREAT|O_TRUNC);
    if(oldfd<0){
        perror("oldfd_open:");
        exit(1);
    }

    int newfd=1;
    dup2( oldfd,  newfd);//newfd=oldfd  无操作
    if(oldfd!=1)
    close(oldfd);

    puts("123");

    return 0;
}