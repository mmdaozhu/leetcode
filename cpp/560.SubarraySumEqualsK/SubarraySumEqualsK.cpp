/*
解题思路：
    找有没有两个前缀和，它们的差等于 k
    prefix[j] - prefix[i] = k
    prefix[i] = prefix[j] - k
*/

// O(n)
// Runtime Beats 90.62%

#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        int count = 0;
        std::unordered_map<int, int> map;
        map[0] = 1;

        int prefix = 0;
        for (const auto& num : nums) {
            prefix += num;
            auto it = map.find(prefix - k);
            if (it != map.end()) {
                count += it->second;
            }
            map[prefix]++;
        }

        return count;
    }
};

void test1() {
    std::vector<int> nums{1, 1, 1};
    int k = 2;
    Solution s;
    assert(s.subarraySum(nums, k) == 2);
}

void test2() {
    std::vector<int> nums{1, 2, 3};
    int k = 3;
    Solution s;
    assert(s.subarraySum(nums, k) == 2);
}

int main() {
    test1();
    test2();
    return 0;
}