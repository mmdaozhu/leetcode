/*
解题思路：
    动态规划
    path(i,j) 表示 到达某个格子 (i, j) 不同路径的数量
    path(i,j) = path(i-1,j) + path(i,j-1)
    遇到障碍 path(i,j) = 0
*/

// O(m*n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        std::vector<std::vector<int>> states(m, std::vector<int>(n, 0));
        bool flag = false;
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 1) {
                flag = true;
            }
            states[i][0] = flag ? 0 : 1;
        }
        flag = false;
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[0][j] == 1) {
                flag = true;
            }
            states[0][j] = flag ? 0 : 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    states[i][j] = 0;
                } else {
                    states[i][j] = states[i - 1][j] + states[i][j - 1];
                }
            }
        }

        return states[m-1][n-1];
    }
};

void test1() {
    std::vector<std::vector<int>> obstacleGrid{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    Solution s;
    assert(s.uniquePathsWithObstacles(obstacleGrid) == 2);
}

void test2() {
    std::vector<std::vector<int>> obstacleGrid{{0, 1}, {0, 0}};
    Solution s;
    assert(s.uniquePathsWithObstacles(obstacleGrid) == 1);
}

int main() {
    test1();
    test2();
    return 0;
}