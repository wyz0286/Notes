//687.最长同值路径

//给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点
//
//注意：两个节点之间的路径长度由它们之间的边数表示
//
//示例 1:
//输入:
//5
/// \
//4   5
/// \   \
//1   1   5
//输出:
//2
//
//示例 2 :
//输入 :
//
//    1
//    / \
//    4   5
//    / \   \
//    4   4   5
//输出:
//2

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
    int ans = 0;
    int longestUnivaluePath(TreeNode* root) 
    {
        arrowLength(root);
        return ans;
    }
    //返回一端为node节点的左/右子树最长的路径值
    int arrowLength(TreeNode* node) 
    {
        if (!node) return 0;
        int left = arrowLength(node->left);
        int right = arrowLength(node->right);
        int arrowLeft = 0, arrowRight = 0;
        if (node->left && node->left->val == node->val)
        {
            arrowLeft += left + 1;
        }
        if (node->right && node->right->val == node->val)
        {
            arrowRight += right + 1;
        }
        //由于是边的数量所以不用-1
        ans = max(ans, arrowLeft + arrowRight);
        return max(arrowLeft, arrowRight);
    }
};

int main()
{
    return 0;
}