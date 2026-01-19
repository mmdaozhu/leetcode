/*
解题思路：
    动态规划
    path(i,j) 表示 到达某个格子 (i, j) 不同路径的数量
    path(i,j) = path(i-1,j) + path(i,j-1)
*/

// O(m*n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> states(m, std::vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            states[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            states[0][j] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                states[i][j] = states[i - 1][j] + states[i][j - 1];
            }
        }

        return states[m - 1][n - 1];
    }
};

void test1() {
    Solution s;
    assert(s.uniquePaths(3, 7) == 28);
}

void test2() {
    Solution s;
    assert(s.uniquePaths(3, 2) == 3);
}

int main() {
    test1();
    test2();
    return 0;
}