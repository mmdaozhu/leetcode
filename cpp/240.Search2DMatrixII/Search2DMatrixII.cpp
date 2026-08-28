/*
解题思路：
    右上角搜索法
*/

// O(m+n)
// Runtime Beats 100%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0;
        int col = n - 1;

        while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                row++;
            } else {
                col--;
            }
        }

        return false;
    }
};

void test1() {
    std::vector<std::vector<int>> matrix{
        {1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    Solution s;
    assert(s.searchMatrix(matrix, 5));
}

void test2() {
    std::vector<std::vector<int>> matrix{
        {1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    Solution s;
    assert(!s.searchMatrix(matrix, 20));
}

int main() {
    test1();
    test2();
    return 0;
}