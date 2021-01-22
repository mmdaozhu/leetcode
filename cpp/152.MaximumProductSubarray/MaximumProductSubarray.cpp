#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

/*
解体思路：
    动态规划
    动态规划方程：
                {  DP[i-1,0] * a[i]   (a[i]>=0)
    DP[i,0] =

                }  DP[i-1,1] * a[i]   (a[i]<0)

                {  DP[i-1,1] * a[i]   (a[i]>=0)
    DP[i,1] =

                }  DP[i-1,0] * a[i]   (a[i]<0)

时间复杂度分析：O(n)
*/

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        auto result = nums[0];
        auto cur_max = nums[0];
        auto cur_min = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            auto max = cur_max * nums[i];
            auto min = cur_min * nums[i];
            cur_max = std::max(std::max(max, min), nums[i]);
            cur_min = std::min(std::min(max, min), nums[i]);
            if (cur_max > result) {
                result = cur_max;
            }
        }
        return result;
    }
};

void test1() {
    std::vector<int> nums{2, 3, -2, 4};
    auto result = 6;
    Solution s;
    assert(s.maxProduct(nums) == result);
}

void test2() {
    std::vector<int> nums{-2, 0, -1};
    auto result = 0;
    Solution s;
    assert(s.maxProduct(nums) == result);
}

int main() {
    test1();
    test2();
    return 0;
}