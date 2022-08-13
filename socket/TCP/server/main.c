#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
 #include <unistd.h>
 #include <string.h>

#define SERVERPORT "2223"

void main(int argc, char** argv) {
    
    int socket_tcp;

    struct sockaddr_in laddr;
    struct sockaddr_in raddr;
    socklen_t addr_len;

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

    int new_sockefd = accept(socket_tcp,(void *)&raddr,&addr_len);
            if(new_sockefd < 0)
        {
            perror("accept:");
            exit(0);
        }

    while(1)
    {
       memset(buf,'\0',sizeof(buf));
       int tmp = recv(new_sockefd,buf,sizeof(buf),0);
        if(tmp < 0)
        {
            printf("recv\n");
            exit(0);
        }
       printf("%s\n",buf);
    }

  
    return;
}
