//22.括号生成

//给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
//
//例如，给出 n = 3，生成结果为：
//
//{
//    "((()))",
//    "(()())",
//    "(())()",
//    "()(())",
//    "()()()"
//}

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void deal(vector<string>& ans, string& cur, int open, int close, int n)
{
    if (2 * n == cur.length())
    {
        ans.push_back(cur);
        return;
    }
    if (open < n)
    {
        cur += '(';
        deal(ans, cur, open + 1, close, n);
        cur.pop_back();
    }
    if (close < open)
    {
        cur += ')';
        deal(ans, cur, open, close + 1, n);
        //cur.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string cur;
    deal(ans, cur, 0, 0, n);
    return ans;
}

int main()
{
    return 0;
}