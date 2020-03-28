//21.合并两个有序链表
//将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
//
//示例：
//
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4


#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {} 
};
 
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* p, * q;
    p = l1;
    q = l2;
    ListNode* dummy = new ListNode(NULL);
    ListNode* head=dummy;
    while (p && q)
    {
        if (p->val < q->val)
        {
            head->next = p;
            p = p->next;
        }
        else
        {
            head->next = q;
            q = q->next;
        }
        head = head->next;
    }
    if (p)
        head->next = p;
    else
        head->next = q;
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
