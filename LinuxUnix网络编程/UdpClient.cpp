#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<cstdlib>
#include<iostream>

#define PORT 50000

#define MAXDATASIZE 100

int main(int argc,char *argv[])
{
    int sockfd;
    int num;
    char buf[MAXDATASIZE];
    struct hostent *he;
    struct sockaddr_in server, peer;
    
    if((he = gethostbyname(argv[1])) == NULL)
    {
        printf("gethostbuname()error\n");
        exit(1);
    }

    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        printf("socket()error\n");
        exit(1);
    }

    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr = *((struct in_addr *)he->h_addr);

    if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1)
    {
        printf("connect()error\n");
        exit(1);
    }

    send(sockfd, argv[2], strlen(argv[2]), 0);
    //sendto(sockfd,argv[2],strlen(argv[2]),0,(struct sockaddr *)&server,sizeof(server));
    std::cout << "here!\n";
    socklen_t len;

    while(1)
    {
        if((num = recvfrom(sockfd, buf, MAXDATASIZE, 0, (struct sockaddr *)&peer, &len)) == -1)
        {
            printf("recvfrom()error\n");
            exit(1);
        }
        if(len != sizeof(server) || memcmp((const void *)&server, (const void *)&peer, len) != 0)
        {
            printf("receive message from other server.\n");
            continue;
        }
        std::cout << num << std::endl;
        buf[num-1] = '\0';
        printf("server message:%s.\n", buf);
        break;
    }
    close(sockfd);
}