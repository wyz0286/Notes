//客户端程序向时间服务器发出请求， 并显示服务器回送的结果
//g++ filename.cpp -o filename
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<cstdlib>
#include<iostream>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<syslog.h>
#include<signal.h>
#include<netdb.h>
#include<string.h>


#define PORT 50000
#define MAXDATASIZE 100

int main(int argc, char **argv)
{
    int numbytes, sockfd;
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

    if((numbytes = recv(sockfd, buf, MAXDATASIZE, 0)) == -1)
    {
        printf("recv()error\n");
        exit(1);
    }

    buf[numbytes] = '\0';
    printf("server message:%s\n",buf);
    close(sockfd);
}