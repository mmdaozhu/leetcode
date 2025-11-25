/*
解题思路：
    两个二分
    O(log n + log n) = O(log n)
*/

// O(log n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        if (nums.size() < 1) {
            return {-1, -1};
        }

        int left = -1, right = -1;

        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                if (mid == 0 || nums[mid - 1] != target) {
                    left = mid;
                    break;
                } else {
                    high = mid - 1;
                }
            }
        }

        low = 0;
        high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                if (mid == nums.size() - 1 || nums[mid + 1] != target) {
                    right = mid;
                    break;
                } else {
                    low = mid + 1;
                }
            }
        }
        return {left, right};
    }
};

void test1() {
    std::vector<int> nums{5, 7, 7, 8, 8, 10};
    std::vector<int> results{3, 4};
    Solution s;
    assert(s.searchRange(nums, 8) == results);
}

void test2() {
    std::vector<int> nums{5, 7, 7, 8, 8, 10};
    std::vector<int> results{-1, -1};
    Solution s;
    assert(s.searchRange(nums, 6) == results);
}

void test3() {
    std::vector<int> nums;
    std::vector<int> results{-1, -1};
    Solution s;
    assert(s.searchRange(nums, 6) == results);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}