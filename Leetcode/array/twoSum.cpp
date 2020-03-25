//1.两数之和
//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标
//你可以假设每种输入只会对应一个答案,但是，你不能重复利用这个数组中同样的元素。


#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

//一遍hash
vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> m;

	for (int i = 0; i < nums.size(); i++)
	{
		if (m.find(target - nums[i]) != m.end() && m[target - nums[i]] != i)
			return { m[target - nums[i]], i };
		m[nums[i]] = i;
	}
	return {};
}

int main()
{
	vector<int> a{ 2,7,11,15 };
	auto b = twoSum(a, 9);
	for (auto c : b)
	{
		cout << c << " ";
	}
    return 0;
}