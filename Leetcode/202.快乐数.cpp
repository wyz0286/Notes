//202.快乐数

//编写一个算法来判断一个数 n 是不是快乐数
//
//「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和
//
//然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1
//
//如果 可以变为  1，那么这个数就是快乐数
//
//如果 n 是快乐数就返回 True ；不是，则返回 False 
//
//示例：
//输入：19
//输出：true
//解释：
//12 + 92 = 82
//82 + 22 = 68
//62 + 82 = 100
//12 + 02 + 02 = 1

#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<algorithm>

using namespace std;
//数学法
//bool isHappy(int n) {
//    int val;
//    while (n != 1)
//    {
//        if (n / 10 == 0 && n != 7)return false;
//        val = 0;
//        while (n != 0)
//        {
//            val += (n % 10) * (n % 10);
//            n = n / 10;
//        }
//        n = val;
//    }
//    return true;
//}
int getNext(int n) {
    int totalSum = 0;
    while (n > 0) {
        int d = n % 10;
        n = n / 10;
        totalSum += d * d;
    }
    return totalSum;
}
//用unordered_set检测循环
//bool isHappy(int n) {
//    unordered_set<int> seen;
//    while (n != 1 && seen.find(n) == seen.end())
//    {
//        seen.insert(n);
//        n = getNext(n);
//    }
//    return n == 1;
//}

//快慢指针法
bool isHappy(int n) 
{
    int slowRunner = n;
    int fastRunner = getNext(n);
    while (fastRunner != 1 && slowRunner != fastRunner) 
    {
        slowRunner = getNext(slowRunner);
        fastRunner = getNext(getNext(fastRunner));
    }
    return fastRunner == 1;
}


int main()
{
    cout << isHappy(19) << endl;
    return 0;
}