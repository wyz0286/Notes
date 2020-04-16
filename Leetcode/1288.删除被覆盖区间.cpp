//1288.删除被覆盖区间

//给你一个区间列表，请你删除列表中被其他区间所覆盖的区间
//
//只有当 c <= a 且 b <= d 时，我们才认为区间 [a, b) 被区间 [c, d) 覆盖
//
//在完成所有删除操作后，请你返回列表中剩余区间的数目
//
//示例：
//
//输入：intervals = [[1, 4], [3, 6], [2, 8]]
//输出：2
//解释：区间[3, 6] 被区间[2, 8] 覆盖，所以它被删除了


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <random>

using namespace std;

int removeCoveredIntervals(vector<vector<int>>& intervals) {
	vector<vector<int>> merged;
	sort(intervals.begin(), intervals.end(), [](const vector<int>& u, const vector<int>& v) {
		return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]);
		});
	for (int i = 0; i < intervals.size(); i++)
	{
		int L = intervals[i][0];
		int R = intervals[i][1];
		if (merged.size() && merged.back()[0] <= L && merged.back()[1] >= R)continue;
		else merged.push_back({ L, R });
	}
	return merged.size();
}

int main()
{
	vector<vector<int>> a =
	{
		{1,4},
		{3,6},
		{2,8}
	};
	cout << removeCoveredIntervals(a) << endl;
	return 0;
}