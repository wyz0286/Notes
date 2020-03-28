//以守护进程方式运行的时间服务器
//g++ filename.cpp -o filename
#include<stdio.h>
#include<unistd.h>
#include<syslog.h>
#include<signal.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<cstdlib>
#include<iostream>

#define MAXFD 64
#define MAXLINE 255

void daemon_init(const char *pname, int facility)
{
    int i;
    pid_t pid;
    if((pid = fork()) != 0)
        exit(0);//父进程终止
    /*1st child continues*/
    setsid(); //成为会话头
    signal(SIGHUP, SIG_IGN);
    if((pid = fork()) != 0)
        exit(0);//第一个子进程终止
    /*2st child continues*/
    chdir("/"); //改变工作目录
    umask(0); //清除文件模式创建掩码， 使新文件的权限位不受原先文件模式创建掩码的权限位的影响
    for(i = 0; i<MAXFD; i++)
        close(i);
    openlog(pname, LOG_PID, facility); //用syslogd处理错误
}

int main(int argc, char **argv)
{
    int listenfd, connfd;
    socklen_t addrlen, len;
    struct sockaddr cliaddr;
    struct sockaddr_in server;
    char buf[MAXLINE];
    time_t ticks;
    bzero(&server, sizeof(server));
    bzero(&cliaddr, sizeof(cliaddr));
    server.sin_family = AF_INET;
    server.sin_port = htons(50000);
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    daemon_init(argv[0], 0);

    if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        syslog(LOG_NOTICE | LOG_LOCAL0, "socket error");
        exit(-1);
    }

    if(bind(listenfd, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1)
    {
        syslog(LOG_NOTICE | LOG_LOCAL0, "bind error");
        exit(-1);
    }

    if(listen(listenfd, 5) == -1)
        exit(1);

    for(; ;)
    {
        len = sizeof(cliaddr);
        connfd = accept(listenfd, &cliaddr, &len);
        ticks = time(NULL);
        snprintf(buf, sizeof(buf), "%.24s\r\n", ctime(&ticks));
        int a;
        if(a = write(connfd, buf, strlen(buf)) == -1)
        {
            syslog(LOG_NOTICE | LOG_LOCAL0, "write error");
            exit(0);
        }
        //sleep(1);
        close(connfd);
    }
}