﻿//69.x 的平方根

//实现 int sqrt(int x) 函数
//
//计算并返回 x 的平方根，其中 x 是非负整数
//
//由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去
//
//示例 1:
//输入: 4
//输出 : 2
//
//示例 2 :
//输入 : 8
//输出 : 2
//说明 : 8 的平方根是 2.82842...
//由于返回类型是整数，小数部分将被舍去

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//int mySqrt(int x) {
//    if (x == 0)return 0;
//    int ans = exp(0.5 * log(x));
//    return (long long)(ans + 1) * (ans + 1) == x ? ans + 1 : ans;
//}

//int mySqrt(int x) {
//    int l = 0;
//    int r = x;
//    int ans = -1;
//    while (l <= r)
//    {
//        int mid = (l + r) / 2;
//        if ((long long)mid * mid <= x)
//        {
//            ans = mid;
//            l = mid + 1;
//        }
//        else
//            r = mid - 1;
//    }
//    return ans;
//}

int mySqrt(int x) {
    if (x == 0)return 0;
    double C = x, x0 = x;
    while (true)
    {
        double xi = 0.5 * (x0 + C / x0);
        if ((x0 - xi) < 1e-7)break;
        x0 = xi;
    }
    return (int)x0;
}

int main()
{
    cout << mySqrt(4) << endl;
    cout << mySqrt(8) << endl;
    return 0;
}