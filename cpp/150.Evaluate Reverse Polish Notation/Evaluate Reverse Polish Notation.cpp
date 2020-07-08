/*
解体思路：
    利用堆栈来求表达式

时间复杂度分析：O(n)
*/

#include <assert.h>

#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> ss;
        for (auto iter : tokens) {
            if (isOperator(iter)) {
                int b = ss.top();
                ss.pop();
                int a = ss.top();
                ss.pop();
                if (iter == "+") {
                    ss.push(a + b);
                } else if (iter == "-") {
                    ss.push(a - b);
                } else if (iter == "*") {
                    ss.push(a * b);
                } else {
                    ss.push(a / b);
                }
            } else {
                ss.push(stoi(iter));
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
    std::vector<std::string> vs;
    vs.push_back("2");
    vs.push_back("1");
    vs.push_back("+");
    vs.push_back("3");
    vs.push_back("*");
    Solution s;
    assert(s.evalRPN(vs) == 9);
}

void test2() {
    std::vector<std::string> vs;
    vs.push_back("4");
    vs.push_back("13");
    vs.push_back("5");
    vs.push_back("/");
    vs.push_back("+");
    Solution s;
    assert(s.evalRPN(vs) == 6);
}

void test3() {
    std::vector<std::string> vs;
    vs.push_back("10");
    vs.push_back("6");
    vs.push_back("9");
    vs.push_back("3");
    vs.push_back("+");
    vs.push_back("-11");
    vs.push_back("*");
    vs.push_back("/");
    vs.push_back("*");
    vs.push_back("17");
    vs.push_back("+");
    vs.push_back("5");
    vs.push_back("+");
    Solution s;
    assert(s.evalRPN(vs) == 22);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}