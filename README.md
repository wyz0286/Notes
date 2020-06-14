# Notes
-----------------------------------------

1. Linux/Unix网络编程里面的文件会出现LF、CRLF格式问题，Windows下为CRLF， Linux/Unix为LF

2. xshell 后台运行任务并打印日志文件：```nohup git clone -b refresh-v0.6 --recursive https://github.com/lowrisc/lowrisc-chip.git > /home/yzwang/log.txt 2>&1 &```

3. 
````C++
//使用remove和erase去除字符串中指定字符
string s1;
s1.erase(std::remove(s1.begin(), s1.end(), 'X'), s1.end());
````

4. 
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
5. 
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
	//二叉树的最近公共祖先(236. 二叉树的最近公共祖先)
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
class Solution {
public:
    //判断树B是A的子结构(面试题26.树的子结构)
    bool check(TreeNode* A, TreeNode* B)
    {
        if (!B)return true;
        if (!A)return false;
        if (A->val != B->val)return false;
        else return check(A->left, B->left) && check(A->right, B->right);

    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!B)return false;
        if (!A)return false;
        return check(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};
````
