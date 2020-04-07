//面试题 01.07.旋转矩阵
//
//给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度
//
//不占用额外内存空间能否做到？
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//暴力旋转
//void rotate(vector<vector<int>>& matrix) {
//    int n = matrix.size();
//    // C++ 这里的 = 拷贝是值拷贝，会得到一个新的数组
//    auto matrix_new = matrix;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            matrix_new[j][n - i - 1] = matrix[i][j];
//        }
//    }
//    // 这里也是值拷贝
//    matrix = matrix_new;
//}
//原地旋转
//void rotate(vector<vector<int>>& matrix) {
//    int n = matrix.size();
//    for (int i = 0; i < n / 2; ++i) {
//        for (int j = 0; j < (n + 1) / 2; ++j) {
//            int temp = matrix[i][j];
//            matrix[i][j] = matrix[n - j - 1][i];
//            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
//            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
//            matrix[j][n - i - 1] = temp;
//        }
//    }
//}

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // 水平翻转
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n; ++j) {
            swap(matrix[i][j], matrix[n - i - 1][j]);
        }
    }
    // 主对角线翻转
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main()
{
    vector<vector<int>> a{
        { 5, 1, 9, 11},
        { 2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
    };
    rotate(a);
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}