//面试题62.圆圈中最后剩下的数字
//0, 1, , n - 1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字
//
//例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int f(int n, int m)
{
    if (n == 1)return 0;
    int x = f(n - 1, m);
    return (m + x) % n;
}

int lastRemaining(int n, int m) 
{
    int f = 0;
    for (int i = 2; i != n + 1; ++i)
        f = (m + f) % i;
    return f;
    //return f(n, m);
}

int main()
{
    cout << lastRemaining(5, 3) << endl;
    cout << lastRemaining(10, 17) << endl;
    return 0;
}
