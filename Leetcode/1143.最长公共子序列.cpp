//1143.最长公共子序列
//给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列
//
//一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串
//例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列
//
//若这两个字符串没有公共子序列，则返回 0。
//
//示例 1:
//
//输入：text1 = "abcde", text2 = "ace"
//输出：3
//解释：最长公共子序列是 "ace"，它的长度为 3

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int len1 = text1.length();
    int len2 = text2.length();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 1; i < len1 + 1; i++) 
    {
        for (int j = 1; j < len2 + 1; j++) 
        {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[len1][len2];
}


int main()
{
    cout << longestCommonSubsequence("abcde", "ace") << endl;
    return 0;
}
