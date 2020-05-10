# Notes
-----------------------------------------

1. Linux/Unix网络编程里面的文件会出现LF、CRLF格式问题，Windows下为CRLF， Linux/Unix为LF；

2. 
````C++
//使用remove和erase去除字符串中指定字符
string s1;
s1.erase(std::remove(s1.begin(), s1.end(), 'X'), s1.end());
````

3. 
````C++
//完美转发
void f(int v1, int& v2)
{
	std::cout << v1 << " " << ++v2 << std::endl;
}

void g(int&& v1, int& v2)
{
	std::cout << v1 << " " << ++v2 << std::endl;
}

template <typename F, typename T1, typename T2>
void flip(F f, T1&& t1, T2&& t2)
{
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}

int main()
{
	int j = 0;
	flip(f, j, 42);
	flip(g, j, 42);
}
//output
//42 1
//42 2
````
4. 
````C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	//二叉树的最近公共祖先
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        if(root == p || root == q) 
            return root;
            
        TreeNode* left =  lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
       
        if(left == NULL)
            return right;
        if(right == NULL)
            return left;      
        if(left && right) // p和q在两侧
            return root;
        
        return NULL; // 必须有返回值
    }
};
````
