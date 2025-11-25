/*
解题思路：
        1. 转置
        2. 反转
*/

// O(n*n)
// Runtime Beats 100%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[i][n - 1 - j];
                matrix[i][n - 1 - j] = t;
            }
        }
    }
};

void test1() {
    std::vector<std::vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<int>> results{{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
    Solution s;
    s.rotate(matrix);
    assert(matrix == results);
}

void test2() {
    std::vector<std::vector<int>> matrix{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    std::vector<std::vector<int>> results{{15, 13, 2, 5}, {14, 12, 4, 1}, {16, 10, 8, 9}, {7, 3, 6, 11}};
    Solution s;
    s.rotate(matrix);
    assert(matrix == results);
}

int main() {
    test1();
    test2();
    return 0;
}