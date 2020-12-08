/*
解体思路：
    先排序，然后找中间数，就是众数

时间复杂度分析：O(nlogn)
*/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
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