//连续子数组最大和
//输入一个整型数组，数组里有正数也有负数,数组中的一个或连续多个整数组成一个子数组,求所有子数组的和的最大值,要求时间复杂度为O(n)
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int ans = INT32_MIN;
    int sum = 0;
    for (int i : nums)
    {
        sum = max(sum + i, i);
        ans = max(sum, ans);
    }
    return ans;
}

int main()
{
    vector<int> a{ -2,1,-3,4,-1,2,1,-5,4 };
    cout << maxSubArray(a) << endl;
    return 0;
}