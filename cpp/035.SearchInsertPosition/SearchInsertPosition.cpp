/*
解体思路：
    二分查找
    low 正好是第一个 >= target 的位置
*/

// O(log n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        if (nums.size() < 1) {
            return -1;
        }

        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};

void test1() {
    std::vector<int> nums{1, 3, 5, 6};
    int target = 5;
    Solution s;
    assert(s.searchInsert(nums, 5) == 2);
}

void test2() {
    std::vector<int> nums{1, 3, 5, 6};
    Solution s;
    assert(s.searchInsert(nums, 2) == 1);
}

void test3() {
    std::vector<int> nums{1, 3, 5, 6};
    Solution s;
    assert(s.searchInsert(nums, 7) == 4);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}