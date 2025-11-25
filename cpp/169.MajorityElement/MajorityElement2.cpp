/*
解题思路：
    摩尔投票

时间复杂度分析：O(n)
*/

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        auto count = 0;
        auto majority = 0;
        for (const auto& num : nums) {
            if (count == 0) {
                majority = num;
            }
            if (num == majority) {
                count++;
            } else {
                count--;
            }
        }
        return majority;
    }
};

void test1() {
    std::vector<int> nums{3, 2, 3};
    Solution s;
    assert(s.majorityElement(nums) == 3);
}

void test2() {
    std::vector<int> nums{2, 2, 1, 1, 1, 2, 2};
    Solution s;
    assert(s.majorityElement(nums) == 2);
}

int main() {
    test1();
    test2();
    return 0;
}