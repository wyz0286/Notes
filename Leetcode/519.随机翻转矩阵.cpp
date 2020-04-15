//519.随机翻转矩阵

//题中给出一个 n 行 n 列的二维矩阵(n_rows, n_cols)，且所有值被初始化为 0
//
//要求编写一个 flip 函数，均匀随机的将矩阵中的 0 变为 1，并返回该值的位置下标[row_id, col_id]
//
//同样编写一个 reset 函数，将所有的值都重新置为 0。尽量最少调用随机函数 Math.random()，并且优化时间和空间复杂度

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <random>

using namespace std;

class Solution {
public:
	int total;//总数
	int count;//当前值
	int n_cols;//列数
	unordered_map<int, int> blackMap;
	Solution(int n_rows, int n_cols) :n_cols(n_cols) {
		total = count = n_rows * n_cols;
	}

	vector<int> flip() 
	{
		int r = rand() % count;
		while (blackMap.count(r))r = blackMap[r];
		blackMap[r] = --count;
		return { r / n_cols, r % n_cols };
	}

	void reset()
	{
		count = total;
		blackMap.clear();
	}
};

int main()
{
	return 0;
}