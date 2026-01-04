/*
解题思路：
    区间 BFS + 贪心扩边界
*/

// O(n)
// Runtime Beats 100%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return 0;
        }

        int steps = 0;
        int current_end = 0;  // 当前步数能覆盖到的最远位置
        int farthest = 0;     // 下一步能覆盖到的最远位置

        for (int i = 0; i < n - 1; i++) {
            farthest = std::max(farthest, i + nums[i]);
            if (i == current_end) {
                steps++;
                current_end = farthest;

                if (current_end >= n - 1) {
                    break;
                }
            }
        }

        return steps;
    }
};

void test1() {
    std::vector<int> nums{2, 3, 1, 1, 4};
    Solution s;
    assert(s.jump(nums) == 2);
}

void test2() {
    std::vector<int> nums{2, 3, 0, 1, 4};
    Solution s;
    assert(s.jump(nums) == 2);
}

int main() {
    test1();
    test2();
    return 0;
}