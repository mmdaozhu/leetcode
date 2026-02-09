/*
解题思路：
    动态规划
*/

// O(n)
// Runtime Beats 100%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int n = height.size();
        std::vector<int> left_max(n, 0);
        std::vector<int> right_max(n, 0);

        left_max[0] = height[0];
        for (int i = 1; i < n; i++) {
            left_max[i] = std::max(left_max[i - 1], height[i]);
        }

        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right_max[i] = std::max(right_max[i + 1], height[i]);
        }

        int water = 0;
        for (int i = 0; i < n; i++) {
            water += std::max(0, std::min(left_max[i], right_max[i]) - height[i]);
        }
        return water;
    }
};

void test1() {
    std::vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution s;
    assert(s.trap(height) == 6);
}

void test2() {
    std::vector<int> height{4, 2, 0, 3, 2, 5};
    Solution s;
    assert(s.trap(height) == 9);
}

int main() {
    test1();
    test2();
    return 0;
}