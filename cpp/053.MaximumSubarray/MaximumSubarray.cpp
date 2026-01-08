/*
解题思路：
    贪心
*/

// O(n)
// Runtime Beats 22.61%

#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int cur = 0;
        int max = INT_MIN;
        for (const auto& num : nums) {
            cur = std::max(cur + num, num);
            max = std::max(max, cur);
        }
        return max;
    }
};

void test1() {
    std::vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution s;
    assert(s.maxSubArray(nums) == 6);
}

void test2() {
    std::vector<int> nums{1};
    Solution s;
    assert(s.maxSubArray(nums) == 1);
}

void test3() {
    std::vector<int> nums{5, 4, -1, 7, 8};
    Solution s;
    assert(s.maxSubArray(nums) == 23);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}