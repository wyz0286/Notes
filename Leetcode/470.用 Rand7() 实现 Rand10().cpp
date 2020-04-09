//470.用 Rand7() 实现 Rand10()

//已有方法 rand7 可生成 1 到 7 范围内的均匀随机整数，试写一个方法 rand10 生成 1 到 10 范围内的均匀随机整数
//
//不要使用系统的 Math.random() 方法

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <string>
#include <random>

using namespace std;

int rand7()
{
    return rand() % 7 + 1;
}
//方法一：拒绝采样
//int rand10() 
//{
//    int row, col, idx;
//    do 
//    {
//        row = rand7();
//        col = rand7();
//        idx = col + (row - 1) * 7;
//    } while (idx > 40);
//    return 1 + idx % 10;
//}

//方法二：合理使用被拒绝的随机数
int rand10()
{
    int a, b, idx;
    while (true) {
        a = rand7();
        b = rand7();
        idx = b + (a - 1) * 7;
        if (idx <= 40)
            return 1 + (idx - 1) % 10;
        a = idx - 40;
        b = rand7();
        // get uniform dist from 1 - 63
        idx = b + (a - 1) * 7;
        if (idx <= 60)
            return 1 + (idx - 1) % 10;
        a = idx - 60;
        b = rand7();
        // get uniform dist from 1 - 21
        idx = b + (a - 1) * 7;
        if (idx <= 20)
            return 1 + (idx - 1) % 10;
    }
}

int main()
{
    cout << rand10() << endl;
    return 0;
}