//72.编辑距离
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int minDistance(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();

    // 有一个字符串为空串
    if (n * m == 0) return n + m;

    // DP 数组
    vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));

    // 边界状态初始化
    for (int i = 0; i < n + 1; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j < m + 1; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            int a = dp[i - 1][j] + 1;
            int b = dp[i][j - 1] + 1;
            int c = dp[i - 1][j - 1] + 1;
            if (word1[i - 1] == word2[j - 1])//word1的第i个字符   word2的第j个字符
                c--;
            dp[i][j] = min(a, min(b, c));

        }
    }
    return dp[n][m];
}

int main()
{
    cout << minDistance("intention", "execution") << endl;
    cout << minDistance("horse", "ros") << endl;
}