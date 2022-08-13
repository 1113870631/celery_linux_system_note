#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
 #include <unistd.h>

#define BUFFER_SIZE 1024

enum  STAT
{
    STAT_R=0,STAT_W,STAT_E
};

struct stat_drv
{
    int fd1;
    int fd2;
    enum STAT stat_flag;
    char buffer[BUFFER_SIZE];
    int len_r;
    int pos;
    char *  err_str;
};

void  relay_drive(struct stat_drv * stat);

int main(int argc , char** argv) 
{
    struct stat_drv stat1,stat2;
    int fd1,fd2;
    int ret;
    stat1.len_r=stat2.len_r=0;
    stat1.stat_flag=STAT_R;
    stat2.stat_flag=STAT_R;
    fd1=open("/dev/tty11", O_RDWR|O_NONBLOCK);
    if(fd1<0)
    {
        perror("open1");
        exit(0);
    }
    stat1.fd1=fd1;
    stat2.fd2=fd1;
    fd2=open("/dev/tty12", O_RDWR|O_NONBLOCK);
    if(fd2<0)
    {
        perror("open2");
        exit(0);
    }
    stat1.fd2=fd2;
    stat2.fd1=fd2;
    while(stat1.stat_flag!=STAT_E &&stat2.stat_flag!=STAT_E)
    {
            relay_drive(&stat1);
            relay_drive(&stat2);
    }

}


void  relay_drive(struct stat_drv * stat)
{
    int ret;
        switch (stat->stat_flag)
        {
        case STAT_R:
                   stat->len_r =  read(stat->fd1,stat->buffer,BUFFER_SIZE);
                   if(stat->len_r==0)
                   {
                        stat->stat_flag = STAT_E;
                   }
                   else if(stat->len_r < 0)
                   {
                        if(errno== EAGAIN)
                            stat->stat_flag = STAT_R;
                        else
                        {
                            stat->err_str="read";
                            stat->stat_flag = STAT_E;
                        }
                             
                   }
                   else
                   {
                     stat->stat_flag = STAT_W;
                     stat->pos=0;
                   }
                       
                   
            break;

        case STAT_W:
            ret = write(stat->fd2,stat->buffer+stat->pos, stat->len_r);
                if(ret < 0 )
                {
                    if(errno == EAGAIN)
                        stat->stat_flag = STAT_W;
                    else
                    {
                        stat->err_str="write";
                        stat->stat_flag=STAT_E;
                    }
                        
                }
                else 
                {
                    stat->pos+=ret;
                    if((stat->len_r=stat->len_r- ret) >0 )
                    {
                        stat->stat_flag=STAT_W;
                    }
                    else
                        stat->stat_flag=STAT_R;
                }
            break;     

        case STAT_E:
            perror(stat->err_str);

            break;

        default:
            break;
        }
};
