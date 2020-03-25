//892. 三维形体的表面积
//在 N * N 的网格上，我们放置一些 1 * 1 * 1  的立方体,每个值 v = grid[i][j] 表示 v 个正方体叠放在对应单元格 (i, j) 上,请你返回最终形体的表面积。


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int surfaceArea(vector<vector<int>>& grid) {
    int dr[]{ 0, 1, 0, -1 };
    int dc[]{ 1, 0, -1, 0 };

    int N = grid.size();
    int ans = 0;

    for (int r = 0; r < N; ++r)
        for (int c = 0; c < N; ++c)
            if (grid[r][c] > 0) 
            {
                ans += 2;
                for (int k = 0; k < 4; ++k) 
                {
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    int nv = 0;
                    if (0 <= nr && nr < N && 0 <= nc && nc < N)
                        nv = grid[nr][nc];

                    ans += max(grid[r][c] - nv, 0);
                }
            }
    return ans;
}

int main()
{
    vector<vector<int>> a
    {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };
    cout << surfaceArea(a) << endl;
    return 0;
}