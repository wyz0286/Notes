//1248.统计「优美子数组」
//
//给你一个整数数组 nums 和一个整数 k
//
//如果某个 连续 子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」
//
//请返回这个数组中「优美子数组」的数目

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) {
    int n = (int)nums.size();
    vector<int> odd(n + 2, 0);
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] & 1) odd[++cnt] = i;
    }
    odd[0] = -1, odd[++cnt] = n;
    for (int i = 1; i + k <= cnt; ++i) {
        ans += (odd[i] - odd[i - 1]) * (odd[i + k] - odd[i + k - 1]);
    }
    return ans;
}

int main() {
    //nums = [1,1,2,1,1], k = 3
    //2

    //nums = [2,4,6], k = 1
    //0

    //nums = [2,2,2,1,2,2,1,2,2,2], k = 2
    //16

    vector<int> nums = { 2,2,2,1,2,2,1,2,2,2 };
    int k = 2;
    cout << numberOfSubarrays(nums, k) << endl;
	return 0;
}
