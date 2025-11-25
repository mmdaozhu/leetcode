#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

/*
解题思路：
    动态规划。
    动态规划方程：min_dist(i, j) = w[i][j] + min(min_dist(i, j-1), min_dist(i-1, j))

时间复杂度分析：O(n*m)
*/

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int line = grid.size();
        if (line == 0) {
            return 0;
        }

        int colume = grid[0].size();
        if (colume == 0) {
            return 0;
        }
        std::vector<std::vector<int>> states;
        for (int i = 0; i < line; i++) {
            std::vector<int> t(colume, 0);
            states.emplace_back(t);
        }

        states[0][0] = grid[0][0];
        for (int i = 1; i < colume; i++) {
            states[0][i] = states[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < line; i++) {
            states[i][0] = states[i - 1][0] + grid[i][0];
        }

        for (int i = 1; i < line; i++) {
            for (int j = 1; j < colume; j++) {
                states[i][j] = std::min(states[i - 1][j], states[i][j - 1]) + grid[i][j];
            }
        }
        return states[line - 1][colume - 1];
    }
};

void test1() {
    std::vector<std::vector<int>> grid;
    std::vector<int> line1{1, 3, 1};
    std::vector<int> line2{1, 5, 1};
    std::vector<int> line3{4, 2, 1};
    grid.emplace_back(line1);
    grid.emplace_back(line2);
    grid.emplace_back(line3);

    Solution s;
    assert(s.minPathSum(grid) == 7);
}

void test2() {
    std::vector<std::vector<int>> grid;
    std::vector<int> line1{1, 2, 3};
    std::vector<int> line2{4, 5, 6};
    grid.emplace_back(line1);
    grid.emplace_back(line2);

    Solution s;
    assert(s.minPathSum(grid) == 12);
}

int main() {
    test1();
    test2();
    return 0;
}