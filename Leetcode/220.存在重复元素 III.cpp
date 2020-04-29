//220.存在重复元素 III

//给定一个整数数组，判断数组中是否有两个不同的索引 i 和 j，使得 nums[i] 和 nums[j] 的差的绝对值最大为 t，并且 i 和 j 之间的差的绝对值最大为 ķ
//
//示例 1 :
//输入: nums = [1, 2, 3, 1], k = 3, t = 0
//输出 : true
//
//示例 2 :
//输入 : nums = [1, 0, 1, 1], k = 1, t = 2
//输出 : true
//
//示例 3 :
//输入 : nums = [1, 5, 9, 1, 5, 9], k = 2, t = 3
//输出 : false

#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<algorithm>

using namespace std;
 
class Solution {
public:
    //平衡二叉树
    //bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    //    set<int> s;
    //    for (int i = 0; i < nums.size(); ++i) {
    //        auto lower = s.lower_bound(nums[i]);
    //        if (lower != s.end() && *lower <= nums[i] + t) return true;
    //        auto upper = s.upper_bound(nums[i]);
    //        //set::upper_bound返回的是小于等于目标元素的最大元素的后一个元素（即大于目标元素的最小元素），所以要对返回的迭代器进行自减操作
    //        if (upper != s.begin() && nums[i] <= *--upper + t) return true; // upper 为 s.begin() 时说明查找结果为空
    //        s.insert(nums[i]);
    //        if (s.size() > k) s.erase(nums[i - k]);
    //    }
    //    return false;
    //}
    //hash桶
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0) return false;
        //t+1可能会溢出，所以要+ 1LL
        long long mod = t + 1LL;
        unordered_map<long long, long long> buck;
        for (int i = 0; i < nums.size(); i++)
        {
            long long nth = nums[i] / mod;
            //可能nums[i]为负数，比如-4 / 5 以及 -4 / 5都等于0，所以负数要向下移动一位
            if (nums[i] < 0) nth--;
            //这里要用find 不能直接[],因为可能本身存储的数字就为0
            if (buck.find(nth) != buck.end())
                return true;
            else if (buck.find(nth - 1) != buck.end() && abs(nums[i] - buck[nth - 1]) <= t)
                return true;
            else if (buck.find(nth + 1) != buck.end() && abs(nums[i] - buck[nth + 1]) <= t)
                return true;
            buck[nth] = nums[i];
            if (i >= k)
            {
                if (nums[i - k] < 0)
                    buck.erase(nums[i - k] / mod - 1);
                else
                    buck.erase(nums[i - k] / mod);
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}