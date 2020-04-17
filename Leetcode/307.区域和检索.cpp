//307.区域和检索 - 数组可修改

//给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i, j 两点
//
//update(i, val) 函数可以通过将下标为 i 的数值更新为 val，从而对数列进行修改
//
//示例 :
//
//Given nums = [1, 3, 5]
//
//sumRange(0, 2) -> 9
//update(1, 2)
//sumRange(0, 2) -> 8

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class NumArray {
    vector<int> tree;
    int n;
public:
    NumArray(vector<int>& nums) :n(nums.size())
    {
        if (n > 0) tree.resize(2 * n);
        else return;
        //构建线段树
        for (int i = n, j = 0; i < 2 * n; i++, j++)
            tree[i] = nums[j];
        for (int i = n - 1; i > 0; --i)
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }

    void update(int i, int val) 
    {
        i += n;
        tree[i] = val;
        while (i > 0) 
        {
            int left = i;
            int right = i;
            //寻找兄弟节点下标
            if (i % 2 == 0) 
            {
                right = i + 1;
            }
            else 
            {
                left = i - 1;
            }
            // parent is updated after child is updated
            tree[i / 2] = tree[left] + tree[right];
            i /= 2;
        }
    }

    int sumRange(int i, int j) 
    {
        // get leaf with value 'i'
        i += n;
        // get leaf with value 'j'
        j += n;
        int sum = 0;
        while (i <= j)
        {
            if ((i % 2) == 1) 
            {
                sum += tree[i];
                i++;
            }
            if ((j % 2) == 0) 
            {
                sum += tree[j];
                j--;
            }
            i /= 2;
            j /= 2;
        }
        return sum;
    }
};

int main()
{
	return 0;
}