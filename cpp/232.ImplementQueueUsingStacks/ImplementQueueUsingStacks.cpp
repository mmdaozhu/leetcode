/*
解题思路:
    使用两个栈：输入栈和输出栈
    进队列：输入栈进栈
    出队列：1. 输出栈不为空，则输出栈出栈。
            2. 输出栈为空，将输入栈出栈的所有元素进输出栈，最后输出栈出栈。
*/

#include <cassert>
#include <iostream>
#include <stack>

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) { input.push(x); }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (empty()) {
            return -1;
        }

        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        auto res = output.top();
        output.pop();
        return res;
    }

    /** Get the front element. */
    int peek() {
        if (empty()) {
            return -1;
        }

        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() { return input.empty() && output.empty(); }

private:
    std::stack<int> input;
    std::stack<int> output;
};

void test1() {
    MyQueue myQueue;
    myQueue.push(1);                   // queue is: [1]
    myQueue.push(2);                   // queue is: [1, 2] (leftmost is front of the queue)
    assert(myQueue.peek() == 1);       // return 1
    assert(myQueue.pop() == 1);        // return 1, queue is [2]
    assert(myQueue.empty() == false);  // return false
}

int main() {
    test1();
    return 0;
}