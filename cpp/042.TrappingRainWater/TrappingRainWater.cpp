/*
解题思路：
    双指针
    每个柱子能接的水 = 左右最高柱子的最小值 - 当前柱子高度
*/

// O(n)
// Runtime Beats 100%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int left_max = height[left];
        int right_max = height[right];
        int water = 0;
        while (left <= right) {
            if (left_max < right_max) {
                water += std::max(0, left_max - height[left]);
                left_max = std::max(left_max, height[left]);
                left++;
            } else {
                water += std::max(0, right_max - height[right]);
                right_max = std::max(right_max, height[right]);
                right--;
            }
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