#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

/*
解体思路：
    动态规划
    动态规划方程：min_dist(i, j) = w[i][j] + min(min_dist(i-1, j-1), min_dist(i-1, j))
    从底向上递推

时间复杂度分析：O(n*m)
*/

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        std::vector<int> states = triangle[triangle.size() - 1];

        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                states[j] = triangle[i][j] + std::min(states[j], states[j + 1]);
            }
        }
        return states[0];
    }
};

void test1() {
    std::vector<std::vector<int>> triangle{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    Solution s;
    assert(s.minimumTotal(triangle) == 11);
}

void test2() {
    std::vector<std::vector<int>> triangle{{-10}};
    Solution s;
    assert(s.minimumTotal(triangle) == -10);
}

int main() {
    test1();
    test2();
    return 0;
}