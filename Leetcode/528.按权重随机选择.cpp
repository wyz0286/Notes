//528.按权重随机选择

//给定一个正整数数组 w ，其中 w[i] 代表位置 i 的权重，请写一个函数 pickIndex ，它可以随机地获取位置 i，选取位置 i 的概率与 w[i] 成正比

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> s;
    int hi;
    Solution(vector<int>& w) {
        s = w;
        for (int i = 1; i < s.size(); ++i) {
            s[i] += s[i - 1];
        }
        hi = s.back();
    }

    int pickIndex() {
        int r = rand() % hi + 1;
        return lower_bound(s.begin(), s.end(), r) - s.begin();
        /*int r = rand() % hi;
        return upper_bound(s.begin(), s.end(), r) - s.begin();*/
    }
};

int main()
{
    vector<int> a{ 1,2,3 };
    Solution s(a);
    cout << s.pickIndex() << endl;
	return 0;
}