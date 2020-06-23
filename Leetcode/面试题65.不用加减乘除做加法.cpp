//面试题65.不用加减乘除做加法

//写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int add(int a, int b) 
{
    while (b != 0) 
    { // 当进位为 0 时跳出
        int c = (unsigned int)(a & b) << 1;  // c = 进位
        a ^= b; // a = 非进位和
        b = c; // b = 进位
    }
    return a;
}

int main()
{ 
    string s = "123";
    return 0;
}