//200.岛屿数量
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

//深度优先搜索
//void dfs(vector<vector<char>>& grid, int i, int j)
//{
//	int r = grid.size();
//	int c = grid[0].size();
//
//	grid[i][j] = '0';
//	for (int k = 0; k < 4; k++)
//	{
//		int x = i + dx[k];
//		int y = j + dy[k];
//		if (x < 0 || x >= r || y < 0 || y >= c)continue;
//		else if (grid[x][y] == '1')dfs(grid, x, y);
//	}
//}
//
//int numIslands(vector<vector<char>>& grid) {
//	int r = grid.size();
//	if (!r)return 0;
//	int c = grid[0].size();
//	
//	int ans = 0;
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			if (grid[i][j] == '1')
//			{
//				++ans;
//				dfs(grid, i, j);
//			}
//		}
//	}
//	return ans;
//}

//广度优先搜索
//int numIslands(vector<vector<char>>& grid) {
//	int r = grid.size();
//	if (!r) return 0;
//	int c = grid[0].size();
//
//	int ans = 0;
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			if (grid[i][j] == '1')
//			{
//				queue<pair<int, int>>q;
//				++ans;
//				grid[i][j] = '0';
//				q.push({ i,j });
//				while (!q.empty())
//				{
//					auto rc = q.front();
//					q.pop();
//					int a = rc.first;
//					int b = rc.second;
//					for (int k = 0; k < 4; k++)
//					{
//						int x = a + dx[k];
//						int y = b + dy[k];
//						if (x < 0 || x >= r || y < 0 || y >= c)continue;
//						else if (grid[x][y] == '1')
//						{
//							grid[x][y] = '0';
//							q.push({ x,y });
//						}
//					}
//				}
//			}
//		}
//	}
//	return ans;
//}

//并查集
class UnionFind {
public:
    UnionFind(vector<vector<char>>& grid) {
        count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * n + j);
                    ++count;
                }
                else {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }

    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
            --count;
        }
    }

    int getCount() const {
        return count;
    }

private:
    vector<int> parent;
    vector<int> rank;//使并查集树的左右子树的深度差尽可能小https://segmentfault.com/a/1190000004023326
    int count;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        UnionFind uf(grid);
        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    grid[r][c] = '0';
                    if (r - 1 >= 0 && grid[r - 1][c] == '1') uf.unite(r * nc + c, (r - 1) * nc + c);
                    if (r + 1 < nr && grid[r + 1][c] == '1') uf.unite(r * nc + c, (r + 1) * nc + c);
                    if (c - 1 >= 0 && grid[r][c - 1] == '1') uf.unite(r * nc + c, r * nc + c - 1);
                    if (c + 1 < nc && grid[r][c + 1] == '1') uf.unite(r * nc + c, r * nc + c + 1);
                }
            }
        }

        return uf.getCount();
    }
};

int main() {
	vector<vector<char>> a =
	{
		{'1','1','1','1','0'},
		{'1','1','0','1','0'},
		{'1','1','0','0','0'},
		{'0','0','0','0','0'}
	};
	//cout << numIslands(a) << endl;
	return 0;
}
