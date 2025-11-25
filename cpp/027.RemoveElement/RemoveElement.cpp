/*
解题思路：
    快慢指针
*/

// O(n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int pos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[pos++] = nums[i];
            }
        }
        return pos;
    }
};

void test1() {
    std::vector<int> nums{3, 2, 2, 3};
    std::vector<int> expected_nums{2, 2};
    Solution s;
    auto result = s.removeElement(nums, 3);
    assert(result == 2);
    for (int i = 0; i < result; i++) {
        assert(nums[i] == expected_nums[i]);
    }
}

void test2() {
    std::vector<int> nums{0, 1, 2, 2, 3, 0, 4, 2};
    std::vector<int> expected_nums{0, 1, 3, 0, 4};
    Solution s;
    auto result = s.removeElement(nums, 2);
    assert(result == 5);
    for (int i = 0; i < result; i++) {
        assert(nums[i] == expected_nums[i]);
    }
}

int main() {
    test1();
    test2();
    return 0;
}