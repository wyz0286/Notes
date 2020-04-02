//137.只出现一次的数字 II

//可以任意推广
//可解决超过半数数组长度的数字问题
#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < 32; i++)
    {
        int ones = 0;
        for (int n : nums)
            ones += (n >> i) & 1;  //位运算法统计每个位置上1出现的次数，每次出现则ones+1
        res += (ones % 3) << i;    //如果1出现次数不是3的倍数，1即为这个位置的目标数字
    }
    return res;
}

int main()
{
    vector<int> a = { 2,2,3,2 };
    cout << singleNumber(a) << endl;
    return 0;
}