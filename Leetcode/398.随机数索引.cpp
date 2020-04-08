//398.随机数索引
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
    vector<int>nums;
public:
    Solution(vector<int>& nums) :nums(nums){
    }

    int pick(int target) {
        int n = 0;
        int index = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == target) {
                //我们的目标对象中选取。
                n++;
                //我们以1/n的概率留下该数据
                if (rand() % n == 0) index = i;
            }
        return index;
    }
};

int main()
{
	return 0;
}