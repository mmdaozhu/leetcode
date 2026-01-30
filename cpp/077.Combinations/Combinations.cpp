/*
解题思路：
    回溯
*/

// O(C(n, k)*k)
// Runtime Beats 23.44%

#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<int> path;
        backtrace(n, k, 1, path);

        return results;
    }

    void backtrace(int n, int k, int start, std::vector<int>& path) {
        if (path.size() == k) {
            results.push_back(path);
            return;
        }

        for (int i = start; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            backtrace(n, k, i + 1, path);
            path.pop_back();
        }
    }

private:
    std::vector<std::vector<int>> results;
};

void test1() {
    std::vector<std::vector<int>> result{{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};
    Solution s;
    assert(s.combine(4, 2) == result);
}

void test2() {
    std::vector<std::vector<int>> result{{1}};
    Solution s;
    assert(s.combine(1, 1) == result);
}

int main() {
    test1();
    test2();
    return 0;
}