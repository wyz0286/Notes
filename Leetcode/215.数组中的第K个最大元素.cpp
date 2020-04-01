//215.数组中的第K个最大元素
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& nums, int l, int r)
{
    int t = nums[l];
    while (l < r)
    {
        while (l < r && nums[r] <= t) r--;
        nums[l] = nums[r];
        while (l < r && nums[l] >= t) l++;
        nums[r] = nums[l];
    }
    nums[l] = t;
    return l;
}

void quickSelect(vector<int>& nums, int k, int l, int r)
{
    if (l < r)
    {
        int a = partition(nums, l, r);
        int cur = a - l + 1;
        if (cur > k)
            quickSelect(nums, k, l, a - 1);
        else if (cur < k)
            quickSelect(nums, k - cur, a + 1, r);
        else
            return;
    }
    return;
}

int findKthLargest(vector<int>& nums, int k)
{
    quickSelect(nums, k, 0, nums.size() - 1);
    return nums[k - 1];
}

int main()
{
    vector<int> a = { 3,2,3,1,2,4,5,5,6 };

    cout << findKthLargest(a, 4) << endl;

    return 0;
}