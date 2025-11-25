// O(m*n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> results;
        int m = matrix.size();
        int n = matrix[0].size();

        std::vector<int> tmp(n, 0);
        std::vector<std::vector<int>> used(m, tmp);

        int i = 0, j = -1;
        int count = 0;
        while (count < m * n) {
            // right
            while (j < n - 1 && !used[i][j + 1]) {
                results.emplace_back(matrix[i][++j]);
                used[i][j] = 1;
                count++;
            }

            // bottom
            while (i < m - 1 && !used[i + 1][j]) {
                results.emplace_back(matrix[++i][j]);
                used[i][j] = 1;
                count++;
            }

            // left
            while (j > 0 && !used[i][j - 1]) {
                results.emplace_back(matrix[i][--j]);
                used[i][j] = 1;
                count++;
            }

            // up
            while (i > 0 && !used[i - 1][j]) {
                results.emplace_back(matrix[--i][j]);
                used[i][j] = 1;
                count++;
            }
        }
        return results;
    }
};

void test1() {
    std::vector<std::vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution s;
    std::vector<int> result{1, 2, 3, 6, 9, 8, 7, 4, 5};
    assert((result == s.spiralOrder(matrix)));
}

void test2() {
    std::vector<std::vector<int>> matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    Solution s;
    std::vector<int> result{1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
    assert((result == s.spiralOrder(matrix)));
}

int main() {
    test1();
    test2();
    return 0;
}