// O(n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() == 1) {
            return 1;
        }

        int pos = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] != nums[i + 1]) {
                nums[++pos] = nums[i + 1];
            }
        }

        return pos + 1;
    }
};

void test1() {
    std::vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    std::vector<int> expected_nums{0, 1, 2, 3, 4};
    Solution s;
    auto result = s.removeDuplicates(nums);
    assert(result == 5);
    for (int i = 0; i < result; i++) {
        assert(nums[i] == expected_nums[i]);
    }
}

void test2() {
    std::vector<int> nums{1, 1, 2};
    std::vector<int> expected_nums{1, 2};
    Solution s;
    auto result = s.removeDuplicates(nums);
    assert(result == 2);
    for (int i = 0; i < result; i++) {
        assert(nums[i] == expected_nums[i]);
    }
}

int main() {
    test1();
    test2();
    return 0;
}