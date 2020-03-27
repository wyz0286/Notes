//24.两两交换链表中的节点
//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表
//
//你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换
//
//示例:
//
//给定 1->2->3->4, 你应该返回 2->1->4->3.


#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {} 
};
 
//递归
ListNode* swapPairs(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode *next = head->next;
    head->next = swapPairs(next->next);
    next->next = head;
    return next;
}

//非递归
ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode(0);//头结点方便操作
    dummy->next = head;
    ListNode* pre = dummy;
    ListNode* cur, * next;
    while (pre->next != NULL && pre->next->next != NULL)
    {
        cur = pre->next;
        next = pre->next->next;
        pre->next = next;
        cur->next = next->next;
        next->next = cur;
        pre = pre->next->next;
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