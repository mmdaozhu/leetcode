/*
时间复杂度分析：O(n)
*/

#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> result;
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end()) {
                result.emplace_back(map[target - nums[i]]);
                result.emplace_back(i);
                return result;
            } else {
                map[nums[i]] = i;
            }
        }
        return result;
    }
};

void test1() {
    std::vector<int> nums{2, 7, 11, 15};
    auto target = 9;
    std::vector<int> result{0, 1};
    Solution s;
    assert(s.twoSum(nums, target) == result);
}

void test2() {
    std::vector<int> nums{3, 2, 4};
    auto target = 6;
    std::vector<int> result{1, 2};
    Solution s;
    assert(s.twoSum(nums, target) == result);
}

void test3() {
    std::vector<int> nums{3, 3};
    auto target = 6;
    std::vector<int> result{0, 1};
    Solution s;
    assert(s.twoSum(nums, target) == result);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}