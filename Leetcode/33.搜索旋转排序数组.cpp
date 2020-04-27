//33.搜索旋转排序数组

//假设按照升序排序的数组在预先未知的某个点上进行了旋转。
//
//(例如，数组 [0, 1, 2, 4, 5, 6, 7] 可能变为 [4, 5, 6, 7, 0, 1, 2])。
//
//搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回  - 1 。
//
//你可以假设数组中不存在重复的元素。
//
//你的算法时间复杂度必须是 O(log n) 级别。
//
//示例 1:
//输入: nums = [4, 5, 6, 7, 0, 1, 2], target = 0
//输出 : 4
//
//示例 2 :
//输入 : nums = [4, 5, 6, 7, 0, 1, 2], target = 3
//输出 : -1

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    if (l == r && target == nums[0])return 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;

        if (target == nums[mid])return mid;
        if (nums[0] <= nums[mid]) {
            if (nums[0] <= target && target < nums[mid]) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        else {
            if (nums[mid] < target && target <= nums[nums.size() - 1]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> vec{ 4,5,6,7,0,1,2 };
    cout << search(vec, 0) << endl;
    cout << search(vec, 3) << endl;
    return 0;
}
