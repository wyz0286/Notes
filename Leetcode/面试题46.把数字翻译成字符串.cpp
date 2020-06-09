//面试题46.把数字翻译成字符串

//给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”
//一个数字可能有多个翻译
//请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法
//
//示例 1:
//
//输入: 12258
//输出 : 5
//解释 : 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int translateNum(int num) {
    string src = to_string(num);
    int p = 0, q = 0, r = 1;
    for (int i = 0; i < src.size(); ++i) {
        p = q;
        q = r;
        r = 0;
        r += q;
        if (i == 0) {
            continue;
        }
        auto pre = src.substr(i - 1, 2);
        if (pre <= "25" && pre >= "10") {
            r += p;
        }
    }
    return r;
}

int main()
{
    cout << translateNum(12258) << endl; //5
    return 0;
}