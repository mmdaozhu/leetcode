/*
解题思路：
    深度优先遍历 + 回溯

    判断皇后的攻击范围：
    1. 列 col
    2. 撇 row + col
    3. 捺 row - col
*/

// O(n!)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::string s(n, '.');
        std::vector<std::string> ans(n, s);

        std::vector<bool> cols(n, false);
        std::vector<bool> pie(2 * n - 1, false);
        std::vector<bool> na(2 * n - 1, false);
        backtrace(n, 0, ans, cols, pie, na);
        return results;
    }

    void backtrace(int n, int row, std::vector<std::string>& ans, std::vector<bool>& cols, std::vector<bool>& pie,
                   std::vector<bool>& na) {
        if (row == n) {
            results.push_back(ans);
        }
        for (int col = 0; col < n; col++) {
            if (cols[col] || pie[row + col] || na[row - col + n - 1]) {
                continue;
            }
            ans[row][col] = 'Q';
            cols[col] = true;
            pie[row + col] = true;
            na[row - col + n - 1] = true;
            backtrace(n, row + 1, ans, cols, pie, na);

            ans[row][col] = '.';
            cols[col] = false;
            pie[row + col] = false;
            na[row - col + n - 1] = false;
        }
    }

private:
    std::vector<std::vector<std::string>> results;
};

void test1() {
    std::vector<std::vector<std::string>> results{{".Q..", "...Q", "Q...", "..Q."}, {"..Q.", "Q...", "...Q", ".Q.."}};
    auto n = 4;
    Solution s;
    assert(s.solveNQueens(n) == results);
}

void test2() {
    std::vector<std::vector<std::string>> results{{"Q"}};
    auto n = 1;
    Solution s;
    assert(s.solveNQueens(n) == results);
}

int main() {
    test1();
    test2();
    return 0;
}