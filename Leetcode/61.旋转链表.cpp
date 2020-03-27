//61.旋转链表
//示例 1:
//
//输入: 1->2->3->4->5->NULL, k = 2
//输出 : 4->5->1->2->3->NULL
//解释 :
//向右旋转 1 步 : 5->1->2->3->4->NULL
//向右旋转 2 步 : 4->5->1->2->3->NULL
//示例 2 :
//
//输入: 0->1->2->NULL, k = 4
//输出 : 2->0->1->NULL
//解释 :
//向右旋转 1 步 : 2->0->1->NULL
//向右旋转 2 步 : 1->2->0->NULL
//向右旋转 3 步 : 0->1->2->NULL
//向右旋转 4 步 : 2->0->1->NULL


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
 
ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL)return head;

    ListNode* dummy = new ListNode(NULL);
    ListNode* slow, * fast, * pre;

    dummy->next = head;   
    slow = fast = dummy;
    //先求链表长度(k可能大于链表长度)
    int len = -1;
    while (fast != NULL)
    {
        len++;
        fast = fast->next;
    }
    fast = dummy;
    for (int i = 0; i < k % len; i++)
    {
        fast = fast->next;
    }
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = dummy->next;
    pre = slow;
    slow = slow->next;
    pre->next = NULL;
    dummy->next = slow;
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