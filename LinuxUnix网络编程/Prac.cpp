//点分十和数值之间的IP地址转化
//g++ filename.cpp -o filename -lpthread
#include<arpa/inet.h>
#include<iostream>
#include<string>
#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
    string IPdotdec; //存放点分十进制IP地址
    char tmp[16];
    struct in_addr s; // IPv4地址结构体
    // 输入IP地址
    cout << "Please input IP address: ";
    cin >> IPdotdec;
    // 转换
    inet_pton(AF_INET, IPdotdec.c_str(), (void *)&s);
    printf("inet_pton: 0x%x\n", s.s_addr); 
    // 反转换
    inet_ntop(AF_INET, (void *)&s, tmp, 16);
    cout << strlen(tmp) << std::endl;
    IPdotdec = tmp;
    cout << "inet_ntop:" << IPdotdec<<endl;

    cout << IPdotdec.length() << std::endl;
    return 0;
}