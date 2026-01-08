/*
解题思路：
    区间 BFS + 贪心扩边界
*/

// O(n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        for (int i = 0; i <= farthest; i++) {
            farthest = std::max(farthest, i + nums[i]);
            if (farthest >= n - 1) {
                return true;
            }
        }

        return false;
    }
};

void test1() {
    std::vector<int> nums{2, 3, 1, 1, 4};
    Solution s;
    assert(s.canJump(nums));
}

void test2() {
    std::vector<int> nums{3, 2, 1, 0, 4};
    Solution s;
    assert(!s.canJump(nums));
}

int main() {
    test1();
    test2();
    return 0;
}