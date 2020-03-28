//gethostbyname usage
//g++ filename.cpp -o filename
//./filename www.baidu.com
// stdout:
// 主机点分十地址、主机正式名称：61.135.169.121    www.a.shifen.com  主机别名： www.baidu.com 
// 主机点分十地址、主机正式名称：61.135.169.125    www.a.shifen.com  主机别名： www.baidu.com
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<cstdlib>
#include<iostream>

int main(int argc, char *argv[])
{
    struct hostent *hp;
    char **p;
    hp = gethostbyname(argv[1]);
    if(hp == NULL)
    {
        printf("host info for %s not found\n", argv[1]);
        exit(1);
    }

    for(p = hp->h_addr_list; *p != 0; p++)
    {
        struct in_addr in;
        char **q;
        std::cout << "主机点分十地址、主机正式名称：";
        memcpy(&in.s_addr, *p, sizeof(in.s_addr) );
        printf("%s\t%s ", inet_ntoa(in), hp->h_name);
        std::cout << " 主机别名：";
        for(q = hp->h_aliases; *q != 0; q++)
            printf(" %s ", *q);
        std::cout << "\n";
    }
    return 0;
}