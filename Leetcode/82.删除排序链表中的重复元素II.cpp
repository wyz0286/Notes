//82->删除排序链表中的重复元素 II
//给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
//
//示例 1 :
//
//输入: 1->2->3->3->4->4->5
//输出 : 1->2->5
//示例 2 :
//
//    输入 : 1->1->1->2->3
//    输出 : 2->3


#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {} 
};
 
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummy = new ListNode(NULL);
    dummy->next = head;
    ListNode* cur = dummy;
    while (cur->next != NULL && cur->next->next != NULL) {
        if (cur->next->val == cur->next->next->val) {
            ListNode* temp = cur->next;
            while (temp != NULL && temp->next != NULL && temp->val == temp->next->val) {
                temp = temp->next;
            }
            cur->next = temp->next;
        }
        else
            cur = cur->next;
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