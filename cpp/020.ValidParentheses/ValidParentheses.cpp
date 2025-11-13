// O(n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <map>
#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::map<char, char> map{{'(', ')'}, {'{', '}'}, {'[', ']'}};

        std::stack<char> stack;
        for (const auto& c : s) {
            if (map.find(c) != map.end()) {
                stack.push(c);
            } else {
                if (stack.empty()) {
                    return false;
                }
                auto top = stack.top();
                if (map[top] != c) {
                    return false;
                }

                stack.pop();
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