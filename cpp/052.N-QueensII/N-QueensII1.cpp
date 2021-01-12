/*
解体思路：
    深度优先遍历
    判断皇后的攻击范围：
        1. 列 col
        2. 撇 row + col
        3. 捺 row - col

时间复杂度分析：O(n^n)
*/

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int totalNQueens(int n) {
        count = 0;
        if (n == 0) {
            return 0;
        }
        std::vector<int> states;
        DFS(n, 0, states);
        return count;
    }

    void DFS(int n, int row, std::vector<int>& states) {
        if (row == n) {
            count++;
            return;
        }
        for (int col = 0; col < n; col++) {
            bool ok = true;
            for (int i = 0; i < states.size(); i++) {
                if (col == states[i] || row + col == states[i] + i || row - col == i - states[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                states.emplace_back(col);
                DFS(n, row + 1, states);
                states.pop_back();
            }
        }
    }

private:
    int count;
};

void test1() {
    auto count = 2;
    auto n = 4;
    Solution s;
    assert(s.totalNQueens(n) == count);
}

void test2() {
    auto count = 1;
    auto n = 1;
    Solution s;
    assert(s.totalNQueens(n) == count);
}

int main() {
    test1();
    test2();
    return 0;
}