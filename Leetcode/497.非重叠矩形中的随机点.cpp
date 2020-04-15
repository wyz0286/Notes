//497.非重叠矩形中的随机点
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <random>

using namespace std;

class Solution {
    vector<vector<int>> a;
    vector<int> s;
    int sum;
public:
    Solution(vector<vector<int>>& rects):sum(0),a(rects){
        for (int i = 0; i < rects.size(); i++)
        {
            int x1 = rects[i][0];
            int y1 = rects[i][1];
            int x2 = rects[i][2];
            int y2 = rects[i][3];
            sum += (x2 - x1 + 1) * (y2 - y1 + 1);
            s.push_back(sum);
        }
    }

    vector<int> pick() {
        int r = rand() % sum + 1;
        int i = lower_bound(s.begin(), s.end(), r) - s.begin();
        int ans;
        if (i == 0)ans = r - 1;
        else ans = r - s[i - 1] - 1;
        int x1 = a[i][0];
        int y1 = a[i][1];
        int x2 = a[i][2];
        int y2 = a[i][3];
        return { x1 + ans % (x2 - x1 + 1),y1 + ans / (x2 - x1 + 1) };
    }
};

int main()
{
	return 0;
}