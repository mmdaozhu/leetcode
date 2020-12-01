/*
解题思路
a.  左括号 -> push
b.  右括号 ->
        b.1 stack empty: return false
        b.2 stack not empty ->
                                b.2.1 peek: if match, pop
                                b.2.2 peek: not match, return false
c.  扫描完  return stack.empty()

时间复杂度: O(n)
*/

#include <cassert>
#include <iostream>
#include <map>
#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::map<char, char> map;
        map[')'] = '(';
        map[']'] = '[';
        map['}'] = '{';

        std::stack<char> stack;
        for (const auto& c : s) {
            if (map.find(c) == map.end()) {
                stack.push(c);
            } else {
                if (stack.empty()) {
                    return false;
                } else {
                    if (map[c] != stack.top()) {
                        return false;
                    } else {
                        stack.pop();
                    }
                }
            }
        }
        return stack.empty();
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