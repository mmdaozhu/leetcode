/*
解题思路：递归

时间复杂度分析：O(2^n)
*/

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        gen(0, 0, n, "");
        return results;
    }

    void gen(int left, int right, int n, const std::string& parenthesis) {
        if (left == n && right == n) {
            results.emplace_back(parenthesis);
            return;
        }

        if (left < n) {
            gen(left + 1, right, n, parenthesis + "(");
        }

        if (right < n && right < left) {
            gen(left, right + 1, n, parenthesis + ")");
        }
    }

private:
    std::vector<std::string> results;
};

void test1() {
    std::vector<std::string> results{"()"};
    auto n = 1;
    Solution s;
    assert(s.generateParenthesis(n) == results);
}

void test2() {
    std::vector<std::string> results{"(())", "()()"};
    auto n = 2;
    Solution s;
    assert(s.generateParenthesis(n) == results);
}

void test3() {
    std::vector<std::string> results{"((()))", "(()())", "(())()", "()(())", "()()()"};
    auto n = 3;
    Solution s;
    assert(s.generateParenthesis(n) == results);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}
