//445.两数相加 II

//给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表
//
//你可以假设除了数字 0 之外，这两个数字都不会以零开头
//
//进阶：
//
//如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转
//
//示例：
//
//输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 8 -> 0 -> 7

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> s1;
    stack<int> s2;
    auto p = l1;
    auto q = l2;
    ListNode* dummy = new ListNode(0);
    while (p)
    {
        s1.push(p->val);
        p = p->next;
    }
    while (q)
    {
        s2.push(q->val);
        q = q->next;
    }
    int cin = 0;
    while (!s1.empty() && !s2.empty())
    {
        int a = s1.top();
        int b = s2.top();
        s1.pop(); s2.pop();
        auto cur = new ListNode((cin + a + b) % 10);
        cur->next = dummy->next;
        dummy->next = cur;
        cin = (a + b + cin) / 10;
    }
    while (!s1.empty())
    {
        int a = s1.top();
        s1.pop();
        auto cur = new ListNode((cin + a) % 10);
        cur->next = dummy->next;
        dummy->next = cur;
        cin = (a + cin) / 10;
    }
    while (!s2.empty())
    {
        int a = s2.top();
        s2.pop();
        auto cur = new ListNode((cin + a) % 10);
        cur->next = dummy->next;
        dummy->next = cur;
        cin = (a + cin) / 10;
    }
    if (cin)
    {
        auto cur = new ListNode(1);
        cur->next = dummy->next;
        dummy->next = cur;
    }
    return dummy->next;
}

int main()
{
    
	return 0;
}