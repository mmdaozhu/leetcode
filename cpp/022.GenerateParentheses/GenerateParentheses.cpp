/*
解题思路：
    回溯
*/

// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::string path;
        backtrack(0, 0, n, path);
        return results;
    }

    void backtrack(int left, int right, int n, std::string& path) {
        if (left == n && right == n) {
            results.emplace_back(path);
            return;
        }

        if (left < n) {
            path.push_back('(');
            backtrack(left + 1, right, n, path);
            path.pop_back();
        }

        if (right < left) {
            path.push_back(')');
            backtrack(left, right + 1, n, path);
            path.pop_back();
        }
    }

private:
    std::vector<std::string> results;
};

void test1() {
    std::vector<std::string> results{"((()))", "(()())", "(())()", "()(())", "()()()"};
    auto n = 3;
    Solution s;
    assert(s.generateParenthesis(n) == results);
}

void test2() {
    std::vector<std::string> results{"()"};
    auto n = 1;
    Solution s;
    assert(s.generateParenthesis(n) == results);
}

int main() {
    test1();
    test2();
    return 0;
}
