#include<stdio.h>
#include<strings.h>
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
    struct sockaddr_in server;

    if((he = gethostbyname(argv[1])) == NULL)
    {
        printf("gethostbuname()error\n");
        exit(1);
    }

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
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

    if((num = recv(sockfd, buf, MAXDATASIZE, 0)) == -1)
    {
        printf("recv()error\n");
        exit(1);
    }

    std::cout << num << std::endl;
    buf[num-1] = '\0';
    printf("server message:%s\n", buf);
    close(sockfd);
}