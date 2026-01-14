/*
解题思路：
    原地哈希
*/

// O(n)
// Runtime Beats 100%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                std::swap(nums[nums[i] - 1], nums[i]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1;
    }
};

void test1() {
    std::vector<int> nums{1, 2, 0};
    Solution s;
    assert(s.firstMissingPositive(nums) == 3);
}

void test2() {
    std::vector<int> nums{3, 4, -1, 1};
    Solution s;
    assert(s.firstMissingPositive(nums) == 2);
}

void test3() {
    std::vector<int> nums{7, 8, 9, 11, 12};
    Solution s;
    assert(s.firstMissingPositive(nums) == 1);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}