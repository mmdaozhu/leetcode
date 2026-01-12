// O(n)
// Runtime Beats 100.00%

#include <algorithm>
#include <cassert>
#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        std::stack<int> stack;
        stack.push(-1);
        int max = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);
                } else {
                    max = std::max(max, i - stack.top());
                }
            }
        }

        return max;
    }
};

void test1() {
    std::string s = "(()";
    Solution solution;
    assert(solution.longestValidParentheses(s) == 2);
}

void test2() {
    std::string s = ")()())";
    Solution solution;
    assert(solution.longestValidParentheses(s) == 4);
}

void test3() {
    std::string s = "";
    Solution solution;
    assert(solution.longestValidParentheses(s) == 0);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}