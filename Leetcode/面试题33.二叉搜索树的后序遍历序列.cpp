//面试题33.二叉搜索树的后序遍历序列

//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果
//
//如果是则返回 true，否则返回 false
//
//假设输入的数组的任意两个数字都互不相同

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

bool verifyPostorder(vector<int>& postorder) {
    // 单调栈使用，单调递增的单调栈
    stack<int> s;
    int pervElem = INT32_MAX;
    // 逆向遍历，就是翻转的先序遍历
    for (int i = postorder.size() - 1; i >= 0; i--) {
        // 左子树元素必须要小于递增栈被peek访问的元素，否则就不是二叉搜索树
        if (postorder[i] > pervElem) {
            return false;
        }
        while (!s.empty() && postorder[i] < s.top()) {
            // 数组元素小于单调栈的元素了，表示往左子树走了，记录下上个根节点
            // 找到这个左子树对应的根节点，之前右子树全部弹出，不再记录，因为不可能在往根节点的右子树走了
            pervElem = s.top();
            s.pop();
        }
        // 这个新元素入栈
        s.push(postorder[i]);
    }
    return true;
}

int main()
{ 
    vector<int> v{ 1,3,2,6,5 };
    cout << verifyPostorder(v) << endl;
    return 0;
}