// O(n)
// Runtime Beats 45.41%

#include <cassert>
#include <iostream>
#include <stack>

class MinStack {
public:
    MinStack() {}

    void push(int value) {
        data.push(value);

        if (mins.empty() || value <= mins.top()) {
            mins.push(value);
        }
    }

    void pop() {
        if (data.top() == mins.top()) {
            mins.pop();
        }

        data.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return mins.top();
    }

private:
    std::stack<int> data;
    std::stack<int> mins;
};

void test1() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    assert(minStack.getMin() == -3);
    minStack.pop();
    assert(minStack.top() == 0);
    assert(minStack.getMin() == -2);
}

int main() {
    test1();
    return 0;
}