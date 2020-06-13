//面试题59 - I滑动窗口的最大值
//给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
//
//示例 :
//
//输入: nums = [1, 3, -1, -3, 5, 3, 6, 7], 和 k = 3
//输出 : [3, 3, 5, 5, 6, 7]
//解释 :
//
//    滑动窗口的位置                最大值
//    -------------- - ---- -
//    [1  3 - 1] - 3  5  3  6  7       3
//    1[3 - 1 - 3] 5  3  6  7       3
//    1  3[-1 - 3  5] 3  6  7       5
//    1  3 - 1[-3  5  3] 6  7       5
//    1  3 - 1 - 3[5  3  6] 7       6
//    1  3 - 1 - 3  5[3  6  7]      7

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
    vector<int> ans;   //定义一个数组保存结果
    int n = nums.size();
    if (n == 0) return ans;
    deque<int> dq;    //定义一个双端队列来实现滑动窗口
    for (int i = 0; i < n; ++i) 
    {
        while (!dq.empty() && nums[i] >= nums[dq.back()]) //滑动窗口中只保存最大值，每次取时就是最大值了
        { 
            dq.pop_back();
        }
        while (!dq.empty() && dq.front() < i - k + 1)     //确实滑动窗口里的值是否有效，删除无效索引
        {
            dq.pop_front();
        }
        dq.push_back(i);     //将原始数据逐步加入滑动窗口
        if (i >= k - 1) ans.push_back(nums[dq.front()]);  // 将每次的滑动窗口最大值存入我们的输出数组
    }
    return ans;
}

int main()
{
    vector<int> nums{ 1,3,-1,-3,5,3,6,7 };
    int k = 3;
    auto ans = maxSlidingWindow(nums, k);
    for (auto num : ans)
        cout << num << " ";
    return 0;
}