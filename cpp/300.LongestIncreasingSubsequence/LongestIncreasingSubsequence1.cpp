/*
解题思路：
    动态规划：
    DP[i]
    0<=i<n

    DP[i] = max(DP[0-j]) + 1 (nums[i] > nums[j] && j < i)

    DP[0-n-1]
*/

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            int max = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i] && dp[j] > max) {
                    max = dp[j];
                }
            }
            dp[i] = max + 1;
        }

        return *std::max_element(dp.begin(), dp.end());
    }
};

void test1() {
    std::vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    Solution s;
    assert(s.lengthOfLIS(nums) == 4);
}

void test2() {
    std::vector<int> nums{0, 1, 0, 3, 2, 3};
    Solution s;
    assert(s.lengthOfLIS(nums) == 4);
}

void test3() {
    std::vector<int> nums{7, 7, 7, 7, 7, 7, 7};
    Solution s;
    assert(s.lengthOfLIS(nums) == 1);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}