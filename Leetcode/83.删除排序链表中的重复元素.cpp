//83.删除排序链表中的重复元素
//给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
//
//示例 1 :
//
//输入: 1->1->2
//输出 : 1->2
//示例 2 :
//
//    输入 : 1->1->2->3->3
//    输出 : 1->2->3


#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {} 
};
 
ListNode* deleteDuplicates(ListNode* head) {
    unordered_set<int> a;
    if (head == NULL)return NULL;
    ListNode* dummy = new ListNode(NULL);
    dummy->next = head;
    auto cur = head;
    auto pre = dummy;
    while (cur != NULL)
    {
        if (a.find(cur->val) != a.end())
        {
            a.insert(cur->val);
            cur = cur->next;
            pre = pre->next;      
        }
        else
        {
            pre->next = cur->next;
            cur = pre->next;
        }
    }
    return dummy->next;
}


int main()
{
    vector<int> a{ 1, 1, 2, 4, 4, 4, 4, 4 };
    vector<int> b{ 1, 1, 1, 1, 1, 2, 3, 3 };
    /*cout << majorityElement(a)<< endl;
    cout << majorityElement(b)<< endl;*/
    return 0;
}