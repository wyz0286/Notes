//199.二叉树的右视图

//给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值
//示例 :
//输入: [1, 2, 3, null, 5, null, 4]
//输出 : [1, 3, 4]
//解释 :
//
//    1 < -- -
//    / \
//    2     3 < -- -
//    \     \
//    5     4 < -- -

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int len = que.size();
            for (int i = 0; i < len; i++) {
                auto q = que.front();
                que.pop();
                if (i == len - 1) {
                    ans.push_back(q->val);
                }
                if (q->left != nullptr) {
                    que.push(q->left);
                }
                if (q->right != nullptr) {
                    que.push(q->right);
                }
            }
        }
        return ans;
    }
};

int main() {
	return 0;
}
