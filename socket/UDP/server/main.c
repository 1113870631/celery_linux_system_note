#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <assert.h>
#include <netinet/in.h>
#include <netinet/ip.h> 
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
/*192.168.155.17 */

#define PORT "2334"

 struct test_msg 
 {
    u_int16_t num1;
    u_int8_t    name[31];
 };

void main(int argc , char**argv) {

    
    int ret;
     struct test_msg recv_msg;
    struct sockaddr_in addr_l;
    struct sockaddr_in addr_r;
    socklen_t addrlen;
    char IP_r[1024]={'\0'};

    int udp_socket = socket(AF_INET, SOCK_DGRAM, 0);
        if(udp_socket <0)
        {
            printf("udp socket err\n");
            assert(0);
        }

        inet_pton(AF_INET, "0.0.0.0", &addr_l.sin_addr);
        addr_l.sin_family = AF_INET;
        addr_l.sin_port = htons(atoi(PORT));

        addrlen = sizeof(addr_l);
        ret = bind(udp_socket,(void *)&addr_l,addrlen);
        if(ret < 0)
        {
            perror("socket bind:");
            assert(0);
        }
        while(1)
        {
            socklen_t  len=sizeof(addr_r);
            recvfrom(udp_socket,&recv_msg,sizeof(recv_msg),0,(void *)&addr_r,&len);
            inet_ntop(AF_INET,&addr_r.sin_addr,IP_r,sizeof(IP_r));
            printf("msg:%s,%d remote ip:%s:%d\n",recv_msg.name,ntohs(recv_msg.num1),IP_r,addr_r.sin_port);
            
        }


    
    return ;
}
