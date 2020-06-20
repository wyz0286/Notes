//面试题35.复制带随机指针的链表

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)  return head;
        //方法1：利用哈希表map：时间复杂度O(n)，空间复杂度O(n)
        /*unordered_map<Node*, Node*>mp;
        Node* t = head;
        while (t != NULL) {
            mp[t] = new Node(t->val);
            t = t->next;
        }
        t = head;
        while (t != NULL) {
            if (t->next) {
                mp[t]->next = mp[t->next];
            }
            if (t->random) {
                mp[t]->random = mp[t->random];
            }
            t = t->next;
        }
        return mp[head];*/

        //方法2：时间复杂度O(n),空间复杂度O(1）
        //以下是至少有一个节点的情况
        //复制节点
        Node* pNode = head;
        while (pNode != nullptr)
        {
            Node* pNext = pNode->next;
            //创建新节点
            Node* newNode = new Node(pNode->val);
            //newNode->val = pNode->val;
            //插入新节点
            pNode->next = newNode;
            newNode->next = pNext;
            pNode = pNext;
        }

        //复制随机指针
        Node* preNode = head;
        while (preNode != nullptr)
        {
            pNode = preNode->next;
            //添加随即指针
            pNode->random = preNode->random == nullptr ? nullptr : preNode->random->next;
            //更新当前处理的节点
            preNode = pNode->next;
        }

        //拆分成两个链表
        preNode = head;
        Node* newHead = preNode->next;
        while (preNode != nullptr)
        {
            pNode = preNode->next;

            preNode->next = pNode->next;
            preNode = preNode->next;

            pNode->next = preNode == nullptr ? nullptr : preNode->next;
        }
        return newHead;
    }
};

int main()
{ 
    return 0;
}