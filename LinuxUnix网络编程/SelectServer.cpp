//select实现单进程并发服务器
//可用PidClient进行测试
//g++ filename.cpp -o filename
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/time.h>
#include<cstdlib>
#include<iostream>

#define PORT 50000
#define BACKLOG 5
#define MAXDATASIZE 1000

typedef struct CLIENT{
    int fd;
    char *name;
    struct sockaddr_in addr;
    char *data;
}CLIENT;

void process_cli(CLIENT* client, char* recvbuf, int len);
void savedata(char* recvbuf, int len, char* cli_data);

int main()
{
    int listenfd, connectfd;

    struct sockaddr_in server;
    CLIENT client[FD_SETSIZE];
    char recvbuf[MAXDATASIZE];

    if((listenfd = socket(AF_INET,SOCK_STREAM,0)) == -1)
    {
        printf("creating socket()error\n");
        exit(1);
    }

    int opt = SO_REUSEADDR;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = htonl(INADDR_ANY);

    //std::cout << server.sin_addr.s_addr << std::endl;

    if(bind(listenfd, (struct sockaddr *)&server, sizeof(server)) == -1)
    {
        printf("bind()error\n");
        exit(1);
    }

    if(listen(listenfd, BACKLOG) == -1)
    {
        printf("listen()error\n");
        exit(1);
    }

    socklen_t sin_size = sizeof(struct sockaddr_in);

    //init for select
    int i, sockfd, nready;
    ssize_t n;
    fd_set rset, allset;

    int maxfd = listenfd;
    int maxi = -1;
    for(i = 0; i < FD_SETSIZE; i++)
    {
        client[i].fd = -1;
    }
    FD_ZERO(&allset);
    FD_SET(listenfd, &allset);

    while(1)
    {
        struct sockaddr_in addr;
        rset = allset;
        nready = select(maxfd + 1, &rset, NULL, NULL, NULL);
        std::cout << "nready:" << nready << std::endl;

        if(FD_ISSET(listenfd, &rset))
        {
            if((connectfd = accept(listenfd, (struct sockaddr *)&addr, &sin_size)) == -1)
            {
                printf("accept()error\n");
                exit(1);
            }
            std::cout << "connectfd:" << connectfd << std::endl;
        
            for(i = 0; i < FD_SETSIZE; i++)
                if(client[i].fd < 0)
                {
                    client[i].fd = connectfd;
                    client[i].name = new char[MAXDATASIZE];
                    client[i].addr = addr;
                    client[i].data = new char[MAXDATASIZE];
                    client[i].name[0] = '\0';
                    client[i].data[0] = '\0';
                    printf("you got a connection from %s.",inet_ntoa(client[i].addr.sin_addr));
                    break;
                }
            if(i == FD_SETSIZE) printf("too many clients\n");
            FD_SET(connectfd, &allset);
            if(connectfd > maxfd) maxfd = connectfd;
            if(i > maxi) maxi = i;
            if(--nready <= 0) continue;
        }

        for(i = 0; i <= maxi; i++)
        {
            if((sockfd = client[i].fd) < 0) continue;
            if(FD_ISSET(sockfd, &rset))
            {
                if((n = recv(sockfd, recvbuf, MAXDATASIZE, 0)) == 0)
                {
                    close(sockfd);
                    printf("client(%s)closed connection.user's data:%s\n", client[i].name, client[i].data);
                    FD_CLR(sockfd, &allset);
                    client[i].fd = -1;
                    free(client[i].name);
                    free(client[i].data);
                }
                else process_cli(&client[i], recvbuf, n);

                if(--nready <= 0) break;
            }
        }
    }
    close(listenfd);
}

void process_cli(CLIENT* client, char* recvbuf, int len)
{
    char sendbuf[MAXDATASIZE];
    recvbuf[len - 1] = '\0';
    if(strlen(client->name) == 0)
    {
        memcpy(client->name, recvbuf, len);
        printf("client's name is %s.\n", client->name);
        return;
    }

    printf("received client(%s) message:%s.\n", client->name, recvbuf);
    savedata(recvbuf, len, client->data);

    for(int j = 0; j < len - 1; j++)
    {
        sendbuf[j] = recvbuf[len - j - 2];
    }
    sendbuf[len - 1] = '\0';

    send(client->fd, sendbuf, strlen(sendbuf), 0);
}

void savedata(char* recvbuf, int len, char* cli_data)
{
    int start = strlen(cli_data);
    for(int i = 0;i < len; i++)
    {
        cli_data[start + i] = recvbuf[i];
    }
}