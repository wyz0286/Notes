//Used for connect TSDThreadServer/SimpleThreadServer/PidServer
//g++ filename.cpp -o filename
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

void process(FILE *fp, int sockfd); 
char *getmassage(char* sendline, int len, FILE *fp);

int main(int argc, char *argv[])
{
    int sockfd;
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

    process(stdin, sockfd);
    close(sockfd);
}
void process(FILE *fp, int sockfd)
{
    char sendline[MAXDATASIZE], recvline[MAXDATASIZE];
    int num;
    printf("connected to server.\n");
    printf("input client name:");
    if(fgets(sendline, MAXDATASIZE, fp) == NULL)
    {
        printf("\nExit.\n");
        return;
    }
    send(sockfd, sendline, strlen(sendline), 0);
    while(getmassage(sendline, MAXDATASIZE, fp) != NULL)
    {
        send(sockfd, sendline, strlen(sendline), 0);
        if((num = recv(sockfd, recvline, MAXDATASIZE, 0)) == 0)
        {
            printf("server terminated.\n");
            return;
        }
        recvline[num] = '\0';
        printf("server message:%s\n", recvline);
    }
    sendline[0] = '\0';
    send(sockfd, sendline, strlen(sendline), 0);
    printf("\nExit.\n");
}
char *getmassage(char *sendline, int len, FILE *fp)
{
    printf("input string to server:");
    return (fgets(sendline, MAXDATASIZE, fp));
}