#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
 #include <netinet/ip.h> 
 #include <unistd.h>
 #include <stdlib.h>
 #include <arpa/inet.h>
#include <string.h>


#define SERVERPORT "2333"

 struct test_msg 
 {
    u_int16_t num1;
    u_int8_t    name[31];
 };
 

void main(int argc , char** argv) {

    int socket_udp;
    struct sockaddr_in  addr_l;
    struct sockaddr_in  addr_r;
    socklen_t addrlen;
    struct test_msg test1;


    socket_udp = socket(AF_INET,SOCK_DGRAM,0);
     if(socket_udp < 0)
     {
        printf("socket fail\n");
        exit(0);
     }
     inet_pton(AF_INET, "192.168.155.199", &addr_r.sin_addr);
     addr_r.sin_family = AF_INET;
     addr_r.sin_port = (htons(atoi(SERVERPORT)));

    test1.num1 = htons(100);
    strcpy(test1.name,"test1");

    addrlen = sizeof(addr_r);
    while(1)
    {
         if(sendto(socket_udp, &test1, sizeof(test1), 0, (struct sockaddr*)&addr_r,addrlen) < 0)
         {
            printf("send err\n");
            exit(0);
         };
         sleep(1);
    }
   

    return ;
}
