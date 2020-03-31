#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
    vector<int> tmp;
    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int mid = (l + r) >> 1;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        int i = l, j = mid + 1;
        int cnt = 0;
        while (i <= mid && j <= r) {
            if (nums[i] < nums[j]) {
                tmp[cnt++] = nums[i++];
            }
            else {
                tmp[cnt++] = nums[j++];
            }
        }
        while (i <= mid) tmp[cnt++] = nums[i++];
        while (j <= r) tmp[cnt++] = nums[j++];
        for (int i = 0; i < r - l + 1; ++i) nums[i + l] = tmp[i];
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        tmp.resize((int)nums.size(), 0);
        mergeSort(nums, 0, (int)nums.size() - 1);
        return nums;
    }
};

int main()
{
    vector<int> a = { 5,1,1,2,0,0 };
    Solution s;
    vector<int> rst = s.sortArray(a);
    for (auto it = rst.begin(); it != rst.end(); it++)
    {
        cout << *it << " ";
    }
    return 0;
}