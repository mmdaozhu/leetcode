/*
解题思路：
    二分查找
*/

// O(log(m * n))
// Runtime Beats 100%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int row = find_row(matrix, target);
        return find_col(matrix, target, row);
    }

    int find_row(std::vector<std::vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid][0] <= target) {
                if (mid == matrix.size() - 1 || matrix[mid + 1][0] > target) {
                    return mid;
                }
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

    bool find_col(std::vector<std::vector<int>>& matrix, int target, int row) {
        if (row == -1) {
            return false;
        }

        int left = 0;
        int right = matrix[0].size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};

void test1() {
    std::vector<std::vector<int>> matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    Solution s;
    assert(s.searchMatrix(matrix, 3));
}

void test2() {
    std::vector<std::vector<int>> matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    Solution s;
    assert(!s.searchMatrix(matrix, 13));
}

int main() {
    test1();
    test2();
    return 0;
}