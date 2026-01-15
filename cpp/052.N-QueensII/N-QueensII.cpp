/*
解题思路：
    深度优先遍历 + 回溯

    判断皇后的攻击范围：
    1. 列 col
    2. 撇 row + col
    3. 捺 row - col
*/

// O(n!)
// Runtime Beats 57.18%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int totalNQueens(int n) {
        std::vector<bool> cols(n, false);
        std::vector<bool> pie(2 * n - 1, false);
        std::vector<bool> na(2 * n - 1, false);
        backtrace(n, 0, cols, pie, na);
        return count;
    }

    void backtrace(int n, int row, std::vector<bool>& cols, std::vector<bool>& pie, std::vector<bool>& na) {
        if (row == n) {
            count++;
        }
        for (int col = 0; col < n; col++) {
            if (cols[col] || pie[row + col] || na[row - col + n - 1]) {
                continue;
            }
            cols[col] = true;
            pie[row + col] = true;
            na[row - col + n - 1] = true;
            backtrace(n, row + 1, cols, pie, na);
            cols[col] = false;
            pie[row + col] = false;
            na[row - col + n - 1] = false;
        }
    }

private:
    int count = 0;
};

void test1() {
    auto n = 4;
    Solution s;
    assert(s.totalNQueens(n) == 2);
}

void test2() {
    auto n = 1;
    Solution s;
    assert(s.totalNQueens(n) == 1);
}

int main() {
    test1();
    test2();
    return 0;
}