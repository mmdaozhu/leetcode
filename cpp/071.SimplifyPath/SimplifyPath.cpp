// O(n)
// Runtime Beats 29.51%

#include <cassert>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::stack<std::string> stack;
        std::string result;

        std::string cur;
        std::stringstream ss(path);
        while (getline(ss, cur, '/')) {
            if (cur.empty() || cur == ".") {
                continue;
            } else if (cur == "..") {
                if (!stack.empty()) {
                    stack.pop();
                }
            } else {
                stack.push(cur);
            }
        }

        if (stack.empty()) {
            return "/";
        }

        while (!stack.empty()) {
            auto top = stack.top();
            stack.pop();
            result = "/" + top + result;
        }
        return result;
    }
};

void test1() {
    std::string path = "/home/";
    Solution s;
    assert(s.simplifyPath(path) == "/home");
}

void test2() {
    std::string path = "/home/foo/";
    Solution s;
    assert(s.simplifyPath(path) == "/home/foo");
}

void test3() {
    std::string path = "/home/user/Documents/../Pictures";
    Solution s;
    assert(s.simplifyPath(path) == "/home/user/Pictures");
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}