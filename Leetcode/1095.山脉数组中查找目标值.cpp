//1095.山脉数组中查找目标值
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>

using namespace std;


class MountainArray {
public:
    int get(int index);
    int length();
};
 

class Solution {
public:
    int binary_search(MountainArray& mountain, int target, int l, int r, int key(int)) 
    {
        target = key(target);
        while (l <= r) {
            int mid = (l + r) >> 1;
            int cur = key(mountain.get(mid));
            if (cur == target)
                return mid;
            else if (cur < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray& mountainArr) 
    {
        int len = mountainArr.length();
        int l = 0, r = len - 1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                l = mid + 1;
            else
                r = mid;
        }
        int peak = l;
        int index = binary_search(mountainArr, target, 0, peak, [](int x) -> int {return x; });
        if (index != -1)
            return index;
        return binary_search(mountainArr, target, peak + 1, mountainArr.length() - 1, [](int x) -> int {return -x; });
    }
};

int main()
{
    return 0;
}