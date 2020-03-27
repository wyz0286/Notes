//225.用队列实现栈
//使用队列实现栈的下列操作
//
//push(x) --元素 x 入栈
//pop() --移除栈顶元素
//top() --获取栈顶元素
//empty() --返回栈是否为空

#include <iostream>
#include <queue>

using namespace std;

class MyStack {
    queue<int> a;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        int n = a.size();
        a.push(x);
        for (int i = 0; i < n; i++) {
            a.push(a.front());
            a.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int rst = a.front();
        a.pop();
        return rst;
    }

    /** Get the top element. */
    int top() {
        return a.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return a.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


int main()
{
    cout << endl;
    return 0;
}
