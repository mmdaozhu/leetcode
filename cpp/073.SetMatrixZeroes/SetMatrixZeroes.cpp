/*
解题思路：
    原地算法
*/

// O(m*n)
// Runtime Beats 100%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool first_row_has_zero = false;
        bool first_col_has_zero = false;

        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                first_row_has_zero = true;
                break;
            }
        }
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                first_col_has_zero = true;
                break;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (first_row_has_zero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        if (first_col_has_zero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

void test1() {
    std::vector<std::vector<int>> matrix{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    std::vector<std::vector<int>> results{{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    Solution s;
    s.setZeroes(matrix);
    assert(matrix == results);
}

void test2() {
    std::vector<std::vector<int>> matrix{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    std::vector<std::vector<int>> results{{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};
    Solution s;
    s.setZeroes(matrix);
    assert(matrix == results);
}

int main() {
    test1();
    test2();
    return 0;
}