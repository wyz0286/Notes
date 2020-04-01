//1111.有效括号的嵌套深度
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> maxDepthAfterSplit(string seq) {
    int d = 0;
    vector<int> ans;
    for (char& c : seq)
        if (c == '(') {
            ++d;
            ans.push_back(d % 2);
        }
        else {
            ans.push_back(d % 2);
            --d;
        }
    return ans;
}

int main()
{
    vector<int> a = maxDepthAfterSplit("()(())()");

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}