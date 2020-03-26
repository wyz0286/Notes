//20. 有效的括号
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//
//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串。


#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

bool isValid(string s) {
    int len = s.length();
    stack<char> a;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[')
        {
            a.push(s[i]);
            continue;
        }
        else if (s[i] == '}')
        {
            if (a.empty())return false;
            if (a.top() != '{')return false;
            a.pop();
        }
        else if (s[i] == ')')
        {
            if (a.empty())return false;
            if (a.top() != '(')return false;
            a.pop();
        }
        else if (s[i] == ']')
        {
            if (a.empty())return false;
            if (a.top() != '[')return false;
            a.pop();
        }
    }
    if (a.empty())return true;
    else return false;
}

int main()
{
    cout << isValid("()))")<< endl;
    cout << isValid("([)]") << endl;
    return 0;
}