// O(n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        int index = 0;
        for (const auto& elem : nums) {
            if (map.find(target - elem) != map.end()) {
                return {map[target - elem], index};
            } else {
                map[elem] = index;
            }
            index++;
        }
        return {};
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