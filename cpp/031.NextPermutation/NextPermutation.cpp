/*
解题思路：
    1. 从后向前找到第一个“升序对”（第一个 nums[i] < nums[i+1] 的位置 i）。
    2. 在后半部分找到比 nums[i] 大的最小元素，交换两者。
    3. 把 i 之后的序列翻转，变成最小的升序序列。
*/

// O(n)
// Runtime Beats 100.00%

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int m = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                m = i;
                break;
            }
        }
        if (m == -1) {
            std::reverse(nums.begin(), nums.end());
            return;
        }

        int n = -1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] > nums[m]) {
                n = i;
                break;
            }
        }

        std::swap(nums[m], nums[n]);
        std::reverse(nums.begin() + m + 1, nums.end());
    }
};

void test1() {
    std::vector<int> nums{1, 2, 3};
    std::vector<int> expect_nums{1, 3, 2};
    Solution s;
    s.nextPermutation(nums);
    assert(nums == expect_nums);
}

void test2() {
    std::vector<int> nums{3, 2, 1};
    std::vector<int> expect_nums{1, 2, 3};
    Solution s;
    s.nextPermutation(nums);
    assert(nums == expect_nums);
}

void test3() {
    std::vector<int> nums{1, 1, 5};
    std::vector<int> expect_nums{1, 5, 1};
    Solution s;
    s.nextPermutation(nums);
    assert(nums == expect_nums);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}