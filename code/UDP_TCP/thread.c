#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> 
#include <arpa/inet.h>
#include <sys/select.h>
 #include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>


#define SOCKET_NUM 102
#define LISTEN_PORT 6688
#define LISTEN_IP "127.0.0.1"
#define MSG_SIZE  1024
int MAX_FD(int * arr,int NUM);

void * thread_task(void *pdata)
{
    int ret;
    int Fd_Arr[SOCKET_NUM];
    int tcp_socket,udp_socket;
    struct sockaddr_in laddr,raddr;
    socklen_t addrlen;
    fd_set readfds;
    char Msg_Buf[MSG_SIZE]={'\0'};

    memset(Fd_Arr,-1,sizeof(Fd_Arr));
    tcp_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(tcp_socket < 0)
    {
        perror("tcp_socket:");
    }
    udp_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if(udp_socket <0)
    {
        perror("udp_socket:");
    }

    laddr.sin_family = AF_INET;
    laddr.sin_port = htons(LISTEN_PORT);
    inet_pton(AF_INET ,LISTEN_IP , &laddr.sin_addr.s_addr);

    addrlen = sizeof(laddr);
    bind(tcp_socket,(void *)&laddr,addrlen);
    bind (udp_socket, (void *)&laddr,addrlen);

    listen(tcp_socket,5);

    Fd_Arr[0] = tcp_socket;
    Fd_Arr[1] = udp_socket;

    while(1)
    {
        for(int i=0; i<SOCKET_NUM; i++)
        {
            if(Fd_Arr[i] >=0)
            {
               FD_SET(Fd_Arr[i], &readfds);
            }
        }

        ret = select(MAX_FD(Fd_Arr,SOCKET_NUM)+1, &readfds, NULL, NULL,NULL);
        printf("select ok\n");
        if(ret < 0)
        {
            perror("select:");
        }
       for(int i=0; i<SOCKET_NUM; i++)
        {
            if(Fd_Arr[i] < 0)
            {
                continue;
            }
            if(FD_ISSET(Fd_Arr[i] ,&readfds)&& i == 0)
            {
                /*监听数组满*/
                if(Fd_Arr[SOCKET_NUM-1]>=0)
                {
                    continue;
                }
                /*建立新的TCP连接*/
                ret = accept(Fd_Arr[0],&raddr,&addrlen);
                if(ret >= 0)
                {
                 Fd_Arr[SOCKET_NUM-1]=ret;
                }
            }
             if(FD_ISSET(Fd_Arr[i] ,&readfds)&& i == 1)
            {
                recvfrom(Fd_Arr[i] , Msg_Buf, MSG_SIZE, 0, &raddr, &addrlen);
                printf("%s\n",Msg_Buf);
            }
           if(FD_ISSET(Fd_Arr[i] ,&readfds)&& i > 1)
            {
                recv(Fd_Arr[i] , Msg_Buf, MSG_SIZE, 0);
                printf("%s\n",Msg_Buf);
                close(Fd_Arr[i] );
                Fd_Arr[i]=-1;
            }
        }

    };

}

int compar(const void * num1, const void * num2)
{
    return *((int*)num2 )-*((int*)num1);
}

int MAX_FD(int * arr,int NUM)
{
    qsort(arr+2, NUM-2, sizeof(*arr), compar);
    if(arr[1] > arr[2])
    {
        return arr[1];
    }
    return arr[2];
};
