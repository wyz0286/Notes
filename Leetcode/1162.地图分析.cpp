//1162.地图分析
//你现在手里有一份大小为 N x N 的『地图』（网格） grid，上面的每个『区域』（单元格）都用 0 和 1 标记好了。其中 0 代表海洋，1 代表陆地
//
//你知道距离陆地区域最远的海洋区域是是哪一个吗？请返回该海洋区域到离它最近的陆地区域的距离
//
//我们这里说的距离是『曼哈顿距离』（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个区域之间的距离是  | x0 - x1 | +| y0 - y1 | 
//
//如果我们的地图上只有陆地或者海洋，请返回  - 1


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int maxDistance(vector<vector<int>>& grid) {
    const int N = 101;
    const int INF = INT32_MAX;
    int dp[N][N];
    int n = grid.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = grid[i][j] == 1 ? 0 : INF;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j])continue;
            if(i > 0)dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);
            if (j > 0)dp[i][j] = min(dp[i][j - 1] + 1, dp[i][j]);
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (grid[i][j])continue;
            if (i < n - 1)dp[i][j] = min(dp[i + 1][j] + 1, dp[i][j]);
            if (j < n - 1)dp[i][j] = min(dp[i][j + 1] + 1, dp[i][j]);
        }
    }

    int ans = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!grid[i][j]) {
                ans = max(ans, dp[i][j]);
            }
        }
    }

    if (ans == INF) return -1;
    else return ans;
}

int main()
{
    vector<vector<int>> a =
    {
        {1,0,1},
        {0,0,0},
        {1,0,1}
    };
    cout << maxDistance(a) << endl;
    return 0;
}
