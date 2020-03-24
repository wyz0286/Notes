#include<stdio.h>
#include<strings.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<cstdlib>
#include<iostream>

#define PORT 50000
#define BACKLOG 1

int main()
{
    int listenfd;
    int connectfd;
    struct sockaddr_in server;
    struct sockaddr_in client;
    socklen_t addrlen;

    if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        printf("socket()error\n");
        exit(1);
    }

    int opt = SO_REUSEADDR;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    bzero(&server,sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    std::cout << server.sin_addr.s_addr << std::endl;

    if(bind(listenfd, (struct sockaddr *)&server, sizeof(server)) == -1)
    {
        printf("bind()error\n");
        exit(1);
    }

    if(listen(listenfd,BACKLOG) == -1)
    {
        printf("listen()error\n");
        exit(1);
    }

    addrlen = sizeof(client);

    if((connectfd = accept(listenfd, (struct sockaddr *)&client, &addrlen)) == -1)
    {
        printf("accept()error\n");
        exit(1);
    }

    printf("You got a connection from client's ip is %s,port is %d\n", inet_ntoa(client.sin_addr), htons(client.sin_port));
    send(connectfd, "welcome\n", 8, 0);
    sleep(1);
    close(connectfd);
    close(listenfd);
}