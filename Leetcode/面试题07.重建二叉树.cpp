//面试题07.重建二叉树

//输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, 0, inorder.size() - 1);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int root, int start, int end) {// 中序的start和end
        if (start > end) return NULL;
        TreeNode* tree = new TreeNode(preorder[root]);
        int i = start;
        while (i < end && preorder[root] != inorder[i]) i++;
        tree->left = build(preorder, inorder, root + 1, start, i - 1);
        tree->right = build(preorder, inorder, root + 1 + i - start, i + 1, end);
        return tree;
    }
};

int main()
{
	vector<int> vec{ -2,1,-3,4,-1,2,1,-5,4 };
    return 0;
}