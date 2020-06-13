//面试题12.矩阵中的路径

//请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径
//路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格
//如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子
//例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径
//
//[["a", "b", "c", "e"],
//["s", "f", "c", "s"],
//["a", "d", "e", "e"]]
//
//但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
//
//示例 1：
//
//输入：board = [["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]], word = "ABCCED"
//输出：true
//
//示例 2：
//
//输入：board = [["a", "b"], ["c", "d"]], word = "abcd"
//输出：false

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> dir = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    bool dfs(vector<vector<char>>& board, vector<vector<int>>& vis, int i, int j, string& word, int idx) {
        vis[i][j] = 1;
        if(idx == word.size()) return true;
        idx++;
        for (auto xy : dir)
        {
            int x = i + xy[0]; 
            int y = j + xy[1];
            if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || vis[x][y] || board[x][y] != word[idx - 1])continue;
            else
            {
                if (dfs(board, vis, x, y, word, idx)) return true;
            }
        }
        vis[i][j] = 0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, vis, i, j, word, 1)) return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}