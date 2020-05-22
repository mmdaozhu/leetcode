/*
解体思路：
    先排序，然后找中间数，就是众数

时间复杂度分析：
    std::sort是改进后的快排，结果为O(nlogn)
*/

#include <assert.h>

#include <algorithm>
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
    std::vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(3);
    Solution s;
    assert(s.majorityElement(nums) == 3);
}

void test2() {
    std::vector<int> nums;
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    Solution s;
    assert(s.majorityElement(nums) == 2);
}

int main() {
    test1();
    test2();
    return 0;
}