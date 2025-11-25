/*
解题思路：
    维护LIS数组

时间复杂度分析：O(n*log(n))
*/

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> lis;
        for (int i = 0; i < nums.size(); i++) {
            auto it = std::lower_bound(lis.begin(), lis.end(), nums[i]);
            if (it == lis.end()) {
                lis.emplace_back(nums[i]);
            } else {
                *it = nums[i];
            }
        }

        return lis.size();
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