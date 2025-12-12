/*
解题思路：
    二分查找
*/

// O(log n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target) {
                return mid;
            }

            // 左边有序
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // 右边有序
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};

void test1() {
    std::vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    Solution s;
    assert(s.search(nums, 0) == 4);
}

void test2() {
    std::vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    Solution s;
    assert(s.search(nums, 3) == -1);
}

void test3() {
    std::vector<int> nums{1};
    Solution s;
    assert(s.search(nums, 0) == -1);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}