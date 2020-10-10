/*
解题思路
a. 左括号 -> push
b. 右括号 ->
        b.1 stack empty: return false
        b.2 stack not empty ->
                                b.2.1 peek: if match, pop
                                b.2.2 peek: not match, return false
c. 扫描完   stack empty: return true
            stack not empty: return false

时间复杂度: O(n)

*/

#include <assert.h>

#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        for (auto c : s) {
            if (isLeftBracket(c)) {
                stack.push(c);
            } else {
                if (stack.empty()) {
                    return false;
                } else {
                    auto top = stack.top();
                    if (!isMatch(top, c)) {
                        return false;
                    } else {
                        stack.pop();
                    }
                }
            }
        }
        return stack.empty();
    }

private:
    bool isLeftBracket(char c) {
        switch (c) {
            case '(':
            case '{':
            case '[':
                return true;
                break;
            default:
                return false;
                break;
        }
        return false;
    }

    bool isMatch(char left, char right) {
        switch (left) {
            case '(':
                return right == ')';
                break;
            case '{':
                return right == '}';
                break;
            case '[':
                return right == ']';
                break;
            default:
                break;
        }
        return false;
    }
};

void test1() {
    Solution s;
    assert(s.isValid("()") == true);
}

void test2() {
    Solution s;
    assert(s.isValid("()[]{}") == true);
}

void test3() {
    Solution s;
    assert(s.isValid("(]") == false);
}

void test4() {
    Solution s;
    assert(s.isValid("([)]") == false);
}

void test5() {
    Solution s;
    assert(s.isValid("{[]}") == true);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}