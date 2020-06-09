//面试题29.顺时针打印矩阵

//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
//
//示例 1：
//
//输入：matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
//输出：[1, 2, 3, 6, 9, 8, 7, 4, 5]
//
//示例 2：
//
//输入：matrix = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
//输出：[1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector <int> res;
    if (matrix.empty()) return res;
    int rl = 0, rh = matrix.size() - 1; //记录待打印的矩阵上下边缘
    int cl = 0, ch = matrix[0].size() - 1; //记录待打印的矩阵左右边缘
    while (1) {
        for (int i = cl; i <= ch; i++) res.push_back(matrix[rl][i]);//从左往右
        if (++rl > rh) break; //若超出边界，退出
        for (int i = rl; i <= rh; i++) res.push_back(matrix[i][ch]);//从上往下
        if (--ch < cl) break;
        for (int i = ch; i >= cl; i--) res.push_back(matrix[rh][i]);//从右往左
        if (--rh < rl) break;
        for (int i = rh; i >= rl; i--) res.push_back(matrix[i][cl]);//从下往上
        if (++cl > ch) break;
    }
    return res;
}

int main()
{
    vector<vector<int>> matrix = 
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
    };
    vector<vector<int>> matrix1 =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    auto rst = spiralOrder(matrix);
    for (int i = 0; i < rst.size(); i++)
    {
        cout << rst[i] << " ";
    }
    cout << endl;
    auto rst1 = spiralOrder(matrix1);
    for (int i = 0; i < rst1.size(); i++)
    {
        cout << rst1[i] << " ";
    }
    return 0;
}