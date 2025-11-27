// O(m*n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<int> tmp(n, 0);
        std::vector<std::vector<int>> results(n, tmp);

        int i = 0, j = -1;
        int count = 0;
        while (count < n * n) {
            // right
            while (j < n - 1 && !results[i][j + 1]) {
                results[i][++j] = ++count;
            }

            // bottom
            while (i < n - 1 && !results[i + 1][j]) {
                results[++i][j] = ++count;
            }

            // left
            while (j > 0 && !results[i][j - 1]) {
                results[i][--j] = ++count;
            }

            // top
            while (i > 0 && !results[i - 1][j]) {
                results[--i][j] = ++count;
            }
        }

        return results;
    }
};

void test1() {
    std::vector<std::vector<int>> results{{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
    Solution s;
    assert(s.generateMatrix(3) == results);
}

void test2() {
    std::vector<std::vector<int>> results{{1}};
    Solution s;
    assert(s.generateMatrix(1) == results);
}

int main() {
    test1();
    test2();
    return 0;
}