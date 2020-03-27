//169.多数元素
//给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n / 2 ⌋ 的元素
//
//你可以假设数组是非空的，并且给定的数组总是存在多数元素


#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

int majorityElement(vector<int>& nums) {
    int count = 0;
    int num;
    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            num = nums[i];
            count++;
        }
        else if (nums[i] != num)count--;
        else count++;
    }
    return num;
}

int main()
{
    vector<int> a{ 1, 1, 2, 4, 4, 4, 4, 4 };
    vector<int> b{ 1, 1, 1, 1, 1, 2, 3, 3 };
    cout << majorityElement(a)<< endl;
    cout << majorityElement(b)<< endl;
    return 0;
}