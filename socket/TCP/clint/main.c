#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> 
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

#define SERVERPORT "6688"

void main(int argc, char** argv)
{
    struct sockaddr_in laddr;
    struct sockaddr_in raddr;
    int socket_tcp;
    int newfd;
    socklen_t addrlen;

    char buf[10] = "123456789";

    socket_tcp = socket(AF_INET,SOCK_STREAM,0);
    if(socket_tcp < 0)
    {
        perror("socket:");
        exit(0);
    }

    raddr.sin_family = AF_INET;
    raddr.sin_port = htons(atoi(SERVERPORT));
    inet_pton(AF_INET, "127.0.0.1", &raddr.sin_addr);

    addrlen = sizeof(raddr);
    
    if(connect(socket_tcp,(void*) &raddr,addrlen) <0)
    {
        perror("connect:");
    };
    while(1)
    {
        send(socket_tcp,buf,sizeof(buf), 0);
        sleep(1);
    }
    
    return;
}
