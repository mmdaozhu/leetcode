/*
解体思路：
    利用堆栈来求表达式

时间复杂度分析：O(n)
*/

#include <cassert>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> ss;
        for (auto token : tokens) {
            if (isOperator(token)) {
                auto b = ss.top();
                ss.pop();
                auto a = ss.top();
                ss.pop();
                if (token == "+") {
                    ss.push(a + b);
                } else if (token == "-") {
                    ss.push(a - b);
                } else if (token == "*") {
                    ss.push(a * b);
                } else {
                    ss.push(a / b);
                }
            } else {
                ss.push(stoi(token));
            }
        }
        return ss.top();
    }

    bool isOperator(const std::string& op) {
        if (op == "+" || op == "-" || op == "*" || op == "/") {
            return true;
        } else {
            return false;
        }
    }
};

void test1() {
    std::vector<std::string> vs{"2", "1", "+", "3", "*"};
    Solution s;
    assert(s.evalRPN(vs) == 9);
}

void test2() {
    std::vector<std::string> vs{"4", "13", "5", "/", "+"};
    Solution s;
    assert(s.evalRPN(vs) == 6);
}

void test3() {
    std::vector<std::string> vs{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    Solution s;
    assert(s.evalRPN(vs) == 22);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}