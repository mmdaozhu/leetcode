/*
解题思路：
    三指针
*/

// O(n)
// Runtime Beats 100%

#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int left = 0;
        int mid = 0;
        int right = nums.size() - 1;
        while (mid <= right) {
            if (nums[mid] == 0) {
                std::swap(nums[mid], nums[left]);
                left++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                std::swap(nums[mid], nums[right]);
                right--;
            }
        }
    }
};

void test1() {
    std::vector<int> nums{2, 0, 2, 1, 1, 0};
    std::vector<int> result{0, 0, 1, 1, 2, 2};
    Solution s;
    s.sortColors(nums);
    assert(nums == result);
}

void test2() {
    std::vector<int> nums{2, 0, 1};
    std::vector<int> result{0, 1, 2};
    Solution s;
    s.sortColors(nums);
    assert(nums == result);
}

int main() {
    test1();
    test2();
    return 0;
}