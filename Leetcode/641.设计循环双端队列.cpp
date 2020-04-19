#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

//循环双端队列
class MyCircularDeque {
    vector<int> arr;
    int front;
    int rear;
    int capacity;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) :arr(k + 1, 0) {
        capacity = k + 1;
        front = 0;
        rear = 0;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        front = (front - 1 + capacity) % capacity;
        arr[front] = value;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        arr[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        rear = (rear - 1 + capacity) % capacity;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return arr[(rear - 1 + capacity) % capacity];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return rear == front;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return front == (rear + 1) % capacity;
    }
};

//循环队列
class MyCircularQueue {
    vector<int> arr;
    int front;
    int rear;
    int capacity;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        arr.resize(k + 1);
        capacity = k + 1;
        front = rear = 0;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        arr[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front= (front + 1) % capacity;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return arr[(rear - 1 + capacity) % capacity];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return front == rear;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return front == (rear + 1) % capacity;
    }
};

int main()
{
	return 0;
}