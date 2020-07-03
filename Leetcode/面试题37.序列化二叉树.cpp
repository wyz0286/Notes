#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        dfs(root, ret);
        return ret;
    }

    void dfs(TreeNode* root, string& ret) {
        if (root == nullptr) {
            ret.append("#,");
            return;
        }

        ret.append(to_string(root->val)).append(",");
        dfs(root->left, ret);
        dfs(root->right, ret);

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return rdfs(data, i);
    }

    TreeNode* rdfs(const string& data, int& i) {
        if (data[i] == '#') {
            i += 2;
            return nullptr;
        }

        int next = i;
        while (data[next] != ',')
            next++;
        int val = stoi(data.substr(i, next - i));
        auto ret = new TreeNode(val);
        i = next + 1;

        ret->left = rdfs(data, i);
        ret->right = rdfs(data, i);

        return ret;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


int main()
{
    return 0;
}

