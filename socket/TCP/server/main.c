#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
 #include <unistd.h>
 #include <string.h>
#include <pthread.h>


#define SERVERPORT "2223"

int FD_ARR[100]={-1};
pthread_t PID_ARR[100];
int pos=0;

void* thread_msg_recv(void* args);

void main(int argc, char** argv) 
{
    
    int socket_tcp;

    struct sockaddr_in laddr;
    struct sockaddr_in raddr;
    socklen_t addr_len;

    pthread_t pid;

    char buf[10];

    socket_tcp = socket(AF_INET,SOCK_STREAM,0);
    if(socket_tcp < 0)
    {
        perror("sockrt:");
        exit(0);
    }

    inet_pton(AF_INET, "0.0.0.0", &laddr.sin_addr);
    laddr.sin_family=AF_INET;
    laddr.sin_port=htons(atoi(SERVERPORT));

    addr_len = sizeof(laddr);
    bind(socket_tcp,(void *)&laddr,addr_len);

    if(listen(socket_tcp,10) < 0)
    {
        perror("listen:");
        exit(0);
    };

  
        while(1)
        {
            FD_ARR[pos] = accept(socket_tcp,(void *)&raddr,&addr_len);
                if(FD_ARR[pos] < 0)
            {
                perror("accept:");
                exit(0);
            }
            /*子线程 并发*/
            printf("thread %d",pos);
            if(pthread_create(&PID_ARR[pos],NULL,thread_msg_recv,&FD_ARR[pos]) == 0)
            {
                pos++;
                printf("pos:%d\n",pos);
            };
        }
}

void* thread_msg_recv(void* args)
{
    
    int* fd = args;

    char * buf = (char *)malloc(10);
    while(1)
    {
        memset(buf,'\0',10);

       int tmp = recv(*fd,buf,10,0);
        if(tmp < 0)
        {
            printf("recv%d\n",*fd);
            exit(0);
        }
       printf("%lx:%s\n",*fd,buf);

    }
 
}

