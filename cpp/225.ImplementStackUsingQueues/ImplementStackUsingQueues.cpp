/*
解题思路:
    使用两个队列：queue1，queue2
    进栈：  1.queue1空，进queue1，然后就queue2所有元素出队列，进queue1
            2.queue2空，进queue2，然后就queue1所有元素出队列，进queue2
    出栈：  1.queue1不空，出队列
            2.queue2不空，出队列
*/

#include <cassert>
#include <iostream>
#include <queue>

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) {
        if (queue1.empty()) {
            queue1.push(x);
            while (!queue2.empty()) {
                queue1.push(queue2.front());
                queue2.pop();
            }
        } else {
            queue2.push(x);
            while (!queue1.empty()) {
                queue2.push(queue1.front());
                queue1.pop();
            }
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        auto top = 0;
        if (queue1.empty()) {
            top = queue2.front();
            queue2.pop();
        } else {
            top = queue1.front();
            queue1.pop();
        }
        return top;
    }

    /** Get the top element. */
    int top() { return !queue1.empty() ? queue1.front() : queue2.front(); }

    /** Returns whether the stack is empty. */
    bool empty() { return queue1.empty() && queue2.empty(); }

private:
    std::queue<int> queue1;
    std::queue<int> queue2;
};

void test1() {
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    assert(myStack.top() == 2);        // return 2
    assert(myStack.pop() == 2);        // return 2
    assert(myStack.empty() == false);  // return False
}

int main() {
    test1();
    return 0;
}