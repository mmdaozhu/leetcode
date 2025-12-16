/*
解题思路：
    快慢指针
*/

// O(n)
// Runtime Beats 12.61%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }

        int pos = 2;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[pos - 2]) {
                nums[pos++] = nums[i];
            }
        }
        return pos;
    }
};

void test1() {
    std::vector<int> nums{1, 1, 1, 2, 2, 3};
    std::vector<int> expected_nums{1, 1, 2, 2, 3};
    Solution s;
    int result = s.removeDuplicates(nums);

    assert(result == 5);
    for (int i = 0; i < result; i++) {
        assert(nums[i] == expected_nums[i]);
    }
}

void test2() {
    std::vector<int> nums{0, 0, 1, 1, 1, 1, 2, 3, 3};
    std::vector<int> expected_nums{0, 0, 1, 1, 2, 3, 3};
    Solution s;
    int result = s.removeDuplicates(nums);
    assert(result == 7);
    for (int i = 0; i < result; i++) {
        assert(nums[i] == expected_nums[i]);
    }
}

int main() {
    test1();
    test2();
    return 0;
}