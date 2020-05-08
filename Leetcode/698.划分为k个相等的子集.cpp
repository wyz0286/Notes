//698.划分为k个相等的子集

//给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等
//
//示例 1：
//输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
//输出： True
//说明： 有可能将其分成 4 个子集（5），（1, 4），（2, 3），（2, 3）等于总和

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        vector<int> sums(k, sum / k);
        sort(nums.begin(), nums.end());
        if (nums.back() > sum / k) return false;
        return dfs(nums, sums, sum / k, (int)nums.size() - 1);
    }

    int dfs(vector<int>& nums, vector<int>& sums, int target, int idx) {
        if (idx == -1) {
            return true;
        }
        int num = nums[idx];
        for (int i = 0; i < sums.size(); ++i) {
            if (sums[i] == num || (idx > 0 && sums[i] - num >= nums[0])) {
                sums[i] -= num;
                if (dfs(nums, sums, target, idx - 1)) return true;
                sums[i] += num;
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}