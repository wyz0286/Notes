//136.只出现一次的数字
//位操作
//
//1.如果我们对 0 和二进制位做 XOR 运算，得到的仍然是这个二进制位
//a ^ 0 = a
//
//2.如果我们对相同的二进制位做 XOR 运算，返回的结果是 0
//a ^ a = 0
//
//3.XOR 满足交换律和结合律
//(a ^ b) ^ a = (a ^ a) ^ b = 0 ^ b = b
//
//所以我们只需要将所有的数进行 XOR 操作，得到那个唯一的数字。

#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    int len = nums.size();
    int ans = 0;
    for (int i = 0; i < len; i++)
    {
        ans = ans ^ nums[i];
    }
    return ans;
}

int main()
{
    vector<int> a = { 4,1,2,1,2 };
    cout << singleNumber(a) << endl;
    return 0;
}