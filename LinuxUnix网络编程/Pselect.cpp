//pselect基础用法
//屏蔽键盘输入的ctrl+c
//g++ filename.cpp -o filename
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/time.h>
#include <signal.h>
#include<cstdlib>
#include<iostream>

#define MAXDATASIZE 100

int main()
{
    fd_set rset;
    sigset_t newsig, oldsig;
    char temp[MAXDATASIZE];

    FD_ZERO(&rset);
    FD_SET(0, &rset);
    //该函数的作用是将信号集初始化为空。
    sigemptyset(&newsig);
    sigemptyset(&oldsig);
    //SIGINT->ctrl+c 表示屏蔽ctrl+c
    sigaddset(&newsig, SIGINT);
    //int sigpromask(int how, const sigset_t *set, sigset_t *oset);
    //该函数可以根据参数指定的方法修改进程的信号屏蔽字。新的信号屏蔽字由参数set（非空）指定，而原先的信号屏蔽字将保存在oset（非空）中
    //如果set为空，则how没有意义，但此时调用该函数，如果oset不为空，则把当前信号屏蔽字保存到oset中
    //按照参数  set 提供的屏蔽字，屏蔽信号,并将原信号屏蔽保存到oldset中
    sigprocmask(SIG_BLOCK, &newsig, &oldsig);
    while(1)
    {
        if(pselect(1, &rset, NULL, NULL, NULL, &newsig) > 0)
        {
            fgets(temp, MAXDATASIZE, stdin);
            printf("Input string is %s\n", temp);
            exit(0);
        }
    }
}