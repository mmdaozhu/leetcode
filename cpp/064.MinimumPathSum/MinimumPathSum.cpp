/*
解题思路：
    动态规划
    states(i,j) 表示 到达某个格子 (i, j) 最小的路径和
    states(i,j) = min(states(i-1,j), states(i,j-1)) + grid[i][j]
*/

// O(m*n)
// Runtime Beats 100.00%

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }

        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> states(m, std::vector<int>(n, 0));

        states[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            states[i][0] = states[i - 1][0] + grid[i][0];
        }

        for (int j = 1; j < n; j++) {
            states[0][j] = states[0][j - 1] + grid[0][j];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                states[i][j] = std::min(states[i - 1][j], states[i][j - 1]) + grid[i][j];
            }
        }

        return states[m - 1][n - 1];
    }
};

void test1() {
    std::vector<std::vector<int>> grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    Solution s;
    assert(s.minPathSum(grid) == 7);
}

void test2() {
    std::vector<std::vector<int>> grid{{1, 2, 3}, {4, 5, 6}};
    Solution s;
    assert(s.minPathSum(grid) == 12);
}

int main() {
    test1();
    test2();
    return 0;
}