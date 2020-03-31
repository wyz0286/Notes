//86.分隔链表
//给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前
//
//你应当保留两个分区中每个节点的初始相对位置
//
//示例 :
//
//输入: head = 1->4->3->2->5->2, x = 3
//输出 : 1->2->2->4->3->5

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {} 
};
 
ListNode* partition(ListNode* head, int x) {
    ListNode* dummy1 = new ListNode(NULL);
    ListNode* p = dummy1;

    ListNode* dummy2 = new ListNode(NULL);
    ListNode* q = dummy2;

    ListNode* r = head;
    while (r)
    {
        if (r->val < x)
        {
            //ListNode* tmp = new ListNode(r->val);
            p->next = r;
            p = r;
        }
        else
        {
            //ListNode* tmp = new ListNode(r->val);
            q->next = r;
            q = r;
        }
        r = r->next;
    }
    q->next = NULL;
    p->next = dummy2->next;
    delete(dummy2);
    return dummy1->next;
}

int main()
{
    vector<int> a{ 1, 1, 2, 4, 4, 4, 4, 4 };
    vector<int> b{ 1, 1, 1, 1, 1, 2, 3, 3 };
    /*cout << majorityElement(a)<< endl;
    cout << majorityElement(b)<< endl;*/
    return 0;
}
