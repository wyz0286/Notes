//多进程服务器
//g++ filename.cpp -o filename -lpthread
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<cstdlib>
#include<iostream>

#define PORT 50000
#define BACKLOG 5
#define MAXDATASIZE 1000

void process_cli(int connfd, struct sockaddr_in client);

int main()
{
    int listenfd;
    int connectfd;
    pid_t pid;
    struct sockaddr_in server;
    struct sockaddr_in client;
    socklen_t len;

    if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
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
    std::cout << server.sin_addr.s_addr << std::endl;

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

    len = sizeof(client);

    while(1)
    {
        if((connectfd = accept(listenfd, (struct sockaddr *)&client, &len)) == -1)
        {
            printf("accept()error\n");
            exit(1);
        }
        if((pid = fork()) > 0)
        {
            printf("You got a connection from server's ip is %s,port is %d\n", inet_ntoa(server.sin_addr), htons(server.sin_port));
            close(connectfd);
            continue;
        }
        else if(pid == 0)
        {
            printf("You got a connection from server's ip is %s,port is %d\n", inet_ntoa(server.sin_addr), htons(server.sin_port));
            close(listenfd);
            process_cli(connectfd, client);
            exit(0);
        }
        else
        {
            printf("fork()error\n");
            exit(0);
        }
    }
    //close(listenfd);
}

void process_cli(int connfd, struct sockaddr_in client)
{
    char recvbuf[MAXDATASIZE], sendbuf[MAXDATASIZE], cli_name[MAXDATASIZE];
    printf("You got a connection from %s.\n", inet_ntoa(client.sin_addr));
    int num = recv(connfd, cli_name, MAXDATASIZE, 0);
    if(num == 0)
    {
        close(connfd);
        printf("client disconnected\n");
        return;
    }
    cli_name[num-1] = '\0';
    printf("client name is %s\n", cli_name);
    while(num = recv(connfd, recvbuf, MAXDATASIZE, 0))
    {
        recvbuf[num] = '\0';
        printf("Recieved client(%s)message:%s", cli_name, recvbuf);
        int i = 0;
        for(i = 0; i < num - 1; i++)
        {
            if((recvbuf[i] >= 'a' && recvbuf[i] <= 'z') || (recvbuf[i] >= 'A' && recvbuf[i] <= 'Z'))
            {
                recvbuf[i] = recvbuf[i] + 3;
                if((recvbuf[i] > 'Z' && recvbuf[i] <= 'Z' + 3) || (recvbuf[i] > 'z'))
                    recvbuf[i] = recvbuf[i] - 26;
            }
            sendbuf[i] = recvbuf[i];
        }
        sendbuf[num] = '\0';
        send(connfd, sendbuf, strlen(sendbuf), 0);
    }
    if(num == 0)
    {        
        printf("client disconnected\n");
    }
    close(connfd);
}