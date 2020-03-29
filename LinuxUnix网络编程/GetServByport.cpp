//getservbyname getservbyport gethostbyaddr
//g++ filename.cpp -o filename 
//./filename 127.0.0.1
//OUT：
// service port 53 udp is domain
// service port for telent is 23
// 127.0.0.1       localhost
//无法通过IP地址查询百度的域名地址，由于：
// gethostbyname可以通过DNS服务器通过域名获取IP地址等信息。
// 但是gethostbyaddr输入参数时IP地址，这样无需经过DNS转换，无法获取域名等信息，但是可以在hosts文件中增加一个映射，它应该会检查hosts文件。
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

using namespace std;

int main(int argc, char **argv)
{
    //use getservbyport
    struct servent *serv_p = getservbyport(htons(53), "udp");
    if(serv_p == NULL)
        cout << "error getservbyport" <<endl;
    else 
        printf("service port 53 udp is %s\n", serv_p -> s_name);

    //use getservbyname
    serv_p = getservbyname("telnet", "tcp");
    if(serv_p == NULL)
        cout << "error getservbyname" <<endl;
    else 
        printf("service port for telent is %d\n", htons(serv_p -> s_port) );


    struct in_addr  addr;
    struct hostent *hp;
    char **p;
    if(argc != 2)
    {
        printf("usage:%s IP-address\n", argv[0]);
        exit(1);
    }

    if (inet_pton(AF_INET, argv[1], &addr) <= 0) {
		printf("inet_pton error\n");
		return -1;
	}
    
    hp = gethostbyaddr( (char *)&addr, sizeof(addr), AF_INET);
    if(hp == NULL)
    {
        printf("host info for %s not found\n", argv[1]);
        exit(1);
    }

    for(p = hp->h_addr_list; *p != 0; p++)
    {
        struct in_addr in;
        char **q;
        memcpy(&in.s_addr, *p, sizeof(in.s_addr) );
        printf("%s\t%s", inet_ntoa(in), hp->h_name);
        for(q = hp->h_aliases; *q != 0; q++)
            printf(" %s", *q);
        cout << endl;
    }
    return 0;
}