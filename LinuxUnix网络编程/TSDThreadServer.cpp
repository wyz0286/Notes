//TSD取代静态变量实现线程安全
//多线程服务器
//g++ filename.cpp -o filename -lpthread
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<pthread.h>
#include<cstdlib>
#include<iostream>

#define PORT 50000
#define BACKLOG 5
#define MAXDATASIZE 1000

void process_cli(int connfd, struct sockaddr_in client);
void savedata_r(char* recvbuf, int len, char* cli_data);
void *function(void *arg);

struct ARG{
    int connfd;
    struct sockaddr_in client;
};

pthread_key_t key;
pthread_once_t once = PTHREAD_ONCE_INIT;

static void destructor(void *ptr)
{
    free(ptr);
}

static void creatkey_once(void)
{
    pthread_key_create(&key, destructor);
}

struct ST_DATA{
    int index;
};

int main()
{
    int listenfd;
    int connectfd;
    pthread_t tid;
    struct ARG *arg;
    struct sockaddr_in server;
    struct sockaddr_in client;
    socklen_t len;

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
        arg = (struct ARG *)malloc(sizeof(struct ARG));
        arg->connfd = connectfd;
        memcpy((void *)&arg->client, &client, sizeof(client));

        if(pthread_create(&tid, NULL, function, (void *)arg))
        {
            printf("pthread_create()error\n");
            exit(1);
        }
    }
    close(listenfd);
}

void process_cli(int connfd,struct sockaddr_in client)
{
    char recvbuf[MAXDATASIZE], sendbuf[MAXDATASIZE], cli_name[MAXDATASIZE], cli_data[MAXDATASIZE];
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
        printf("Recieved client(%s)message:%s", cli_name,recvbuf);
        savedata_r(recvbuf, num, cli_data);
        int i = 0;
        for(i = 0; i < num - 1; i++)
        {
            if((recvbuf[i] >= 'a' && recvbuf[i] <= 'z') || (recvbuf[i] >= 'A' && recvbuf[i] <= 'Z'))
            {
                recvbuf[i] = recvbuf[i] + 3;
                if((recvbuf[i] > 'Z' && recvbuf[i] <= 'Z'+3) || (recvbuf[i] > 'z'))
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
    printf("client(%s)closed connection.\nuser's data:%s\n", cli_name, cli_data);
}

void* function(void *arg)
{
    struct ARG *info = (struct ARG*)arg;
    process_cli(info->connfd, info->client);
    free(arg);
    pthread_exit(NULL);
}

void savedata_r(char* recvbuf, int len, char* cli_data)
{
    struct ST_DATA* data;
    pthread_once(&once,creatkey_once);

    if((data = (struct ST_DATA*)pthread_getspecific(key)) == NULL)
    {
        data = (struct ST_DATA *)malloc(sizeof(struct ST_DATA));
        pthread_setspecific(key, data);
        data->index = 0;
    }

    int i = 0;
    while(i < len - 1)
    {
        cli_data[data->index++] = recvbuf[i];
        ++i;
    }
    cli_data[data->index] = '\0';
}