//1382.将二叉搜索树变平衡

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
    vector<TreeNode*> arr;
public:
    TreeNode* balanceBST(TreeNode* root) { 
        InOrder(root);
        return construct(0, arr.size() - 1);
    }

    void InOrder(TreeNode* root) {
        if (root)
        {
            InOrder(root->left);
            arr.push_back(root);
            InOrder(root->right);
        }
    }

    TreeNode* construct(int left, int right) {
        if (left > right) return NULL;
        int mid = (left + right) / 2;
        arr[mid]->left = construct(left, mid - 1);
        arr[mid]->right = construct(mid + 1, right);
        return arr[mid];
    }
};

int main()
{
	return 0;
}