//232.用栈实现队列
//使用栈实现队列的下列操作：
//
//push(x) --将一个元素放入队列的尾部
//pop() --从队列首部移除元素
//peek() --返回队列首部的元素
//empty() --返回队列是否为空

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

class MyQueue {
    int size;
    stack<int> a;
    stack<int> b;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        size = 0;
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        a.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (b.empty())
        {
            while (!a.empty())
            {
                b.push(a.top());
                a.pop();
            }
        }
        int rst = b.top();
        b.pop();
         return rst;
    }

    /** Get the front element. */
    int peek() {
        if (b.empty())
        {
            while (!a.empty())
            {
                b.push(a.top());
                a.pop();
            }
        }
        return b.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return a.empty() && b.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


int main()
{
    cout << endl;
    return 0;
}
