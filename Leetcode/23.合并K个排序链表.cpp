//23.合并K个排序链表

//合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
//
//示例 :
//
//输入:
//[
//    1->4->5,
//    1->3->4,
//    2->6
//]

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:

    struct cmp
    {
        bool operator ()(ListNode*& a, ListNode*& b)
        {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        ListNode* dummy = new ListNode(0);
        auto q = dummy;
        priority_queue<ListNode*, vector<ListNode*>, cmp>que;
        for (int i = 0; i < len; i++)
        {
            if (lists[i] != NULL)
            {
                que.push(lists[i]);
            }
        }
        while (!que.empty())
        {
            auto p = que.top();
            q->next = p;
            q = q->next;
            if (p->next)que.push(p->next);
            que.pop();
        }
        return dummy->next;
    }
};

int main() {
	return 0;
}
